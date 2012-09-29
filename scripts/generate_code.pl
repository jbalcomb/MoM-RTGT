use strict;
use warnings;

my $INPUTFILE = "MoMTemplate.h";
my @INPUTFILENAMES = ("Platform/MoMCommon.h", "MoMModel/$INPUTFILE");
my $GENDIR = "MoMModel/Generated";
my $HFILENAME = "MoMGenerated.h";
my $CPPFILENAME = "MoMGenerated.cpp";
my $QT_GENDIR = "QMoMCommon/Generated";
my $QT_HFILENAME = "QMoMGenerated.h";
my $QT_CPPFILENAME = "QMoMGenerated.cpp";
my $IDC_GENDIR = ".";
my $IDC_FILENAME = "MoMGenerated.idc";

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
# Collect constants
#
my %gConstants = ();
while (s#\bconst (unsigned|size_t) (\w+) = (\d+);##m)
{
    my ($name, $value) = ($2, $3);
    $gConstants{$name} = $value;
}

#
# Collect enums (includes collecting the enumerators in %gConstants)
#
my %gEnums = ();
while (s#enum\s+(\w+)\s*(ENUMSIZE(\d+))?[^{]*{([^}]*)}[^;]*;##m)
{
    my ($enumname, $enumsizebits, $enumbody) = ($1, $3, $4);
    next if $enumname =~ m#ENUMSIZE#;
    process_enum($enumname, $enumsizebits, $enumbody);
}

#
# Collect structs and unions
#
my %gStructUnions = ();
while (s#typedef (struct|union|class)\b[^{]*{((.|\n)*?\n)}\s*(\w+);##m)
{
    my ($classtype, $classbody, $classname) = ($1, $2, $4);
    process_struct_union($classtype, $classname, $classbody);
}

generate_code($GENDIR, $HFILENAME, $CPPFILENAME);

generate_Qt_code($QT_GENDIR, $QT_HFILENAME, $QT_CPPFILENAME);

generate_IDC_code($IDC_GENDIR, $IDC_FILENAME);

exit;


sub generate_code
{
    my ($gendir, $hfilename, $cppfilename) = @_;

    #
    # Open output files
    #
    open(HFILE, ">$gendir/$hfilename") || die "Cannot open '$gendir/$hfilename' to write: $!";
    open(CPPFILE, ">$gendir/$cppfilename") || die "Cannot open '$gendir/$cppfilename' to write: $!";

    #
    # Generate .h file
    #
    select(HFILE);
    
    print "// File: $gendir/$hfilename\n";
    print "// Generated from: $INPUTFILE\n";
    print "\n";
    print "#include <iostream>\n";
    print "\n";
    print "#include \"$INPUTFILE\"\n";
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
        
    print "// File: $gendir/$cppfilename\n";
    print "// Generated from: $INPUTFILE\n";
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
        my @enumvalues = @{$gEnums{$enumname}{'names'}};
        
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
        my @datamembers = @{$gStructUnions{$classname}{'datamembers'}};
        
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
            
			$type = "uint16_t" if ($type eq "DS_Offset");
            $datamember =~ m#^(\w+)(\[([^\]]+)\])?(\s*:\s*(.*))?$#;
            my ($name, $range, $bitmask) = ($1, $3, $5);
            my $cast = "";
            $cast = "(unsigned)" if $type eq "uint8_t" or $type =~ m#\benum\b#;
            $cast = "(int)" if $type eq "int8_t";
            if ((defined $range) && ($type =~ m#int\d+_t$#))
            {
                print "    os << \"$name=(\\n\";\n";
                print "    for (unsigned i = 0; i < $range; ++i)\n";
                print "    {\n";
                print qq#        os << "[" << i << "] " << ${cast}rhs.$name\[i] << " 0x" << std::hex << ${cast}rhs.$name\[i] << std::dec << ",\\n";\n#;
                print "    }\n";
                print "    os << \")\\n\";\n";
            }
            elsif ((defined $range) && ($type ne "char"))
            {
                print "    os << \"$name=(\\n\";\n";
                print "    for (unsigned i = 0; i < $range; ++i)\n";
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
        my @enumvalues = @{$gEnums{$enumname}{'names'}};
        
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
        my @datamembers = @{$gStructUnions{$classname}{'datamembers'}};
        
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
            
            $type = "uint16_t" if ($type eq "DS_Offset");
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
                
                print qq#    for (unsigned i = 0; i < $range; ++i)\n#;
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
    my ($gendir, $hfilename, $cppfilename) = @_;

    #
    # Open output files
    #
    open(HFILE, ">$gendir/$hfilename") || die "Cannot open '$gendir/$hfilename' to write: $!";
    open(CPPFILE, ">$gendir/$cppfilename") || die "Cannot open '$gendir/$cppfilename' to write: $!";

    #
    # Generate .h file
    #
    select(HFILE);
    
    print "// File: $gendir/$hfilename\n";
    print "// Generated from: $INPUTFILE\n";
    print "\n";
    print "#include <iostream>\n";
    print "\n";
    print "#include \"$INPUTFILE\"\n";
    print "#include \"QMoMTreeItemModel.h\"\n";
    print "\n";
    print "namespace MoM {\n";
    print "\n";
   
    foreach my $classname (sort keys %gStructUnions)
    {
        print "QMoMTreeItemModelBase* constructTreeItem($classname* rhs, const QString& context);\n";
    }
    
    print "\n";
    print "}\n";

    close(HFILE);
    

    #
    # Generate .cpp file
    #

    select(CPPFILE);
        
    print "// File: $gendir/$cppfilename\n";
    print "// Generated from: $INPUTFILE\n";
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
        my @datamembers = @{$gStructUnions{$classname}{'datamembers'}};
        
        print "QMoMTreeItemModelBase* constructTreeItem($classname* rhs, const QString& context)\n";
        print "{\n";
        print "    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<$classname>(rhs, context);\n";
        print "    if (0 == rhs)\n";
        print "        return ptree;\n";
        print "\n";
        
        while (1)
        {
            my $type = shift @datamembers;
            my $datamember = shift @datamembers;
            last if not defined $datamember;
            
            #next if ($datamember =~ m#trash#i);
            
			$type = "uint16_t" if ($type eq "DS_Offset");
            $datamember =~ m#^(\w+)(\[([^\]]+)\])?(\s*:\s*(.*))?$#;
            my ($name, $range, $bitmask) = ($1, $3, $5);
            my $cast = "";
            $cast = "(unsigned)" if $type eq "uint8_t" or $type =~ m#\benum\b#;
            $cast = "(int)" if $type eq "int8_t";
            if (defined $range and $type eq "char")
            {
                print "    ptree->appendChild(\"${name}\", new QMoMTreeItemModel<char[$range]>(rhs->${name}));\n";
            }
            elsif (defined $range)
            {
                my $psubtree = "ptree${name}";
                print qq#    QMoMTreeItemModelBase* $psubtree = ptree;\n#;
                if (1 * @{$gStructUnions{$classname}{'datamembers'}} > 2)
                {
                    print qq#    if ($range > 3)\n#;
                    print qq#    {\n#;
                    print qq#        $psubtree = new QMoMTreeItemModelBase("${name}");\n#;
                    print qq#        ptree->appendTree($psubtree, "");\n#;
                    print qq#    }\n#;
                }
            
                print qq#    for (unsigned i = 0; i < $range; ++i)\n#;
                print qq#    {\n#;
                print qq#          std::ostringstream oss;\n#;
                print qq#          oss << "${name}\[" << i << "]";\n#;
                if ($type =~ m#u?int\d+_t# or exists $gEnums{$type})
                {
                    print qq#          $psubtree->appendChild(oss.str().c_str(), new QMoMTreeItemModel<$type>(&rhs->${name}\[i]));\n#;
                }
                else
                {
                    print qq#          $psubtree->appendTree(constructTreeItem(&rhs->${name}\[i], oss.str().c_str()), "");\n#;
                }
                print qq#    }\n#;
            }
            elsif ($type =~ m#u?int\d+_t# and defined $bitmask)
            {
                my $max_value = 2**$bitmask - 1;
                print qq#    $classname mask${name};\n#;
                print qq#    memset(&mask${name}, '\\0', sizeof(mask${name}));\n#;
                print qq#    mask${name}.${name} = $max_value;\n#;
                print qq#    if (1 == sizeof(mask${name}))\n#;
                print qq#        ptree->appendChild("${name}", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&mask${name}));\n#;
                print qq#    else if (2 == sizeof(mask${name}))\n#;
                print qq#        ptree->appendChild("${name}", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&mask${name}));\n#;
                print qq#    else\n#;
                print qq#        ptree->appendChild("${name}", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&mask${name}));\n#;
            }
            elsif (exists $gEnums{"${type}"} and exists $gEnums{"${type}140m"})
            {
                print qq#    if (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string("v1.40m"))\n#;
                print qq#    {\n#;
                print qq#        ptree->appendChild("${name}", new QMoMTreeItemModel<${type}140m>((${type}140m*)&rhs->${name}));\n#;
                print qq#    }\n#;
                print qq#    else\n#;
                print qq#    {\n#;
                print qq#        ptree->appendChild("${name}", new QMoMTreeItemModel<${type}>(&rhs->${name}));\n#;
                print qq#    }\n#;
            }
            elsif ($type =~ m#u?int\d+_t# or exists $gEnums{$type})
            {
                print qq#    ptree->appendChild("${name}", new QMoMTreeItemModel<$type>(&rhs->${name}));\n#;
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

sub generate_IDC_code
{
    my ($gendir, $idcfilename) = @_;

    #
    # Open output files
    #
    open(IDCFILE, ">$gendir/$idcfilename") || die "Cannot open '$gendir/$idcfilename' to write: $!";

    #
    # Generate .idc file
    #

    select(IDCFILE);
        
    print
	"// File: $gendir/$idcfilename\n".
	"// Generated from: $INPUTFILE\n".
	"\n".
	"//      This file contains the user-defined type definitions.\n".
	"//      To use it press F2 in IDA and enter the name of this file.\n".
	"//\n".
	"\n".
	"#define UNLOADED_FILE   1\n".
	"#include <idc.idc>\n".
	"\n".
	"static main(void)\n".
	"{\n".
	"  Enums();              // enumerations\n".
	"  Structures();         // structure types\n".
	"	LowVoids(0x20);\n".
	"	HighVoids(0xF978);\n".
	"}\n".
	"\n".
	"static Enums_0(id) {\n".
	"\n";
    
    ## Bitmask enum
	# id = AddEnum(-1,"eWeaponModification",0x1100000);
	# SetEnumBf(id,1);
	# AddConstEx(id,"MODIFICATION_None",	0X1,	0x1);
	# AddConstEx(id,"MODIFICATION_Heavy",	0X2,	0x2);

    ## Regular enum
	# id = AddEnum(-1,"eHullSize",0x1100000);
	# AddConstEx(id,"HULL_Frigate",	0X0,	-1);
	# AddConstEx(id,"HULL_Destroyer",	0X1,	-1);
	
    foreach my $enumname (sort keys %gEnums)
    {
        print qq#    id = AddEnum(-1,"$enumname",0x1100000);\n#;
		my @names = @{$gEnums{$enumname}{'names'}};
		my @values = @{$gEnums{$enumname}{'values'}};
        print qq#    SetEnumBf(id,1);\n# if exists $gEnums{$enumname}{'bitmask'};
		for my $i (0..$#names)
		{
			die "Can't find values[$i] for '$enumname' '$names[$i]'" if not defined $values[$i];
			my $bitmask_value = -1;
			$bitmask_value = $values[$i] if exists $gEnums{$enumname}{'bitmask'};
			print qq#    AddConstEx(id,"$names[$i]",	$values[$i],	$bitmask_value);\n#;
		}
	}
	
	print
	"\n".	
	"	return id;\n".
	"}\n".
	"\n".
	"//------------------------------------------------------------------------\n".
	"// Information about enum types\n".
	"\n".
	"static Enums(void) {\n".
	"        auto id;\n".
	"	id = Enums_0(id);\n".
	"}\n".
	"\n".
	"static Structures_0(id) {\n".
	"        auto mid;\n".
	"\n";

	# id = AddStrucEx(-1,"Battlefield",0);
	# id = AddStrucEx(-1,"Moo2_Ship",0);
    foreach my $classname (sort keys %gStructUnions)
	{
        print qq#    id = AddStrucEx(-1,"$classname",0);\n#;
	}
	print "\n";
	
	# id = GetStrucIdByName("Battlefield");
	# mid = AddStrucMember(id,"field_Terrain",	0X0,	0x10000400,	-1,	924);
	# SetMemberComment(id,	0X0,	"22 x 21 map (21 squares per line)",	0);
	# mid = AddStrucMember(id,"field_terrainGroupType",	0X39C,	0x000400,	-1,	462);
	# SetMemberComment(id,	0X39C,	"\n0=walkable\n1=rough\n2=walkable\n3=river\n4=sea",	1);
	# mid = AddStrucMember(id,"field_road",	0X56A,	0x000400,	-1,	462);
	# SetMemberComment(id,	0X56A,	"\n0=no road, 81h=road, other=?",	1);
	# mid = AddStrucMember(id,"field_Movement_walking",	0X738,	0x000400,	-1,	462);
	#
	# mid = AddStrucMember(id,"offset_Label",	0X0,	0x10500400,	0X36AA0,	2,	0XFFFFFFFF,	0X0,	0x000002);
	#
	# id = GetStrucIdByName("Moo2_Ship");
	# mid = AddStrucMember(id,"name",	0X0,	0x000400,	-1,	16);
	# mid = AddStrucMember(id,"hull_size",	0X10,	0x800400,	GetEnum("eHullSize"),	1);
	# mid = AddStrucMember(id,"ship_type",	0X11,	0x000400,	-1,	1);
	# mid = AddStrucMember(id,"shield_type",	0X12,	0x000400,	-1,	1);
	# mid = AddStrucMember(id,"drive_type",	0X13,	0x000400,	-1,	1);
	# mid = AddStrucMember(id,"field_14",	0X14,	0x000400,	-1,	1);
	# mid = AddStrucMember(id,"computer_type",	0X15,	0x000400,	-1,	1);
	# mid = AddStrucMember(id,"armor_type",	0X16,	0x000400,	-1,	1);
	# mid = AddStrucMember(id,"specials",	0X17,	0x000400,	-1,	5);
	# mid = AddStrucMember(id,"weapon_slots",	0X1C,	0x60000400,	GetStrucIdByName("Moo2_ShipWeapon"),	64);
    foreach my $classname (sort keys %gStructUnions)
    {
        my @members = @{$gStructUnions{$classname}{'members'}};
        
        print qq#    id = GetStrucIdByName("$classname");\n#;
        
        foreach my $member (@members)
        {
			my $name = $member->{'name'};
			my $offset = $member->{'offset'};
            my $type = $member->{'type'};
            my $size = $member->{'size'};
			my $idcflags = 0x000400;
			my $idctype = -1;

			#   0x000400 db ?
			#   0x200400 db ?   		; base 10
			#   0x300400 db 30 dup(?)   ; char
			#   0x800400 enum
			#  0x1100400 db 2 dup(?)   	; base 16
			# 0x10800400 dw ?			; enum
			# 0x11100400 dw ?
			# 0x21100400 dd ?
			# 0x12200400 dw ?
			# 0x14400400 dw ?
			# 0x50000400 db 16 dup(?)   ; string(C)
			# 0x10000400 dw 6 dup(?)
			# 0x20100400 dd ?           ; base 16
			# 0x10500400 dw ?           ; offset (idctype=00036AA0)
			
			#   0x000400 struct-field (always on)
			#   0x100000 base 16
			#   0x200000 base 10
			#   0x300000 char
			#   0x500000 offset - has extra parameters, in particular idctype=00036AA0 instead of -1
			#   0x800000 enum-byte
			# 0x00000000 db
			# 0x10000000 dw
			# 0x20000000 dd
			# 0x50000000 string(C) - has type 0x0 instead of -1
			# 0x60000000 struct
			if ($type eq "char")
			{
				$idctype = qq#0x0#;
				$idcflags |= 0x800000;
			}
			elsif (exists $gEnums{$type})
			{
				$idctype = qq#GetEnum("$type")#;
				$idcflags |= 0x800000;
			}
			elsif (exists $gStructUnions{$type})
			{
				$idctype = qq#GetStrucIdByName("$type")#;
				$idcflags |= 0x60000000;
			}
			else
			{
			}
			
			if ($type =~ m#^u?int16_t# or (exists $gEnums{$type} and $gEnums{$type}{'size'} == 2))
			{
				$idcflags |= 0x10000000;
			}
			elsif ($type =~ m#^u?int32_t#)
			{
				$idcflags |= 0x20000000;
			}
			else
			{
			}

			if ($type eq "DS_Offset")
			{
				printf qq#    mid = AddStrucMember(id,"$name",	0X%X,	0x10500400,	0X36AA0,	2,	0XFFFFFFFF,	0X0,	0x000002);\n#, $offset;
			}
			else
			{
				printf qq#    mid = AddStrucMember(id,"$name",	0X%X,	0X%06X,	$idctype,	$size);\n#, $offset, $idcflags;
			}
        }
    }

	print	
	"	return id;\n".
	"}\n".
	"\n".
	"//------------------------------------------------------------------------\n".
	"// Information about structure types\n".
	"\n".
	"static Structures(void) {\n".
	"        auto id;\n".
	"	id = Structures_0(id);\n".
	"}\n".
	"\n".
	"// End of file.\n";
 
    close(IDCFILE);
}

sub process_enum
{
    my ($enumname, $enumsizebits, $enumbody) = @_;
	my $enumsize = 4;
	$enumsize = $enumsizebits / 8 if defined $enumsizebits;
    my @enumerator_names = ();
    my @enumerator_values = ();
	my $enumerator_value = -1;
    
    # For each line in $enumbody
    print "enumname = $enumname ($enumsize)\n";
    while ($enumbody =~ s#^\s*([^\n]*)\n##)
    {
        my $line = $1;
        
        # Strip comment and white space
        my $comment = "";
        $comment = $1 if ($line =~ s#\s*//\s*(.*)##);
        $line =~ s#^\s*##;
        
		my @enumerators = split(/,\s*/, $line);
		foreach my $enumerator (@enumerators)
		{
			my $enumerator_name = undef;
			
			if ($enumerator =~ m#^(\w+)\s*=\s*([\S]+)$#)
			{
				($enumerator_name, $enumerator_value) = ($1, $2);
			}
			elsif ($enumerator =~ m#^(\w+)$#)
			{
				($enumerator_name, $enumerator_value) = ($1, eval($enumerator_value) + 1);
			}
			else
			{
				die "Cannot parse enum '$enumname' at line '$line'";
			}
		
			# Collect enumerators
			push(@enumerator_names, $enumerator_name);
			push(@enumerator_values, $enumerator_value);
			$gConstants{$enumerator_name} = $enumerator_value;
		}
    }
    
    # Register enum
    $gEnums{$enumname}{'size'} = $enumsize;
    $gEnums{$enumname}{'names'} = \@enumerator_names;
    $gEnums{$enumname}{'values'} = \@enumerator_values;
}

sub process_struct_union
{
    my ($classtype, $classname, $classbody) = @_;
    my @datamembers = ();	# old-style
    my @memberlist = ();
	my $offset = 0;
	my $countbits = 0;
	my $classsize;

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
		
		$datamember =~ m#^(\w+)(\[([^\]]+)\])?(\s*:\s*(\d+))?$# 
			or die "Cannot parse class '$classname' at declaration '$declaration'";
        my ($name, $range, $bits) = ($1, $3, $5);
		my ($rangevalue, $typesize, $membersize);

		if (not defined $range)
		{
		}
		elsif (exists $gConstants{$range})
		{
			$rangevalue = $gConstants{$range};
		}
		else
		{
			$rangevalue = eval($range);
		}
		
		$typesize = 0;
		if ($type =~ m#^char$#)
		{
			$typesize = 1;
		}
		elsif ($type =~ m#^u?int(\d+)_t$#)
		{
			$typesize = $1 / 8;
		}
		elsif ($type eq "DS_Offset")
		{
			$typesize = 2;
		}
		elsif (exists $gEnums{$type})
		{
			$typesize = $gEnums{$type}{'size'};
		}
		elsif (exists $gStructUnions{$type})
		{
			$typesize = $gStructUnions{$type}{'size'};
		}
		$membersize = $typesize;
		$membersize *= $rangevalue if defined $rangevalue;
		
		print "$type\t$name";
		print "[$rangevalue]" if defined $rangevalue;
		print ":$bits" if defined $bits;
		printf ";\t// %02X\tsize %03X\n", $offset, $membersize;
      
        # Register data member
        push(@datamembers, $type, $datamember);
		my %member = ();
		$member{'type'} = $type;
		$member{'name'} = $name;
		$member{'range'} = $range if defined $range;
		$member{'rangevalue'} = $rangevalue if defined $rangevalue;
		$member{'bits'} = $bits if defined $bits;
		$member{'bitmask'} = (1 << $countbits) if defined $bits;
		$member{'offset'} = $offset;
		$member{'typesize'} = $typesize;
		$member{'size'} = $membersize;
		push(@memberlist, \%member);
		
		if ($classtype eq "union")
		{
			$classsize = $membersize;
		}
		else
		{
			if (defined $bits)
			{
				$countbits += $bits;
			}
			else
			{
				$offset += $membersize;
			}
		}
    }
	$classsize = $offset if $classtype ne "union";
	printf "SIZE %03X\n", $classsize;
    
#	if ($countbits > 0)
	if (0)
	{
		my $enumname = "e${classname}";
		my @enumerator_names = ();
		my @enumerator_values = ();
		foreach my $member (@memberlist)
		{
			return if not exists $member->{'bitmask'};
			push(@enumerator_names, "${classname}_".$member->{'name'});
			push(@enumerator_values, $member->{'bitmask'});
		}
		$gEnums{$enumname}{'size'} = $classsize;
		$gEnums{$enumname}{'names'} = \@enumerator_names;
		$gEnums{$enumname}{'values'} = \@enumerator_values;
		$gEnums{$enumname}{'bitmask'} = 1;
	}

	$gStructUnions{$classname}{'datamembers'} = \@datamembers;	# old-style
	$gStructUnions{$classname}{'size'} = $classsize;
	$gStructUnions{$classname}{'members'} = \@memberlist;
}
