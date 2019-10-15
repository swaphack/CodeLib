#pragma once

#include "../Core/import.h"
#include <map>

namespace business
{
	class HumanRelationNet;

	// �Ա�
	enum class Gender
	{
		// ��
		Male,
		// Ů
		Female,
	};

	// ��
	class Human : public Object
	{
	public:
		Human();
		virtual~Human();
	public: 
		// �Ա�
		void setGender(Gender eGender);
		Gender getGender();
		// �Ƿ�����
		bool isMale();
		// �Ƿ�Ů��
		bool isFemale();
	protected:
	private:
		// �Ա�
		Gender m_eGender;
		// ��ϵ
		HumanRelationNet* m_pRelationNet = nullptr;
	};	
}