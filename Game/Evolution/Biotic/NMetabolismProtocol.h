#pragma once

#include "macros.h"

namespace nature
{

	// �³´�л
	class NMetabolismProtocol
	{
	public:
		virtual ~NMetabolismProtocol() {}
	public:
		// ͬ��, ����д
		virtual bool input(NObject* pObject) = 0;
		// ע���컯�ص�
		virtual void setOutputHandler(NObject* pTarget, OutputCallback callback) {}
	};
}