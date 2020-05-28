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
	assert(mat.getWidth() == getWidth() && mat.getHeight() == getHeight());

	Matrix result(getHeight(), mat.getWidth());

	int32_t len = getWidth() * getHeight();
	for (int32_t i = 0; i < len; i++)
	{
		result.setValue(i, getValue(i) + mat.getValue(i));
	}

	return result;
}

Matrix Matrix::operator-(const Matrix& mat)
{
	assert(mat.getWidth() == getWidth() && mat.getHeight() == getHeight());

	Matrix result(getHeight(), mat.getWidth());

	int32_t len = getWidth() * getHeight();
	for (int32_t i = 0; i < len; i++)
	{
		result.setValue(i, getValue(i) - mat.getValue(i));
	}

	return result;
}

Matrix Matrix::operator*(const Matrix& mat)
{
	assert(getWidth() == mat.getHeight());

	Matrix result(getHeight(), mat.getWidth());

	float val = 0;
	for (int32_t bh = 0; bh < getHeight(); bh++)
	{
		for (int32_t mw = 0; mw < mat.getWidth(); mw++)
		{
			val = 0;
			for (int32_t mh = 0; mh < mat.getHeight(); mh++)
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
	assert(mat.getWidth() == getWidth() && mat.getHeight() == getHeight());

	int32_t len = getWidth() * getHeight();
	for (int32_t i = 0; i < len; i++)
	{
		setValue(i, getValue(i) + mat.getValue(i));
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& mat)
{
	assert(mat.getWidth() == getWidth() && mat.getHeight() == getHeight());

	int32_t len = getWidth() * getHeight();
	for (int32_t i = 0; i < len; i++)
	{
		setValue(i, getValue(i) - mat.getValue(i));
	}

	return *this;
}

Matrix& Matrix::operator*=(float k)
{
	for (int32_t i = 0; i < getHeight(); i++)
	{
		for (int32_t j = 0; j < getWidth(); j++)
		{
			int32_t index = i * getWidth() + j;
			float value = getValue(index) * k;
			setValue(index, value);
		}
	}

	return *this;
}

Matrix Matrix::operator*(float k)
{
	Matrix mat(getHeight(), getWidth());

	for (int32_t i = 0; i < getHeight(); i++)
	{
		for (int32_t j = 0; j < getWidth(); j++)
		{
			float value = getValue(i * getWidth() + j) * k;
			mat.setValue(i, j, value);
		}
	}

	return mat;
}

Matrix Matrix::operator/(float k)
{
	Matrix mat(getHeight(), getWidth());

	for (int32_t i = 0; i < getHeight(); i++)
	{
		for (int32_t j = 0; j < getWidth(); j++)
		{
			float value = getValue(i * getWidth() + j) / k;
			mat.setValue(i, j, value);
		}
	}

	return mat;
}

Matrix& Matrix::operator=(const Matrix& mat)
{
	this->reset(mat.getHeight(), mat.getWidth());
	int32_t len = mat.getWidth() * mat.getHeight();
	for (int32_t i = 0; i < len; i++)
	{
		setValue(i, mat.getValue(i));
	}

	return *this;
}

Matrix Matrix::getTranspose() const
{
	Matrix mat;
	mat.reset(getHeight(), getWidth());

	for (int32_t i = 0; i < getHeight(); i++)
	{
		for (int32_t j = 0; j < getWidth(); j++)
		{
			mat.setValue(j, i, getValue(i * getWidth() + j));
		}
	}

	return mat;
}

float Matrix::getDetValue() const
{
	assert(getWidth() == getHeight());

	return Determinant(getValue(), getWidth()).getMagnitude();
}

Matrix Matrix::getMinor(int32_t i, int32_t j) const
{
	assert(i >= 0 && j >= 0 && i < getHeight() && j < getWidth());

	Matrix mat(getHeight() - 1, getWidth() - 1);
	int dn = 0;
	int dm = 0;

	for (int h = 0; h < getHeight(); h++)
	{
		if (h == i)
		{
			dn++;
			continue;
		}
		dm = 0;
		for (int w = 0; w < getWidth(); w++)
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
	assert(getWidth() == getHeight());

	float det = this->getDetValue();

	assert(det != 0);

	Matrix mat = Matrix(getWidth(), getHeight());

	if (getWidth() == 1)
	{
		mat.setValue(0, 0, 1 / this->getValue((size_t)0, (size_t)0));
		return mat;
	}

	for (int i = 0; i < getHeight(); i++)
	{
		for (int j = 0; j < getWidth(); j++)
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
	assert(getWidth() == getHeight());

	float det = this->getDetValue();

	assert(det != 0);

	Matrix adjoint = this->getAdjoint();
	Matrix transpose = adjoint.getTranspose();
	return transpose / det;
}

math::Matrix::Matrix(const Matrix& mat)
{
	this->set(mat.getValue(), mat.getHeight(), mat.getWidth());
}

math::Matrix::~Matrix()
{

}



