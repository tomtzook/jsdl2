#include <SDL.h>

#include "jni_objects.h"
#include "jni_except.h"


void throw_out_of_memory(JNIEnv* env, const char* message) {
    jclass cls = (*env)->FindClass(env, "java/lang/OutOfMemoryError");
    if (NULL == cls) {
        (*env)->FatalError(env, "java/lang/OutOfMemoryError not found");
        return;
    }

    (*env)->ThrowNew(env, cls, message);
    // TODO: returns an error
}

void throw_unsupported(JNIEnv* env, const char* message) {
    jclass cls = (*env)->FindClass(env, "java/lang/UnsupportedOperationException");
    if (NULL == cls) {
        (*env)->FatalError(env, "java/lang/UnsupportedOperationException not found");
        return;
    }

    (*env)->ThrowNew(env, cls, message);
    // TODO: returns an error
}

void throw_class_not_found(JNIEnv* env, const char* className) {
    jclass cls = (*env)->FindClass(env, "java/lang/NoClassDefFoundError");
    if (NULL == cls) {
        (*env)->FatalError(env, "java/lang/NoClassDefFoundError not found");
        return;
    }

    (*env)->ThrowNew(env, cls, className);
    // TODO: returns an error
}

void throw_method_not_found(JNIEnv* env, const char* methodName, const char* signature) {
    jclass cls = get_class(env, "java/lang/NoSuchMethodError");
    if (NULL == cls) {
        return;
    }

    size_t messageSize = strlen(methodName) + strlen(signature) + 1;
    char* messageBuffer = (char*) malloc(messageSize);
    if (NULL == messageBuffer) {
        throw_out_of_memory(env, "throw_method_not_found");
        return;
    }

    sprintf(messageBuffer, "%s.%s", methodName, signature);

    (*env)->ThrowNew(env, cls, messageBuffer);
    free(messageBuffer);
}

void throw_sdl_exception(JNIEnv* env) {
    jclass cls = get_class(env, "sdl2/SDLException");
    if (NULL == cls) {
        return;
    }

    const char* message = SDL_GetError();
    (*env)->ThrowNew(env, cls, message);
}
