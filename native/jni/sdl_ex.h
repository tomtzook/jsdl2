#pragma once

#include <jni.h>
#include <SDL.h>


jobject joystick_type_to_java(JNIEnv* env, SDL_JoystickType type);

SDL_GameControllerAxis gamecontroller_axis_type_from_java(JNIEnv* env, jobject jtype);
SDL_GameControllerButton gamecontroller_button_type_from_java(JNIEnv* env, jobject jtype);
