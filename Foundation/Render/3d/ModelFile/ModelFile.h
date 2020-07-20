#pragma once

#include "Common/DrawNode/MultiDrawNode.h"

namespace render
{
	class Model;

	// 从配置加载模型
	class ModelFile : public MultiDrawNode
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
		// 部件
		std::vector<Model*> _models;
	};
}
