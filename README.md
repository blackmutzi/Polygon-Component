# Polygon-Component
Component Architecture - Linux - Library - Polygon 

### build & install 

```sh
# Download Polygon-Component
git clone https://github.com/blackmutzi/Polygon-Component/
cd ./Polygon-Component

# Makefile Generation
./autogen.sh

# Build & Install
cd ./build
make && make install

# default lib directory: /usr/lib/libpolycomponent.so
# default include directory : /usr/include/polygon-component/
```
### include it in your Project

LIBS += lpolycomponent

```sh
  #include "arch.h"
```

### other library dependencies

* nothing

