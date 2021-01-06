#pragma once

#include "Common/DrawNode/MultiDrawNode.h"
#include "Common/struct/shape_common.h"
#include "3d/Environment/LightProtocol.h"

namespace render
{
	class MultiMeshModel : 
		public MultiDrawNode,
		public LightProtocol
	{
	public:
		MultiMeshModel();
		virtual ~MultiMeshModel();
	public:
		virtual bool init();
	public:
		/**
		*	是否显示矩形框
		*/
		void setBoxVisible(bool bVisible);
		/**
		*	是否显示矩形框
		*/
		bool isBoxVisible() const;
	protected:
		virtual bool containPoint(float x, float y);
	protected:
		void calBoxData();
		/**
		*	绘制模型框
		*/
		void drawBox();
	protected:
		/**
		*	绘制
		*/
		virtual void afterDrawNode();
	private:
		/**
		*	是否显示矩形框
		*/
		bool _bBoxVisible = false;
		// 模型框
		CubePoints _boxVertex;
		// 实际模型框
		CubePoints _realBoxVertex;
	};
}