#include "Matrixi.h"

using namespace math;


Matrixi::Matrixi(int h, int w)
	:Array2D(h, w)
{

}

Matrixi Matrixi::operator+(const Matrixi& mat)
{
	assert(mat._width == _width && mat._height == _height);

	Matrixi result(_height, mat._width);

	int32_t len = _width * _height;
	for (int32_t i = 0; i < len; i++)
	{
		result[i] = _values[i] + mat._values[i];
	}

	return result;
}

Matrixi Matrixi::operator-(const Matrixi& mat)
{
	assert(mat._width == _width && mat._height == _height);

	Matrixi result(_height, mat._width);

	int32_t len = _width * _height;
	for (int32_t i = 0; i < len; i++)
	{
		result[i] = _values[i] - mat[i];
	}

	return result;
}

Matrixi Matrixi::operator*(const Matrixi& mat)
{
	assert(_width == mat._height);

	Matrixi result(_height, mat._width);

	Complex val;
	for (int32_t bh = 0; bh < _height; bh++)
	{
		for (int32_t mw = 0; mw < mat._width; mw++)
		{
			val.reset();
			for (int32_t mh = 0; mh < mat._height; mh++)
			{
				Complex a = getValue(bh, mh);
				Complex b = mat.getValue(mh, mw);
				val += a * b;
			}
			result.setValue(bh, mw, val);
		}
	}
	return result;
}

Matrixi& Matrixi::operator+=(const Matrixi& mat)
{
	assert(mat._width == _width && mat._height == _height);

	int32_t len = _width * _height;
	for (int32_t i = 0; i < len; i++)
	{
		_values[i] += mat[i];
	}

	return *this;
}

Matrixi& Matrixi::operator-=(const Matrixi& mat)
{
	assert(mat._width == _width && mat._height == _height);

	int32_t len = _width * _height;
	for (int32_t i = 0; i < len; i++)
	{
		_values[i] -= mat[i];
	}

	return *this;
}

Matrixi& Matrixi::operator*=(float k)
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
