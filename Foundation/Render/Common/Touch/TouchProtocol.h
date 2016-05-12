#pragma once

#include "../Node/import.h"

namespace render
{
	class TouchProtocol
	{
	public:
		TouchProtocol();
		virtual ~TouchProtocol();
	public:
		virtual bool onTouchBegan(float x, float y);
		virtual void onTouchMove(float x, float y);
		virtual void onTouchEnd(float x, float y);

		inline void setTarget(Node* target) { _target = target; }
		inline Node* getTarget() { return _target; }
	protected:
	private:
		Node* _target;
	};
}