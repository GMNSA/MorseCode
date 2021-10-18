cmake_minimum_required(VERSION 3.14)

project(MorseCode LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/examples)

set(QML_IMPORT_PATH ${CMAKE_CURRENT_LIST_DIR}/qml
    CACHE STRING "Qt Creator 5.15 extra qml import paths"
    FORCE)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package(...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick LinguistTools REQUIRED)
find_package(morseCodeLib)

set(TS_FILES MorseCode_ru_RU.ts)

set(PROJECT_HEADERS
        includes/morsecode.hpp
        includes/internationmorse.hpp
        ${QML_IMPORT_PATH}
    )

set(PROJECT_SOURCES
        srcs/main.cpp
        srcs/morsecode.cpp
        ${CMAKE_CURRENT_LIST_DIR}/rcc/qml.qrc
        ${CMAKE_CURRENT_LIST_DIR}/rcc/application.qrc
        ${CMAKE_CURRENT_LIST_DIR}/rcc/qtquickcontrols2.conf
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MorseCode
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
    )
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(MorseCode SHARED
            ${PROJECT_SOURCES}
            ${PROJECT_HEADERS}
        )
    else()
        add_executable(MorseCode
          ${PROJECT_SOURCES}
          ${PROJECT_HEADERS}
        )
endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_include_directories(MorseCode
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/includes
    ${CMAKE_CURRENT_LIST_DIR}/qml
    )

add_subdirectory(tests)
add_subdirectory(lib)

target_compile_definitions(MorseCode
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(MorseCode
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick morseCodeLib)
