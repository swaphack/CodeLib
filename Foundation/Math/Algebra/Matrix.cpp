#include "Matrix.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <cstdarg>

using namespace math;

Matrix::Matrix(int h, int w)
	:Array2D(h, w)
{

}

Matrix Matrix::operator+(const Matrix& mat)
{
	assert(mat._width == _width && mat._height == _height);

	Matrix result(_height, mat._width);

	int32_t len = _width * _height;
	for (int32_t i = 0; i < len; i++)
	{
		result[i] = _values[i] + mat._values[i];
	}

	return result;
}

Matrix Matrix::operator-(const Matrix& mat)
{
	assert(mat._width == _width && mat._height == _height);

	Matrix result(_height, mat._width);

	int32_t len = _width * _height;
	for (int32_t i = 0; i < len; i++)
	{
		result[i] = _values[i] - mat[i];
	}

	return result;
}

Matrix Matrix::operator*(const Matrix& mat)
{
	assert(_width == mat._height);

	Matrix result(_height, mat._width);

	float val = 0;
	for (int32_t bh = 0; bh < _height; bh++)
	{
		for (int32_t mw = 0; mw < mat._width; mw++)
		{
			val = 0;
			for (int32_t mh = 0; mh < mat._height; mh++)
			{
				float a = getValue(bh, mh);
				float b = mat.getValue(mh, mw);
				val += a * b;
			}
			result.setValue(bh, mw, val);
		}
	}

	return result;
}

Matrix& Matrix::operator+=(const Matrix& mat)
{
	assert(mat._width == _width && mat._height == _height);

	int32_t len = _width * _height;
	for (int32_t i = 0; i < len; i++)
	{
		_values[i] += mat[i];
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& mat)
{
	assert(mat._width == _width && mat._height == _height);

	int32_t len = _width * _height;
	for (int32_t i = 0; i < len; i++)
	{
		_values[i] -= mat[i];
	}

	return *this;
}

Matrix& Matrix::operator*=(float k)
{
	for (int32_t i = 0; i < _height; i++)
	{
		for (int32_t j = 0; j < _width; j++)
		{
			_values[i * _width + j] *= k;
		}
	}

	return *this;
}

