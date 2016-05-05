#pragma once

#include "DrawNode.h"

namespace render
{
	// 直线
	class LineNode : public DrawNode
	{
	public:
		LineNode();
		virtual ~LineNode();
	public:
		virtual void draw();		

		// 终点
		void setDestination(float x, float y, float z = 0);
		const sys::Vector& getDestination();

		// 起始点
		void setSource(float x, float y, float z = 0);
		const sys::Vector& getSource();
	protected:
		virtual void initSelf();
	private:
		// 终点
		sys::Vector _destPosition;
		// 起始点
		sys::Vector _srcPosition;

		sys::Vector _obLine[2];
	};
}