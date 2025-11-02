#!/bin/bash
# parameters and informations
PLATFORM="LINUX"
DIST="stable"
VERSION=0.0.3
NAME="SpargatFramework Noble Repo"
DESCRIPTION="SpargatGroup's Framework Library's for SpargatCore and SpargatFramwork"
MAINTAINER="SpargatGroup <comicalusa@gmail.com>"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$SCRIPT_DIR/../build"
OLD_BUILD_DIR="$SCRIPT_DIR/../build"
# disk
rm -rf $BUILD_DIR
mkdir -p $BUILD_DIR
FS_TYPE=$(df -T "$PWD" | tail -1 | awk '{print $2}')
if [[ "$FS_TYPE" != ext4 && "$FS_TYPE" != xfs && "$FS_TYPE" != btrfs ]]; then
    TEMP_BUILD=$(mktemp -d)
    BUILD_DIR="$TEMP_BUILD"
    mkdir -p "$BUILD_DIR"
fi
for LIBSRC in os; do
    # build lib
    LIBNAME=sf$LIBSRC
    PACKAGE_NAME=lib$LIBNAME
    mkdir -p $BUILD_DIR/core/$PACKAGE_NAME/include
    mkdir -p $BUILD_DIR/core/$PACKAGE_NAME/artefact
    if [[ "$LIBSRC" == "os" ]]; then
        DEPENDS=""
        DEP_NAME=""
    fi
    mkdir -p $BUILD_DIR/noble
    mkdir -p $BUILD_DIR/noble/pool/conf
    mkdir -p $BUILD_DIR/noble/key
    cp spargat.gpg $BUILD_DIR/noble/key/
    cp -r "$LIBSRC/"* "$BUILD_DIR/core/$PACKAGE_NAME/include/"
    cp -r "$LIBSRC/".[!.]* "$BUILD_DIR/core/$PACKAGE_NAME/include/" 2>/dev/null
    find $BUILD_DIR/core/$PACKAGE_NAME/include -name "*.c" -type f -delete
    SRC_FILES=$(find $LIBSRC -name "*.c")
    for ARCH in amd64 i386 arm64 armhf; do
        OVERRIDE_FILE="$BUILD_DIR/noble/pool/conf/override-$ARCH"
        touch $OVERRIDE_FILE
        mkdir -p "$BUILD_DIR/noble/dists/$DIST/main/binary-$ARCH"
        OBJ_FILES=""
        mkdir -p $BUILD_DIR/core/$PACKAGE_NAME/lib/$ARCH
        mkdir -p $BUILD_DIR/core/$PACKAGE_NAME/binary/$ARCH
        if [[ "$ARCH" == "amd64" ]]; then
            BUILD_COMMAND="gcc -m64"
            ARCH2="x86_64"
        elif [[ "$ARCH" == "i386" ]]; then
            BUILD_COMMAND="gcc -m32"
            ARCH2="i386"
        elif [[ "$ARCH" == "arm64" ]]; then
            BUILD_COMMAND="aarch64-linux-gnu-gcc"
            ARCH2="aarch64"
        elif [[ "$ARCH" == "armhf" ]]; then
            BUILD_COMMAND="arm-linux-gnueabihf-gcc"
            ARCH2="arm"
        fi
        for f in $SRC_FILES; do
            OBJ="$BUILD_DIR/core/$PACKAGE_NAME/binary/$ARCH/$(echo $f | tr / _).o"
            $BUILD_COMMAND -Wall -fPIC -I$BUILD_DIR/core/$PACKAGE_NAME/include -c "$f" -o "$OBJ" -DLINUX=1
            OBJ_FILES="$OBJ_FILES $OBJ"
        done
        $BUILD_COMMAND $DEP_NAME -shared -o $BUILD_DIR/core/$PACKAGE_NAME/lib/$ARCH/lib$LIBNAME.so $OBJ_FILES
        # clean h files
        for h in $(find "$BUILD_DIR/core/$PACKAGE_NAME/include" -name "*.h"); do
            tmp="${h}.tmp"
            awk '
                /^[[:space:]]*\/\// { next }
                { print }
            ' "$h" > "$tmp"
            mv "$tmp" "$h"
        done
        # deb package
        DEB_DIR=$BUILD_DIR/core/$PACKAGE_NAME/deb
        mkdir -p "$DEB_DIR/DEBIAN"
        mkdir -p "$DEB_DIR/usr/include"
        mkdir -p "$DEB_DIR/usr/lib"
        cp -r $BUILD_DIR/core/$PACKAGE_NAME/include/* "$DEB_DIR/usr/include/"
        cp $BUILD_DIR/core/$PACKAGE_NAME/lib/$ARCH/lib$LIBNAME.so "$DEB_DIR/usr/lib/"
cat > "$DEB_DIR/DEBIAN/control" <<EOF
Package: $PACKAGE_NAME
Version: $VERSION
Priority: optional
Section: libs
Depends: $DEPENDS
Architecture: $ARCH
Maintainer: $MAINTAINER
Description: $DESCRIPTION
EOF
        dpkg-deb --build $DEB_DIR $BUILD_DIR/core/$PACKAGE_NAME/artefact/${PACKAGE_NAME}_${VERSION}_${ARCH}.deb
        ARCH_POOL="$BUILD_DIR/noble/pool/$ARCH"
        mkdir -p "$ARCH_POOL"
        cp $BUILD_DIR/core/$PACKAGE_NAME/artefact/${PACKAGE_NAME}_${VERSION}_${ARCH}.deb $BUILD_DIR/noble/pool/main/
        cp $BUILD_DIR/core/$PACKAGE_NAME/artefact/${PACKAGE_NAME}_${VERSION}_${ARCH}.deb $ARCH_POOL
        echo "$PACKAGE_NAME optional libs" >> "$OVERRIDE_FILE"
        # pacman package
        PACMAN_DIR=$BUILD_DIR/core/$PACKAGE_NAME/pacman
        mkdir -p $PACMAN_DIR/pkg/$PACKAGE_NAME-$VERSION/usr/include
        mkdir -p $PACMAN_DIR/pkg/$PACKAGE_NAME-$VERSION/usr/lib
        cp -r $BUILD_DIR/core/$PACKAGE_NAME/include/* $PACMAN_DIR/pkg/$PACKAGE_NAME-$VERSION/usr/include/
        cp $BUILD_DIR/core/$PACKAGE_NAME/lib/$ARCH/lib$LIBNAME.so $PACMAN_DIR/pkg/$PACKAGE_NAME-$VERSION/usr/lib/
cat > $PACMAN_DIR/PKGBUILD <<EOF
pkgname=$PACKAGE_NAME
pkgver=$VERSION
pkgrel=1
arch=('$ARCH2')
pkgdesc=$DESCRIPTION
license=('custom')
depends=()
source=()
EOF
        cd $PACMAN_DIR
        makepkg -s
        mkdir -p $BUILD_DIR/noble/$ARCH2
        cp ${PACKAGE_NAME}-$VERSION-1-$ARCH2.pkg.tar.gz $BUILD_DIR/core/$PACKAGE_NAME/artefact/${PACKAGE_NAME}_${VERSION}_${ARCH}.pkg.tar.gz
        cp ${PACKAGE_NAME}-$VERSION-1-$ARCH2.pkg.tar.gz $BUILD_DIR/noble/$ARCH2/
        cd -
    done
done
# create apt + pacman + dnf repo(only apt one works)
cd "$BUILD_DIR/noble"
cat > sframeworknoble.repo <<EOF
[repository]
name=$NAME
baseurl=https://sframeworknoble.vercel.app
gpgcheck=1
repo_gpgcheck=1
gpgkey=https://sframeworknoble.vercel.app/key/spargat.gpg
EOF
cat > apt.conf <<EOF
APT::FTPArchive::Release {
  Origin "$NAME";
  Label "$NAME";
  Suite "stable";
  Codename "stable";
  Architectures "amd64 i386 arm64 armhf";
  Components "main";
  Description "$DESCRIPTION";
};
EOF
for ARCH in amd64 i386 arm64 armhf; do
    OVERRIDE_FILE="$BUILD_DIR/noble/pool/conf/override-$ARCH"
    ARCH_POOL="pool/$ARCH"
    dpkg-scanpackages "$ARCH_POOL" "$OVERRIDE_FILE" | gzip -9c > "dists/$DIST/main/binary-$ARCH/Packages.gz"
    gunzip -k dists/$DIST/main/binary-$ARCH/Packages.gz
    apt-ftparchive -c=apt.conf release dists/$DIST > dists/$DIST/main/binary-$ARCH/Release
    repo-add "$ARCH2/repo.db.tar.gz" "$ARCH2"/*.pkg.tar.gz
done
apt-ftparchive -c=apt.conf release dists/$DIST > dists/$DIST/Release
gpg --clearsign -o dists/$DIST/InRelease dists/$DIST/Release
gpg -abs -o dists/$DIST/Release.gpg dists/$DIST/Release
cd -
# copy build
if [[ -n "$TEMP_BUILD" ]]; then
    cp -r "$BUILD_DIR/"* "$OLD_BUILD_DIR"
    rm -rf "$TEMP_BUILD"
fi