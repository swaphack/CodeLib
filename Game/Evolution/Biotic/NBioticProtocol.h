#pragma once

#include "NOrganism.h"
#include "NMetabolismProtocol.h"

namespace nature
{
	/**
	*	����ͨ��
	*��	1����������������Ľṹ��
	*	��΢����һ��ʲô�������Ľṹ��Ҳ����˵ϸ����������ṹ�͹��ܵĻ�����λ��
	*	2���������ܽ����³´�л��
	*	3����������������
	*	4�����������Ӧ���ԡ�
	*	5������������ֳ�ͷ�����
	*	6������������Ŵ��ͱ�������ԡ�
	*	7������������һ���̶�����Ӧ������Ӱ�컷����
	*/
	class NBioticProtocol 
	{
	public:
		NBioticProtocol() {}
		virtual ~NBioticProtocol() {}
	public:
		// ��ȡ����
		virtual const NOrganism* getOrganism() = 0;

		// ͬ��, ����д
		virtual bool input(NObject* pObject) = 0;
		// ע���컯�ص�
		virtual void setOutputCallback(NObject* pTarget, OutputCallback callback) {};

		// ����
		virtual void growing() = 0;

		// Ӧ��
		virtual bool touch(NObject* pObject) = 0;
		// ע��Ӧ�������ص�
		virtual void setFeedbackCallback(NObject* pTarget, OutputCallback callback) {};
	};
}