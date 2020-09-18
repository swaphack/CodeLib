#pragma once

#include <cstdint>

#include "Basic/Array2D.h"
#include "Algebra/Determinant/Determinant.h"
#include <map>

namespace math
{
	/**
	*	����
	*/
	template<typename T, const uint32_t Height, const uint32_t Width>
	struct Matrix : public Array2D<T, Height, Width>
	{
		typedef Array2D<T, Height, Width> base;
	public:
		Matrix() 
		{

		}
		Matrix(const float* value) 
		{
			this->assign(value);
		}
		Matrix(const Matrix& mat)
		{
			this->assign(mat.getValue());
		}
		virtual ~Matrix() {}
	public:
		/**
		*	�������
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
		*	�������
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
		*	�������
		*/
		Matrix operator*(const Matrix& mat)
		{
			assert(Width == mat.getHeight());

			std::map<int, Array<T, Width>> mapRow;
			std::map<int, Array<T, Height>> mapColumn;

			for (int i = 0; i < Height; i++)
			{
				mapRow[i] = this->getRow(i);
				mapColumn[i] = mat.getColumn(i);
			}

			Matrix result;

			for (int i = 0 ; i < Height; i++)
			{
				for (int j = 0; j < mat.getWidth(); j++)
				{
					float value = mapRow[i] * mapColumn[j];
					result.setValue(i, j, value);
				}
			}

			return result;
		}
		/**
		*	�������
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
		*	�������
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
		*	������չϵ��
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
		*	������չϵ��
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
		*	������չϵ��
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
		*	���ƾ���Ԫ��
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
		*	��ȡת�þ���
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
		*	����ʽ
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
		
	};
}