#pragma once

#include "macros.h"

namespace nature
{
	class NCell;
	typedef NCell* (NObject::*CreateCellHandler)();
	/**
	*	ϸ�� ��Ӣ������cell����û��ͳһ�Ķ��壬�Ƚ��ձ���ᷨ�ǣ�ϸ��������������Ľṹ�͹��ܵ�λ��
	*	��֪������֮��������������ϸ������ɣ������������Ҳ������ϸ���в������֡�
	*
	*	һ����˵��ϸ���Ⱦ��󲿷�΢�����Լ�ԭ��������һ��ϸ����ɣ�����ϸ������ߵ�ֲ����ߵȶ������Ƕ�ϸ�����
	*	ϸ���ɷ�Ϊԭ��ϸ�������ϸ�����࣬��Ҳ�������Ӧ��Ϊ���࣬����ԭ����ԭ��ϸ���Ĺź�ϸ������������Ϊ��֮���е�һ�ࡣ
	*	�о�ϸ����ѧ�Ƴ�Ϊϸ������ѧ��
	*	ϸ�����μ�΢������΢����ʼ�ܿ�������״���ֶ�����
	*	��Ҫ��ϸ������ϸ���ʹ��ɣ�������ϸ��Ĥ��
	*	�ߵ�ֲ��ϸ��Ĥ����ϸ���ڣ�ϸ�����г������壬������Ҷ�����Һ�ݣ����������塣
	*	����ϸ����ϸ���ڣ�ϸ�����г��������壬���ߵ�ֲ��ϸ�������ޡ�
	*	ϸ�����˶���Ӫ���ͷ�ֳ�Ȼ��ܡ�
	*/
	class NCell : public NOrganism
	{
	public:
		NCell();
		virtual ~NCell();
	public:
		// ϸ�����ѣ�����д
		virtual NCell* division();
		// ���£�����д
		virtual void update(float dt);
	protected:
		// �ж��Ƿ����ͬ������,����д
		virtual bool canAddInputTarget(NObject* pObject);
		// ͬ������
		virtual NObject* handInputTarget(TargetHandler* handler);
	};
}