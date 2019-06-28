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
		virtual int count() const;
		/**
		*	������������ʼ��
		*/
		virtual void reset() const;
		/**
		*	��������
		*/
		virtual void update() const;
		/**
		*	��ȡָ����ŵ�����
		*/
		virtual int getPosition(int nID) const;
		/**
		*	��ȡָ��λ�õ�����id
		*/
		virtual int getID(int nPosition) const;
	};
}