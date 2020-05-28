#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/import.h"

namespace render
{
	class Texture2D;
	/**
	*	�����壬��������������
	*/
	class Cube : public Model
	{
	public:
		Cube();
		virtual ~Cube();
	public:
		virtual bool init();
	public:
		void setFaceImage(const std::string& filepath);
	protected:
		void onSpaceChanged();
	private:
		// ����
		CubeVertex _cubePosition;
		// ����
		Texture2D* _tex2d = nullptr;
	};
}