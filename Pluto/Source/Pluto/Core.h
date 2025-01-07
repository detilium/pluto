#pragma once

#ifdef PLUTO_PLATFORM_WINDOWS
#ifdef PLUTO_BUILD_DLL
#define PLUTO_API __declspec(dllexport)
#else
#define PLUTO_API __declspec(dllimport)
#endif
#else
#error Pluto only supports Windows!
#endif

#define BIT(x) (1 << x)