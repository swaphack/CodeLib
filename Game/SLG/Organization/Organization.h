#pragma once

#include "Member.h"

namespace slg
{
	// 组织
	class Organization
	{
	public:
		virtual ~Organization();
	public:
		// 添加成员
		void addMember(Member* member);
		// 移除成员
		void removeMember(Member* member);
		// 移除所有成员
		void removeAllMembers();
	protected:
	private:
	};
}