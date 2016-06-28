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
		// ��������
		virtual void onParseProperty(const char* name);
	protected:
		render::UINode* _node;
	private:
		// ����ֵ
		std::map<std::string, UIElementLoader*> _elements;
		// �ӽڵ�
		std::map<std::string, UINodeLoader*> _children;
		// ���ڵ�
		UINodeLoader* _parent;
	};
}