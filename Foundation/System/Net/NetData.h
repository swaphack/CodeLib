#pragma once

#include <string>
#include <cstdint>
#include <queue>

#include "Memory/MemoryData.h"

namespace sys
{
	struct NetData
	{
	public:
		// ����
		MemoryData data;
		// �α�
		int32_t pos;
	public:
		NetData();
		NetData(const std::string& value);
		NetData(const char* value, int32_t size);
		NetData(const NetData& value);
		NetData(const MemoryData& value);
		~NetData();
	public:
		/**
		*	��ǰָ��λ��
		*/
		const char* getPtr();
		/**
		*	��С
		*/
		uint32_t getSize();
		/**
		*	��ǰָ��λ��
		*/
		const char* getCursorPtr();
		/**
		*	ʣ��δ��ȡ�ռ��С
		*/
		int32_t getRemainSize();
		/**
		*	��ʼ��
		*/
		void init(const char* value, int32_t len);
		/**
		*	��ͷ������
		*/
		void insert(const char* value, int32_t len);
	};
}