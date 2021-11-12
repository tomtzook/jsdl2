#include <jni.h>
#include <SDL.h>

#include "event_objects.h"


JNIEXPORT jobject JNICALL Java_sdl2_SDLEvents_waitEventTimeout
        (JNIEnv *env, jclass obj, jint timeout){
    SDL_Event event;
    if (!SDL_WaitEventTimeout(&event, timeout)) {
        return NULL;
    }

    return make_event_object(env, event);
}
