#include <jni.h>
#include <SDL.h>


static jobject makeJoyAxisEvent(JNIEnv* env, SDL_JoyAxisEvent event) {
    jclass class = (*env)->FindClass(env, "sdl2/events/JAxisMotionEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(III)V");
    return (*env)->NewObject(env, class, constructor,
                             event.which, event.axis, event.value);
}

static jobject makeJoyButtonEvent(JNIEnv* env, SDL_JoyButtonEvent event) {
    jclass class = (*env)->FindClass(env, "sdl2/events/JButtonChangeEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(IIZ)V");
    return (*env)->NewObject(env, class, constructor,
                             event.which, event.button,
                             event.state == 1);
}

static jobject makeJoyHatMotionEvent(JNIEnv* env, SDL_JoyHatEvent event) {
    jclass class = (*env)->FindClass(env, "sdl2/events/JHatMotionEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(III)V");
    return (*env)->NewObject(env, class, constructor,
                             event.which, event.hat, event.value);
}

static jobject makeJoyBallMotionEvent(JNIEnv* env, SDL_JoyBallEvent event) {
    jclass class = (*env)->FindClass(env, "sdl2/events/JBallMotionEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(IIII)V");
    return (*env)->NewObject(env, class, constructor,
                             event.which, event.ball,
                             event.xrel, event.yrel);
}

static jobject makeJoyConnectionEvent(JNIEnv* env, SDL_JoyDeviceEvent event, int connected) {
    jclass class = (*env)->FindClass(env, "sdl2/events/JDeviceConnectionEvent");
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "(IZ)V");
    return (*env)->NewObject(env, class, constructor,
                             event.which, connected);
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
        default:
            return NULL;
    }
}

JNIEXPORT jobject JNICALL Java_sdl2_SDLEvents_waitEventTimeout
        (JNIEnv *env, jclass obj, jint timeout){
    SDL_Event event;
    if (!SDL_WaitEventTimeout(&event, timeout)) {
        // error
        return NULL;
    }

    return makeEventObject(env, event);
}
