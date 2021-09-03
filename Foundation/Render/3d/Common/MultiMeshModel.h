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
		*	body�����ı�
		*/
		void onMultiDrawNodeBodyChange();
		/**
		*	��������
		*/
		virtual void updateMultiDrawNode3DMesh();
		/**
		*	���ƽ�����
		*/
		virtual void afterDrawNode();
	protected:
		// ������Ϣ
		CubeVertex _cubeVertex;
	};
}