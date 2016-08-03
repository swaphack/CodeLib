#pragma once

#include "macros.h"

#include "INodeLoader.h"

#include "helper.h"

#include "../UIBase/import.h"

using namespace render;

namespace ui
{
	// UI�ڵ�
	class NodeLoader : public INodeLoader
	{
	public:
		NodeLoader();
		virtual ~NodeLoader();
	protected:
		// ��������
		virtual void parseAttribute();
		// ��������
		virtual void saveAttributes();
	private:
		INIT_LOADER_NODE(UINode);
	};
}