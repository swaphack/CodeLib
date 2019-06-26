#pragma once

namespace game
{

	/**
	*	����
	*/
	enum class AttributeType : int
	{
		/**
		*	����
		*/
		Name,
		/**
		*	�Ա�
		*/
		Gender,
		/**
		*	��������
		*/
		Birthday,
		/**
		*	����
		*/
		Country,
		/**
		*	����
		*/
		City,
		/**
		*	�������ֲ�
		*/
		Club,
		/**
		*	��������
		*/
		Team,
		/**
		*	���ֵ
		*/
		Max,
	};

	/**
	*	�ռ�����
	*/
	enum class SpaceType : int
	{
		/**
		*	����x
		*/
		PositionX,
		/**
		*	����y
		*/
		PositionY,
		/**
		*	����z
		*/
		PositionZ,
		/**
		*	����
		*/
		Length,
		/**
		*	���
		*/
		Width,
		/**
		*	�߶�
		*/
		Height,
		/**
		*	���ֵ
		*/
		Max,
	};
}