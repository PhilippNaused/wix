#pragma once
// Copyright (c) .NET Foundation and contributors. All rights reserved. Licensed under the Microsoft Reciprocal License. See LICENSE.TXT file in the project root for full license information.


#if defined(__cplusplus)
extern "C" {
#endif

enum BOOTSTRAPPER_EXTENSION_LOG_LEVEL
{
    BOOTSTRAPPER_EXTENSION_LOG_LEVEL_NONE,      // turns off report (only valid for XXXSetLevel())
    BOOTSTRAPPER_EXTENSION_LOG_LEVEL_STANDARD,  // written if reporting is on
    BOOTSTRAPPER_EXTENSION_LOG_LEVEL_VERBOSE,   // written only if verbose reporting is on
    BOOTSTRAPPER_EXTENSION_LOG_LEVEL_DEBUG,     // reporting useful when debugging code
    BOOTSTRAPPER_EXTENSION_LOG_LEVEL_ERROR,     // always gets reported, but can never be specified
};

enum BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE
{
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_ESCAPESTRING,
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_EVALUATECONDITION,
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_FORMATSTRING,
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_GETVARIABLENUMERIC,
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_GETVARIABLESTRING,
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_GETVARIABLEVERSION,
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_LOG,
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_SETVARIABLENUMERIC,
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_SETVARIABLESTRING,
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_SETVARIABLEVERSION,
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_COMPAREVERSIONS,
    BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE_GETRELATEDBUNDLEVARIABLE,
};

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_COMPAREVERSIONS_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVersion1;
    LPCWSTR wzVersion2;
} BOOTSTRAPPER_EXTENSION_ENGINE_COMPAREVERSIONS_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_COMPAREVERSIONS_RESULTS
{
    DWORD cbSize;
    int nResult;
} BOOTSTRAPPER_EXTENSION_ENGINE_COMPAREVERSIONS_RESULTS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_ESCAPESTRING_ARGS
{
    DWORD cbSize;
    LPCWSTR wzIn;
} BOOTSTRAPPER_EXTENSION_ENGINE_ESCAPESTRING_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_ESCAPESTRING_RESULTS
{
    DWORD cbSize;
    LPWSTR wzOut;
    // Should be initialized to the size of wzOut.
    SIZE_T cchOut;
} BOOTSTRAPPER_EXTENSION_ENGINE_ESCAPESTRING_RESULTS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_EVALUATECONDITION_ARGS
{
    DWORD cbSize;
    LPCWSTR wzCondition;
} BOOTSTRAPPER_EXTENSION_ENGINE_EVALUATECONDITION_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_EVALUATECONDITION_RESULTS
{
    DWORD cbSize;
    BOOL f;
} BOOTSTRAPPER_EXTENSION_ENGINE_EVALUATECONDITION_RESULTS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_FORMATSTRING_ARGS
{
    DWORD cbSize;
    LPCWSTR wzIn;
} BOOTSTRAPPER_EXTENSION_ENGINE_FORMATSTRING_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_FORMATSTRING_RESULTS
{
    DWORD cbSize;
    LPWSTR wzOut;
    // Should be initialized to the size of wzOut.
    SIZE_T cchOut;
} BOOTSTRAPPER_EXTENSION_ENGINE_FORMATSTRING_RESULTS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLENUMERIC_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
} BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLENUMERIC_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLENUMERIC_RESULTS
{
    DWORD cbSize;
    LONGLONG llValue;
} BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLENUMERIC_RESULTS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLESTRING_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
} BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLESTRING_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLESTRING_RESULTS
{
    DWORD cbSize;
    LPWSTR wzValue;
    // Should be initialized to the size of wzValue.
    SIZE_T cchValue;
} BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLESTRING_RESULTS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLEVERSION_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
} BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLEVERSION_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLEVERSION_RESULTS
{
    DWORD cbSize;
    LPWSTR wzValue;
    // Should be initialized to the size of wzValue.
    SIZE_T cchValue;
} BOOTSTRAPPER_EXTENSION_ENGINE_GETVARIABLEVERSION_RESULTS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_LOG_ARGS
{
    DWORD cbSize;
    BOOTSTRAPPER_EXTENSION_LOG_LEVEL level;
    LPCWSTR wzMessage;
} BOOTSTRAPPER_EXTENSION_ENGINE_LOG_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_LOG_RESULTS
{
    DWORD cbSize;
} BOOTSTRAPPER_EXTENSION_ENGINE_LOG_RESULTS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLENUMERIC_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
    LONGLONG llValue;
} BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLENUMERIC_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLENUMERIC_RESULTS
{
    DWORD cbSize;
} BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLENUMERIC_RESULTS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLESTRING_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
    LPCWSTR wzValue;
    BOOL fFormatted;
} BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLESTRING_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLESTRING_RESULTS
{
    DWORD cbSize;
} BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLESTRING_RESULTS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLEVERSION_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
    LPCWSTR wzValue;
} BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLEVERSION_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLEVERSION_RESULTS
{
    DWORD cbSize;
} BOOTSTRAPPER_EXTENSION_ENGINE_SETVARIABLEVERSION_RESULTS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_GETRELATEDBUNDLEVARIABLE_ARGS
{
    DWORD cbSize;
    LPCWSTR wzBundleCode;
    LPCWSTR wzVariable;
} BOOTSTRAPPER_EXTENSION_ENGINE_GETRELATEDBUNDLEVARIABLE_ARGS;

typedef struct _BOOTSTRAPPER_EXTENSION_ENGINE_GETRELATEDBUNDLEVARIABLE_RESULTS
{
    DWORD cbSize;
    LPWSTR wzValue;
    // Should be initialized to the size of wzValue.
    SIZE_T cchValue;
} BOOTSTRAPPER_EXTENSION_ENGINE_GETRELATEDBUNDLEVARIABLE_RESULTS;

extern "C" typedef HRESULT(WINAPI *PFN_BOOTSTRAPPER_EXTENSION_ENGINE_PROC)(
    __in BOOTSTRAPPER_EXTENSION_ENGINE_MESSAGE message,
    __in const LPVOID pvArgs,
    __inout LPVOID pvResults,
    __in_opt LPVOID pvContext
    );

#if defined(__cplusplus)
}
#endif
