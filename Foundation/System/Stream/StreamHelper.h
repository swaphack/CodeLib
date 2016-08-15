#pragma once

#include "macros.h"
#include "IStreamBase.h"

namespace sys
{
	// ��������
	class StreamHelper
	{
	public:
		// ����һ����С�����ƶ�����ռ���ڴ�
		static char* mallocStream(ss_t size);
		// ����һ����С����Ŀ�������ڴ棬����ֵ
		static char* mallocStream(void* data, ss_t size);
		// ����һ����С����ָ������ռ���ڴ棬����������
		static char* mallocStream(ss_t capacity, void* data, ss_t size);
		// �ͷ���
		static void freeStream(void* data);
	};
}