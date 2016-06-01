#pragma once

#include "Human.h"

#include <map>

namespace slg
{
	class Human;
	// ��ͥ
	class Family
	{
	public:
		Family();
		~Family();
	public:
		// ����
		const Human* getFather();
		void setFather(const Human* father);

		// ĸ��
		const Human* getMonther();
		void setMonther(const Human* monther);

		// ��Ӻ���
		void addChild(const Human* child);
		// �Ƴ�����
		void removeChild(const Human* child);
		// ���Һ���
		const Human* getChild(const char* name);
	protected:
		// ��
		Human* _father;
		// ĸ
		Human* _monther;
		// ����
		std::map<std::string, Human*> _children;
	};
}