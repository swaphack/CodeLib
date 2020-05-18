#pragma once

#include "system.h"

namespace render
{
	/**
	*	片元处理类型
	*/
	enum class FragmentType
	{
		NONE,
		SCISSOR_TEST,
		SAMPLE,
		STENCIL_TEST,
		DEPTH_TEST,
		POLYGON_OFFSET,
		BLEND,
		LOGIC,
		OCCLUSION_QUERY,
		CONDITION_RENDER,
	};
	/**
	*	片元测试或操作
	*/
	class FragmentHandle : public sys::Object
	{
	public:
		FragmentHandle();
		virtual ~FragmentHandle();
	public:
		void setEnabled(bool enabled);
		bool isEnabled();
		FragmentType getFragmentType();
	public:
		virtual void begin();
		virtual void update();
		virtual void end();
	protected:
		bool _enabled = false;
		FragmentType _fragmentType = FragmentType::NONE;
	};
}
