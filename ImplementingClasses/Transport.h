#pragma once
#include "AllTerrainBoots.h"
#include "Camel.h"
#include "Centaur.h"
#include "FastCamel.h"
#include "Eagle.h"
#include "FlyingCarpet.h"
#include "Broomstick.h"

#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

extern "C" MYDLL_API int Add(int a, int b);