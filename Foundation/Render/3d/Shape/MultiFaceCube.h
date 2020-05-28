#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/enum_common.h"
#include "Common/struct/vertex_common.h"

namespace render
{

	class Texture2D;

	/**
	*	���������壬ÿ����һ��mesh
	*/
	class MultiFaceCube : public Model
	{
	public:
		MultiFaceCube();
		virtual ~MultiFaceCube();
	public:
		virtual bool init();
	public:
		// ��������
		void setFaceTextureName(CubeFace face, const std::string& name);
		// ��������
		void setAllFacesTextureName(const std::string& name);
	protected:
		virtual void initBufferObject();

		void onCubeChanged();
	private:
		// ����
		CubeVertex _cubePosition;
	};
}