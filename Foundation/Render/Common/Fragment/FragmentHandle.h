#pragma once

#include "system.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
	/**
	*	ƬԪ��������
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
	*	ƬԪ���Ի����
	*/
	class FragmentHandle : public sys::Object
	{
	public:
		FragmentHandle(FragmentType type);
		FragmentHandle(FragmentType type, EnableMode mode);
		virtual ~FragmentHandle();
	public:
		/**
		*	�����Ƿ���Ч
		*/
		void setEnabled(bool enabled);
		/**
		*	�Ƿ���Ч
		*/
		bool isEnabled();
		/**
		*	ƬԪ��������
		*/
		FragmentType getFragmentType();
		/**
		*	���ÿ�������
		*/
		void setEnableMode(EnableMode mode);
		/**
		*	��������
		*/
		EnableMode getEnableMode();
	public:
		virtual void begin();
		virtual void update();
		virtual void end();
	protected:
		/**
		*	�����������
		*/
		virtual void saveData();
		/**
		*	�ָ���������
		*/
		virtual void reloadData();
	private:
		/**
		*	�Ƿ���Ч
		*/
		bool _enabled = false;
		/**
		*	ƬԪ��������
		*/
		FragmentType _fragmentType = FragmentType::NONE;
		/**
		*	��������
		*/
		EnableMode _enableMode = EnableMode::NONE;
		/**
		*	��һ�ο�������״̬
		*/
		int _lastEnableModeStatus = 0;
	};
}
