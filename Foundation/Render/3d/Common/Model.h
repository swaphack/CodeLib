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
	class Mesh;
	class Material;

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
		void setModelData(sys::ModelDetail* detail);
	protected:
		virtual void drawing();
		virtual void drawSampleWithClientArray();
	private:
		bool _loadModel = false;
	};
}