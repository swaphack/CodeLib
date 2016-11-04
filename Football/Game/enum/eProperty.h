#pragma once

namespace game
{

	/**
	*	��������
	*/
	enum ePersonProperty
	{
		/**
		*	�Ա�
		*/
		EPP_GENDER,
		/**
		*	��������
		*/
		EPP_BIRTHDAY,
		/**
		*	����
		*/
		EPP_COUNTRY,
		/**
		*	�������ֲ�
		*/
		EPP_CLUB,
		/**
		*	��������
		*/
		EPP_TEAM,
		/**
		*	���ֵ
		*/
		EPP_MAX,
	};

	/**
	*	��������
	*/
	enum eBodyProperty
	{
		/**
		*	����x
		*/
		EBP_POSITION_X = EPP_MAX,
		/**
		*	����y
		*/
		EBP_POSITION_Y,
		/**
		*	����z
		*/
		EBP_POSITION_Z,
		/**
		*	����
		*/
		EBP_VOLUME_LENGTH,
		/**
		*	���
		*/
		EBP_VOLUME_WIDTH,
		/**
		*	�߶�
		*/
		EBP_VOLUME_HEIGHT,
		/**
		*	���ֵ
		*/
		EBP_MAX,
	};
}