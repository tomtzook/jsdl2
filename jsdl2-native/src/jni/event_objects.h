#pragma once

#include <jni.h>
#include <SDL.h>


jobject make_joy_axis_event(JNIEnv* env, SDL_JoyAxisEvent event);
jobject make_joy_button_event(JNIEnv* env, SDL_JoyButtonEvent event);
jobject make_joy_hat_motion_event(JNIEnv* env, SDL_JoyHatEvent event);
jobject make_joy_ball_motion_event(JNIEnv* env, SDL_JoyBallEvent event);
jobject make_joy_connection_event(JNIEnv* env, SDL_JoyDeviceEvent event, int connected);

jobject make_controller_axis_event(JNIEnv* env, SDL_ControllerAxisEvent event);
jobject make_controller_button_event(JNIEnv* env, SDL_ControllerButtonEvent event);
jobject make_controller_connection_event(JNIEnv* env, SDL_ControllerDeviceEvent event, int connected);

jobject make_event_object(JNIEnv* env, SDL_Event event);
