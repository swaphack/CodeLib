#pragma once

#include "Common/Node/ColorNode.h"

#include <map>
#include <string>

namespace render
{
	class ModelDetail;
	class NamedBufferObject;

	// Ä£ÐÍ
	class Model : public ColorNode
	{
	public:
		Model();
		virtual ~Model();
	protected:
		virtual void drawSample();
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

		std::map<int, NamedBufferObject*> _bufferObjects;
	};
}