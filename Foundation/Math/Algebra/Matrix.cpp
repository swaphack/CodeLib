#include "Matrix.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace math;

Matrix::Matrix()
:_values(nullptr)
, _width(0)
, _height(0)
{
}

Matrix::Matrix(uint32_t w, uint32_t h)
{
	_height = h;
	_width = w;
	float size = _width * _height * sizeof(float);
	_values = (float*)malloc(size);
	memset(_values, 0, size);
}

Matrix::Matrix(float* val, uint32_t w, uint32_t h)
{
	assert(val != nullptr && w > 0 && h > 0);

	_height = h;
	_width = w;
	float size = _width * _height * sizeof(float);
	_values = (float*)malloc(size);
	memset(_values, 0, size);
	memcpy(_values, val, size);
}

Matrix::Matrix(const Matrix& mat)
{
	*this = mat;
}

std::string Matrix::toString()
{
	std::ostringstream stream;
	for (int j = 0; j < _height; j++)
	{
		for (int i = 0; i < _width; i++)
		{
			float fValue = getValue(i, j);
			stream << fValue;
			stream << ",";
		}
		stream << "\n";
	}
	
	return stream.str();
}

Matrix::~Matrix()
{
	this->dispose();
}

uint32_t Matrix::getWidth()
{
	return _width;
}

uint32_t Matrix::getHeight()
{
	return _height;
}

void Matrix::reset(uint32_t w, uint32_t h)
{
	assert(w != 0 && h != 0);

	this->dispose();

	_height = h;
	_width = w;
	float size = _width * _height * sizeof(float);
	_values = (float*)malloc(size);
	memset(_values, 0, size);
}

void Matrix::reset()
{
	if (_values != nullptr && _width != 0 && _height != 0)
	{
		float size = _width * _height * sizeof(float);
		memset(_values, 0, size);
	}
}

float Matrix::getValue(uint32_t index) const
{
	assert(index < _width * _height);

	return _values[index];
}

float Matrix::getValue(uint32_t w, uint32_t h) const
{
	assert(w < _width && h < _height);

	return _values[h * _width + w];
}

void Matrix::setValue(uint32_t w, uint32_t h, float value)
{
	assert(w < _width && h < _height);

	_values[h * _width + w] = value;
}

void Matrix::setValue(uint32_t index, float value)
{
	assert(index < _width * _height);

	_values[index] = value;
}

Matrix Matrix::transpose()
{
	Matrix mat;
	mat.reset(_height, _width);

	for (uint32_t i = 0; i < _height; i++)
	{
		for (uint32_t j = 0; j < _width; j++)
		{
			mat.setValue(j * _height + i, _values[i * _width + j]);
		}
	}

	return mat;
}

void Matrix::dispose()
{
	if (_values)
	{
		free(_values);
		_values = nullptr;
	}
}

Matrix& Matrix::operator=(const Matrix& mat)
{
	this->reset(mat._width, mat._height);
	uint32_t len = mat._width * mat._height;
	for (uint32_t i = 0; i < len; i++)
	{
		_values[i] = mat[i];
	}

	return *this;
}

float& Matrix::operator[](uint32_t index)
{
	assert(index < _width * _height);

	return _values[index];
}

float Matrix::operator[](uint32_t index) const
{
	assert(index < _width * _height);

	return _values[index];
}

Matrix Matrix::operator+(const Matrix& mat)
{
	assert(mat._width == _width && mat._height == _height);

	Matrix result;
	uint32_t len = _width * _height;
	for (uint32_t i = 0; i < len; i++)
	{
		result[i] = _values[i] + mat._values[i];
	}

	return result;
}

Matrix Matrix::operator-(const Matrix& mat)
{
	assert(mat._width == _width && mat._height == _height);

	Matrix result;

	uint32_t len = _width * _height;
	for (uint32_t i = 0; i < len; i++)
	{
		result[i] = _values[i] - mat[i];
	}

	return result;
}

Matrix Matrix::operator*(const Matrix& mat)
{
	assert(_width == mat._height);

	Matrix result;
	result.reset(mat._width, _height);

	float val = 0;
	for (uint32_t bh = 0; bh < _height; bh++)
	{
		for (uint32_t mw = 0; mw < mat._width; mw++)
		{
			val = 0;
			for (uint32_t mh = 0; mh < mat._height; mh++)
			{
				float a = getValue(mh, bh);
				float b = mat.getValue(mw, mh);
				val += a * b;
			}
			result.setValue(mw, bh, val);
		}
	}

	return result;
}

Matrix& Matrix::operator+=(const Matrix& mat)
{
	assert(mat._width == _width && mat._height == _height);

	uint32_t len = _width * _height;
	for (uint32_t i = 0; i < len; i++)
	{
		_values[i] += mat[i];
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& mat)
{
	assert(mat._width == _width && mat._height == _height);

	uint32_t len = _width * _height;
	for (uint32_t i = 0; i < len; i++)
	{
		_values[i] -= mat[i];
	}

	return *this;
}

Matrix& Matrix::operator*=(float k)
{
	for (uint32_t i = 0; i < _height; i++)
	{
		for (uint32_t j = 0; j < _width; j++)
		{
			_values[i * _width + j] *= k;
		}
	}

	return *this;
}
