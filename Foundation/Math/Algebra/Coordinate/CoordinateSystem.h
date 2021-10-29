#pragma once
#include "Algebra/Matrix/SquareMatrix.h"
#include "Basic/Array.h"

namespace math
{
	/**
	*	����ϵ
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
		*	ά�ȸ���
		*/
		int getDimensionCount() const
		{
			return Count;
		}
		/**
		*	��ϵ��
		*/
		Array<float, Count + 1> getRow(int nRow)
		{
			return _systemMatrix.getRow(nRow);
		}
		/**
		*	��ϵ��
		*/
		Array<float, Count + 1> getColumn(int nColumn)
		{
			return _systemMatrix.getColumn(nColumn);
		}
		/**
		*	������ϵ��
		*/
		void setColumn(int nColumn, const Array<float, Count + 1>& value)
		{
			return _systemMatrix.setColumn(nColumn, value);
		}
		/**
		*	����ϵ����
		*/
		const SquareMatrixF<Count + 1>& getMatrix() const
		{
			return _systemMatrix;
		}
		/**
		*	����ϵ����
		*/
		SquareMatrixF<Count + 1>& getMatrix()
		{
			return _systemMatrix;
		}
		/**
		*	��������ϵ����
		*	��ʱ����ϵ�����ǹ̶����ɸı�
		*/
		void setMatrix(const SquareMatrixF<Count + 1>& matrix)
		{
			_systemMatrix = matrix;
		}

		/**
		*	�������ϵ
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
		*	����ϵ����
		*/
		SquareMatrixF<Count + 1> _systemMatrix;
	};
}