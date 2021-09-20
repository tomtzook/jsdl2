#include <jni.h>
#include <SDL.h>


static jobject makeJoyAxisEvent(JNIEnv* env, SDL_JoyAxisEvent event) {
    jclass class = (*env)->FindClass(env, "sdl2/events/AxisMotionEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(IIII)V");
    return (*env)->NewObject(env, class, constructor,
                             event.type, event.which, event.axis, event.value);
}

static jobject makeJoyButtonEvent(JNIEnv* env, SDL_JoyButtonEvent event) {
    jclass class = (*env)->FindClass(env, "sdl2/events/ButtonChangeEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(IIII)V");
    return (*env)->NewObject(env, class, constructor,
                             event.type, event.which, event.button, event.state);
}

static jobject makeJoyHatMotionEvent(JNIEnv* env, SDL_JoyHatEvent event) {
    jclass class = (*env)->FindClass(env, "sdl2/events/HatMotionEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(IIII)V");
    return (*env)->NewObject(env, class, constructor,
                             event.type, event.which, event.hat, event.value);
}

static jobject makeJoyBallMotionEvent(JNIEnv* env, SDL_JoyBallEvent event) {
    jclass class = (*env)->FindClass(env, "sdl2/events/BallMotionEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(IIIII)V");
    return (*env)->NewObject(env, class, constructor,
                             event.type, event.which, event.ball,
                             event.xrel, event.yrel);
}

static jobject makeJoyConnectionEvent(JNIEnv* env, SDL_JoyDeviceEvent event, int connected) {
    jclass class = (*env)->FindClass(env, "sdl2/events/DeviceConnectionEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(IIZ)V");
    return (*env)->NewObject(env, class, constructor,
                             event.type, event.which, connected);
}

static jobject makeControllerAxisEvent(JNIEnv* env, SDL_ControllerAxisEvent event) {
    jclass class = (*env)->FindClass(env, "sdl2/events/AxisMotionEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(IIII)V");
    return (*env)->NewObject(env, class, constructor,
                             event.type, event.which, event.axis, event.value);
}

static jobject makeControllerButtonEvent(JNIEnv* env, SDL_ControllerButtonEvent event) {
    jclass class = (*env)->FindClass(env, "sdl2/events/ButtonChangeEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(IIII)V");
    return (*env)->NewObject(env, class, constructor,
                             event.type, event.which, event.button, event.state);
}

static jobject makeControllerConnectionEvent(JNIEnv* env, SDL_ControllerDeviceEvent event, int connected) {
    jclass class = (*env)->FindClass(env, "sdl2/events/DeviceConnectionEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(IIZ)V");
    return (*env)->NewObject(env, class, constructor,
                             event.type, event.which, connected);
}

static jobject makeEventObject(JNIEnv* env, SDL_Event event) {
    switch (event.type) {
        case SDL_JOYAXISMOTION:
            return makeJoyAxisEvent(env, event.jaxis);
        case SDL_JOYBUTTONDOWN:
        case SDL_JOYBUTTONUP:
            return makeJoyButtonEvent(env, event.jbutton);
        case SDL_JOYHATMOTION:
            return makeJoyHatMotionEvent(env, event.jhat);
        case SDL_JOYBALLMOTION:
            return makeJoyBallMotionEvent(env, event.jball);
        case SDL_JOYDEVICEADDED:
            return makeJoyConnectionEvent(env, event.jdevice, 1);
        case SDL_JOYDEVICEREMOVED:
            return makeJoyConnectionEvent(env, event.jdevice, 0);
        case SDL_CONTROLLERAXISMOTION:
            return makeControllerAxisEvent(env, event.caxis);
        case SDL_CONTROLLERBUTTONDOWN:
        case SDL_CONTROLLERBUTTONUP:
            return makeControllerButtonEvent(env, event.cbutton);
        case SDL_CONTROLLERDEVICEADDED:
            return makeControllerConnectionEvent(env, event.cdevice, 1);
        case SDL_CONTROLLERDEVICEREMOVED:
            return makeControllerConnectionEvent(env, event.cdevice, 0);
        default:
            return NULL;
    }
}

JNIEXPORT jobject JNICALL Java_sdl2_EventsJni_waitEventTimeout
        (JNIEnv *env, jclass obj, jint timeout){
    SDL_Event event;
    if (!SDL_WaitEventTimeout(&event, timeout)) {
        // error
        return NULL;
    }

    return makeEventObject(env, event);
}
