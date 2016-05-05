#pragma once

#include "../DataBase/DataBase.h"

#include "BusinessGlobal.h"

namespace user
{
	class BusinessDataBase : public DataBase
	{
	public:
		BusinessDataBase(long type, const char* url);
		virtual ~BusinessDataBase();
	public:
		virtual void load();

		virtual void save();
	public:

	};
}