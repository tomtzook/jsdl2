
#include "event_objects.h"

#include "jni_except.h"
#include "jni_objects.h"


jobject make_joy_axis_event(JNIEnv* env, SDL_JoyAxisEvent event) {
    jclass class = get_class(env, "sdl2/events/JAxisMotionEvent");
    if (NULL == class) {
        return NULL;
    }
    jmethodID constructor = get_constructor(env, class, "(III)V");
    if (NULL == constructor) {
        return NULL;
    }

    return (*env)->NewObject(env, class, constructor,
                             event.which, event.axis, event.value);
}

jobject make_joy_button_event(JNIEnv* env, SDL_JoyButtonEvent event) {
    jclass class = get_class(env, "sdl2/events/JButtonChangeEvent");
    if (NULL == class) {
        return NULL;
    }
    jmethodID constructor = get_constructor(env, class, "(IIZ)V");
    if (NULL == constructor) {
        return NULL;
    }

    return (*env)->NewObject(env, class, constructor,
                             event.which, event.button,
                             event.state == SDL_PRESSED);
}

jobject make_joy_hat_motion_event(JNIEnv* env, SDL_JoyHatEvent event) {
    jclass class = get_class(env, "sdl2/events/JHatMotionEvent");
    if (NULL == class) {
        return NULL;
    }
    jmethodID constructor = get_constructor(env, class, "(III)V");
    if (NULL == constructor) {
        return NULL;
    }

    return (*env)->NewObject(env, class, constructor,
                             event.which, event.hat, event.value);
}

jobject make_joy_ball_motion_event(JNIEnv* env, SDL_JoyBallEvent event) {
    jclass class = get_class(env, "sdl2/events/JBallMotionEvent");
    if (NULL == class) {
        return NULL;
    }
    jmethodID constructor = get_constructor(env, class, "(IIII)V");
    if (NULL == constructor) {
        return NULL;
    }

    return (*env)->NewObject(env, class, constructor,
                             event.which, event.ball,
                             event.xrel, event.yrel);
}

jobject make_joy_connection_event(JNIEnv* env, SDL_JoyDeviceEvent event, int connected) {
    jclass class = get_class(env, "sdl2/events/JDeviceConnectionEvent");
    if (NULL == class) {
        return NULL;
    }
    jmethodID constructor = get_constructor(env, class, "(IZ)V");
    if (NULL == constructor) {
        return NULL;
    }

    return (*env)->NewObject(env, class, constructor,
                             event.which, connected);
}

jobject make_controller_axis_event(JNIEnv* env, SDL_ControllerAxisEvent event) {
    jclass class = get_class(env, "sdl2/events/CAxisMotionEvent");
    if (NULL == class) {
        return NULL;
    }
    jmethodID constructor = get_constructor(env, class, "(III)V");
    if (NULL == constructor) {
        return NULL;
    }

    return (*env)->NewObject(env, class, constructor,
                             event.which, event.axis, event.value);
}

jobject make_controller_button_event(JNIEnv* env, SDL_ControllerButtonEvent event) {
    jclass class = get_class(env, "sdl2/events/CButtonChangeEvent");
    if (NULL == class) {
        return NULL;
    }
    jmethodID constructor = get_constructor(env, class, "(IIZ)V");
    if (NULL == constructor) {
        return NULL;
    }

    return (*env)->NewObject(env, class, constructor,
                             event.which, event.button,
                             event.state == SDL_PRESSED);
}

jobject make_controller_connection_event(JNIEnv* env, SDL_ControllerDeviceEvent event, int connected) {
    jclass class = get_class(env, "sdl2/events/CDeviceConnectionEvent");
    if (NULL == class) {
        return NULL;
    }
    jmethodID constructor = get_constructor(env, class, "(IZ)V");
    if (NULL == constructor) {
        return NULL;
    }

    return (*env)->NewObject(env, class, constructor,
                             event.which, connected);
}

jobject make_event_object(JNIEnv* env, SDL_Event event) {
    switch (event.type) {
        case SDL_JOYAXISMOTION:
            return make_joy_axis_event(env, event.jaxis);
        case SDL_JOYBUTTONDOWN:
        case SDL_JOYBUTTONUP:
            return make_joy_button_event(env, event.jbutton);
        case SDL_JOYHATMOTION:
            return make_joy_hat_motion_event(env, event.jhat);
        case SDL_JOYBALLMOTION:
            return make_joy_ball_motion_event(env, event.jball);
        case SDL_JOYDEVICEADDED:
            return make_joy_connection_event(env, event.jdevice, 1);
        case SDL_JOYDEVICEREMOVED:
            return make_joy_connection_event(env, event.jdevice, 0);
        case SDL_CONTROLLERAXISMOTION:
            return make_controller_axis_event(env, event.caxis);
        case SDL_CONTROLLERBUTTONDOWN:
        case SDL_CONTROLLERBUTTONUP:
            return make_controller_button_event(env, event.cbutton);
        case SDL_CONTROLLERDEVICEADDED:
            return make_controller_connection_event(env, event.cdevice, 1);
        case SDL_CONTROLLERDEVICEREMOVED:
            return make_controller_connection_event(env, event.cdevice, 0);
        default:
            return NULL;
    }
}
