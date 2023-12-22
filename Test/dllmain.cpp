// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "NativeTest.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

/*
 * Class:     NativeTest
 * Method:    nativeFunc
 * Signature: (Ljava/util/function/Supplier;)V
 */
JNIEXPORT void JNICALL Java_NativeTest_nativeFunc
  (JNIEnv *env, jobject, jobject supplier)
{
    const jclass supplier_class = env->GetObjectClass(supplier);
    const jmethodID get_function = env->GetMethodID(supplier_class, "get", "()Ljava/lang/Object;");
    const auto obj = reinterpret_cast<jstring>(env->CallObjectMethod(supplier, get_function));
    const auto len = env->GetStringLength(obj);
    printf("str length: %ld\n", len);
    env->DeleteLocalRef(supplier_class);
}