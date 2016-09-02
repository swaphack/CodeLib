#pragma once

namespace game
{
	/**
	*	����
	*/
	class IRank
	{
	public:
		virtual ~IRank() {}
	public:
		/**
		*	����������
		*/
		virtual int count() const = 0;
		/**
		*	������������ʼ��
		*/
		virtual void reset() const = 0;
		/**
		*	��������
		*/
		virtual void update() const = 0;
		/**
		*	��ȡָ����ŵ�����
		*/
		virtual int getPosition(int nID) const = 0;
		/**
		*	��ȡָ��λ�õ�����id
		*/
		virtual int getID(int nPosition) const = 0;
	};
}