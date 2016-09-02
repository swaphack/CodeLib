#pragma once

namespace game
{
	class IContract;
	/**
	*	����
	*/
	class IFinance
	{
	public:
		virtual ~IFinance() {}
	public:
		/**
		*	���һ��Э��
		*/
		virtual void addContract(IContract* pContract) = 0;
		/**
		*	�Ƴ�һ��Э��
		*/
		virtual void removeContract(IContract* pContract) = 0;
		/**
		*	����
		*/
		virtual int getBlance() const = 0;
	};
}