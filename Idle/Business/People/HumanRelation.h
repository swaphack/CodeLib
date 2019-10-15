#pragma once

#include "../Core/import.h"

namespace business
{
	class Human;

	// ˫��
	class HumanParent : public Relation
	{
	public:
		HumanParent();
		virtual ~HumanParent();
	public:
		// ����
		Human* getFather();
		void setFather(Human* pFather);
		// ĸ��
		Human* getMonther();
		void setMother(Human* pMother);
	private:

	};

	// ��ż
	class HumanSpouse : public Relation
	{
	public:
		HumanSpouse();
		virtual ~HumanSpouse();
	public:
		// ��ż
		Human* getSpouse();
		void setSpouse(Human* pSpouse);
	};

	// ����
	class HumanChildren : public Relation
	{
	public:
		HumanChildren();
		virtual ~HumanChildren();
	public:
	private:
	};

	// ����
	class HumanFriend : public Relation
	{
	public:
		HumanFriend();
		virtual ~HumanFriend();
	public:

	protected:
	private:
	};

	// ͬ��
	class HumanColleague : public Relation
	{
	public:
	protected:
	private:
	};

	// ͬѧ
	class HumanClassmate : public Relation
	{

	};

	// ��ʦ
	class HumanTeacher : public Relation
	{
	public:
	protected:
	private:
	};

	// �˼ʹ�ϵ
	class HumanRelationNet : public RelationNet
	{
	public:
		HumanRelationNet();
		virtual ~HumanRelationNet();
	public:
	};
}