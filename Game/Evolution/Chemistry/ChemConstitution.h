#pragma once

#include "macros.h"

#include <map>
#include <set>
#include <string>

namespace nature
{
	// Ԫ����Ϣ {Ԫ��id,Ԫ�ظ���}
	typedef std::map<int, int> Elements;

	/**
	*	��ѧ�ṹ(һ�����ʵķ��ű�ʶ)
	*/
	class ChemConstitution
	{
	public:
		ChemConstitution();
		virtual ~ChemConstitution();
	public:
		// ���ñ��ʽ
		virtual void setExpression(const char* expression);
		// ��ȡ���ʽ
		const char* getExpression();
	protected:// ���ʽ
		std::string _expression;
	};

	/**
	*	ԭ��
	*	��׼:Ag
	*/
	class Atom : public ChemConstitution
	{
	public:
		Atom();
		virtual ~Atom();
	public:
		// ���ñ��ʽ
		virtual void setExpression(const char* expression);
		// ��ȡԪ�ر�ʶ
		int getElement();
	private:
		// �����ṹ
		void parseConstitution();
	private:
		// Ԫ��
		int _element;
	};

	/**
	*	����
	*	��׼:H2, Al(OH)3
	*/
	class Molecule : public ChemConstitution
	{
	public:
		Molecule();
		virtual ~Molecule();
	public:
		// ���ñ��ʽ
		virtual void setExpression(const char* expression);
		// ����Ԫ��
		Elements::const_iterator elementBegin();
		Elements::const_iterator elementEnd();
	private:
		// �����ṹ
		void parseConstitution();
	private:
		// ����Ԫ�� {Ԫ�أ�����}
		Elements _elements;
	};

	/**
	*	����
	*	��׼:NH4+,AL3+
	*/
	class Hydrogenion : public ChemConstitution
	{
	public:
		Hydrogenion();
		virtual	~Hydrogenion();
	public:
		// ���ñ��ʽ
		virtual void setExpression(const char* expression);
		// ����Ԫ��
		Elements::const_iterator elementBegin();
		Elements::const_iterator elementEnd();
		// ��ȡ�������
		int getCharge();
	private:
		// �����ṹ,δ���
		void parseConstitution();
	private:
		// ����Ԫ�� {Ԫ�أ�����}
		Elements _elements;
		// �������
		int _charge;
	};
}