#include <jni.h>
#include <SDL.h>

#include "jni_except.h"
#include "sdl_ex.h"


JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getNumJoysticks
        (JNIEnv *env, jclass obj){
    int result = SDL_NumJoysticks();
    if (result < 0) {
        THROW_SDL_ERROR2(env, 0);
    }

    return result;
}

JNIEXPORT void JNICALL Java_sdl2_SDLJoystick_updateJoysticks
        (JNIEnv *env, jclass obj){
    SDL_JoystickUpdate();
}

JNIEXPORT void JNICALL Java_sdl2_SDLJoystick_setEventPolling
        (JNIEnv *env, jclass obj, jboolean enabled){
    if (SDL_JoystickEventState(enabled ? SDL_ENABLE : SDL_DISABLE) < 0) {
        THROW_SDL_ERROR(env);
    }
}

JNIEXPORT jboolean JNICALL Java_sdl2_SDLJoystick_isEventPolling
        (JNIEnv *env, jclass obj){
    int result = SDL_JoystickEventState(SDL_QUERY);
    if (result < 0) {
        THROW_SDL_ERROR2(env, 0);
    }

    return result == SDL_ENABLE;
}

JNIEXPORT jobject JNICALL Java_sdl2_SDLJoystick_getDeviceType
        (JNIEnv *env, jclass obj, jint device){
    SDL_JoystickType type = SDL_JoystickGetDeviceType(device);
    return joystick_type_to_java(env, type);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getDeviceInstanceId
        (JNIEnv *env, jclass obj, jint device){
    int result = SDL_JoystickGetDeviceInstanceID(device);
    if (result < 0) {
        THROW_SDL_ERROR2(env, 0);
    }

    return result;
}

JNIEXPORT jlong JNICALL Java_sdl2_SDLJoystick_open
        (JNIEnv *env, jclass obj, jint device){
    SDL_Joystick* joystick = SDL_JoystickOpen(device);
    if (NULL == joystick) {
        THROW_SDL_ERROR2(env, 0);
    }

    return (jlong) joystick;
}

JNIEXPORT void JNICALL Java_sdl2_SDLJoystick_close
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    SDL_JoystickClose(joystick);
}

JNIEXPORT jlong JNICALL Java_sdl2_SDLJoystick_fromInstanceId
    (JNIEnv *env, jclass obj, jint id){
    SDL_Joystick* joystick = SDL_JoystickFromInstanceID(id);
    if (NULL == joystick) {
        THROW_SDL_ERROR2(env, 0);
    }

    return (jlong) joystick;
}

JNIEXPORT jstring JNICALL Java_sdl2_SDLJoystick_getName
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    const char* name = SDL_JoystickName(joystick);
    if (NULL == name) {
        THROW_SDL_ERROR2(env, NULL);
    }

    return (*env)->NewStringUTF(env, name);
}

JNIEXPORT jobject JNICALL Java_sdl2_SDLJoystick_getType
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    SDL_JoystickType type = SDL_JoystickGetType(joystick);
    return joystick_type_to_java(env, type);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getInstanceId
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    SDL_JoystickID result = SDL_JoystickInstanceID(joystick);
    if (result < 0) {
        THROW_SDL_ERROR2(env, 0);
    }

    return result;
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getNumAxes
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    int result = SDL_JoystickNumAxes(joystick);
    if (result < 0) {
        THROW_SDL_ERROR2(env, 0);
    }

    return result;
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getNumButtons
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    int result = SDL_JoystickNumButtons(joystick);
    if (result < 0) {
        THROW_SDL_ERROR2(env, 0);
    }

    return result;
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getNumHats
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    int result = SDL_JoystickNumHats(joystick);
    if (result < 0) {
        THROW_SDL_ERROR2(env, 0);
    }

    return result;
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getNumBalls
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    int result = SDL_JoystickNumBalls(joystick);
    if (result < 0) {
        THROW_SDL_ERROR2(env, 0);
    }

    return result;
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getAxis
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickGetAxis(joystick, index);
}

JNIEXPORT jboolean JNICALL Java_sdl2_SDLJoystick_getButton
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    int result = SDL_JoystickGetButton(joystick, index);
    return result == 1;
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getHat
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickGetHat(joystick, index);
}

JNIEXPORT jlong JNICALL Java_sdl2_SDLJoystick_getBall
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;

    int dx, dy;
    SDL_JoystickGetBall(joystick, index, &dx, &dy);
    // how to indicate error?

    return dx | (dy << 4);
}
