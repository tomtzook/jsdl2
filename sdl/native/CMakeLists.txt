cmake_minimum_required(VERSION 3.16)
project(flashlib_hid_sdl_native C)

set(CMAKE_C_STANDARD 11)

find_package(JNI REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(${JNI_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})

add_library(sdl_jni SHARED jni/sdl_jni.c jni/gamecontroller_jni.c jni/joystick_jni.c jni/events_jni.c)
target_link_libraries(sdl_jni ${SDL2_LIBRARIES})
