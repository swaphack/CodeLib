#pragma once

#include "Member.h"

namespace slg
{
	// ��֯
	class Organization
	{
	public:
		virtual ~Organization();
	public:
		// ��ӳ�Ա
		void addMember(Member* member);
		// �Ƴ���Ա
		void removeMember(Member* member);
		// �Ƴ����г�Ա
		void removeAllMembers();
	protected:
	private:
	};
}