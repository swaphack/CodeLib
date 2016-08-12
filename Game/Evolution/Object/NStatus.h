#pragma once

#include "NMark.h"
#include <string>

namespace nature
{
	class NObject;
	class NStatus;
	typedef void (NObject::*NStatusChanged)(NStatus* pStatus);

	// ״̬
	class NStatus : public NMark
	{
	public:
		NStatus();
		~NStatus();
	public:
		// ��ǰ״̬
		void setStatus(bool status);
		bool getStatus();

		// ע�����
		void registerChangedHandler(NObject* pTarget, NStatusChanged handler);
		// ���ü���
		void resetChangedHandler();
	protected:
		virtual void onRunChangedHand();
	private:
		bool _status; // ��ǰ״̬
		std::pair<NObject*, NStatusChanged> _trigger; // ������
	};
}