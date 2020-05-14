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
		virtual void drawing();
		virtual void drawSampleWithClientArray();
	private:
		bool _loadModel = false;
	};
}