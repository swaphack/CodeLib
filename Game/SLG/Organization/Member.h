#pragma once

#include "../Data/Target.h"
#include <list>

namespace slg
{
	// 组织成员
	class Member
	{
	public:
		Member(Target* target);
		virtual ~Member();
	public:
		const Target* getTarget();

		// 上级
		void addSuperior(Member* member);
		void removeSuperior(Member* member);
		void removeAllSuperiors();

		// 平级
		void addEqual(Member* member);
		void removeEqual(Member* member);
		void removeAllEquals();

		// 下级
		void addSubordinate(Member* member);
		void removeSubordinate(Member* member);
		void removeAllSubordinates();
	private:
		// 上级
		std::list<Member*> _superiors;
		// 平级
		std::list<Member*> _equals;
		// 下级
		std::list<Member*> _subordinates;
	};
}