#!/bin/sh

#################################################
#  Auto Project Generation ./autogen.sh         #
#                         by Mutzi              #
#################################################

# Do not change this.
RPATH="-rpath '$"
RPATH+="(libdir)'"
# -------------------

clean_lists()
{
   [ -f source.list ] && rm -rf source.list
   [ -f headers.list ] && rm -rf headers.list  
}

add_source_directory()
{

data=$(find $1 -type f)

for entry in ${data}
do
echo ${entry} >> source.list
done 

}

add_header_directory()
{

data=$(find $1 -type f)
		
for entry in ${data}
do
echo ${entry} >> headers.list
done 

}

touch AUTHORS NEWS README ChangeLog

#project configuration
project_name="OpenPolygon-Component"
project_version="1.0.0"
project_header_installdir="polygon-component"

# --prefix=/usr/
prefix="/usr"

#compiler Options
CFLAGS="-pipe -g -Wall -W -fPIC"
CXXFLAGS="-std=c++11 -Wdeprecated-declarations"
LDFLAGS=" -shared -export-dynamic"

#include path 
CPPFLAGS="../include/"

#project source list 
clean_lists

add_source_directory ./Interface/
add_source_directory ./Manager/
add_source_directory ./Test/

add_header_directory ./include/

HEADERS_LIST=$(cat headers.list)
SOURCE_LIST=$(cat source.list)

LIB_NAME="libpolycomponent"
LIB_EXT_A="a"
LIB_EXT_SO="so"
LIB_EXT_LA="la"

LIB_DEST_A=$LIB_NAME"."$LIB_EXT_A
LIB_DEST_SO=$LIB_NAME"."$LIB_EXT_SO
LIB_DEST_LA=$LIB_NAME"."$LIB_EXT_LA

#if configure.ac found then remove 
[ -f configure.ac ] && rm -rf configure.ac

#create configure.ac
# ----------------------------------------------------------------------
echo "create configure.ac"
echo "AC_PREREQ([2.69])" >> configure.ac

echo "AC_INIT([$LIB_NAME],[$project_version])" >> configure.ac
echo "AC_CONFIG_AUX_DIR([./aux])" >> configure.ac
echo "AC_CONFIG_HEADERS([config.h])" >> configure.ac
echo "AC_CONFIG_MACRO_DIRS([m4])" >> configure.ac
echo "AM_INIT_AUTOMAKE([subdir-objects])" >> configure.ac 
echo "LT_INIT([disable-static])" >> configure.ac

echo "# Checks for programs." >> configure.ac
echo "AC_PROG_CXX" >> configure.ac
echo "AC_PROG_CC" >> configure.ac

echo "# Checks for libraries." >> configure.ac
#INTI_REQUIRED_VERSION=1.0.7
#PKG_CHECK_MODULES(INTI, inti-1.0 >= $INTI_REQUIRED_VERSION)

# Checks for header files 
echo "# Checks for header files." >> configure.ac
echo "AC_PATH_X" >> configure.ac
echo "AC_CHECK_HEADERS([limits.h stdlib.h string.h sys/time.h])" >> configure.ac

# Checks for typedefs, structures, and compiler characteristics
echo "# Checks for typedefs, structures, and compiler characteristics." >> configure.ac
echo "AC_CHECK_HEADER_STDBOOL" >> configure.ac

echo "AC_ENABLE_SHARED" >> configure.ac 
echo "AC_DISABLE_STATIC" >> configure.ac
echo "AC_PROG_LIBTOOL(libtool)" >> configure.ac

# create Makefile
echo "AC_CONFIG_FILES([Makefile])" >> configure.ac
echo "AC_OUTPUT" >> configure.ac 

#if Makefile.am found then remove 
[ -f Makefile.am ] && rm -rf Makefile.am 

# create Makefile.am 
# ----------------------------------------------------------------------
echo "create Makefile.am"

echo "ACLOCAL_AMFLAGS= -I m4" >> Makefile.am
echo "CFLAGS="$CFLAGS >> Makefile.am
echo "CXXFLAGS="$CXXFLAGS >> Makefile.am
echo "LDFLAGS="$RPATH" "$LDFLAGS >> Makefile.am
echo "CPPFLAGS= -I"$CPPFLAGS >> Makefile.am
echo "TARGET_LIB="$LIB_NAME"."$LIB_EXT_SO >> Makefile.am
echo "includedir = ${prefix}/include/"$project_header_installdir >> Makefile.am
echo "include_HEADERS="$HEADERS_LIST >> Makefile.am

echo "lib_LTLIBRARIES="$LIB_DEST_LA >> Makefile.am
echo $LIB_NAME"_"$LIB_EXT_LA"_SOURCES="$SOURCE_LIST >> Makefile.am
echo $LIB_NAME"_"$LIB_EXT_LA"_LDFLAGS= -version-info 1:0:0 " >> Makefile.am

libtoolize --force
aclocal
autoheader
automake --add-missing --copy --force-missing
autoconf

[ ! -d ./build ] && mkdir ./build 
cd build 
../configure --enable-shared --prefix=$prefix

