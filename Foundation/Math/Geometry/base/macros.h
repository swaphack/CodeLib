#pragma once

namespace math 
{
	/**
	*	����ֱ�ߵ�λ�ù�ϵ
	*/
	enum class PointAndLinePositionType
	{
		NONE,
		// ����
		INCLUDE,
		// �����
		EXLUDE_LEFT,
		// ���ұ�
		EXLUDE_RIGHT,
		
	};

	/**
	*	��ֱ�ߵ�λ�ù�ϵ
	*/
	enum class TwoLinesPositionType
	{
		// ƽ��
		PARALLEL,
		// �ཻ
		INTERSECT,
	};
}