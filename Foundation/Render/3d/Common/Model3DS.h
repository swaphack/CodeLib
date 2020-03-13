#pragma once

#include "Model.h"

namespace render
{
	class File3DS;

#define MAX_TEXTURES  100			// ����������Ŀ
	/**
	*	3ds��ʽ ģ��
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
		// ��������
		uint32_t createTexture(const std::string& strFileName, const std::string& dir);
		// ������ʾ
		void getDisplayListForEveryMat(Lib3dsNode* node);
	private:
		/**
		*	ģ������
		*/
		File3DS* _modelLoader = nullptr;
	};
}