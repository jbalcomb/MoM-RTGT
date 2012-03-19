#!/bin/sh -e

# SCRIPT PARAMETERS
PLATFORM=Linux
VERSION=0.2.1

# CONFIG
[ -z "$QTDIR" ] && QTDIR="/usr/local/Trolltech/Qt-4.8.0"
GIT_REPOS="ssh://ilikeserena@git.code.sf.net/p/momrtgt/code"
CHECKOUTDIR="$PWD"
RELEASEDIR="$PWD/releases"

# FUNCTIONS
BUILD=
CHECKOUT=
GENERATE=
HELP=1
TEST=
RELEASE=

usage() {
    echo "USAGE:"
    echo ""
    echo "\$ $0 [-bcghtR] [-q <qtdir>] [-r <git-repository-URL>] [-v <version>]"
    echo "-a           Do everything for a regular release"
    echo "             Equivalent to -bcgRt"
    echo "-b           Compile all sources"
    echo "-c           Checkout from repository"
    echo "-g           Generate source. Necessary for a new build"
    echo "-q <qtdir>   Specify the location of Qt root directory"
    echo "             Default is '$QTDIR'"
    echo "-r <git-repository-URL>  Specify the location of the GIT repository"
    echo "             Default is '$GIT_REPOS'"
    echo "             Implies that the sources must be checked out"
    echo "-R           Copy to release directory and compress"
    echo "-t           Run tests to verify the build"
    echo "-v <version> Specify the version to build"
    echo "             Default is '$VERSION'"
    echo ""
    echo "EXAMPLE:"
    echo ""
    echo "\$ $0 -bcgR -q /opt/Qt-4.8.0"
    echo "This will build everything and copy it to '$RELEASEDIR'"
    echo "where the applications will be compressed as well, ready for upload."
    echo ""
    exit 2
}

while getopts abcghq:r:Rtv: name
do
    case $name in
    a)  BUILD=1 ; CHECKOUT=1 ; GENERATE=1 ; RELEASE=1 ; TEST=1 ; HELP= ;;
    b)  BUILD=1 ; HELP= ;;
    c)  CHECKOUT=1 ; HELP= ;;
    g)  GENERATE=1 ; HELP= ;;
    h)  usage ; exit 2 ;;
    q)  QTDIR="$OPTARG" ; HELP= ;;
    r)  GIT_REPOS="$OPTARG" ; CHECKOUT=1 ; HELP= ;;
    R)  RELEASE=1 ; HELP= ;;
    t)  TEST=1 ; HELP= ;;
    v)  VERSION="$OPTARG" ; HELP= ;;
    ?)  usage ; exit 2 ;;
    esac
done
shift $(($OPTIND - 1))

echo "PLATFORM=$PLATFORM"
echo "VERSION=$VERSION"
echo "QTDIR=$QTDIR"
echo "GIT_REPOS=$GIT_REPOS"
echo "CHECKOUTDIR=$CHECKOUTDIR"
echo "RELEASEDIR=$RELEASEDIR"
echo ""

if [ -n "$HELP" ]; then
    usage
    exit 2
fi

# CHECK OUT / UPDATE from repository
if [ -n "$CHECKOUT" ]; then
    echo "-------------------------"
    echo "CHECKOUT:"
    if [ -d trunk/ ]; then
        echo "Pull sources to trunk/"
        cd trunk && git pull
    else
        echo "Clone sources to trunk/ from '$GIT_REPOS'"
        git clone "$GIT_REPOS" trunk/
    fi
fi


# BUILD ALL

if [ -n "$GENERATE" ]; then
    echo "-------------------------"
    echo "GENERATE:"
    cd "$CHECKOUTDIR/trunk/MoMEditorTemplate"
    perl generate_code.pl
fi

if [ -n "$BUILD" ]; then
    echo "-------------------------"
    echo "BUILD: MoMCustomizer"
    cd "$CHECKOUTDIR/trunk/MoMCustomizer"
    "$QTDIR/bin/qmake"
    make

    echo "-------------------------"
    echo "BUILD: MoMCustomizer"
    cd "$CHECKOUTDIR/trunk/MoMTweaker"
    "$QTDIR/bin/qmake"
    make
fi

# TEST
if [ -n "$TEST" ]; then
    echo "-------------------------"
    echo "EXECUTING TESTS:"
    cd "$CHECKOUTDIR/trunk/MoMTest"
    "$QTDIR/bin/qmake"
    make
    bin/MoMTest
fi

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
    cp "$CHECKOUTDIR/trunk/MoMCustomizer/bin/MoMCustomizer" "$RELEASEDIR/MoMCustomizer-$VERSION-$PLATFORM/MoMCustomizer-$VERSION"
    cp "$CHECKOUTDIR/trunk/MoMCustomizer"/*.txt "$RELEASEDIR/MoMCustomizer-$VERSION-$PLATFORM/"

    echo "Copy MoMCustomizer to '$RELEASEDIR/MoMTweaker-$VERSION-$PLATFORM/'"
    mkdir "$RELEASEDIR/MoMTweaker-$VERSION-$PLATFORM/"
    cp "$RELEASEDIR/MoMTweaker-TEMPLATE-$PLATFORM"/* "$RELEASEDIR/MoMTweaker-$VERSION-$PLATFORM/"
    cp "$CHECKOUTDIR/trunk/MoMTweaker/bin/MoMTweaker" "$RELEASEDIR/MoMTweaker-$VERSION-$PLATFORM/MoMTweaker-$VERSION"
    cp "$CHECKOUTDIR/trunk/MoMTweaker"/*.txt "$RELEASEDIR/MoMTweaker-$VERSION-$PLATFORM/"

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

