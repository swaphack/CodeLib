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

	// 模型
	class Model : public ColorNode
	{
	public:
		Model();
		virtual ~Model();
	public:
		// 务必调用，包含属性修改时通知
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