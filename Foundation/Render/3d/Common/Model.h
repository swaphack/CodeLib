#pragma once

#include "Common/Node/ColorNode.h"

#include <map>
#include <string>

namespace render
{
	class ModelDetail;
	// Ä£ÐÍ
	class Model : public ColorNode
	{
	public:
		Model();
		virtual ~Model();
	protected:
		virtual void draw();
	public:
		const ModelDetail* getModelData();
		void setModelData(const ModelDetail* detail);
	protected:
		ModelDetail* _modelDetail = nullptr;
	};
}