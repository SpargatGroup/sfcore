cmake_minimum_required(VERSION 3.13)
set(DIST "stable")
set(VERSION "0.0.4")
set(NAME "SpargatFramework Noble Repo")
set(OWNER "SpargatGroup")
set(DESCRIPTION "SpargatGroup's Framework Libraries for SpargatCore and SpargatFramework")
set(MAINTAINER "SpargatGroup <comicalusa@gmail.com>")
project(sf
    VERSION ${VERSION}
    DESCRIPTION "${DESCRIPTION}"
    LANGUAGES C
)
#CPack Metadata
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "${DESCRIPTION}")
set(CPACK_PACKAGE_CONTACT "${MAINTAINER}")
set(CPACK_PACKAGE_VENDOR "${OWNER}")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "${CPACK_PACKAGE_CONTACT}")
set(CPACK_DEBIAN_PACKAGE_SECTION "libs")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
set(CPACK_DEBIAN_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
#sources
file(GLOB_RECURSE SF_SOURCES_BASE "src/*.c")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include(cmake/system.cmake)
option(SF_BUILD_SHARED "Build sfcore as a shared library" OFF)
option(SF_BUILD_STATIC "Build sfcore as a static library" ON)
option(SF_BUILD++ "Build sfcore with C++ support" OFF)
option(SF_BUILD_RUST "Build sfcore with Rust support" OFF)
file(GLOB_RECURSE SF_SOURCES++ "src/*.cc")
if(SF_BUILD++)
    list(APPEND SF_SOURCES_BASE ${SF_SOURCES++})
endif()
#shared and static
set(SFCORE_NAME ${PROJECT_NAME}core)
add_library(${PROJECT_NAME} INTERFACE)
if(SF_BUILD_SHARED)
    set(SFCORE_NAME_SHARED ${SFCORE_NAME}_shared)
    add_library(${SFCORE_NAME_SHARED} SHARED ${SF_SOURCES_BASE})
    set_target_properties(${SFCORE_NAME_SHARED} PROPERTIES OUTPUT_NAME ${SFCORE_NAME})
endif()
if(SF_BUILD_STATIC)
    set(SFCORE_NAME_STATIC ${SFCORE_NAME}_static)
    add_library(${SFCORE_NAME_STATIC} STATIC ${SF_SOURCES_BASE})
    set_target_properties(${SFCORE_NAME_STATIC} PROPERTIES OUTPUT_NAME ${SFCORE_NAME})
endif()
if(SF_BUILD++)
    target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_98)
    if(SF_BUILD_SHARED)
        target_compile_features(${SFCORE_NAME_SHARED} PUBLIC cxx_std_98)
    endif()
    if(SF_BUILD_STATIC)
        target_compile_features(${SFCORE_NAME_STATIC} PUBLIC cxx_std_98)
    endif()
endif()
if(SF_BUILD_RUST)
    include(FetchContent)
    FetchContent_Declare(
        Corrosion
        GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
        GIT_TAG v0.5 
    )
    FetchContent_MakeAvailable(Corrosion)
    corrosion_import_crate(MANIFEST_PATH rust/Cargo.toml)
    if(SF_BUILD_SHARED)
        target_link_libraries(${SFCORE_NAME_SHARED} PUBLIC sfrust)
    endif()
    if(SF_BUILD_STATIC)
        target_link_libraries(${SFCORE_NAME_STATIC} PUBLIC sfrust)
    endif()
endif()
#install
install(DIRECTORY include/ DESTINATION usr/include
        FILES_MATCHING PATTERN "*.h")
if(SF_BUILD_STATIC OR SF_BUILD_SHARED)
    if(SF_BUILD_STATIC AND SF_BUILD_SHARED)
        set(SFCORE_INSTALL_LIB ${SFCORE_NAME_STATIC} ${SFCORE_NAME_SHARED})
    elseif(SF_BUILD_STATIC)
        install(TARGETS ${SFCORE_NAME_STATIC}
            ARCHIVE DESTINATION usr/lib
            LIBRARY DESTINATION usr/lib
            RUNTIME DESTINATION usr/bin
        )
        target_link_libraries(${PROJECT_NAME} INTERFACE ${SFCORE_NAME_STATIC})
        target_include_directories(${PROJECT_NAME} INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:usr/include>
        )
        set(SFCORE_INSTALL_LIB ${SFCORE_NAME_STATIC})
    else()
        install(TARGETS ${SFCORE_NAME_SHARED}
            ARCHIVE DESTINATION usr/lib
            LIBRARY DESTINATION usr/lib
            RUNTIME DESTINATION usr/bin
        )
        set(SFCORE_INSTALL_LIB ${SFCORE_NAME_SHARED})
    endif()
endif()
install(TARGETS ${SFCORE_INSTALL_LIB}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
#CPack
if(LINUX)
    include(CPack)
endif()
