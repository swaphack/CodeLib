#pragma once

#include "DrawNode.h"

namespace render
{
	// ֱ��
	class LineNode : public DrawNode
	{
	public:
		LineNode();
		virtual ~LineNode();
	public:
		virtual void draw();		

		// �յ�
		void setDestination(float x, float y, float z = 0);
		const sys::Vector& getDestination();

		// ��ʼ��
		void setSource(float x, float y, float z = 0);
		const sys::Vector& getSource();
	protected:
		virtual void initSelf();
	private:
		// �յ�
		sys::Vector _destPosition;
		// ��ʼ��
		sys::Vector _srcPosition;

		sys::Vector _obLine[2];
	};
}