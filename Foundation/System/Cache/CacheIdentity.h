#pragma once

#include "Base/import.h"
#include <string>

namespace sys
{
	// �������
	class CacheIdentity : public Name
	{
	public:
		CacheIdentity();
		virtual ~CacheIdentity();
	public:
		// ��ʶid
		int getID();
		// �������
		void setInControl(bool status);
		bool isInControl();
	protected:
		// ����id����cachemgr����
		void makeID();
	private:
		// ��ʶid
		int _id;
		// �Ƿ��ڻ��������
		bool _bInCacheControl;
	};
}