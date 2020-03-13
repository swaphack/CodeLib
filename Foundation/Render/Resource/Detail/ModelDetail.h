#pragma once

#include "system.h"

namespace render
{
	// 模型资源格式
	enum ModelResourceFormat
	{
		EMRF_NONE,
		EMRF_3DS,	// 3ds
	};

	// 3d模型
	class ModelDetail
	{
	public:
		ModelDetail();
		virtual ~ModelDetail();
	public:
		// 获取图像格式
		ModelResourceFormat getModelFormat();
		// 加载
		virtual void load(const char* filename);
	protected:
		void setModelFormat(ModelResourceFormat format);
	private:
		ModelResourceFormat _format = EMRF_NONE;
	};
	//////////////////////////////////////////////////////////////////////////
	class File3DS;

	// 3ds格式模型
	class Model3DSDetail : public ModelDetail
	{
	public:
		Model3DSDetail();
		virtual ~Model3DSDetail();
	public:
		// 加载
		virtual void load(const char* filename);
		// 获取数据
		const File3DS* getData();
	protected:

	private:
		File3DS* _data = nullptr;
	};
}