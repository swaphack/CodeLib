#pragma once

#include "macros.h"

using namespace render;

namespace ui
{
	// UI�ڵ�
	class NodeLoader : public INodeParser
	{ 
	public:
		NodeLoader();
		virtual ~NodeLoader();
	protected:
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
	protected:
		// ui�ڵ�
		Node* _node;
	private:
		INIT_LOADER_NODE(Node);
	};
}