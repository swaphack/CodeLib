#pragma once

#include "Model.h"

namespace render
{
	class ModelFile : public Model
	{
	public:
		ModelFile();
		virtual ~ModelFile();
	public:
		// 务必调用，包含属性修改时通知
		virtual bool init();
	public:
		// 设置模型数据
		void setModelData(sys::ModelDetail* detail);
	protected:
		virtual void onDraw();
	protected:
		bool _bloadedModel = false;
	};
}
