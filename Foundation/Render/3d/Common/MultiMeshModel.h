#pragma once

#include "Common/DrawNode/MultiDrawNode.h"
#include "Common/struct/shape_common.h"

namespace render
{
	class MultiMeshModel : public MultiDrawNode
	{
	public:
		MultiMeshModel();
		virtual ~MultiMeshModel();
	public:
		virtual bool init();
	public:
		/**
		*	�Ƿ���ʾ���ο�
		*/
		void setBoxVisible(bool bVisible);
		/**
		*	�Ƿ���ʾ���ο�
		*/
		bool isBoxVisible() const;
	public:
		virtual bool containTouchPoint(float x, float y);
	protected:
		void calBoxData();
		/**
		*	����ģ�Ϳ�
		*/
		void drawBox();
	protected:
		/**
		*	����
		*/
		virtual void afterDrawNode();
	private:
		/**
		*	�Ƿ���ʾ���ο�
		*/
		bool _bBoxVisible = false;
		// ģ�Ϳ�
		CubeVectices _boxVertex;
		// ʵ��ģ�Ϳ�
		CubeVectices _realBoxVertex;
	};
}