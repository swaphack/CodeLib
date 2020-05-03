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
		// �������
		void addTexture(const std::string& name, Texture2D* texture);
		// ��������
		void setAllFacesTexture(const std::string& name);
		// ��������
		void setFaceTexture(ModelFace face, const std::string& name);
	protected:
		virtual void onCubeChange();
	private:
		// ����
		TextureCubeVertex _cubePosition;

		TextureRectVertex _faces[CUBE_FACE_COUNT];
	};
}