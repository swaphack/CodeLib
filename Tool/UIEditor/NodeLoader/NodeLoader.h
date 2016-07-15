#pragma once

#include "macros.h"

#include "INodeLoader.h"

#include "helper.h"

using namespace render;

namespace ui
{
	// UI节点
	class NodeLoader : public INodeLoader
	{
	public:
		NodeLoader();
		virtual ~NodeLoader();
	protected:
		// 解析属性
		virtual void parseAttribute();
		// 保存属性
		virtual void saveAttributes();
	private:
		INIT_LOADER_NODE(UINode);
	};
}