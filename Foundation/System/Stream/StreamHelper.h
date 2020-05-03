#pragma once

#include "macros.h"

namespace sys
{
	// ��������
	class StreamHelper
	{
	public:
		// ����һ����С�����ƶ�����ռ���ڴ�
		static char* mallocStream(size_t size);
		// ����һ����С����Ŀ�������ڴ棬����ֵ
		static char* mallocStream(void* data, size_t size);
		// ����һ����С����ָ������ռ���ڴ棬����������
		static char* mallocStream(size_t capacity, void* data, size_t size);
		// �ͷ���
		static void freeStream(void* data);
	};
}