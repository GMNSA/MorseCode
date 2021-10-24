cmake_minimum_required(VERSION 3.14)

project(DBManager LANGUAGES CXX)
set(OUT_NAME dbManager)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-g3 -Wall -Wextra -Werror")


set(HEADERS
    includes/connectmanager.hpp
    includes/executor.hpp
    includes/dbtype.hpp
    includes/selector.hpp
    includes/processor.hpp
    )

set(SOURCES
    srcs/connectmanager.cpp
    srcs/executor.cpp
    srcs/selector.cpp
    srcs/processor.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../rcc/application.qrc
    )



add_library(${OUT_NAME} SHARED ${SOURCES} ${HEADERS})

find_package(Qt5 COMPONENTS Core Sql REQUIRED)


set_target_properties(${OUT_NAME}
        PROPERTIES
        CMAKE_CXX_STANDARD 20
        CMAKE_CXX_STANDARD_REQUIRED ON
        )


target_include_directories(${OUT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/includes
        ${CMAKE_CURRENT_BINARY_DIR}
        )


target_link_libraries(${OUT_NAME}
        PUBLIC
        Qt5::Core
        Qt5::Sql
        )


