#pragma once

namespace game
{
	class IBill;
	/**
	*	����
	*/
	class IFinance
	{
	public:
		virtual ~IFinance() {}
	public:
		/**
		*	���Ǯ��
		*/
		virtual void addMoney(unsigned int money) = 0;
		/**
		*	����Ǯ��
		*/
		virtual void subMoney(unsigned int money) = 0;
		/**
		*	����
		*/
		virtual int getBlance() const = 0;
		/**
		*	�Ƿ����
		*/
		virtual bool isDeficit() const = 0;
		/**
		*	��ȡ�������еĲ���֧��
		*/
		virtual int getExpenditure() const = 0;
		/**
		*	��ȡ�������еĲ�������
		*/
		virtual int getIncome() const = 0;
		/**
		*	�����˵�
		*/
		virtual void handle(IBill* pBill) = 0;
	};
}