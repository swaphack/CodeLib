#pragma once

#include "macros.h"
#include "NBioticProtocol.h"
#include "NOrganism.h"

namespace nature
{
	/**
	*	����
	*/
	class NBiotic : public NObject, public NBioticProtocol, public NTimer
	{
	public:
		NBiotic();
		virtual ~NBiotic();
	public:
		// ��ʼ��
		virtual bool init();
		// ���£�����д
		virtual void update(float dt);

		// ��ȡ����
		virtual const NOrganism* getOrganism();

		// ͬ��������д
		virtual bool input(NObject* pObject);
		// ע���컯�ص�
		virtual void setOutputHandler(NObject* pTarget, OutputCallback callback);

		// ����
		virtual void growing();

		// Ӧ��
		virtual bool touch(NObject* pObject);
		// ע��Ӧ�������ص�
		virtual void setFeedbackCallback(NObject* pTarget, OutputCallback callback);
	protected:
		// ���û���
		void setOrganism(NOrganism* pOrganism);
		// �컯����
		void onOuputHandler(NObject* pObject);
		// ��������
		void onFeedbackHandler(NObject* pObject);
	private:
		// ����
		NOrganism* _organism;
		// �컯�ص�����
		std::pair<NObject*, OutputCallback> _outputCallback;
		// �����ص�����
		std::pair<NObject*, OutputCallback> _feedbackCallback;
	};
}