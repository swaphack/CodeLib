#pragma once

#include "Framework/Object.h"
#include "Base/Protocol.h"

namespace sys
{
	class Event : public Object, public Name
	{
	public:
		Event();
		virtual ~Event();
	public:
		/**
		*  �����Զ�������
		*/
		void setUserData(void* data);
		/**
		*  �Զ�������
		*/
		void* getUserData() const;
	private:
		void* _userData = nullptr;
	};
}
