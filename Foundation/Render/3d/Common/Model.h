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

	// ģ��
	class Model : public DrawNode
	{
	public:
		Model();
		virtual ~Model();
	public:
		// ��ص��ã����������޸�ʱ֪ͨ
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