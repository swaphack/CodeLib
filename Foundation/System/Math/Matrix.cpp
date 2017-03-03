#include "Matrix.h"
#include <cmath>
#include <cstdlib>

using namespace sys;

static float errorValue = 0;

Matrix::Matrix()
:values(nullptr)
, width(0)
, height(0)
{
}

Matrix::Matrix(uint w, uint h)
:Matrix()
{
	this->reset(w, h);
}

Matrix::~Matrix()
{
	this->dispose();
}

uint Matrix::getWidth()
{
	return width;
}

uint Matrix::getHeight()
{
	return height;
}

void Matrix::reset(uint w, uint h)
{
	if (w == 0 || h == 0)
	{
		return;
	}
	this->dispose();

	height = h;
	width = w;
	values = (float*)malloc(width * height * sizeof(float));
	memset(values, 0, width * height * sizeof(float));
}

void Matrix::reset()
{
	if (values != nullptr && width != 0 && height != 0)
	{
		memset(values, 0, width * height * sizeof(float));
	}
}

float Matrix::getValue(uint index) const
{
	if (index >= width * height)
	{
		return 0;
	}

	return values[index];
}

float Matrix::getValue(uint w, uint h) const
{
	if (w >= width || h >= height)
	{
		return 0;
	}

	return values[h * width + w];
}

void Matrix::setValue(uint w, uint h, float value)
{
	if (w >= width || h >= height)
	{
		return;
	}

	values[h * width + w] = value;
}

void Matrix::setValue(uint index, float value)
{
	if (index >= width * height)
	{
		return;
	}

	values[index] = value;
}

Matrix Matrix::transpose()
{
	Matrix mat;
	mat.reset(height, width);

	for (uint i = 0; i < height; i++)
	{
		for (uint j = 0; j < width; j++)
		{
			mat.setValue(j * height + i, values[i * width + j]);
		}
	}

	return mat;
}

void Matrix::dispose()
{
	if (values)
	{
		free(values);
		values = nullptr;
	}
}

Matrix& Matrix::operator=(const Matrix& mat)
{
	this->reset(mat.width, mat.height);
	int len = mat.width * mat.height;
	for (int i = 0; i < len; i++)
	{
		values[i] = mat[i];
	}

	return *this;
}

float& Matrix::operator[](uint index)
{
	if (index >= width * height)
	{
		return errorValue;
	}

	return values[index];
}

float Matrix::operator[](uint index) const
{
	if (index >= width * height)
	{
		return 0;
	}

	return values[index];
}

Matrix Matrix::operator+(const Matrix& mat)
{
	Matrix result;
	if (mat.width != width || mat.height != height)
	{
		return result;
	}

	int len = width * height;
	for (int i = 0; i < len; i++)
	{
		result[i] = values[i] + mat.values[i];
	}

	return result;
}

Matrix Matrix::operator-(const Matrix& mat)
{
	Matrix result;
	if (mat.width != width || mat.height != height)
	{
		return result;
	}

	int len = width * height;
	for (int i = 0; i < len; i++)
	{
		result[i] = values[i] - mat[i];
	}

	return result;
}

Matrix Matrix::operator*(const Matrix& mat)
{
	Matrix result;
	if (width != mat.height)
	{
		return result;
	}
	result.reset(height, mat.width);

	float val = 0;
	for (uint i = 0; i < height; i++)
	{
		for (uint j = 0; j < mat.width; j++)
		{
			val = 0;
			for (uint k = 0; k < width; k++)
			{
				val += getValue(i, k) * mat.getValue(k, j);
			}
			result[i * width + j] = val;
		}
	}

	return result;
}

Matrix& Matrix::operator+=(const Matrix& mat)
{
	if (mat.width != width || mat.height != height)
	{
		return *this;
	}

	int len = width * height;
	for (int i = 0; i < len; i++)
	{
		values[i] += mat[i];
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& mat)
{
	if (mat.width != width || mat.height != height)
	{
		return *this;
	}

	int len = width * height;
	for (int i = 0; i < len; i++)
	{
		values[i] -= mat[i];
	}

	return *this;
}

Matrix& Matrix::operator*=(const Matrix& mat)
{
	if (width != mat.height)
	{
		return *this;
	}

	float val = 0;
	for (uint i = 0; i < height; i++)
	{
		for (uint j = 0; j < mat.width; j++)
		{
			val = 0;
			for (uint k = 0; k < width; k++)
			{
				val += getValue(i, k) * mat.getValue(k, j);
			}
			values[i * width + j] = val;
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(float k)
{
	for (uint i = 0; i < height; i++)
	{
		for (uint j = 0; j < width; j++)
		{
			values[i * width + j] *= k;
		}
	}

	return *this;
}
