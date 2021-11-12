#include <jni.h>
#include <SDL.h>

#include "jni_except.h"
#include "sdl_ex.h"


JNIEXPORT void JNICALL Java_sdl2_SDLGameController_updateGameControllers
        (JNIEnv *env, jclass obj){
    SDL_GameControllerUpdate();
}

JNIEXPORT void JNICALL Java_sdl2_SDLGameController_setEventPolling
        (JNIEnv *env, jclass obj, jboolean enabled){
    if (SDL_GameControllerEventState(enabled ? SDL_ENABLE : SDL_DISABLE) < 0) {
        THROW_SDL_ERROR(env);
    }
}

JNIEXPORT jboolean JNICALL Java_sdl2_SDLGameController_isEventPolling
        (JNIEnv *env, jclass obj){
    int result = SDL_GameControllerEventState(SDL_QUERY);
    if (result < 0) {
        THROW_SDL_ERROR2(env, 0);
    }

    return result == SDL_ENABLE;
}

JNIEXPORT jboolean JNICALL Java_sdl2_SDLGameController_isGameController
        (JNIEnv *env, jclass obj, jint index){
    return SDL_IsGameController(index);
}

JNIEXPORT jlong JNICALL Java_sdl2_SDLGameController_open
        (JNIEnv *env, jclass obj, jint device){
    SDL_GameController* controller = SDL_GameControllerOpen(device);
    if (NULL == controller) {
        THROW_SDL_ERROR2(env, 0);
    }

    return (jlong) controller;
}

JNIEXPORT void JNICALL Java_sdl2_SDLGameController_close
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_GameController* controller = (SDL_GameController*) ptr;
    SDL_GameControllerClose(controller);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLGameController_getAxis
        (JNIEnv *env, jclass obj, jlong ptr, jobject axis_type){
    SDL_GameController* controller = (SDL_GameController*) ptr;
    SDL_GameControllerAxis axis = gamecontroller_axis_type_from_java(env, axis_type);
    if (SDL_CONTROLLER_AXIS_INVALID == axis) {
        return 0;
    }

    return SDL_GameControllerGetAxis(controller, axis);
}

JNIEXPORT jboolean JNICALL Java_sdl2_SDLGameController_getButton
        (JNIEnv *env, jclass obj, jlong ptr, jobject button_type){
    SDL_GameController* controller = (SDL_GameController*) ptr;
    SDL_GameControllerButton button = gamecontroller_button_type_from_java(env, button_type);
    if (SDL_CONTROLLER_BUTTON_INVALID == button) {
        return 0;
    }

    int result = SDL_GameControllerGetButton(controller, button);
    return result == 1;
}
