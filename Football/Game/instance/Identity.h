#pragma once

#include <string>

namespace game
{
	class Identity
	{
	public:
		Identity();
		virtual ~Identity();
	public:
		/**
		*	��ȡ���
		*/
		int getID();
		/**
		*	���ñ��
		*/
		void setID(int nID);
		/**
		*	��ȡ����
		*/
		const char* getName();
		/**
		*	��������
		*/
		void setName(const char* name);
	private:
		int	_id;
		std::string _name;
	};
}