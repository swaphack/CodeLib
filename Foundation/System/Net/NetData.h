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
		int32_t pos = 0;
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
		const char* getPtr() const;
		/**
		*	��С
		*/
		uint32_t getSize() const;
		/**
		*	��ǰָ��λ��
		*/
		const char* getCursorPtr() const;
		/**
		*	ʣ��δ��ȡ�ռ��С
		*/
		int32_t getRemainSize() const;
	public:
		/**
		*	����λ�ã���0��ʼ
		*/
		void resetPos();
		/**
		*	��ʼ��
		*/
		void init(const char* value, int32_t len);
		/**
		*	��β������
		*/
		void append(const char* value, int32_t len);
	};
}