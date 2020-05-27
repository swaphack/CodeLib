#pragma once

#include "Common/DrawNode/DrawNode.h"
#include "Common/struct/shape_common.h"
#include <map>
#include <string>

namespace sys
{
	class ModelDetail;
}

namespace render
{
	class Meshes;
	class Materials;

	// 模型
	class Model : public DrawNode
	{
	public:
		Model();
		virtual ~Model();
	public:
		// 务必调用，包含属性修改时通知
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
	public:
		virtual bool containTouchPoint(float x, float y);
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
		CubeVectices _boxVertex;
		// 实际模型框
		CubeVectices _realBoxVertex;
	};
}