#pragma once

// 纹理
namespace render
{
	// 如果 USE_MEMORY_CLONE 为1，使用内存分配和拷贝
	//#define USE_MEMORY_CLONE 1
	// 顶点
	struct T_Vertex
	{
		int count;
		float* value;
		int size;

		T_Vertex()
		{
			count = 0;
			value = nullptr;
			size = 0;
		}
		~T_Vertex()
		{
			SAFE_FREE(value);
		}

		/*
		T_Vertex& operator= (const T_Vertex* vertex)
		{
			count = vertex->count;
			size = vertex->size;
#if defined(USE_MEMORY_CLONE) && USE_MEMORY_CLONE == 1
			SAFE_FREE(value);
			value = (float*)malloc(count * sizeof(float));
			memcpy(value, _value, count * sizeof(float));
#else
			value = vertex->value;
#endif
			
		}
		*/

		void init(int _count, float* _value, int _size)
		{
			if (_value == nullptr)
			{
				return;
			}
			SAFE_FREE(value);
			count = _count;
			size = _size;

			value = (float*)malloc(count * sizeof(float));
			memcpy(value, _value, count * sizeof(float));
		}
	};

	// 索引
	struct T_Indice
	{
		int count;
		ushort* value;

		T_Indice()
		{
			count = 0;
			value = nullptr;
		}

		~T_Indice()
		{
			SAFE_FREE(value);
		}

		/*
		T_Indice& operator= (const T_Indice* indice)
		{
			count = indice->count;
#if defined(USE_MEMORY_CLONE) && USE_MEMORY_CLONE == 1
			SAFE_FREE(value);
			value = (ushort*)malloc(count * sizeof(ushort));
			memcpy(value, _value, count * sizeof(ushort));
#else
			value = indice->value;
#endif
		}
		*/

		void init(int _count, ushort* _value)
		{
			if (_value == nullptr)
			{
				return;
			}
			SAFE_FREE(value);
			count = _count;

			value = (ushort*)malloc(count * sizeof(ushort));
			memcpy(value, _value, count * sizeof(ushort));
		}
	};
}