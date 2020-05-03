#include "Determinant.h"
#include <cassert>

using namespace math;

Determinant::Determinant()
{

}

Determinant::Determinant(size_t order)
{
	assert(order > 0);

	this->reset(order);
}

Determinant::Determinant(const float* val, size_t order)
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

size_t Determinant::getOrder() const
{
	return getWidth();
}

void Determinant::reset(size_t order)
{
	assert(order != 0);

	Array2D<float>::reset(order, order);
}

void Determinant::set(const float* val, size_t order)
{
	assert(val != nullptr && order > 0);

	Array2D<float>::set(val, order, order);
}

float Determinant::getMagnitude() const
{
	assert(getOrder() > 0);
	if (getOrder() == 1)
	{
		return getValue(0);
	}
	if (getOrder() == 2)
	{
		return getValue(0) * getValue(3) - getValue(1) * getValue(2);
	}
	float value = 0;
	
	for (size_t i = 0; i < getOrder(); i++)
	{
		int len = getOrder() - 1;
		int x = 0;
		Determinant det = this->getMinor(0, i);
		float k = getValue((size_t)0, i) * det.getMagnitude() * pow(-1.0f, i);
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

Determinant Determinant::mul(float k, size_t row)
{
	assert(row < getOrder());

	Determinant det;
	
	for (size_t i = 0; i < getOrder(); i++)
	{
		det[row * getOrder() + i] = k;
	}

	return det;
}

Determinant Determinant::add(const Determinant& det, size_t row)
{
	assert(det.getOrder() != this->getOrder());
	size_t order = getOrder();
	Determinant target(order);

	for (size_t i = 0; i < order; i++)
	{
		if (i == row)
		{
			for (size_t j = 0; j < order; j++)
			{
				target.setValue(i, j, this->getValue(i, j) + det.getValue(i, j));
			}
		}
		else if (i != row)
		{
			for (size_t j = 0; j < order; j++)
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
	assert(getOrder() == det.getOrder());

	Determinant result(getOrder());

	float val = 0;
	for (size_t bh = 0; bh < getOrder(); bh++)
	{
		for (size_t mw = 0; mw < getOrder(); mw++)
		{
			val = 0;
			for (size_t mh = 0; mh < getOrder(); mh++)
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

Determinant Determinant::getMinor(size_t i, size_t j) const
{
	assert(i >= 0 && j >= 0 && i < getOrder() && j < getOrder());

	Determinant mat(getOrder() - 1);
	int dn = 0;
	int dm = 0;

	for (size_t h = 0; h < getOrder(); h++)
	{
		if (h == i)
		{
			dn++;
			continue;
		}
		dm = 0;
		for (size_t w = 0; w < getOrder(); w++)
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
