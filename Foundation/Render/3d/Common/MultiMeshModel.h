#pragma once

#include "Common/DrawNode/MultiDrawNode.h"
#include "3d/Environment/LightProtocol.h"
#include "Common/struct/vertex_common.h"

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
	protected:
		/**
		*	body发生改变
		*/
		void onMultiDrawNodeBodyChange();
		/**
		*	更新网格
		*/
		virtual void updateMultiDrawNode3DMesh();
		/**
		*	绘制结束后
		*/
		virtual void afterDrawNode();
	protected:
		// 顶点信息
		CubeVertex _cubeVertex;
	};
}