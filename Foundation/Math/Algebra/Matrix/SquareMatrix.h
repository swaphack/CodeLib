#pragma once

namespace math
{
	/**
	*	方阵
	*/
	template<const int Order>
	class SquareMatrix :  public Matrix<float, Order, Order>
	{
	public:
		SquareMatrix()
		{
		}
		SquareMatrix(const Matrix<float, Order, Order>& mat)
		{
			this->assign(mat.getValue());
		}
		SquareMatrix(const float* value)
		{
			this->assign(value);
		}
		virtual ~SquareMatrix()
		{

		}
	public:
		operator Determinant<Order>()
		{
			return Determinant<Order>(this->getValue());
		}
		/**
		*	行列式的值
		*/
		float getDetValue()
		{
			Determinant<Order> det = *this;
			return getDeterminantMagnitude(det);
		}
	public:
		/**
		*	余子式
		*/
		SquareMatrix<Order - 1> getMinor(int32_t i, int32_t j) const
		{
			assert(i >= 0 && j >= 0 && i < Order&& j < Order);

			SquareMatrix<Order - 1> mat;
			int dn = 0;
			int dm = 0;

			for (int h = 0; h < Order; h++)
			{
				if (h == i)
				{
					dn++;
					continue;
				}
				dm = 0;
				for (int w = 0; w < Order; w++)
				{
					if (w == j)
					{
						dm++;
						continue;
					}
					mat.setValue(h - dn, w - dm, this->getValue(h, w));
				}
			}

			return mat;
		}
		/**
		*	伴随矩阵
		*/
		SquareMatrix getAdjoint()
		{
			float det = this->getDetValue();

			assert(det != 0);

			SquareMatrix mat;

			if (Order == 1)
			{
				mat.setValue(0, 0, 1 / this->getValue((size_t)0, (size_t)0));
				return mat;
			}

			for (int i = 0; i < Order; i++)
			{
				for (int j = 0; j < Order; j++)
				{
					SquareMatrix<Order - 1> minor = this->getMinor(i, j);
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
		*	获取转置矩阵
		*/
		SquareMatrix getTranspose()
		{
			SquareMatrix mat;

			for (int32_t i = 0; i < Order; i++)
			{
				for (int32_t j = 0; j < Order; j++)
				{
					mat.setValue(j, i, this->getValue(i * Order + j));
				}
			}

			return mat;
		}
		/**
		*	逆矩阵
		*/
		SquareMatrix getInverse()
		{
			float det = this->getDetValue();

			assert(det != 0);

			SquareMatrix adjoint = this->getAdjoint();
			SquareMatrix transpose = adjoint.getTranspose();
			return transpose / det;
		}
	};

	typedef SquareMatrix<2> SquareMatrix2;
	typedef SquareMatrix<3> SquareMatrix3;
	typedef SquareMatrix<4> SquareMatrix4;
}