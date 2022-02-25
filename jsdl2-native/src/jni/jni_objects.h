#pragma once

#include <jni.h>


jclass get_class(JNIEnv* env, const char* name);

jmethodID get_method(JNIEnv* env, jclass cls, const char* name, const char* signature);

jmethodID get_constructor(JNIEnv* env, jclass cls, const char* signature);

jfieldID get_static_field(JNIEnv* env, jclass cls, const char* name, const char* signature);

jobject get_static_object_value(JNIEnv* env, jclass cls, jfieldID field);

jint get_enum_ordinal(JNIEnv* env, jclass cls, jobject enum_constant);
