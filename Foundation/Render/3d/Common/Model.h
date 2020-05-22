#pragma once

#include "Common/DrawNode/DrawNode.h"

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
		void setModelData(sys::ModelDetail* detail);
	protected:
		virtual void onDraw();
	protected:
		bool _loadModel = false;
	};
}