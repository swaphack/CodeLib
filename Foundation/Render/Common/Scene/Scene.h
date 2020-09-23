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

		void visit();
	};
}