#pragma once

#include "Common/DrawNode/MultiDrawNode.h"
#include "Box/BoxDrawProtocol.h"

namespace render
{
	class ModelFile;
	typedef std::function<void(ModelFile*)> LoadedModelCallback;

	// 从配置加载模型
	class ModelFile :
		public MultiDrawNode,
		public Box3DDrawProtocol
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
		// 加载完毕后回调
		void setAsynLoadedCallback(const LoadedModelCallback& func);
	protected:
		virtual void onDraw();
		// 加载模型数据
		void onLoadModelDetail();
	protected:
		/**
		*	形状改变
		*/
		void onModelFileBodyChange();
	protected:
		bool _bloadedModel = false;
		// 模型数据
		sys::ModelDetail* _modelDetail = nullptr;
		// 加载完毕后回调
		LoadedModelCallback _loadFinishedCallback = nullptr;
	};
}
