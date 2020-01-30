# project
cmake_minimum_required(VERSION 3.13.0)

# target
add_library(sthash SHARED "")
set_target_properties(sthash PROPERTIES OUTPUT_NAME "sthash")
set_target_properties(sthash PROPERTIES LIBRARY_OUTPUT_DIRECTORY "build/linux/x86_64/release")
set_property(TARGET sthash PROPERTY C_STANDARD 99)
if(MSVC)
    target_compile_options(sthash PRIVATE $<$<COMPILE_LANGUAGE:C>:-TP>)
    target_compile_options(sthash PRIVATE $<$<CONFIG:Release>:-Ox -fp:fast>)
    target_compile_options(sthash PUBLIC "/source-charset: utf-8")
    target_link_options(sthash PRIVATE "/DEF: DEF")
else()
    target_compile_options(sthash PRIVATE $<$<COMPILE_LANGUAGE:C>:-fPIC> $<$<COMPILE_LANGUAGE:CXX>:-fPIC>)
    target_compile_options(sthash PRIVATE -O3)
endif()
target_link_libraries(sthash PRIVATE
    mbedtls
    mbedcrypto
)
target_sources(sthash PRIVATE
    src/sthash.c
)

