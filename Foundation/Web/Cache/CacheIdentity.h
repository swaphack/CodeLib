#pragma once

#include "system.h"

#include <string>

namespace web
{
	// �������
	class CacheIdentity : public sys::Name
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