#pragma once

#include "macros.h"

#include <string>

namespace tribe
{
	// ����
	class Human
	{
	public:
		Human();
		virtual ~Human();
	public:
		// ��ȡ������
		inline int getBirthday() const { return _birthday; }
		// ���ó�����
		inline void setBirthday(int val) { _birthday = val; }
		// ��ȡ������
		inline int getDeathday() const { return _deathday; }
		// ����������
		inline void setDeathday(int val) { _deathday = val; }
		// ��ȡ�Ա�
		inline int getSex() const { return _sex; }
		// �����Ա�
		inline void setSex(int val) { _sex = val; }
		// ��ȡ����
		inline std::string getName() const { return _name; }
		// ��������
		inline void setName(std::string val) { _name = val; }
	private:
		// ������
		int _birthday;
		// ������
		int _deathday;
		// �Ա�
		int _sex;
		// ����
		std::string _name;
	};
}