#pragma once

#include <string>
#include <cstdint>
#include <queue>

namespace sys
{
	struct NetData
	{
	public:
		// ����
		char* data;
		// ��С
		int32_t size;
		// �α�
		int32_t pos;
	public:
		NetData();
		NetData(const std::string& value);
		NetData(const char* value, int32_t size);
		~NetData();
	public:
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
		void insert(const char* data, int32_t len);
	};
}