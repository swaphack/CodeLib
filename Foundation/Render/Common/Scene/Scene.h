#pragma once

#include "Common/Node/Node.h"

namespace render
{
	class View;
	// ����
	class Scene : public Node
	{
	public:
		Scene();
		virtual ~Scene();
	public:
		virtual bool init();

		virtual void visit();
	};
}