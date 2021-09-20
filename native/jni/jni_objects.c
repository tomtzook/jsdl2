
#include "jni_except.h"
#include "jni_objects.h"


jclass get_class(JNIEnv* env, const char* name) {
    jclass cls = (*env)->FindClass(env, name);
    if (NULL == cls) {
        throw_class_not_found(env, name);
        return NULL;
    }

    return cls;
}

jmethodID get_method(JNIEnv* env, jclass cls, const char* name, const char* signature) {
    jmethodID method = (*env)->GetMethodID(env, cls, name, signature);
    if (NULL == method) {
        throw_method_not_found(env, name, signature);
        return NULL;
    }

    return method;
}

jmethodID get_constructor(JNIEnv* env, jclass cls, const char* signature) {
    return get_method(env, cls, "<init>", signature);
}
