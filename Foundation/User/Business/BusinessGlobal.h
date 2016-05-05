#pragma once

#include "../Data/import.h"
#include "../Logger/import.h"
#include "../DataBase/import.h"

namespace user
{

#define CREATE_GLOBAL_INSTANCE(var, func, type) \
private: \
	static type* s_##var; \
public: \
	static type* BusinessGlobal::get##func() \
	{ \
	if (s_##var == nullptr) \
	{ \
		s_##var = new type(); \
	} \
	return s_##var; \
	}

#define DEFINE_GLOBAL_INSTANCE_MEMBER(var, type) \
	type* BusinessGlobal::s_##var = nullptr;

#define GET_GLOBAL_INSTANCE(func) BusinessGlobal::get##func()


	// loggers
	DATABASE_DEFINE(Logger, ILogger);

	// databases
	DATABASE_DEFINE(DataBase, IDataBase);

	class BusinessGlobal
	{
	public:
		virtual void init();
	public:
		// loggers
		CREATE_GLOBAL_INSTANCE(Loggers, Loggers, Loggers);

		// databases
		CREATE_GLOBAL_INSTANCE(DataBases, DataBases, DataBases);
	};
}