#pragma once

namespace game
{

	/**
	*	����λ��
	*/
	enum ePosition
	{
		EP_NONE,
		/**
		*	����Ա
		*/
		EP_GOALKEEPER,
		/**
		*	�����
		*/
		EP_LEFT_BACK,
		/**
		*	�Һ���
		*/
		EP_RIGHT_BACK,
		/**
		*	����
		*/
		EP_CENTER_BACK,
		/**
		*	��ǰ��
		*/
		EP_LEFT_MIDFIELDER,
		/**
		*	��ǰ��
		*/
		EP_RIGHT_MIDFIELDER,
		/**
		*	ǰ��
		*/
		EP_MIDFIELDER,
		/**
		*	ǰ��
		*/
		EP_ATTACKING_MIDFIELDER,
		/**
		*	����
		*/
		EP_DEFENDING_MIDFIELDER,
		/**
		*	���ڷ�
		*/
		EP_INSIDE_LEFT_FORWARD,
		/**
		*	���ڷ�
		*/
		EP_INSIDE_RIGHT_FORWARD,
		/**
		*	��߷�
		*/
		EP_OUTSIDE_LEFT_FORWARD,
		/**
		*	�ұ߷�
		*/
		EP_OUTSIDE_RIGHT_FORWARD,
		/**
		*	Ӱ��ǰ��
		*/
		EP_SECOND_STRIKER,
		/**
		*	�з�
		*/
		EP_STRIKER,
	}
}