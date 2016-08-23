#pragma once

#ifdef USE_FMOD_LOW_LEVEL
#include "fsbank/fsbank.h"

#include "lowlevel/fmod.h"

#include "studio/fmod_studio.h"
#else
#include "fsbank/fsbank.h"
#include "lowlevel/fmod.hpp"
#include "studio/fmod_studio.h"
#endif