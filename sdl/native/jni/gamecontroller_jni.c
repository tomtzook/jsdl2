#include <jni.h>
#include <SDL.h>


JNIEXPORT jlong JNICALL Java_sdl2_GameControllerJni_open
        (JNIEnv *env, jclass obj, jint index){
    SDL_GameController* controller = SDL_GameControllerOpen(index);
    return (jlong) controller;
}

JNIEXPORT void JNICALL Java_sdl2_GameControllerJni_close
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_GameController* controller = (SDL_GameController*) ptr;
    SDL_GameControllerClose(controller);
}
