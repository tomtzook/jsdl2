#include <jni.h>
#include <SDL.h>


JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getNumJoysticks
        (JNIEnv *env, jclass obj){
    return SDL_NumJoysticks();
}

JNIEXPORT void JNICALL Java_sdl2_SDLJoystick_updateJoysticks
        (JNIEnv *env, jclass obj){
    SDL_JoystickUpdate();
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_setEventPolling
        (JNIEnv *env, jclass obj, jboolean enabled){
    int result = SDL_JoystickEventState(enabled ? SDL_ENABLE : SDL_DISABLE);
    if (result < 0) {
        return result;
    }

    return 0;
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_isEventPolling
        (JNIEnv *env, jclass obj){
    return SDL_JoystickEventState(SDL_QUERY);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getDeviceType
        (JNIEnv *env, jclass obj, jint device){
    return SDL_JoystickGetDeviceType(device);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getDeviceInstanceId
        (JNIEnv *env, jclass obj, jint device){
    return SDL_JoystickGetDeviceInstanceID(device);
}

JNIEXPORT jlong JNICALL Java_sdl2_SDLJoystick_open
        (JNIEnv *env, jclass obj, jint device){
    SDL_Joystick* joystick = SDL_JoystickOpen(device);
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
    return (jlong) joystick;
}

JNIEXPORT jstring JNICALL Java_sdl2_SDLJoystick_getName
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    const char* name = SDL_JoystickName(joystick);
    if (NULL == name) {
        return NULL;
    }

    return (*env)->NewStringUTF(env, name);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getType
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickGetType(joystick);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getInstanceId
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickInstanceID(joystick);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getNumAxes
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickNumAxes(joystick);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getNumButtons
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickNumButtons(joystick);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getNumHats
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickNumHats(joystick);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getNumBalls
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickNumBalls(joystick);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getAxis
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickGetAxis(joystick, index);
}

JNIEXPORT jint JNICALL Java_sdl2_SDLJoystick_getButton
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickGetButton(joystick, index);
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
