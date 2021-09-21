#pragma once

#include <jni.h>
#include <SDL.h>


jobject joystick_type_to_java(JNIEnv* env, SDL_JoystickType type);
