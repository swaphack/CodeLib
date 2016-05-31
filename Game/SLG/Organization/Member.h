#pragma once

#include "../Data/Target.h"
#include <list>

namespace slg
{
	// ��֯��Ա
	class Member
	{
	public:
		Member(Target* target);
		virtual ~Member();
	public:
		const Target* getTarget();

		// �ϼ�
		void addSuperior(Member* member);
		void removeSuperior(Member* member);
		void removeAllSuperiors();

		// ƽ��
		void addEqual(Member* member);
		void removeEqual(Member* member);
		void removeAllEquals();

		// �¼�
		void addSubordinate(Member* member);
		void removeSubordinate(Member* member);
		void removeAllSubordinates();
	private:
		// �ϼ�
		std::list<Member*> _superiors;
		// ƽ��
		std::list<Member*> _equals;
		// �¼�
		std::list<Member*> _subordinates;
	};
}