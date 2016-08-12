#pragma once

#include <string>

namespace nature
{
	class NMark
	{
	public:
		NMark();
		virtual ~NMark();
	public:
		// ���ñ��
		void setID(int ID);
		// ��ȡ���
		int getID();
		// ��������
		void setName(const char* name);
		// ��ȡ����
		const char* getName();
	private:
		int _ID; // ���
		std::string _name; // ����
	};
}

