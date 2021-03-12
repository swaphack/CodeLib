#pragma once

#include "Common/Node/Node.h"

namespace render
{
	class ViewPort;
	// 场景
	class Scene : public Node
	{
	public:
		Scene();
		virtual ~Scene();
	public:
		virtual bool init();
		void visit();
	public:
		// 添加子节点
		virtual void addChild(Node* node);

		// 添加子节点
		virtual void addChild(Node* node, int zOrder);
	};
}