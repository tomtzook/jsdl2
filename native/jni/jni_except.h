#pragma once

#include <jni.h>

#define THROW_SDL_ERROR(env) \
    throw_sdl_exception(env);\
    return

#define THROW_SDL_ERROR2(env, ret) \
    throw_sdl_exception(env);\
    return ret


void throw_out_of_memory(JNIEnv *env, const char* message);

void throw_unsupported(JNIEnv *env, const char* message);

void throw_class_not_found(JNIEnv* env, const char* className);

void throw_method_not_found(JNIEnv* env, const char* methodName, const char* signature);

void throw_sdl_exception(JNIEnv* env);
