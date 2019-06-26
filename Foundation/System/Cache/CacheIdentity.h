#pragma once

#include "Base/import.h"

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
		int32 getID();
		// �������
		void setInControl(bool status);
		bool isInControl();
	protected:
		// ����id����cachemgr����
		void makeID();
	private:
		// ��ʶid
		int32 _id;
		// �Ƿ��ڻ��������
		bool _bInCacheControl;
	};
}