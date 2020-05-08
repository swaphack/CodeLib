#pragma once

#include "Common/Node/ColorNode.h"

#include <map>
#include <string>

namespace render
{
	class ModelDetail;
	class ShaderProgram;
	class Material;
	class NoNamedBufferObject;
	class VertexArrayObject;

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
	protected:
		void drawSampleWithClientArray();
		void drawSampleWithBufferObject();
	protected:
		Material* _material = nullptr;
	};
}