cmake_minimum_required(VERSION 3.13)
set(DIST "stable")
set(VERSION "0.0.3")
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
#arch package
add_custom_target(
    build_arch_pkg
    COMMAND mkdir -p ${CMAKE_BINARY_DIR}/pacman/pkg/${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}/usr/include
    COMMAND cp -r ${CMAKE_SOURCE_DIR}/include/* ${CMAKE_BINARY_DIR}/pacman/pkg/${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}/usr/include/
    COMMAND cp ${CMAKE_BINARY_DIR}/lib/libsf*.so ${CMAKE_BINARY_DIR}/pacman/pkg/${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}/usr/lib/
    COMMAND cd ${CMAKE_BINARY_DIR}/pacman && makepkg -s
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
#sources
set(SF_SOURCES_BASE
    sfstr/sfstr.c
    sfmem/sfmem.c
)
set(SF_SOURCES_LOG
    ${SF_SOURCES_BASE}
    sflog/sflog.c
)
set(SF_SOURCES_RCODE
    ${SF_SOURCES_BASE}
    rcode/rdecrypt.c
    rcode/rencrypt.c
)
set(SF_SOURCES_MATH
    ${SF_SOURCES_BASE}
    sfmath/sfmath.c
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
include(cmake/system.cmake)
option(SFALL_BUILD_SHARED "Build sfall as a shared library" ON)
option(SFALL_BUILD_STATIC "Build sfall as a static library" ON)
option(SFLOG_BUILD_SHARED "Build sflog as a shared library" OFF)
option(SFLOG_BUILD_STATIC "Build sflog as a static library" OFF)
option(SFR_BUILD_SHARED "Build sflog as a shared library" OFF)
option(SFR_BUILD_STATIC "Build sflog as a static library" OFF)
option(SFMATH_BUILD_SHARED "Build sfmath as a shared library" OFF)
option(SFMATH_BUILD_STATIC "Build sfmath as a static library" OFF)
if(SFALL_BUILD_STATIC)
    set(SFLOG_BUILD_STATIC ON CACHE BOOL "Force static build" FORCE)
    set(SFR_BUILD_STATIC ON CACHE BOOL "Force static build" FORCE)
    set(SFMATH_BUILD_STATIC ON CACHE BOOL "Force static build" FORCE)
endif()
if(SFALL_BUILD_SHARED)
    set(SFLOG_BUILD_SHARED ON CACHE BOOL "Force shared build" FORCE)
    set(SFR_BUILD_SHARED ON CACHE BOOL "Force shared build" FORCE)
    set(SFMATH_BUILD_SHARED ON CACHE BOOL "Force shared build" FORCE)
endif()
#shared and static
set(NAME_LOG ${PROJECT_NAME}log)
if(SFLOG_BUILD_SHARED)
    set(SHARED_NAME_LOG ${PROJECT_NAME}log_shared)
    add_library(${SHARED_NAME_LOG} SHARED ${SF_SOURCES_LOG})
    set_target_properties(${SHARED_NAME_LOG} PROPERTIES OUTPUT_NAME ${NAME_LOG})
endif()
if(SFLOG_BUILD_STATIC)
    set(STATIC_NAME_LOG ${PROJECT_NAME}log_static)
    add_library(${STATIC_NAME_LOG} STATIC ${SF_SOURCES_LOG})
    set_target_properties(${STATIC_NAME_LOG} PROPERTIES OUTPUT_NAME ${NAME_LOG})
endif()
#shared and static
set(NAME_R ${PROJECT_NAME}r)
if(SFR_BUILD_SHARED)
    set(SHARED_NAME_R ${PROJECT_NAME}r_shared)
    add_library(${SHARED_NAME_R} SHARED ${SF_SOURCES_RCODE})
    set_target_properties(${SHARED_NAME_R} PROPERTIES OUTPUT_NAME ${NAME_R})
endif()
if(SFR_BUILD_STATIC)
    set(STATIC_NAME_R ${PROJECT_NAME}r_static)
    add_library(${STATIC_NAME_R} STATIC ${SF_SOURCES_RCODE})
    set_target_properties(${STATIC_NAME_R} PROPERTIES OUTPUT_NAME ${NAME_R})
endif()
#shared and static
set(NAME_MATH ${PROJECT_NAME}math)
if(SFMATH_BUILD_SHARED)
    set(SHARED_NAME_MATH ${PROJECT_NAME}math_shared)
    add_library(${SHARED_NAME_MATH} SHARED ${SF_SOURCES_MATH})
    set_target_properties(${SHARED_NAME_MATH} PROPERTIES OUTPUT_NAME ${NAME_MATH})
endif()
if(SFMATH_BUILD_STATIC)
    set(STATIC_NAME_MATH ${PROJECT_NAME}math_static)
    add_library(${STATIC_NAME_MATH} STATIC ${SF_SOURCES_MATH})
    set_target_properties(${STATIC_NAME_MATH} PROPERTIES OUTPUT_NAME ${NAME_MATH})
endif()
#install
install(DIRECTORY sfdef/ DESTINATION usr/include/sfdef
        FILES_MATCHING PATTERN "*.h")
install(DIRECTORY sfmem/ DESTINATION usr/include/sfmem
        FILES_MATCHING PATTERN "*.h")
install(DIRECTORY sfstr/ DESTINATION usr/include/sfstr
        FILES_MATCHING PATTERN "*.h")
if(SFALL_BUILD_SHARED OR SFALL_BUILD_STATIC)
    install(FILES sfcore.h DESTINATION usr/include)
endif()
if(SFLOG_BUILD_SHARED OR SFLOG_BUILD_STATIC)
    install(DIRECTORY sflog/ DESTINATION usr/include/sflog
        FILES_MATCHING PATTERN "*.h")
    if(SFLOG_BUILD_STATIC)
        install(TARGETS ${STATIC_NAME_LOG}
            ARCHIVE DESTINATION usr/lib
            LIBRARY DESTINATION usr/lib
            RUNTIME DESTINATION usr/bin
        )
    else()
        install(TARGETS ${SHARED_NAME_LOG}
            ARCHIVE DESTINATION usr/lib
            LIBRARY DESTINATION usr/lib
            RUNTIME DESTINATION usr/bin
        )
    endif()
endif()
if(SFR_BUILD_SHARED OR SFR_BUILD_STATIC)
    install(DIRECTORY rcode/ DESTINATION usr/include/rcode
        FILES_MATCHING PATTERN "*.h")
    if(SFR_BUILD_STATIC)
        install(TARGETS ${STATIC_NAME_R}
            ARCHIVE DESTINATION usr/lib
            LIBRARY DESTINATION usr/lib
            RUNTIME DESTINATION usr/bin
        )
    else()
        install(TARGETS ${SHARED_NAME_R}
            ARCHIVE DESTINATION usr/lib
            LIBRARY DESTINATION usr/lib
            RUNTIME DESTINATION usr/bin
        )
    endif()
endif()
if(SFMATH_BUILD_SHARED OR SFMATH_BUILD_STATIC)
    install(DIRECTORY sfmath/ DESTINATION usr/include/sfmath
        FILES_MATCHING PATTERN "*.h")
    if(SFMATH_BUILD_STATIC)
        install(TARGETS ${STATIC_NAME_MATH}
            ARCHIVE DESTINATION usr/lib
            LIBRARY DESTINATION usr/lib
            RUNTIME DESTINATION usr/bin
        )
    else()
        install(TARGETS ${SHARED_NAME_MATH}
            ARCHIVE DESTINATION usr/lib
            LIBRARY DESTINATION usr/lib
            RUNTIME DESTINATION usr/bin
        )
    endif()
endif()
install(TARGETS sflog_shared sflog_static sfmath_shared sfmath_static
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
#AMUI
if(AMUI)
    set(PUBLIC_INCLUDE_DIR "${CMAKE_BINARY_DIR}/include")
    file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
    foreach(HEADER ${HEADERS})
        file(RELATIVE_PATH REL_PATH "${CMAKE_CURRENT_SOURCE_DIR}" "${HEADER}")
        set(DEST_PATH "${PUBLIC_INCLUDE_DIR}/${REL_PATH}")
        configure_file(${HEADER} "${DEST_PATH}" COPYONLY)
    endforeach()
endif()
#CPack
if(LINUX)
    include(CPack)
endif()