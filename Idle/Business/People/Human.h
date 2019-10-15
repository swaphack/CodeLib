#pragma once

#include "../Core/import.h"
#include <map>

namespace business
{
	class HumanRelationNet;

	// 性别
	enum class Gender
	{
		// 男
		Male,
		// 女
		Female,
	};

	// 人
	class Human : public Object
	{
	public:
		Human();
		virtual~Human();
	public: 
		// 性别
		void setGender(Gender eGender);
		Gender getGender();
		// 是否男性
		bool isMale();
		// 是否女性
		bool isFemale();
	protected:
	private:
		// 性别
		Gender m_eGender;
		// 关系
		HumanRelationNet* m_pRelationNet = nullptr;
	};	
}