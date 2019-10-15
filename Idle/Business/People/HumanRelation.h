#pragma once

#include "../Core/import.h"

namespace business
{
	class Human;

	// 双亲
	class HumanParent : public Relation
	{
	public:
		HumanParent();
		virtual ~HumanParent();
	public:
		// 父亲
		Human* getFather();
		void setFather(Human* pFather);
		// 母亲
		Human* getMonther();
		void setMother(Human* pMother);
	private:

	};

	// 配偶
	class HumanSpouse : public Relation
	{
	public:
		HumanSpouse();
		virtual ~HumanSpouse();
	public:
		// 配偶
		Human* getSpouse();
		void setSpouse(Human* pSpouse);
	};

	// 孩子
	class HumanChildren : public Relation
	{
	public:
		HumanChildren();
		virtual ~HumanChildren();
	public:
	private:
	};

	// 朋友
	class HumanFriend : public Relation
	{
	public:
		HumanFriend();
		virtual ~HumanFriend();
	public:

	protected:
	private:
	};

	// 同事
	class HumanColleague : public Relation
	{
	public:
	protected:
	private:
	};

	// 同学
	class HumanClassmate : public Relation
	{

	};

	// 老师
	class HumanTeacher : public Relation
	{
	public:
	protected:
	private:
	};

	// 人际关系
	class HumanRelationNet : public RelationNet
	{
	public:
		HumanRelationNet();
		virtual ~HumanRelationNet();
	public:
	};
}