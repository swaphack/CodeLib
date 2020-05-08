#pragma once

#include "Common/Node/ColorNode.h"

#include <map>
#include <string>

namespace render
{
	class ModelDetail;
	class Material;
	class Mesh;

	// ģ��
	class Model : public ColorNode
	{
	public:
		Model();
		virtual ~Model();
	public:
		// ��ص��ã����������޸�ʱ֪ͨ
		virtual bool init();
	protected:
		virtual void drawSample();
	public:
		void setModelData(ModelDetail* detail);
		Material* getMaterial();
		Mesh* getMesh();
	protected:
		void drawSampleWithClientArray();
		void drawSampleWithBufferObject();
	protected:
		Material* _material = nullptr;
		Mesh * _mesh = nullptr;
	};
}