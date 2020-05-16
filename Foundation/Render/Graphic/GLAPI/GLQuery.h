#pragma once
#include "macros.h"

namespace render
{
	class GLQuery
	{
	public:
		static void beginConditionalRender(uint32_t id, QueryMode mode);
		static void endConditionalRender();
	public:
		static void beginQuery(QueryTarget target, uint32_t id);
		
		static void endQuery(QueryTarget target);
	public:
		static uint32_t genQuery();
		static void genQueries(int n, uint32_t* ids);
		static void deleteQuery(uint32_t id);
		static void deleteQueries(int n, const uint32_t* ids);
		static void getQueryObject(uint32_t id, QueryParameter name, uint32_t* params);
		static void getQueryObject(uint32_t id, QueryParameter name, int32_t* params);
		static void getQuery(QueryTarget target, QueryParameter name, int32_t* params);
		static bool isQuery(uint32_t id);
	};
}