#pragma once

#include "Base/import.h"

namespace sys
{
	struct PtrInfo
	{
		// ָ��
		char* ptr;
		// ��Cacheλ��
		uint32 begin;
		// �����С
		uint32 size;

		PtrInfo()
		{
			ptr = nullptr;
			begin = 0;
			size = 0;
		}
	};
}