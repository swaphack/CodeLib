#pragma once

#include "Node.h"
#include <functional>
#include <vector>
#include <map>

namespace render
{
	typedef std::function<void()> ComputeFunction;
	/**
	*	º∆À„∂”¡–
	*/ 
	class ComputeQueue : public Node
	{
	public:
		ComputeQueue();
		virtual ~ComputeQueue();
	public:
		void pushBack(Node* target, const ComputeFunction& func);
		void remove(Node* target);
	protected:
		void process();
	private:
		std::vector<std::pair<Node*, ComputeFunction>> _funcs;
	};

#define G_COMPUTEQUEUE sys::Instance<render::ComputeQueue>::getInstance()
}