#pragma once

#include "Common/DrawNode/MultiDrawNode.h"
#include "3d/Environment/LightProtocol.h"
#include "Common/struct/vertex_common.h"
#include "Box/BoxDrawProtocol.h"

namespace render
{
	class MultiMeshModel : 
		public MultiDrawNode,
		public LightProtocol,
		public Box3DDrawProtocol
	{
	public:
		MultiMeshModel();
		virtual ~MultiMeshModel();
	public:
		virtual bool init();
	protected:
		/**
		*	绘制结束后
		*/
		virtual void afterDrawNode();
		/**
		*	坐标是否在当前对象内
		*/
		virtual bool containPoint(const math::Vector2& touchPoint);
	};
}