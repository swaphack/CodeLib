#include "Matrix.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <cstdarg>
#include "Algebra/Determinant/Determinant.h"

using namespace math;

Matrix::Matrix(int h, int w)
	:Array2D(h, w)
{

}

Matrix::Matrix()
	: Array2D()
{

}

Matrix::Matrix(float* value, int h, int w)
{
	this->set(value, h, w);
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

Matrix Matrix::operator*(float k)
{
	Matrix mat(_height, _width);

	for (int32_t i = 0; i < _height; i++)
	{
		for (int32_t j = 0; j < _width; j++)
		{
			float value = _values[i * _width + j] * k;
			mat.setValue(i, j, value);
		}
	}

	return mat;
}

Matrix Matrix::operator/(float k)
{
	Matrix mat(_height, _width);

	for (int32_t i = 0; i < _height; i++)
	{
		for (int32_t j = 0; j < _width; j++)
		{
			float value = _values[i * _width + j] / k;
			mat.setValue(i, j, value);
		}
	}

	return mat;
}

Matrix& Matrix::operator=(const Matrix& mat)
{
	this->reset(mat._height, mat._width);
	int32_t len = mat._width * mat._height;
	for (int32_t i = 0; i < len; i++)
	{
		_values[i] = mat[i];
	}

	return *this;
}

Matrix Matrix::getTranspose() const
{
	Matrix mat;
	mat.reset(_height, _width);

	for (int32_t i = 0; i < _height; i++)
	{
		for (int32_t j = 0; j < _width; j++)
		{
			mat.setValue(j, i, _values[i * _width + j]);
		}
	}

	return mat;
}

float Matrix::getDetValue() const
{
	assert(_width == _height);

	return Determinant(_values, _width).getMagnitude();
}

Matrix Matrix::getMinor(int32_t i, int32_t j) const
{
	assert(i >= 0 && j >= 0 && i < _height && j < _width);

	Matrix mat(_height - 1, _width - 1);
	int dn = 0;
	int dm = 0;

	for (int h = 0; h < _height; h++)
	{
		if (h == i)
		{
			dn++;
			continue;
		}
		dm = 0;
		for (int w = 0; w < _width; w++)
		{
			if (w == j) 
			{
				dm++;
				continue;
			}
			mat.setValue(h-dn, w-dm, getValue(h, w));
		}
	}

	return mat;
}

Matrix Matrix::getAdjoint() const
{
	assert(_width == _height);

	float det = this->getDetValue();

	assert(det != 0);

	Matrix mat = Matrix(_width, _height);

	if (_width == 1)
	{
		mat.setValue(0, 0, 1 / this->getValue(0, 0));
		return mat;
	}

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			Matrix minor = this->getMinor(i, j);
			float k = 1;
			if (i != j)
			{
				k = powf(-1, i + j);
			}
			mat.setValue(i, j, k * minor.getDetValue());
		}
	}

	return mat;
}

Matrix Matrix::getInverse() const
{
	assert(_width == _height);

	float det = this->getDetValue();

	assert(det != 0);

	Matrix adjoint = this->getAdjoint();
	Matrix transpose = adjoint.getTranspose();
	return transpose / det;
}



