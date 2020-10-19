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
		*  设置自定义数据
		*/
		void setUserData(void* data);
		/**
		*  自定义数据
		*/
		void* getUserData() const;
	private:
		void* _userData = nullptr;
	};
}
