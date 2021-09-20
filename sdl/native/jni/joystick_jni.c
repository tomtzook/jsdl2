#include <jni.h>
#include <SDL.h>


JNIEXPORT jlong JNICALL Java_sdl2_JoystickJni_open
        (JNIEnv *env, jclass obj, jint index){
    SDL_Joystick* joystick = SDL_JoystickOpen(index);
    return (jlong) joystick;
}

JNIEXPORT void JNICALL Java_sdl2_JoystickJni_close
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    SDL_JoystickClose(joystick);
}

JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getNumAxes
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickNumAxes(joystick);
}

JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getNumButtons
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickNumButtons(joystick);
}

JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getNumHats
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickNumHats(joystick);
}

JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getNumBalls
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickNumBalls(joystick);
}
