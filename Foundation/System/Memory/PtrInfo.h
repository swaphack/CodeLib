#pragma once

#include "../Base/import.h"

namespace sys
{
	struct PtrInfo
	{
		// ָ��
		char* ptr;
		// ��Cacheλ��
		uint begin;
		// �����С
		uint size;

		PtrInfo()
		{
			ptr = nullptr;
			begin = 0;
			size = 0;
		}
	};
}