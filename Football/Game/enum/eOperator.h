#pragma once

namespace game
{
	/**
	*	����������
	*/
	enum eOperator
	{
		/**
		*	����
		*/
		EO_EQUAL = 0,
		/**
		*	������
		*/
		EO_NOTEQUAL = 1,
		/**
		*	����
		*/
		EO_GREATER = 2,
		/**
		*	С��
		*/
		EO_LESS = 3,
		/**
		*	�����
		*/
		EO_GREATER_OR_EQUAL = 4,
		/**
		*	С����
		*/
		EO_LESS_OR_EQUAL = 5,
	};
}