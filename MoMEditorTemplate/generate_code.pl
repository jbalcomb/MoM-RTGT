use strict;

my @INPUTFILENAMES = ("MoMTemplate.h", "MoMcommon.h");
my $HFILENAME = "MoMGenerated.h";
my $CPPFILENAME = "MoMGenerated.cpp";

#
# Read input
#
undef $/;
$_ = "";
foreach my $inputfilename (@INPUTFILENAMES)
{
   open(FH, $inputfilename) || die "Cannot open '$inputfilename' to read: $!";
   $_ .= <FH>;
   close FH;
}

# Strip comment and Carriage Returns (if any)
s#\r##gm;
s#/\*(.|\n)*?\*/##gm;
s#\s*//[^\n]*##gm;


#
# Collect structs and unions (also processes embedded enums)
#
my %gStructUnions = ();
while (s#(struct|union|class)[^{]*{((.|\n)*?\n)}\s*(\w+);##m)
{
    my ($classbody, $classname) = ($2, $4);
    process_struct_union($classname, $classbody);
}

#
# Collect enums
#
my %gEnums = ();
while (s#enum\s+(\w+)[^{]*{([^}]*)}[^;]*;##m)
{
    my ($enumname, $enumbody) = ($1, $2);
    next if $enumname =~ m#ENUMSIZE#;
    process_enum($enumname, $enumbody);
}


generate_code($HFILENAME, $CPPFILENAME);

generate_Qt_code("Q".$HFILENAME, "Q".$CPPFILENAME);

close CPPFILE;
close HFILE;

exit;


sub generate_code
{
    my ($hfilename, $cppfilename) = @_;

    #
    # Open output files
    #
    open(HFILE, ">$hfilename") || die "Cannot open '$hfilename' to write: $!";
    open(CPPFILE, ">$cppfilename") || die "Cannot open '$cppfilename' to write: $!";

    #
    # Generate .h file
    #
    select(HFILE);
    
    print "// File: $hfilename\n";
    print "// Generated from: $INPUTFILENAMES[0]\n";
    print "\n";
    print "#include <iostream>\n";
    print "\n";
    print "#include \"$INPUTFILENAMES[0]\"\n";
    print "\n";
    print "namespace MoM {\n";
    print "\n";
   
    foreach my $enumname (sort keys %gEnums)
    {
        print "std::ostream& operator<<(std::ostream& os, const $enumname& rhs);\n";
    }
    print "\n";
    foreach my $classname (sort keys %gStructUnions)
    {
        print "std::ostream& operator<<(std::ostream& os, const $classname& rhs);\n";
    }
    print "\n";
    foreach my $enumname (sort keys %gEnums)
    {
        print "bool validate(const $enumname& rhs, const std::string& context);\n";
    }
    print "\n";
    foreach my $classname (sort keys %gStructUnions)
    {
        print "bool validate(const $classname& rhs, const std::string& context);\n";
    }
    
    print "\n";
    print "}\n";

    close(HFILE);
    
    
    #
    # Generate .cpp file
    #

    select(CPPFILE);
        
    print "// File: $cppfilename\n";
    print "// Generated from: $INPUTFILENAMES[0]\n";
    print "\n";
    print "#include <ctype.h>\n";
    print "#include <iomanip>\n";
    print "#include <sstream>\n";
    print "\n";
    print "#include \"$hfilename\"\n";
    print "\n";
    print "namespace MoM {\n";
    print "\n";

print <<'EOF';
std::string formatCharArray(const char* buffer, unsigned size)
{
    std::ostringstream oss;
    for (unsigned i = 0; i < size; ++i)
    {
        if (isprint((unsigned char)buffer[i]))
        {
            oss << buffer[i];
        }
        else
        {
            oss << "\\x" << std::setbase(16) << std::setw(2) << std::setfill('0') 
                << (unsigned)(unsigned char)buffer[i] 
                << std::setbase(10);
        }
    }
    return oss.str();
}

EOF

    #
    # Generate ostream operator<<()
    #

    foreach my $enumname (sort keys %gEnums)
    {
        my @enumvalues = @{$gEnums{$enumname}};
        
        print "std::ostream& operator<<(std::ostream& os, const $enumname& rhs)\n";
        print "{\n";
        print "    switch (rhs)\n";
        print "    {\n";
        foreach my $enumvalue (@enumvalues)
        {
            next if $enumvalue =~ m#_SIZE__#;
            next if $enumvalue =~ m#_FIRST#;
            print "    case $enumvalue: os << \"$enumvalue\"; break;\n"
        }
        print "    default: os << \"<Unknown $enumname>\"; break;\n";
        print "    }\n";
        print "    os << \" (\" << (unsigned)rhs << \")\";\n";
        print "    return os;\n";
        print "}\n";
        print "\n";
    }
    
    foreach my $classname (sort keys %gStructUnions)
    {
        my @datamembers = @{$gStructUnions{$classname}};
        
        if ($classname eq "EXE_Reloc")
        {
           print "std::ostream& operator<<(std::ostream& os, const $classname& rhs)\n";
           print "{\n";
           print "    os << std::hex << rhs.segment << ':' << rhs.offset << std::dec;\n";
           print "    return os;\n";
           print "}\n";
           print "\n";
           next;
        }
        
        print "std::ostream& operator<<(std::ostream& os, const $classname& rhs)\n";
        print "{\n";
        print "    os << \"{\\n\";\n";
        while (1)
        {
            my $type = shift @datamembers;
            my $datamember = shift @datamembers;
            last if not defined $datamember;
            
            $datamember =~ m#^(\w+)(\[([^\]]+)\])?(\s*:\s*(.*))?$#;
            my ($name, $range, $bitmask) = ($1, $3, $5);
            my $cast = "";
            $cast = "(unsigned)" if $type eq "uint8_t" or $type =~ m#\benum\b#;
            $cast = "(int)" if $type eq "int8_t";
            if ((defined $range) && ($type =~ m#int\d+_t$#))
            {
                print "    os << \"$name=(\\n\";\n";
                print "    for (int i = 0; i < $range; ++i)\n";
                print "    {\n";
                print qq#        os << "[" << i << "] " << ${cast}rhs.$name\[i] << " 0x" << std::hex << ${cast}rhs.$name\[i] << std::dec << ",\\n";\n#;
                print "    }\n";
                print "    os << \")\\n\";\n";
            }
            elsif ((defined $range) && ($type ne "char"))
            {
                print "    os << \"$name=(\\n\";\n";
                print "    for (int i = 0; i < $range; ++i)\n";
                print "    {\n";
                print qq#        os << "[" << i << "] " << ${cast}rhs.${name}\[i] << ",\\n";\n#;
                print "    }\n";
                print "    os << \")\\n\";\n";
            }
           elsif ((defined $range) && ($type eq "char"))
            {
                print "    os << \"$name=\" << formatCharArray(rhs.$name, $range) << \"\\n\";\n";
            }
            elsif ($type =~ m#int\d+_t$#)
            {
                if (defined $bitmask)
                {
                    print qq#    if (0 != rhs.$name)\n#;
                    print qq#    {\n#;
                    print qq#    os << \"$name=\" << ${cast}rhs.$name << "\\n";\n#;
                    print qq#    }\n#;
                }
                else
                {
                    print qq#    os << \"$name=\" << ${cast}rhs.$name << " 0x" << std::hex << ${cast}rhs.$name << std::dec << \"\\n\";\n#;
                }
            }
            else
            {
                print "    os << \"$name=\" << ${cast}rhs.$name << \"\\n\";\n";
            }
        }
        print "    os << \"}\";\n";
        print "    return os;\n";
        print "}\n";
        print "\n";
    }


    #
    # Generate bool validate()
    #

    foreach my $enumname (sort keys %gEnums)
    {
        my @enumvalues = @{$gEnums{$enumname}};
        
        print "bool validate(const $enumname& rhs, const std::string& context)\n";
        print "{\n";
        print "    bool ok = true;\n";
        if ($enumname eq "eTerrainType" || $enumname eq "eItem_Icon")
        {
            print "    ok = (rhs < ${enumname}_MAX);\n";
        }
        else
        {
            print "    switch (rhs)\n";
            print "    {\n";
            foreach my $enumvalue (@enumvalues)
            {
                next if $enumvalue =~ m#_SIZE__$#;
                next if $enumvalue =~ m#_FIRST$#;
                next if $enumvalue =~ m#_MAX$#;
                print "    case $enumvalue: break;\n"
            }
            print "    default: std::cout << context << \": Unknown $enumname = \" << (int)rhs << \"\\n\"; ok = false; break;\n";
            print "    }\n";
        }
        print "    return ok;\n";
        print "}\n";
        print "\n";
    }
    
    foreach my $classname (sort keys %gStructUnions)
    {
        my @datamembers = @{$gStructUnions{$classname}};
        
        print "bool validate(const $classname& rhs, const std::string& context)\n";
        print "{\n";
        print "    bool ok = true;\n";
        if ($classname eq "Hired_Hero")
        {
            print "    if (-1 == rhs.m_Unit_Nr) { return true; }\n";
        }
        elsif ($classname eq "Item")
        {
            print "    if (-1 == rhs.m_Cost || 0 == rhs.m_Cost) { return true; }\n";
        }
        
        while (1)
        {
            my $type = shift @datamembers;
            my $datamember = shift @datamembers;
            last if not defined $datamember;
            
            next if ($type =~ m#^u?int\d+_t$#);
            next if ($type eq "char");
            next if ($datamember =~ m#trash#i);
            
            $datamember =~ m#^(\w+)(\[([^\]]+)\])?(\s*:\s*(.*))?$#;
            my ($name, $range, $bitmask) = ($1, $3, $5);
            if (defined $range)
            {
                $range = "rhs.m_Game_Data.m_Number_of_Wizards" if ($name eq "m_Wizards");
                $range = "rhs.m_Game_Data.m_Number_of_Cities" if ($name eq "m_Cities");
                $range = "rhs.m_Game_Data.m_Number_of_Units" if ($name eq "m_Unit");
                
                print qq#    for (int i = 0; i < $range; ++i)\n#;
                print qq#    {\n#;
                print qq#          std::ostringstream oss;\n#;
                print qq#          oss << context << ".${name}\[" << i << "]";\n#;
                print qq#          if (!validate(rhs.${name}\[i], oss.str())) ok = false;\n#;
                print qq#    }\n#;
            }
            else
            {
                print "    if (!validate(rhs.${name}, context + \".${name}\")) ok = false;\n"
            }
        }
#		print "    if (!ok) std::cout << \"\\n\" << rhs << std::endl;\n";
        print "    return ok;\n";
        print "}\n";
        print "\n";
    }
    
    print "\n";
    print "} // namespace\n";

    close(CPPFILE);
}


sub generate_Qt_code
{
    my ($hfilename, $cppfilename) = @_;

    #
    # Open output files
    #
    open(HFILE, ">$hfilename") || die "Cannot open '$hfilename' to write: $!";
    open(CPPFILE, ">$cppfilename") || die "Cannot open '$cppfilename' to write: $!";

    #
    # Generate .h file
    #
    select(HFILE);
    
    print "// File: $hfilename\n";
    print "// Generated from: $INPUTFILENAMES[0]\n";
    print "\n";
    print "#include <iostream>\n";
    print "\n";
    print "#include \"$INPUTFILENAMES[0]\"\n";
    print "#include \"treeitem.h\"\n";
    print "\n";
    print "namespace MoM {\n";
    print "\n";
   
    foreach my $classname (sort keys %gStructUnions)
    {
        print "TreeItemBase* constructTreeItem($classname* rhs, const QString& context);\n";
    }
    
    print "\n";
    print "}\n";

    close(HFILE);
    

    #
    # Generate .cpp file
    #

    select(CPPFILE);
        
    print "// File: $cppfilename\n";
    print "// Generated from: $INPUTFILENAMES[0]\n";
    print "\n";
    print "#include <ctype.h>\n";
    print "#include <iomanip>\n";
    print "#include <sstream>\n";
    print "\n";
    print "#include <MoMGenerated.h>\n";
    print "\n";
    print "#include \"$hfilename\"\n";
    print "\n";
    print "namespace MoM {\n";
    print "\n";
    
    
    #
    # Generate void constructTreeItem()
    #

    foreach my $classname (sort keys %gStructUnions)
    {
        my @datamembers = @{$gStructUnions{$classname}};
        
        print "TreeItemBase* constructTreeItem($classname* rhs, const QString& context)\n";
        print "{\n";
        #if ($classname eq "Hired_Hero")
        #{
        #    print "    if (-1 == rhs.m_Unit_Nr) { return true; }\n";
        #
        #elsif ($classname eq "Item")
        #{
        #    print "    if (-1 == rhs.m_Cost || 0 == rhs.m_Cost) { return true; }\n";
        #}
        print "    TreeItemBase* ptree = new TreeItemBase(context);\n";
        print "    if (0 == rhs)\n";
        print "        return ptree;\n";
        print "\n";
        
        while (1)
        {
            my $type = shift @datamembers;
            my $datamember = shift @datamembers;
            last if not defined $datamember;
            
            #next if ($datamember =~ m#trash#i);
            
            $datamember =~ m#^(\w+)(\[([^\]]+)\])?(\s*:\s*(.*))?$#;
            my ($name, $range, $bitmask) = ($1, $3, $5);
            my $cast = "";
            $cast = "(unsigned)" if $type eq "uint8_t" or $type =~ m#\benum\b#;
            $cast = "(int)" if $type eq "int8_t";
            if (defined $range and $type eq "char")
            {
                print "    ptree->appendChild(\"${name}\", new TreeItem<char[$range]>(rhs->${name}));\n";
            }
            elsif (defined $range)
            {
                my $psubtree = "ptree${name}";
                print qq#    TreeItemBase* $psubtree = ptree;\n#;
                if (1 * @{$gStructUnions{$classname}} > 2)
                {
                    print qq#    if ($range > 3)\n#;
                    print qq#    {\n#;
                    print qq#        $psubtree = new TreeItemBase("${name}");\n#;
                    print qq#        ptree->appendTree($psubtree, "");\n#;
                    print qq#    }\n#;
                }
            
                print qq#    for (int i = 0; i < $range; ++i)\n#;
                print qq#    {\n#;
                print qq#          std::ostringstream oss;\n#;
                print qq#          oss << "${name}\[" << i << "]";\n#;
                if ($type =~ m#u?int\d+_t# or exists $gEnums{$type})
                {
                    print qq#          $psubtree->appendChild(oss.str().c_str(), new TreeItem<$type>(&rhs->${name}\[i]));\n#;
                }
                else
                {
                    print qq#          $psubtree->appendTree(constructTreeItem(&rhs->${name}\[i], oss.str().c_str()), "");\n#;
                }
                print qq#    }\n#;
            }
            elsif ($type =~ m#u?int\d+_t# and defined $bitmask)
            {
                print qq#    $classname mask${name};\n#;
                print qq#    memset(&mask${name}, '\\0', sizeof(mask${name}));\n#;
                print qq#    mask${name}.${name} = 0xFF;\n#;
                print qq#    if (1 == sizeof(mask${name}))\n#;
                print qq#        ptree->appendChild("${name}", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&mask${name}));\n#;
                print qq#    else if (2 == sizeof(mask${name}))\n#;
                print qq#        ptree->appendChild("${name}", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&mask${name}));\n#;
                print qq#    else\n#;
                print qq#        ptree->appendChild("${name}", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&mask${name}));\n#;
            }
            elsif ($type =~ m#u?int\d+_t# or exists $gEnums{$type})
            {
                print qq#    ptree->appendChild("${name}", new TreeItem<$type>(&rhs->${name}));\n#;
            }
            else
            {
                print qq#    ptree->appendTree(constructTreeItem(&rhs->${name}, "${name}"), "");\n#;
            }
        }
        print "    return ptree;\n";
        print "}\n";
        print "\n";
    }
    
    print "\n";
    print "} // namespace\n";

    close(CPPFILE);
}

sub process_enum
{
    my ($enumname, $enumbody) = @_;
    my @enumvalues = ();
    
    # For each line in $enumbody
    while ($enumbody =~ s#^\s*([^\n]*)\n##)
    {
        my $line = $1;
        
        # Strip comment and white space
        my $comment = "";
        $comment = $1 if ($line =~ s#\s*//\s*(.*)##);
        $line =~ s#^\s*##;
        
        # Strip initializers
        $line =~ s#\s*=[^,]*##g;
        
        # Collect remaining enum values
        push(@enumvalues, split(/,\s*/, $line));
    }
    
    # Register enum
    $gEnums{$enumname} = \@enumvalues;
}

sub process_struct_union
{
    my ($classname, $classbody) = @_;
    my @datamembers = ();

    # For each declaration in $classbody
    print "classname = $classname\nclassbody = '$classbody'\n\n";
    while ($classbody =~ s#^([^;]*?);[^\n]*\n##)
    {
        my $declaration = $1;
        
        # Strip leading and trailing white space
        $declaration =~ s#^(\s|\n)+##;
        $declaration =~ s#\s+$##;
        
        next if $declaration !~ m#^([^;]*?)\s*\b(\w+(\[[^\]]*\])*(\s*:\s*\d+)?)$#;
        
        my ($type, $datamember) = ($1, $2);
        print "type = '$type'\n";
        print "datamember = $datamember\n";
        
        # Register data member
        push(@datamembers, $type, $datamember);
    }
    
    $gStructUnions{$classname} = \@datamembers;
}
