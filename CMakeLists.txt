cmake_minimum_required(VERSION 3.13)
project(sflog C)
set(SFLOG_SOURCES
    sfstr/sfstr.c
    sfmem/sfmem.c
    sflog/sflog.c
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
if(UNIX)
    if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        add_definitions(-DLINUX)
    elseif(APPLE)
        if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
            add_definitions(-DOSX)
        elseif(CMAKE_SYSTEM_NAME STREQUAL "iOS")
            add_definitions(-DIOS)
        endif()
    else()
        add_definitions(-DANDROID)
    endif()
elseif(AMUI) # for this to work, you need amui in the same folder as core and you need to add -DCMAKE_TOOLCHAIN_FILE=/../amui/cmake/amui.cmake when configuring
    #add_definitions(-DAMUI) # not needed
elseif(WIN32)
    add_definitions(-DWINDOWS)
else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()
option(SFLOG_BUILD_SHARED "Build sflog as a shared library" ON)
option(SFLOG_BUILD_STATIC "Build sflog as a static library" ON)
# shared
if(SFLOG_BUILD_SHARED)
    set(SHARED_NAME ${PROJECT_NAME}_shared)
    add_library(${SHARED_NAME} SHARED ${SFLOG_SOURCES})
    set_target_properties(${SHARED_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
endif()
# static
if(SFLOG_BUILD_STATIC)
    set(STATIC_NAME ${PROJECT_NAME}_static)
    add_library(${STATIC_NAME} STATIC ${SFLOG_SOURCES})
    set_target_properties(${STATIC_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
endif()
install(TARGETS sflog_shared sflog_static
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)