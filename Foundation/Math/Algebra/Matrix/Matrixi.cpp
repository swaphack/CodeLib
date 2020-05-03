#include "Matrixi.h"

using namespace math;


Matrixi::Matrixi(int h, int w)
	:Array2D(h, w)
{

}

Matrixi Matrixi::operator+(const Matrixi& mat)
{
	assert(mat.getWidth() == getWidth() && mat.getHeight() == getHeight());

	Matrixi result(getHeight(), mat.getWidth());

	int32_t len = getWidth() * getHeight();
	for (int32_t i = 0; i < len; i++)
	{
		result[i] = getValue(i) + mat.getValue(i);
	}

	return result;
}

Matrixi Matrixi::operator-(const Matrixi& mat)
{
	assert(mat.getWidth() == getWidth() && mat.getHeight() == getHeight());

	Matrixi result(getHeight(), mat.getWidth());

	int32_t len = getWidth() * getHeight();
	for (int32_t i = 0; i < len; i++)
	{
		result[i] = getValue(i) - mat.getValue(i);
	}

	return result;
}

Matrixi Matrixi::operator*(const Matrixi& mat)
{
	assert(getWidth() == mat.getHeight());

	Matrixi result(getHeight(), mat.getWidth());

	Complex val;
	for (int32_t bh = 0; bh < getHeight(); bh++)
	{
		for (int32_t mw = 0; mw < mat.getWidth(); mw++)
		{
			val.reset();
			for (int32_t mh = 0; mh < mat.getHeight(); mh++)
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
	assert(mat.getWidth() == getWidth() && mat.getHeight() == getHeight());

	int32_t len = getWidth() * getHeight();
	for (int32_t i = 0; i < len; i++)
	{
		setValue(i, getValue(i) + mat.getValue(i));
	}

	return *this;
}

Matrixi& Matrixi::operator-=(const Matrixi& mat)
{
	assert(mat.getWidth() == getWidth() && mat.getHeight() == getHeight());

	int32_t len = getWidth() * getHeight();
	for (int32_t i = 0; i < len; i++)
	{
		setValue(i, getValue(i) - mat.getValue(i));
	}

	return *this;
}

Matrixi& Matrixi::operator*=(float k)
{
	for (int32_t i = 0; i < getHeight(); i++)
	{
		for (int32_t j = 0; j < getWidth(); j++)
		{
			int32_t index = i * getWidth() + j;
			setValue(index, getValue(index) * k);
		}
	}

	return *this;
}

math::Matrixi::~Matrixi()
{

}
