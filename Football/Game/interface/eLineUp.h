#pragma once

namespace game
{
	/**
	�������
	*/
	enum eLineUp
	{
		/**
		*	�ȴ��ϳ�
		*/
		ELU_WAIT = 0,
		/**
		*	�ϳ�
		*/
		ELU_PLAY = 1,
		/**
		*	�滻����
		*/
		ELU_REPLACE = 2,
		/**
		*	���������³�
		*/
		ELU_EXPULSION = 4,
	};
}