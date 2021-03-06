#pragma once

#include "Common/Node/Node.h"
#include "ext-config.h"

#define AUDIO_DEBUG true


#define AUDIO_DO_FUNC(Target, FuncName, ...) \
{\
	if (Target) \
	{\
		FMOD_RESULT ret = Target->FuncName(__VA_ARGS__);\
		if (AUDIO_DEBUG && ret != FMOD_OK) \
		{ \
			PRINT("Audio Error, Function Name %s\n", #FuncName);\
		} \
	}\
}

#define AUDIO_SET_FUNC AUDIO_DO_FUNC

#define AUDIO_GET_FUNC(Target, FuncName, Type) \
{\
	Type value = 0;\
	if (Target) \
	{\
		AUDIO_DO_FUNC(Target, FuncName, &value);\
	}\
	return value;\
}
	

void ConvertToFMODVector(const math::Vector3& src, FMOD_VECTOR* dest);

void ConvertToSysVector(const FMOD_VECTOR* src, math::Vector3& dest);
