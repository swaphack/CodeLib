#pragma once

#include "system.h"

namespace ue
{
	/**
	*	�¼�����
	*/
	class PanelEvent : public sys::EventCenter
	{
	public:
		PanelEvent();
		virtual ~PanelEvent();
	public:
		/**
		*	�ɷ��¼�
		*/
		void dispatchEvent(const std::string& name, void* userData);
	};

#define G_PANELEVT sys::Instance<PanelEvent>::getInstance()
}
