#pragma once

#include <cstdint>
#include "Graphic/GLAPI/macros.h"
#include "FragmentHandle.h"

namespace render
{
	class FragmentQuery : public FragmentHandle
	{
	public:
		FragmentQuery(FragmentType type);
		virtual ~FragmentQuery();
	public:
		uint32_t getQueryID();

		bool isValid();
		void getResult(QueryParameter name, uint32_t* params);
		void getResult(QueryParameter name, int32_t* params);
	public:
		virtual void begin() {}
		virtual void update();
		virtual void end() {}
	protected:
		void releaseQuery();
		void initQuery();
	protected:
		uint32_t _queryID = 0;
	};

	/////////////////////////////////////////////////////////////
	/**
	*	ÕÚµ²²éÑ¯
	*/
	class FragmentOcclusionQuery : public FragmentQuery
	{
	public:
		FragmentOcclusionQuery();
		virtual ~FragmentOcclusionQuery();
	public:
		void setTarget(QueryTarget target);
		QueryTarget getTarget();
	public:
		virtual void begin();
		virtual void end();
	private:
		QueryTarget _queryTarget = QueryTarget::SAMPLES_PASSED;
	};
	/////////////////////////////////////////////////////////////
	/**
	*	Ìõ¼þäÖÈ¾
	*/
	class FragmentConditionRender : public FragmentQuery
	{
	public:
		FragmentConditionRender();
		virtual ~FragmentConditionRender();
	public:
		void setMode(QueryMode mode);
		QueryMode getMode();
	public:
		virtual void begin();
		virtual void end();
	private:
		QueryMode _queryMode = QueryMode::QUERY_WAIT;
	};
}