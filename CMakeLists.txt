cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0011 NEW)
project(Dauphine)

# Project directories
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BIN_DIR ${ROOT_DIR}/bin)
set(BUILD_DIR ${ROOT_DIR}/build)
set(LIB_DIR ${ROOT_DIR}/lib)
set(LIB_SRC_DIR ${LIB_DIR}/src)
set(PATCHES_DIR ${LIB_DIR}/patches)

# System directories
set(SYSTEM_DIR ${ROOT_DIR}/${SYSTEM})
set(SYSTEM_LIB_DIR ${LIB_DIR}/${SYSTEM})
set(SYSTEM_BIN_DIR ${BIN_DIR}/${SYSTEM})
set(SYSTEM_BIN_LIB_DIR ${SYSTEM_BIN_DIR}/lib)
set(SYSTEM_BUILD_DIR ${BUILD_DIR}/${SYSTEM})
set(SYSTEM_BUILD_LIB_SRC_DIR ${SYSTEM_BUILD_DIR}/lib/src)

# External projects
include(ExternalProject)

## SDL
set(SDL_PREFIX ${SYSTEM_LIB_DIR}/SDL2)
set(SDL_INCLUDE_DIR ${SDL_PREFIX}/include/SDL2)

ExternalProject_Add(
    SDL
    PREFIX lib
    URL ${LIB_SRC_DIR}/SDL2-2.0.5.tar.gz
    CMAKE_COMMAND cmake -DCMAKE_INSTALL_PREFIX=${SYSTEM_LIB_DIR}/SDL2
)

## SDL_image
ExternalProject_Add(
    SDL_image
    PREFIX lib
    URL ${LIB_SRC_DIR}/SDL2_image-2.0.1.tar.gz
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${SDL_PREFIX} --with-sdl-prefix=${SDL_PREFIX}
    BUILD_COMMAND $(MAKE)
    INSTALL_COMMAND $(MAKE) install
)


## SDL_ttf
ExternalProject_Add(
    SDL_ttf
    PREFIX lib
    URL ${LIB_SRC_DIR}/SDL2_ttf-2.0.14.tar.gz
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${SDL_PREFIX} --with-sdl-prefix=${SDL_PREFIX}
    BUILD_COMMAND $(MAKE)
    INSTALL_COMMAND $(MAKE) install
)

## SDL_mixer
ExternalProject_Add(
    SDL_mixer
    PREFIX lib
    URL ${LIB_SRC_DIR}/SDL2_mixer-2.0.1.tar.gz
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${SDL_PREFIX} --with-sdl-prefix=${SDL_PREFIX}
    BUILD_COMMAND $(MAKE)
    INSTALL_COMMAND $(MAKE) install
)

## SDL_gfx
ExternalProject_Add(
    SDL_gfx
    PREFIX lib
    URL ${LIB_SRC_DIR}/SDL2_gfx-1.0.3.tar.gz
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${SDL_PREFIX} --with-sdl-prefix=${SDL_PREFIX}
    BUILD_COMMAND $(MAKE)
    INSTALL_COMMAND $(MAKE) install
)

## libtermcap
set(TERMCAP_PREFIX ${SYSTEM_LIB_DIR}/termcap)


ExternalProject_Add(
    termcap
    PREFIX lib
    URL ${LIB_SRC_DIR}/termcap-1.3.1.tar.gz
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${TERMCAP_PREFIX}
    BUILD_COMMAND $(MAKE)
    INSTALL_COMMAND $(MAKE) install
)

## libreadline
ExternalProject_Add(
    readline
    PREFIX lib
    DEPENDS termcap
    URL ${LIB_SRC_DIR}/readline-7.0.tar.gz
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${SYSTEM_LIB_DIR}/readline CFLAGS=-I${TERMCAP_PREFIX}/include LDFLAGS=-L${TERMCAP_PREFIX}/lib --enable-shared
    BUILD_COMMAND $(MAKE) LDFLAGS=${SYSTEM_LIB_DIR}/termcap/lib LIBS=libtermcap.a
    INSTALL_COMMAND $(MAKE) install
)

## Lua
ExternalProject_Add(
    lua
    PREFIX lib
    DEPENDS readline
    URL ${LIB_SRC_DIR}/lua-5.3.4.tar.gz
    URL_HASH MD5=53a9c68bcc0eda58bdc2095ad5cdfc63
    CONFIGURE_COMMAND ""
    BUILD_COMMAND cd <SOURCE_DIR> && $(MAKE) CPPFLAGS=-I${SYSTEM_LIB_DIR}/readline/include
    # LDFLAGS="-L/${SYSTEM_LIB_DIR}/readline/lib -L/${SYSTEM_LIB_DIR}/termcap/lib" LIBS="-lreadline -ltermcap -ldl -lm" ${SYSTEM}
    INSTALL_COMMAND cd <SOURCE_DIR> && $(MAKE) install INSTALL_TOP=${SYSTEM_LIB_DIR}/lua
)


# Subdirs
subdirs(lib src)

### Packing
##set(CPACK_PACKAGE_NAME "jtj")
##set(CPACK_PACKAGE_VERSION_MAJOR "1")
##set(CPACK_PACKAGE_VERSION_MINOR "0")
##set(CPACK_PACKAGE_VERSION_PATCH "1")
##set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "A puzzle/platform game developed by FGA students Athos Ribeiro, Alexandre Barbosa and Matheus Furquim in 2013")
##set(CPACK_DEBIAN_PACKAGE_MAINTAINER "LVDJ - Laboratório Virtual de Desenvolvimento de Jogos")
##set(CPACK_PACKAGE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")

##set(CPACK_PACKAGING_INSTALL_PREFIX "/usr/games")
##set(CPACK_GENERATOR "DEB")

##include(CPack)


###if(${CMAKE_SYSTEM_NAME} MATCHES windows)
###
###    ExternalProject_Add(
###        zlib
###        PREFIX libs
###        URL ${LIBS_DIR_SRC}/zlib-1.2.11.tar.gz
###        URL_HASH SHA256=c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1
###        PATCH_COMMAND ${CMAKE_COMMAND} -E copy ${PATCHES_DIR}/zlib/Makefile.gcc ${SYSTEM_TMP_LIBS_SRC_DIR}/zlib/win32/Makefile.gcc
###        CONFIGURE_COMMAND ""
###        BUILD_IN_SOURCE ${SYSTEM_TMP_LIBS_SRC_DIR}/zlib
###        BUILD_COMMAND BINARY_PATH=${MINGW_BIN_DIR} INCLUDE_PATH=${MINGW_INCLUDE_DIR} LIBRARY_PATH=${MINGW_LIB_DIR} make -f win32/Makefile.gcc
###        INSTALL_COMMAND DESTDIR=${SYSTEM_LIBS_DIR} BINARY_PATH=/zlib-1.2/bin INCLUDE_PATH=/zlib-1.2/include LIBRARY_PATH=/zlib-1.2/lib make -f win32/Makefile.gcc install SHARED_MODE=1
###    )
###
###    ExternalProject_Add(
###        libpng
###        PREFIX libs
###        DEPENDS zlib
###        URL ${LIBS_DIR_SRC}/libpng-1.6.28.tar.gz
###        URL_HASH MD5=897ccec1ebfb0922e83c2bfaa1be8748
###        CONFIGURE_COMMAND LDFLAGS=${LIBPNG_LDFLAGS} <SOURCE_DIR>/configure --prefix=${SYSTEM_LIBS_DIR}/libpng-1.6 ${LIBPNG_CONFIGURE_OPTIONS}
###        BUILD_COMMAND make CFLAGS=${LIBPNG_CPPFLAGS} LDFLAGS=${LIBPNG_LDFLAGS}
###        INSTALL_COMMAND make install
###    )
###
###endif(${CMAKE_SYSTEM_NAME} MATCHES windows)


