#pragma once

#include "../macros.h"
#include "Family.h"

namespace slg
{
	// �Ա�
	enum SexType
	{
		// ��
		EST_MALE,
		// Ů
		EST_FEMALE,
	};

	// ����
	class Human : public Target, public LivingProtocol
	{
	public:
		Human();
		virtual ~Human();
	public:
		// ��ȡ�Ա�
		SexType getSexType();
		// �����Ա�
		void setSexType(SexType sexType);
		// ��ȡ��ͥ
		const Family* getFamily();
	private:
		// �Ա�
		SexType _sexType;
		// ��ͥ
		Family* _family;
	};
}