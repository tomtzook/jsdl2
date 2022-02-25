
#include "jni_objects.h"
#include "jni_except.h"
#include "sdl_ex.h"


jobject joystick_type_to_java(JNIEnv* env, SDL_JoystickType type) {
    jclass cls = get_class(env, "sdl2/JoystickType");
    if (NULL == cls) {
        return NULL;
    }

    jfieldID field;
    switch (type) {
        case SDL_JOYSTICK_TYPE_UNKNOWN:
            field = get_static_field(env, cls, "UNKNOWN", "Lsdl2/JoystickType;");
            break;
        case SDL_JOYSTICK_TYPE_GAMECONTROLLER:
            field = get_static_field(env, cls, "GAME_CONTROLLER", "Lsdl2/JoystickType;");
            break;
        case SDL_JOYSTICK_TYPE_WHEEL:
            field = get_static_field(env, cls, "WHEEL", "Lsdl2/JoystickType;");
            break;
        case SDL_JOYSTICK_TYPE_ARCADE_STICK:
            field = get_static_field(env, cls, "ARCADE_STICK", "Lsdl2/JoystickType;");
            break;
        case SDL_JOYSTICK_TYPE_FLIGHT_STICK:
            field = get_static_field(env, cls, "FLIGHT_STICK", "Lsdl2/JoystickType;");
            break;
        case SDL_JOYSTICK_TYPE_DANCE_PAD:
            field = get_static_field(env, cls, "DANCE_PAD", "Lsdl2/JoystickType;");
            break;
        case SDL_JOYSTICK_TYPE_GUITAR:
            field = get_static_field(env, cls, "GUITAR", "Lsdl2/JoystickType;");
            break;
        case SDL_JOYSTICK_TYPE_DRUM_KIT:
            field = get_static_field(env, cls, "DRUM_KIT", "Lsdl2/JoystickType;");
            break;
        case SDL_JOYSTICK_TYPE_ARCADE_PAD:
            field = get_static_field(env, cls, "ARCADE_PAD", "Lsdl2/JoystickType;");
            break;
        case SDL_JOYSTICK_TYPE_THROTTLE:
            field = get_static_field(env, cls, "THROTTLE", "Lsdl2/JoystickType;");
            break;
        default:
            field = NULL;
            throw_unsupported(env, "joystick_type_to_java: unknown type");
            break;
    }

    if (NULL == field) {
        return NULL;
    }

    return get_static_object_value(env, cls, field);
}

SDL_GameControllerAxis gamecontroller_axis_type_from_java(JNIEnv* env, jobject jtype) {
    jclass cls = get_class(env, "sdl2/SDLGameController$AxisType");
    if (NULL == cls) {
        return SDL_CONTROLLER_AXIS_INVALID;
    }

    jint ordinal = get_enum_ordinal(env, cls, jtype);
    if (ordinal < 0 || ordinal >= SDL_CONTROLLER_AXIS_MAX) {
        return SDL_CONTROLLER_AXIS_INVALID;
    }

    return (SDL_GameControllerAxis) ordinal;
}

SDL_GameControllerButton gamecontroller_button_type_from_java(JNIEnv* env, jobject jtype) {
    jclass cls = get_class(env, "sdl2/SDLGameController$ButtonType");
    if (NULL == cls) {
        return SDL_CONTROLLER_BUTTON_INVALID;
    }

    jint ordinal = get_enum_ordinal(env, cls, jtype);
    if (ordinal < 0 || ordinal >= SDL_CONTROLLER_AXIS_MAX) {
        return SDL_CONTROLLER_BUTTON_INVALID;
    }

    return (SDL_GameControllerButton) ordinal;
}
