#pragma once

#include "defines.h"

#define IASSERTIONS_ENABLED

#ifdef IASSERTIONS_ENABLED
    #ifdef IPLATFORM_WINDOWS
        #define DebugBreak() __debugbreak()
    #else
        #define DebugBreak() __builtin_trap()
    #endif

IAPI void ReportAssertionFailure(const char *expr, const char *msg, const char *file, i32 line);

    #define IASSERT(expr)                                                                                              \
        {                                                                                                              \
            if(expr)                                                                                                   \
            {                                                                                                          \
            }                                                                                                          \
            else                                                                                                       \
            {                                                                                                          \
                ReportAssertionFailure(#expr, "", __FILE__, __LINE__);                                                 \
                DebugBreak();                                                                                          \
            }                                                                                                          \
        }

    #define IASSERT_MSG(expr, message)                                                                                 \
        {                                                                                                              \
            if(expr)                                                                                                   \
            {                                                                                                          \
            }                                                                                                          \
            else                                                                                                       \
            {                                                                                                          \
                ReportAssertionFailure(#expr, message, __FILE__, __LINE__);                                            \
                DebugBreak();                                                                                          \
            }                                                                                                          \
        }

    #ifdef _DEBUG
        #define IASSERT_DEBUG(expr)                                                                                    \
            {                                                                                                          \
                if(expr)                                                                                               \
                {                                                                                                      \
                }                                                                                                      \
                else                                                                                                   \
                {                                                                                                      \
                    ReportAssertionFailure(#expr, "", __FILE__, __LINE__);                                             \
                    DebugBreak();                                                                                      \
                }                                                                                                      \
            }
    #else
        #define IASSERT_DEBUG(expr)
    #endif

#else
    #define IASSERT(expr)
    #define IASSERT_MSG(expr, message)
    #define IASSERT_DEBUG(expr)
#endif