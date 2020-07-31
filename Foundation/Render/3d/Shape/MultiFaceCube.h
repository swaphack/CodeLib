#pragma once

#include "3d/Common/MultiMeshModel.h"
#include "Common/struct/enum_common.h"
#include "Common/struct/vertex_common.h"

namespace render
{

	class Texture2D;

	/**
	*	���������壬ÿ����һ��mesh
	*/
	class MultiFaceCube : public MultiMeshModel
	{
	public:
		MultiFaceCube();
		virtual ~MultiFaceCube();
	public:
		virtual bool init();
	public:
		// ��������
		void setFaceTexture(CubeFace face, const std::string& filepath);

		void setLeftTexture(const std::string& filepath);
		void setRightTexture(const std::string& filepath);
		void setBottomTexture(const std::string& filepath);
		void setTopTexture(const std::string& filepath);
		void setFrontTexture(const std::string& filepath);
		void setBackTexture(const std::string& filepath);

		void setAllFacesTexture(const std::string& filepath);
	protected:
		virtual void initBufferObject();

		void onMultiFaceCubeBodyChanged();
	private:
		// ����
		CubeVertex _cubePosition;
	};
}