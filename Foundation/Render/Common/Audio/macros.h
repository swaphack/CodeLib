#pragma once

#include "../Node/Node.h"


#define AUDIO_DO_FUNC(Target, FuncName, ...) \
if (Target) \
{\
	Target->FuncName(__VA_ARGS__);\
}

#define AUDIO_SET_FUNC AUDIO_DO_FUNC

#define AUDIO_GET_FUNC(Target, FuncName, Type) \
{\
	Type value = 0;\
	AUDIO_DO_FUNC(Target, FuncName, &value);\
	return value;\
}

void ConvertToFMODVector(const sys::Vector3& src, FMOD_VECTOR& dest);

void ConvertToSysVector(const FMOD_VECTOR& src, sys::Vector3& dest);