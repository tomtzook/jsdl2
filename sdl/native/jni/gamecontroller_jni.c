#include <jni.h>
#include <SDL.h>


JNIEXPORT void JNICALL Java_sdl2_JoystickJni_updateControllers
        (JNIEnv *env, jclass obj){
    SDL_GameControllerUpdate();
}

JNIEXPORT int JNICALL Java_sdl2_JoystickJni_setEventState
        (JNIEnv *env, jclass obj, jint state){
    return SDL_GameControllerEventState(state);
}

JNIEXPORT jint JNICALL Java_sdl2_GameControllerJni_isGameController
        (JNIEnv *env, jclass obj, jint index){
    return SDL_IsGameController(index);
}

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

JNIEXPORT jint JNICALL Java_sdl2_GameControllerJni_getAxis
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_GameController* controller = (SDL_GameController*) ptr;
    return SDL_GameControllerGetAxis(controller, index);
}

JNIEXPORT jint JNICALL Java_sdl2_GameControllerJni_getButton
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_GameController* controller = (SDL_GameController*) ptr;
    return SDL_GameControllerGetButton(controller, index);
}
