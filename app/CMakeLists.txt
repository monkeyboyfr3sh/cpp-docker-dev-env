cmake_minimum_required(VERSION 3.5)

project(cv_qt_project LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

if(ANDROID)
  add_library(cv_qt_project SHARED
    main.cpp
    test_widget.cpp
    test_widget.h
  )
else()
  add_executable(cv_qt_project
    main.cpp
    test_widget.cpp
    test_widget.h
  )
endif()

target_link_libraries(cv_qt_project PRIVATE Qt5::Widgets ${OpenCV_LIBS})

# Add compiler options and include directories
target_compile_options(cv_qt_project PUBLIC -std=c++1y -Wall -Wfloat-conversion)
