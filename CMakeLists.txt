cmake_minimum_required(VERSION 2.8)
project(SCS-Lib)

set(CMAKE_C_STANDARD 99)

macro(get_WIN32_WINNT version)
    if (WIN32 AND CMAKE_SYSTEM_VERSION)
        set(ver ${CMAKE_SYSTEM_VERSION})
        string(REPLACE "." "" ver ${ver})
        string(REGEX REPLACE "([0-9])" "0\\1" ver ${ver})

        set(${version} "0x${ver}")
    endif()
endmacro()


get_WIN32_WINNT(ver)
add_definitions(-D_WIN32_WINNT=${ver})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s -O3")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -static")
if(WIN32)
    link_libraries(ws2_32 wsock32)
else()
    link_libraries(socket nsl)
endif()

set(SOURCE_FILES_CLIENT clientTCP.c fonctionsTCP.c fonctionsTCP.h)
set(SOURCE_FILES_SERVEUR serveurTCP.c fonctionsTCP.c fonctionsTCP.h)

add_executable(clientTCP clientTCP.c lib/fonctionsTCP.c lib/fonctionsTCP.h)

add_executable(serveurTCP serveurTCP.c lib/fonctionsTCP.c lib/fonctionsTCP.h)
