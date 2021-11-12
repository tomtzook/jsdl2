
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

jfieldID get_static_field(JNIEnv* env, jclass cls, const char* name, const char* signature) {
    jfieldID field = (*env)->GetStaticFieldID(env, cls, name, signature);
    if (NULL == field) {
        throw_field_not_found(env, name, signature);
        return NULL;
    }

    return field;
}

jobject get_static_object_value(JNIEnv* env, jclass cls, jfieldID field) {
    return (*env)->GetStaticObjectField(env, cls, field);
}

jint get_enum_ordinal(JNIEnv* env, jclass cls, jobject enum_constant) {
    jmethodID method = get_method(env, cls, "ordinal", "()I");
    return (*env)->CallIntMethod(env, enum_constant, method);
}
