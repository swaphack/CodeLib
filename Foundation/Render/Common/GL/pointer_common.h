#pragma once

// ����
namespace render
{
	// ��� USE_MEMORY_CLONE Ϊ1��ʹ���ڴ����Ϳ���
	//#define USE_MEMORY_CLONE 1
	// ����
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

	// ����
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