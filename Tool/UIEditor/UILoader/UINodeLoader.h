#pragma once

#include "macros.h"
#include "UIElementLoader.h"
#include <map>
#include <string>

namespace uieditor
{
	class UINodeLoader
	{
	public:
		UINodeLoader();  
		virtual ~UINodeLoader();
	public:
		// 解析属性
		virtual void onParseProperty(const char* name);
	protected:
		render::UINode* _node;
	private:
		// 属性值
		std::map<std::string, UIElementLoader*> _elements;
		// 子节点
		std::map<std::string, UINodeLoader*> _children;
		// 父节点
		UINodeLoader* _parent;
	};
}