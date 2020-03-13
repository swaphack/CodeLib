#pragma once

#include "Model.h"

namespace render
{
	class File3DS;

#define MAX_TEXTURES  100			// 最大的纹理数目
	/**
	*	3ds格式 模型
	*/
	class Model3DS : public Model
	{
	public:
		Model3DS();
		virtual ~Model3DS();
	public:
		void load(const std::string& filepath);
	public:
		virtual void draw();
	protected:
		// 创建纹理
		uint32_t createTexture(const std::string& strFileName, const std::string& dir);
		// 遍历显示
		void getDisplayListForEveryMat(Lib3dsNode* node);
	private:
		/**
		*	模型数据
		*/
		File3DS* _modelLoader = nullptr;
	};
}