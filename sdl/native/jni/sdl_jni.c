#include <jni.h>
#include <SDL.h>


JNIEXPORT jint JNICALL Java_sdl2_SdlJni_init
        (JNIEnv *env, jclass obj, jint flags){
    return SDL_Init(flags);
}

JNIEXPORT void JNICALL Java_sdl2_SdlJni_quit
        (JNIEnv *env, jclass obj){
    SDL_Quit();
}

JNIEXPORT jstring JNICALL Java_sdl2_SdlJni_getError
        (JNIEnv *env, jclass obj){
    const char* error = SDL_GetError();
    return (*env)->NewStringUTF(env, error);
}
