#!/bin/sh -e

# CONFIG
PLATFORM=Linux
VERSION=
[ -z "$QTDIR" ] && QTDIR="/usr/local/Trolltech/Qt-4.8.0"
GIT_REPOS="ssh://ilikeserena@git.code.sf.net/p/momrtgt/code"
CHECKOUTDIR="$PWD/checkout"
RELEASEDIR="$PWD/releases"
MAKE_ALL="make all"

# FUNCTIONS
BUILD=
CHECKOUT=
FETCH=
GENERATE=
TEST=
RELEASE=

usage() {
    echo "USAGE:"
    echo ""
    echo "\$ $0 [-bcfghrt] [-p <platform>] [-q <qtdir>] [-R <URL>] <version>"
    echo "-a           Do everything for a regular release"
    echo "             Equivalent to -bcfgrt"
    echo "-b           Compile all sources"
    echo "-c           Checkout to <version>"
    echo "-f           Fetch <version> from remote repository"
    echo "             Implies -c that the sources must be checked out to <version>"
    echo "-g           Generate source. Necessary for a new build"
    echo "-p <platform> Build for the platform 'Linux' or 'Windows'"
    echo "             Default is '$PLATFORM'"
    echo "-q <qtdir>   Specify the location of Qt root directory"
    echo "             Default is '$QTDIR'"
    echo "-R <URL>     Specify the location of the GIT repository"
    echo "             Default is '$GIT_REPOS'"
    echo "             Implies -f that the sources must be fetched"
    echo "-r           Copy to release directory and compress"
    echo "-t           Run tests to verify the build"
    echo "<version>    Specify the version to build"
    echo "             This should be the name of a branch in the repository"
    echo ""
    echo "EXAMPLE:"
    echo ""
    echo "\$ $0 -a 0.2.1"
    echo "This will check out branch 0.2.1 from the GIT repository to '$CHECKOUTDIR',"
    echo "build everything and copy it to '$RELEASEDIR'"
    echo "where the applications will be compressed as well, ready for upload."
    echo ""
    exit 2
}

while getopts abcfghp:q:R:rt name
do
    case $name in
    a)  BUILD=1 ; FETCH=1 ; CHECKOUT=1 ; GENERATE=1 ; RELEASE=1 ; TEST=1 ;;
    b)  BUILD=1 ;;
    c)  CHECKOUT=1 ;;
    f)  FETCH=1 ; CHECKOUT=1 ;;
    g)  GENERATE=1 ;;
    h)  usage ; exit 2 ;;
    p)  PLATFORM="$OPTARG" ;;
    q)  QTDIR="$OPTARG" ;;
    R)  GIT_REPOS="$OPTARG" ; FETCH=1 ; CHECKOUT=1 ;;
    r)  RELEASE=1 ;;
    t)  TEST=1 ;;
    ?)  usage ; exit 2 ;;
    esac
done
shift $(($OPTIND - 1))
VERSION="$1"

# MAKE PLATFORM SPECIFIC CHOICES
case $PLATFORM in
    Linux)   MAKE_ALL="make -j4" ;;
    Windows) MAKE_ALL="nmake -f Makefile.Release" ;;
    *)       usage ; exit 2 ;;
esac

echo "CHECKOUTDIR=$CHECKOUTDIR"
echo "GIT_REPOS=$GIT_REPOS"
echo "MAKE_ALL=$MAKE_ALL"
echo "PLATFORM=$PLATFORM"
echo "QTDIR=$QTDIR"
echo "RELEASEDIR=$RELEASEDIR"
echo "VERSION=$VERSION"
echo ""

if [ -z "$VERSION" ]; then
    usage
    exit 2
fi

# FETCH from repository
if [ -n "$FETCH" ]; then
    echo "-------------------------"
    echo "CHECKOUT:"
    echo "Initialize git repository in '$CHECKOUTDIR'"
    mkdir -p "$CHECKOUTDIR"
    cd "$CHECKOUTDIR"
    git init

    echo "Fetch branch '$VERSION' to '$CHECKOUTDIR' from '$GIT_REPOS'"
    cd "$CHECKOUTDIR"
    git fetch "$GIT_REPOS" $VERSION
fi

# CHECK OUT to <version>
if [ -n "$CHECKOUT" ]; then
    echo "Check out '$VERSION' in '$CHECKOUTDIR'"
    cd "$CHECKOUTDIR"
    git checkout $VERSION
fi


# GENERATE
if [ -n "$GENERATE" ]; then
    echo "-------------------------"
    echo "GENERATE:"
    cd "$CHECKOUTDIR/MoMEditorTemplate"
    perl generate_code.pl
fi

# BUILD ALL
if [ -n "$BUILD" ]; then
    echo "-------------------------"
    echo "BUILD: MoMCustomizer"
    cd "$CHECKOUTDIR/MoMCustomizer"
    "$QTDIR/bin/qmake"
    $MAKE_ALL 

    echo "-------------------------"
    echo "BUILD: MoMCustomizer"
    cd "$CHECKOUTDIR/MoMTweaker"
    "$QTDIR/bin/qmake"
    $MAKE_ALL 
fi

# TEST
if [ -n "$TEST" ]; then
    echo "-------------------------"
    echo "EXECUTING TESTS:"
    cd "$CHECKOUTDIR/MoMTest"
    "$QTDIR/bin/qmake"
    $MAKE_ALL
    bin/MoMTest
fi

# MAKE RELEASE FOR UPLOAD
if [ -n "$RELEASE" ]; then
    # COPY TO RELEASE DIRECTORIES
    echo "-------------------------"
    echo "COPY TO RELEASE DIRECTORIES:"
    echo "Remove old release directories if any"
    rm -rf "$RELEASEDIR/MoMCustomizer-$VERSION-$PLATFORM/" || true
    rm -rf "$RELEASEDIR/MoMTweaker-$VERSION-$PLATFORM/" || true

    echo "Copy MoMCustomizer to '$RELEASEDIR/MoMCustomizer-$VERSION-$PLATFORM/'"
    mkdir "$RELEASEDIR/MoMCustomizer-$VERSION-$PLATFORM/"
    cp "$RELEASEDIR/MoMCustomizer-TEMPLATE-$PLATFORM"/* "$RELEASEDIR/MoMCustomizer-$VERSION-$PLATFORM/"
    cp "$CHECKOUTDIR/MoMCustomizer/bin/MoMCustomizer" "$RELEASEDIR/MoMCustomizer-$VERSION-$PLATFORM/MoMCustomizer-$VERSION"
    cp "$CHECKOUTDIR/MoMCustomizer"/*.txt "$RELEASEDIR/MoMCustomizer-$VERSION-$PLATFORM/"

    echo "Copy MoMCustomizer to '$RELEASEDIR/MoMTweaker-$VERSION-$PLATFORM/'"
    mkdir "$RELEASEDIR/MoMTweaker-$VERSION-$PLATFORM/"
    cp "$RELEASEDIR/MoMTweaker-TEMPLATE-$PLATFORM"/* "$RELEASEDIR/MoMTweaker-$VERSION-$PLATFORM/"
    cp "$CHECKOUTDIR/MoMTweaker/bin/MoMTweaker" "$RELEASEDIR/MoMTweaker-$VERSION-$PLATFORM/MoMTweaker-$VERSION"
    cp "$CHECKOUTDIR/MoMTweaker"/*.txt "$RELEASEDIR/MoMTweaker-$VERSION-$PLATFORM/"

    # COMPRESS
    echo "-------------------------"
    echo "COMPRESS:"
    cd "$RELEASEDIR"
    echo "Remove old compressed files if any"
    rm "MoMCustomizer-$VERSION-$PLATFORM.tar.gz" || true
    rm "MoMTweaker-$VERSION-$PLATFORM.tar.gz" || true
    echo "Compress files"
    tar czf "MoMCustomizer-$VERSION-$PLATFORM.tar.gz" "MoMCustomizer-$VERSION-$PLATFORM/"
    tar czf "MoMTweaker-$VERSION-$PLATFORM.tar.gz" "MoMTweaker-$VERSION-$PLATFORM/"

    echo ""
    echo "<<< Did your remember to update the CHANGES.txt files? >>>"
    echo ""
fi

echo "Done!"

