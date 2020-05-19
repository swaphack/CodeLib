#pragma once

#include "system.h"

#include "Graphic/GLAPI/macros.h"

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
		FragmentHandle(FragmentType type);
		FragmentHandle(FragmentType type, EnableMode mode);
		virtual ~FragmentHandle();
	public:
		/**
		*	设置是否有效
		*/
		void setEnabled(bool enabled);
		/**
		*	是否有效
		*/
		bool isEnabled();
		/**
		*	片元处理类型
		*/
		FragmentType getFragmentType();
		/**
		*	设置可用类型
		*/
		void setEnableMode(EnableMode mode);
		/**
		*	可用类型
		*/
		EnableMode getEnableMode();
	public:
		virtual void begin();
		virtual void update();
		virtual void end();
	protected:
		/**
		*	保存旧有数据
		*/
		virtual void saveData();
		/**
		*	恢复旧有数据
		*/
		virtual void reloadData();
	private:
		/**
		*	是否有效
		*/
		bool _enabled = false;
		/**
		*	片元处理类型
		*/
		FragmentType _fragmentType = FragmentType::NONE;
		/**
		*	可用类型
		*/
		EnableMode _enableMode = EnableMode::NONE;
		/**
		*	上一次可用类型状态
		*/
		int _lastEnableModeStatus = 0;
	};
}
