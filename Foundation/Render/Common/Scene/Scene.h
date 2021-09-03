#pragma once

#include "Common/Node/Node.h"

namespace render
{
	class ViewPort;
	// ����
	class Scene : public Node
	{
	public:
		Scene();
		virtual ~Scene();
	public:
		virtual bool init();
		// �����ͻ��Ƴ���
		virtual void visit();
	public:
		// ����ӽڵ�
		virtual void addChild(Node* node);

		// ����ӽڵ�
		virtual void addChild(Node* node, int zOrder);
	};
}