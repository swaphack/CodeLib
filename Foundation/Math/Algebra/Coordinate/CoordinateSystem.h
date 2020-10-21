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
		CoordinateSystem(const SquareMatrixF<Count>& matrix)
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
		int getDimensionCount()
		{
			return Count;
		}
		/**
		*	��ϵ��
		*/
		ArrayF<Count> getRow(int nRow)
		{
			return _systemMatrix.getRow(nRow);
		}
		/**
		*	��ϵ��
		*/
		ArrayF<Count> getColumn(int nRow)
		{
			return _systemMatrix.getColumn(nRow);
		}
		/**
		*	����ϵ����
		*/
		const SquareMatrixF<Count>& getMatrix() const
		{
			return _systemMatrix;
		}
		/**
		*	����ϵ����
		*/
		SquareMatrixF<Count>& getMatrix()
		{
			return _systemMatrix;
		}
		/**
		*	��������ϵ����
		*	��ʱ����ϵ�����ǹ̶����ɸı�
		*/
		void setMatrix(const SquareMatrixF<Count>& matrix)
		{
			_systemMatrix = matrix;
		}

		/**
		*	�������ϵ
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
		*	����ϵ����
		*/
		SquareMatrixF<Count> _systemMatrix;
	};
}