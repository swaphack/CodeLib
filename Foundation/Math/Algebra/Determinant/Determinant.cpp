#include "Determinant.h"
#include <cassert>

using namespace math;

Determinant::Determinant()
{

}

Determinant::Determinant(int32_t order)
{
	assert(order > 0);

	this->reset(order);
}

Determinant::Determinant(float* val, int32_t order)
{
	assert(val != nullptr && order > 0);

	this->set(val, order);
}

Determinant::Determinant(const Determinant& det)
{
	*this = det;
}

Determinant::~Determinant()
{
	this->dispose();
}

int32_t Determinant::getOrder() const
{
	return _width;
}

void Determinant::reset(int32_t order)
{
	assert(order != 0);

	this->dispose();

	_width = _height = order;

	int size = order * order * sizeof(float);
	_values = (float*)malloc(size);
	memset(_values, 0, size);
}

void Determinant::set(float* val, int32_t order)
{
	assert(val != nullptr && order > 0);

	_width = _height = order;
	int size = order * order * sizeof(float);
	_values = (float*)malloc(size);
	memset(_values, 0, size);
	memcpy(_values, val, size);
}

float Determinant::getMagnitude() const
{
	assert(_width > 0);
	if (_width == 1)
	{
		return _values[0];
	}
	if (_width == 2)
	{
		return _values[0] * _values[3] - _values[1] * _values[2];
	}
	float value = 0;
	
	for (int i = 0; i < _width; i++)
	{
		int len = _width - 1;
		int x = 0;
		Determinant det = this->getMinor(0, i);
		float k = getValue(0, i) * det.getMagnitude() * pow(-1.0f, i);
		value += k;
	}

	return value;
}

int Determinant::getInverseNumber(float* data, int len)
{
	if (data == nullptr)
	{
		return 0;
	}
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		int num = 0;
		float val = data[i];
		for (int j = i + 1; j < len; j++)
		{
			if (val > data[j])
			{
				num++;
			}
		}
		count += num;
	}

	return count;
}

Determinant Determinant::mul(float k, int32_t row)
{
	assert(row < _width);

	Determinant det;
	
	for (int i = 0; i < _width; i++)
	{
		det[row * _width + i] = k;
	}

	return det;
}

Determinant Determinant::add(const Determinant& det, int32_t row)
{
	assert(det.getOrder() != this->getOrder());
	int32_t order = getOrder();
	Determinant target(order);

	for (int i = 0; i < order; i++)
	{
		if (i == row)
		{
			for (int j = 0; j < order; j++)
			{
				target.setValue(i, j, this->getValue(i, j) + det.getValue(i, j));
			}
		}
		else if (i != row)
		{
			for (int j = 0; j < order; j++)
			{
				assert(det.getValue(i, j) == this->getValue(i, j));
				target.setValue(i, j, this->getValue(i, j));
			}
		}
	}

	return target;
}

Determinant Determinant::operator*(const Determinant& det)
{
	assert(_width == det._width);

	Determinant result(_width);

	float val = 0;
	for (int32_t bh = 0; bh < _width; bh++)
	{
		for (int32_t mw = 0; mw < _width; mw++)
		{
			val = 0;
			for (int32_t mh = 0; mh < _width; mh++)
			{
				float a = getValue(bh, mh);
				float b = det.getValue(mh, mw);
				val += a * b;
			}
			result.setValue(bh, mw, val);
		}
	}

	return result;
}

Determinant Determinant::getMinor(int32_t i, int32_t j) const
{
	assert(i >= 0 && j >= 0 && i < _height && j < _width);

	Determinant mat(_height - 1);
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
			mat.setValue(h - dn, w - dm, getValue(h, w));
		}
	}

	return mat;
}
