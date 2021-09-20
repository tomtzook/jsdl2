#include <jni.h>
#include <SDL.h>


JNIEXPORT jint JNICALL Java_sdl2_SDL_init
        (JNIEnv *env, jclass obj, jint flags){
    return SDL_Init(flags);
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
