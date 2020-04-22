#pragma once

#include <cstdint>

// ����
namespace render
{
	// ��� USE_MEMORY_CLONE Ϊ1��ʹ���ڴ����Ϳ���
	//#define USE_MEMORY_CLONE 1
	// ����
	struct T_Vertex
	{
	public:
		int size = 0;
		float* value = nullptr;
		int unit = 0;
	public:
		T_Vertex();
		T_Vertex(const T_Vertex& value);
		~T_Vertex();
	public:
		void init(int _size, float* _value, int _unitSize);
		void show();
	};

	// ����
	struct T_Indice
	{
	public:
		int size = 0;
		uint32_t* value = nullptr;
	public:
		T_Indice();
		T_Indice(const T_Indice& value);
		~T_Indice();
	public:
		void init(int _size, uint32_t* _value);
	};
}