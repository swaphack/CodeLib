#pragma once

#include "3d/Common/Model.h"

namespace render
{
#define CUBE_FACE_COUNT 6

	class Texture;

	class CubeModel : public Model
	{
	public:
		CubeModel();
		virtual ~CubeModel();
	public:
		virtual bool init();
	protected:
		virtual void drawSample();
	public:
		// ��������
		void setTexture(const std::string& name, Texture* texture);
	protected:
		void onCubeChange();
		// ��ȡ�������
		TextureRect* getTextureRect(ModelFace index);
	private:
		// ����
		Texture* _texture = nullptr;
		// ��������
		TextureCube _texCube;
	};
}