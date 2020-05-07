#pragma once

#include "Common/Node/ColorNode.h"

#include <map>
#include <string>

namespace render
{
	class ModelDetail;
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

		void updateMatTexture();
		void initBufferObject();
		void updateBufferData();
	public:
		const ModelDetail* getModelData();
		void setModelData(const ModelDetail* detail);
	protected:
		void applyMatToMesh(uint32_t nMatID);

		void drawSampleWithClientArray();
		void drawSampleWithBufferObject();

		void removeAllBufferObjects();
	protected:
		ModelDetail* _modelDetail = nullptr;

		std::map<uint32_t, VertexArrayObject*> _vertexArrayObjects;
		std::map<uint32_t, NoNamedBufferObject*> _indiceObjects;
		std::map<uint32_t, NoNamedBufferObject*> _vertexObjects;
	};
}