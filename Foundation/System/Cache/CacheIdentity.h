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
		int32_t getID();
		// �������
		void setInControl(bool status);
		bool isInControl() const;
	protected:
		// ����id����cachemgr����
		void makeID();
	private:
		// ��ʶid
		int32_t _id;
		// �Ƿ��ڻ��������
		bool _bInCacheControl;
	};
}