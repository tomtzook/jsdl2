#pragma once

#include <jni.h>


jclass get_class(JNIEnv* env, const char* name);

jmethodID get_method(JNIEnv* env, jclass cls, const char* name, const char* signature);

jmethodID get_constructor(JNIEnv* env, jclass cls, const char* signature);
