#include "pointer_common.h"
#include "system.h"

using namespace render;

void T_Vertex::init(int _size, float* _value, int _unitSize)
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

T_Vertex::~T_Vertex()
{
	SAFE_FREE(value);
}

T_Vertex::T_Vertex(const T_Vertex& value)
{
	this->init(value.size, value.value, value.unit);
}

T_Vertex::T_Vertex()
{
	size = 0;
	value = nullptr;
	unit = 0;
}

void T_Vertex::show()
{
	for (int i = 0; i < size; i++)
	{
		PRINT("%f,", value[i]);
	}

	PRINT("\n");
}

void T_Indice::init(int _size, uint32_t* _value)
{
	if (_value == nullptr)
	{
		return;
	}
	SAFE_FREE(value);
	size = _size;

	value = (uint32_t*)malloc(size * sizeof(uint32_t));
	memcpy(value, _value, size * sizeof(uint32_t));
}

T_Indice::~T_Indice()
{
	SAFE_FREE(value);
}

T_Indice::T_Indice(const T_Indice& value)
{
	this->init(value.size, value.value);
}

T_Indice::T_Indice()
{
	size = 0;
	value = nullptr;
}
