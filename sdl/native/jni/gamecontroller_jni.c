#include <jni.h>
#include <SDL.h>


JNIEXPORT void JNICALL Java_sdl2_GameControllerJni_updateControllers
        (JNIEnv *env, jclass obj){
    SDL_GameControllerUpdate();
}

JNIEXPORT int JNICALL Java_sdl2_GameControllerJni_setEventState
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

JNIEXPORT jlong JNICALL Java_sdl2_GameControllerJni_fromInstanceId
        (JNIEnv *env, jclass obj, jint id){
    SDL_GameController* controller = SDL_GameControllerFromInstanceID(id);
    return (jlong) controller;
}

JNIEXPORT jlong JNICALL Java_sdl2_GameControllerJni_getJoystick
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_GameController* controller = (SDL_GameController*) ptr;
    SDL_Joystick* joystick = SDL_GameControllerGetJoystick(controller);
    return (jlong) joystick;
}

JNIEXPORT jstring JNICALL Java_sdl2_GameControllerJni_getName
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_GameController* controller = (SDL_GameController*) ptr;
    const char* name = SDL_GameControllerName(controller);
    return (*env)->NewStringUTF(env, name);
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
