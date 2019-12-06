#include "Determinant.h"
#include <cassert>

using namespace math;

Determinant::Determinant()
	:_values(nullptr)
	, _width(0)
{

}

Determinant::Determinant(uint32_t w)
{
	_width = w;
	float size = w * w * sizeof(float);
	_values = (float*)malloc(size);
	memset(_values, 0, size);
}

Determinant::Determinant(float* val, uint32_t w)
{
	assert(val != nullptr && w > 0);
	_width = w;
	float size = w * w * sizeof(float);
	_values = (float*)malloc(size);
	memset(_values, 0, size);
	memcpy(_values, val, size);
}

Determinant::Determinant(const Determinant& det)
{
	*this = det;
}

Determinant::~Determinant()
{
	this->dispose();
}

uint32_t Determinant::getWidth()
{
	return _width;
}

void Determinant::reset(uint32_t w)
{
	assert(w != 0);

	this->dispose();

	_width = w;
	float size = w * w * sizeof(float);
	_values = (float*)malloc(size);
	memset(_values, 0, size);
}

void Determinant::reset()
{
	if (_values != nullptr && _width != 0)
	{
		float size = _width * _width * sizeof(float);
		memset(_values, 0, size);
	}
}

float Determinant::getValue(uint32_t index) const
{
	assert(index < _width * _width);

	return _values[index];
}

float Determinant::getValue(uint32_t w, uint32_t h) const
{
	assert(w < _width && h < _width);

	return _values[h * _width + w];
}

float Determinant::getValue()
{
	float value = 0;
	for (int i = 0; i < _width; i++)
	{
		float val1 = 0;
		float val2 = 0;
		for (int j = 0; j < _width; j++)
		{
			int a = i + j;
			int b = i - j;
			a = a % _width;
			b = (b + _width) % _width;
			val1 += getValue(j, i + j);
			val2 -= getValue(j, i - j);
		}
		value += val1 + val2;
	}
	return value;
}

void Determinant::setValue(uint32_t w, uint32_t h, float value)
{
	assert(w < _width && h < _width);

	_values[h * _width + w] = value;
}

void Determinant::setValue(uint32_t index, float value)
{
	assert(index < _width * _width);

	_values[index] = value;
}

Determinant& Determinant::operator=(const Determinant& mat)
{
	this->reset(mat._width);
	uint32_t len = mat._width * mat._width;
	for (uint32_t i = 0; i < len; i++)
	{
		_values[i] = mat[i];
	}

	return *this;
}

float& Determinant::operator[](uint32_t index)
{
	assert(index < _width * _width);

	return _values[index];
}

float Determinant::operator[](uint32_t index) const
{
	assert(index < _width * _width);

	return _values[index];
}

Determinant Determinant::operator+(const Determinant& mat)
{

}

Determinant Determinant::operator-(const Determinant& mat)
{

}

Determinant Determinant::operator*(const Determinant& mat)
{

}

Determinant& Determinant::operator+=(const Determinant& mat)
{

}

Determinant& Determinant::operator-=(const Determinant& mat)
{

}

Determinant& Determinant::operator*=(float k)
{

}

std::string Determinant::toString()
{

}

void Determinant::dispose()
{

}

