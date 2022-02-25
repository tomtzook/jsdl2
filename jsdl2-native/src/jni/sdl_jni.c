#include <jni.h>
#include <SDL.h>

#include "jni_except.h"


JNIEXPORT void JNICALL Java_sdl2_SDL_init
        (JNIEnv *env, jclass obj, jint flags){
    if (SDL_Init(flags) < 0) {
        THROW_SDL_ERROR(env);
    }
}

JNIEXPORT void JNICALL Java_sdl2_SDL_quit
        (JNIEnv *env, jclass obj){
    SDL_Quit();
}

JNIEXPORT jstring JNICALL Java_sdl2_SDL_getError
        (JNIEnv *env, jclass obj){
    const char* error = SDL_GetError();
    return (*env)->NewStringUTF(env, error);
}
