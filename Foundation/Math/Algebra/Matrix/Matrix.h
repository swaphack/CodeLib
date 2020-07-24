#pragma once

#include <cstdint>

#include "Basic/Array2D.h"
#include "Algebra/Determinant/Determinant.h"

namespace math
{
	/**
	*	矩阵
	*/
	template<typename T, const int Height, const int Width>
	struct Matrix : public Array2D<T, Height, Width>
	{
		typedef Array2D<T, Height, Width> base;
	public:
		Matrix() 
		{

		}
		Matrix(const float* value) 
		{
			this->set(value);
		}
		Matrix(const Matrix& mat)
		{
			this->set(mat.getValue());
		}
		virtual ~Matrix() {}
	public:
		/**
		*	矩阵相加
		*/
		Matrix operator+(const Matrix& mat)
		{

			Matrix result;

			int32_t len = Width * Height;
			for (int32_t i = 0; i < len; i++)
			{
				result.setValue(i, base::getValue(i) + mat.getValue(i));
			}

			return result;
		}
		/**
		*	矩阵相减
		*/
		Matrix operator-(const Matrix& mat)
		{

			Matrix result;

			int32_t len = Width * Height;
			for (int32_t i = 0; i < len; i++)
			{
				result.setValue(i, base::getValue(i) - mat.getValue(i));
			}

			return result;
		}
		/**
		*	矩阵相乘
		*/
		Matrix operator*(const Matrix& mat)
		{
			Matrix result;

			float val = 0;
			for (int32_t bh = 0; bh < Height; bh++)
			{
				for (int32_t mw = 0; mw < Height; mw++)
				{
					val = 0;
					for (int32_t mh = 0; mh < Width; mh++)
					{
						float a = base::getValue(bh, mh);
						float b = mat.getValue(mh, mw);
						val += a * b;
					}
					result.setValue(bh, mw, val);
				}
			}

			return result;
		}
		/**
		*	矩阵相加
		*/
		Matrix& operator+=(const Matrix& mat)
		{
			int32_t len = Width * Height;
			for (int32_t i = 0; i < len; i++)
			{
				base::setValue(i, base::getValue(i) + mat.getValue(i));
			}

			return *this;
		}
		/**
		*	矩阵相减
		*/
		Matrix& operator-=(const Matrix& mat)
		{
			int32_t len = Width * Height;
			for (int32_t i = 0; i < len; i++)
			{
				base::setValue(i, base::getValue(i) - mat.getValue(i));
			}

			return *this;
		}
		/**
		*	矩阵扩展系数
		*/
		Matrix& operator*=(float k)
		{
			for (int32_t i = 0; i < Height; i++)
			{
				for (int32_t j = 0; j < Width; j++)
				{
					int32_t index = i * Width + j;
					float value = base::getValue(index) * k;
					base::setValue(index, value);
				}
			}

			return *this;
		}
		/**
		*	矩阵扩展系数
		*/
		Matrix operator*(float k)
		{
			Matrix mat;

			for (int32_t i = 0; i < Height; i++)
			{
				for (int32_t j = 0; j < Width; j++)
				{
					float value = base::getValue(i * Width + j) * k;
					mat.setValue(i, j, value);
				}
			}

			return mat;
		}
		/**
		*	矩阵扩展系数
		*/
		Matrix operator/(float k)
		{
			Matrix mat;

			for (int32_t i = 0; i < Height; i++)
			{
				for (int32_t j = 0; j < Width; j++)
				{
					float value = base::getValue(i * Width + j) / k;
					mat.setValue(i, j, value);
				}
			}

			return mat;
		}
	public:
		/**
		*	复制矩阵元素
		*/
		Matrix& operator=(const Matrix& mat)
		{
			int32_t len = Width * Height;
			for (int32_t i = 0; i < len; i++)
			{
				base::setValue(i, mat.getValue(i));
			}

			return *this;
		}
		/**
		*	获取转置矩阵
		*/
		Matrix getTranspose() const
		{
			Matrix mat;

			for (int32_t i = 0; i < Height; i++)
			{
				for (int32_t j = 0; j < Width; j++)
				{
					mat.setValue(j, i, base::getValue(i * Width + j));
				}
			}

			return mat;
		}
		/**
		*	行列式的值
		*/
		float getDetValue() const
		{
			assert(Width == Height);

			return getDeterminantMagnitude(Determinant<Width>(base::getValue()));
		}
		/**
		*	余子式
		*/
		Matrix<T, Height - 1, Width - 1> getMinor(int32_t i, int32_t j) const
		{
			assert(i >= 0 && j >= 0 && i < Height && j < Width);

			Matrix<T, Height - 1, Width - 1> mat;
			int dn = 0;
			int dm = 0;

			for (int h = 0; h < Height; h++)
			{
				if (h == i)
				{
					dn++;
					continue;
				}
				dm = 0;
				for (int w = 0; w < Width; w++)
				{
					if (w == j)
					{
						dm++;
						continue;
					}
					mat.setValue(h - dn, w - dm, base::getValue(h, w));
				}
			}

			return mat;
		}
		/**
		*	伴随矩阵
		*/
		Matrix getAdjoint() const
		{
			assert(Width == Height);

			float det = this->getDetValue();

			assert(det != 0);

			Matrix mat;

			if (Width == 1)
			{
				mat.setValue(0, 0, 1 / base::getValue((size_t)0, (size_t)0));
				return mat;
			}

			for (int i = 0; i < Height; i++)
			{
				for (int j = 0; j < Width; j++)
				{
					Matrix<T, Height - 1, Width - 1> minor = this->getMinor(i, j);
					float k = 1;
					if (i != j)
					{
						if ((i + j) % 2 == 0) k = 1.0f;
						else k = -1.0f;
					}
					mat.setValue(i, j, k * minor.getDetValue());
				}
			}

			return mat;
		}
		/**
		*	逆矩阵
		*/
		Matrix getInverse() const
		{
			assert(Width == Height);

			float det = this->getDetValue();

			assert(det != 0);

			Matrix adjoint = this->getAdjoint();
			Matrix transpose = adjoint.getTranspose();
			return transpose / det;
		}
	};
}