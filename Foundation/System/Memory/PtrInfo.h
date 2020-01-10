#pragma once

#include "Base/import.h"

namespace sys
{
	struct PtrInfo
	{
		// ָ��
		char* ptr;
		// ��Cacheλ��
		uint32_t begin;
		// �����С
		uint32_t size;

		PtrInfo()
		{
			ptr = nullptr;
			begin = 0;
			size = 0;
		}
	};
}