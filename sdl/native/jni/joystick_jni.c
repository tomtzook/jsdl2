#include <jni.h>
#include <SDL.h>


JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getNumJoysticks
        (JNIEnv *env, jclass obj){
    return SDL_NumJoysticks();
}

JNIEXPORT void JNICALL Java_sdl2_JoystickJni_updateJoysticks
        (JNIEnv *env, jclass obj){
    SDL_JoystickUpdate();
}

JNIEXPORT int JNICALL Java_sdl2_JoystickJni_setEventState
        (JNIEnv *env, jclass obj, jint state){
    return SDL_JoystickEventState(state);
}

JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getDeviceType
        (JNIEnv *env, jclass obj, jint index){
    return SDL_JoystickGetDeviceType(index);
}

JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getDeviceInstanceId
        (JNIEnv *env, jclass obj, jint index){
    return SDL_JoystickGetDeviceInstanceID(index);
}

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

JNIEXPORT jlong JNICALL Java_sdl2_JoystickJni_fromInstanceId
    (JNIEnv *env, jclass obj, jint id){
    SDL_Joystick* joystick = SDL_JoystickFromInstanceID(id);
    return (jlong) joystick;
}

JNIEXPORT jstring JNICALL Java_sdl2_JoystickJni_getName
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    const char* name = SDL_JoystickName(joystick);
    return (*env)->NewStringUTF(env, name);
}

JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getType
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickGetType(joystick);
}

JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getInstanceId
        (JNIEnv *env, jclass obj, jlong ptr){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickInstanceID(joystick);
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

JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getAxis
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickGetAxis(joystick, index);
}

JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getButton
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickGetButton(joystick, index);
}

JNIEXPORT jint JNICALL Java_sdl2_JoystickJni_getHat
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;
    return SDL_JoystickGetHat(joystick, index);
}

JNIEXPORT jlong JNICALL Java_sdl2_JoystickJni_getBall
        (JNIEnv *env, jclass obj, jlong ptr, jint index){
    SDL_Joystick* joystick = (SDL_Joystick*) ptr;

    int dx, dy;
    SDL_JoystickGetBall(joystick, index, &dx, &dy);

    return dx | (dy << 4);
}
