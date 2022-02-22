#include <jni.h>
#include <SDL.h>

#include "jni_except.h"
#include "sdl_ex.h"
#include "jni_objects.h"


static jobject get_java_power_state(JNIEnv* env, SDL_PowerState state) {
    jclass class = get_class(env, "sdl2/PowerState");
    if (NULL == class) {
        return NULL;
    }

    jfieldID field;
    switch (state) {
        case SDL_POWERSTATE_ON_BATTERY:
            field = get_static_field(env, class, "ON_BATTERY", "Lsdl2/PowerState;");
            break;
        case SDL_POWERSTATE_NO_BATTERY:
            field = get_static_field(env, class, "NO_BATTERY", "Lsdl2/PowerState;");
            break;
        case SDL_POWERSTATE_CHARGING:
            field = get_static_field(env, class, "CHARGING", "Lsdl2/PowerState;");
            break;
        case SDL_POWERSTATE_CHARGED:
            field = get_static_field(env, class, "CHARGED", "Lsdl2/PowerState;");
            break;
        default:
            field = get_static_field(env, class, "UNKNOWN", "Lsdl2/PowerState;");
            break;
    }

    return get_static_object_value(env, class, field);
}

static jobject make_power_info(JNIEnv* env, SDL_PowerState state, int seconds, int percentage) {
    jclass class = get_class(env, "sdl2/PowerInfo");
    if (NULL == class) {
        return NULL;
    }
    jmethodID constructor = get_constructor(env, class, "(Lsdl2/PowerState;II)V");
    if (NULL == constructor) {
        return NULL;
    }

    jobject jstate = get_java_power_state(env, state);
    return (*env)->NewObject(env, class, constructor,
                             jstate, seconds, percentage);
}

JNIEXPORT jobject JNICALL Java_sdl2_SDLPower_getPowerInfo
        (JNIEnv *env, jclass obj){
    int seconds;
    int percentage;
    SDL_PowerState state = SDL_GetPowerInfo(&seconds, &percentage);

    return make_power_info(env, state, seconds, percentage);
}
