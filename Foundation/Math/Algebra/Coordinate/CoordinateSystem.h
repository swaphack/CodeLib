#pragma once
#include "Algebra/Matrix/SquareMatrix.h"
#include "Basic/Array.h"

namespace math
{
	/**
	*	坐标系
	*/
	template<const int Count>
	class CoordinateSystem
	{
	public:
		CoordinateSystem()
		{

		}
		CoordinateSystem(const CoordinateSystem& cs)
		{
			_systemMatrix = cs.getMatrix();
		}
		CoordinateSystem(const SquareMatrixF<Count + 1>& matrix)
		{
			_systemMatrix = matrix;
		}
		virtual ~CoordinateSystem()
		{

		}
	public:
		/**
		*	维度个数
		*/
		int getDimensionCount() const
		{
			return Count;
		}
		/**
		*	行系数
		*/
		Array<float, Count + 1> getRow(int nRow)
		{
			return _systemMatrix.getRow(nRow);
		}
		/**
		*	列系数
		*/
		Array<float, Count + 1> getColumn(int nColumn)
		{
			return _systemMatrix.getColumn(nColumn);
		}
		/**
		*	设置列系数
		*/
		void setColumn(int nColumn, const Array<float, Count + 1>& value)
		{
			return _systemMatrix.setColumn(nColumn, value);
		}
		/**
		*	坐标系矩阵
		*/
		const SquareMatrixF<Count + 1>& getMatrix() const
		{
			return _systemMatrix;
		}
		/**
		*	坐标系矩阵
		*/
		SquareMatrixF<Count + 1>& getMatrix()
		{
			return _systemMatrix;
		}
		/**
		*	设置坐标系矩阵
		*	有时坐标系矩阵不是固定，可改变
		*/
		void setMatrix(const SquareMatrixF<Count + 1>& matrix)
		{
			_systemMatrix = matrix;
		}

		/**
		*	齐次坐标系
		*/
		CoordinateSystem<Count + 1> getHomogeneousCoordinateSystem()
		{
			CoordinateSystem<Count + 1> system;
			SquareMatrixF<Count + 2> matrix;

			for (int i = 0; i < Count; i++)
			{
				for (int j = 0; j < Count; j++)
				{
					matrix.setValue(i, j, _systemMatrix.getValue(i, j));
				}
			}

			matrix.setValue(Count + 1, Count + 1, 1);
		}
	protected:
		/**
		*	坐标系矩阵
		*/
		SquareMatrixF<Count + 1> _systemMatrix;
	};
}