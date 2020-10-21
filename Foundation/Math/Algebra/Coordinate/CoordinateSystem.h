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
		CoordinateSystem(const SquareMatrixF<Count>& matrix)
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
		int getDimensionCount()
		{
			return Count;
		}
		/**
		*	行系数
		*/
		ArrayF<Count> getRow(int nRow)
		{
			return _systemMatrix.getRow(nRow);
		}
		/**
		*	列系数
		*/
		ArrayF<Count> getColumn(int nRow)
		{
			return _systemMatrix.getColumn(nRow);
		}
		/**
		*	坐标系矩阵
		*/
		const SquareMatrixF<Count>& getMatrix() const
		{
			return _systemMatrix;
		}
		/**
		*	坐标系矩阵
		*/
		SquareMatrixF<Count>& getMatrix()
		{
			return _systemMatrix;
		}
		/**
		*	设置坐标系矩阵
		*	有时坐标系矩阵不是固定，可改变
		*/
		void setMatrix(const SquareMatrixF<Count>& matrix)
		{
			_systemMatrix = matrix;
		}

		/**
		*	齐次坐标系
		*/
		CoordinateSystem<Count + 1> getHomogeneousCoordinateSystem()
		{
			CoordinateSystem<Count + 1> system;
			SquareMatrixF<Count + 1> matrix;

			for (int i = 0; i < Count; i++)
			{
				for (int j = 0; j < Count; j++)
				{
					matrix.setValue(i, j, _systemMatrix.getValue(i, j));
				}
			}

			matrix.setValue(Count, Count, 1);
		}
	protected:
		/**
		*	坐标系矩阵
		*/
		SquareMatrixF<Count> _systemMatrix;
	};
}