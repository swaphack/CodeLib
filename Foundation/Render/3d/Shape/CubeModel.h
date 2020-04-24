#pragma once

#include "3d/Common/Model.h"

namespace render
{
#define CUBE_FACE_COUNT 6

	class Texture2D;

	class CubeModel : public Model
	{
	public:
		CubeModel();
		virtual ~CubeModel();
	public:
		virtual bool init();
	public:
		// ��������
		void setTexture(const std::string& name, Texture2D* texture);
	protected:
		void onCubeChange();
	private:
		// ����
		Texture2D* _texture = nullptr;
		// ��������
		TextureCubeVertex _texCube;
	};
}