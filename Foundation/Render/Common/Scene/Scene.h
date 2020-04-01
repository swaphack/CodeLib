#pragma once

#include "Common/Node/Node.h"

namespace render
{
	class View;
	// ³¡¾°
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