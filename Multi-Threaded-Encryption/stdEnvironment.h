#pragma once

#ifndef stdEnvironment
#define stdFunctions

// Check windows
#if _WIN32 || _WIN64
	#if _WIN64
        #define ENVIRONMENT64
	#else
         #define ENVIRONMENT32
	#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
        #define ENVIRONMENT64
	#else
         #define ENVIRONMENT32
	#endif
#endif

#ifndef ENVIRONMENT32 
    #ifndef ENVIRONMENT64
        #define ENVIRONMENT64
    #endif // !ENVIRONMENT32 
#endif // !ENVIRONMENT64

#endif // !stdEnvironment