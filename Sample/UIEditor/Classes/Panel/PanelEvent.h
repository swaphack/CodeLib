#pragma once

#include "system.h"

namespace ue
{
	/**
	*	事件中心
	*/
	class PanelEvent : public sys::EventCenter
	{
	public:
		PanelEvent();
		virtual ~PanelEvent();
	public:
		/**
		*	派发事件
		*/
		void dispatchEvent(const std::string& name, void* userData);
	};

#define G_PANELEVT sys::Instance<PanelEvent>::getInstance()
}
