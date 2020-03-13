#pragma once

// 纹理
namespace render
{
	// 如果 USE_MEMORY_CLONE 为1，使用内存分配和拷贝
	//#define USE_MEMORY_CLONE 1
	// 顶点
	struct T_Vertex
	{
		int size;
		float* value;
		int unit;

		T_Vertex()
		{
			size = 0;
			value = nullptr;
			unit = 0;
		}
		~T_Vertex()
		{
			SAFE_FREE(value);
		}

		void init(int _size, float* _value, int _unitSize)
		{
			if (_value == nullptr)
			{
				return;
			}
			SAFE_FREE(value);
			size = _size;
			unit = _unitSize;

			value = (float*)malloc(size * sizeof(float));
			memcpy(value, _value, size * sizeof(float));
		}

		void show()
		{
			for (int i = 0; i < size; i++)
			{
				PRINT("%f,", value[i]);
			}

			PRINT("\n");
		}
	};

	// 索引
	struct T_Indice
	{
		int size;
		uint16_t* value;

		T_Indice()
		{
			size = 0;
			value = nullptr;
		}

		~T_Indice()
		{
			SAFE_FREE(value);
		}

		void init(int _size, uint16_t* _value)
		{
			if (_value == nullptr)
			{
				return;
			}
			SAFE_FREE(value);
			size = _size;

			value = (uint16_t*)malloc(size * sizeof(uint16_t));
			memcpy(value, _value, size * sizeof(uint16_t));
		}
	};
}