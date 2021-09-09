#pragma once

#include "Common/DrawNode/DrawNode3D.h"
#include "3d/Environment/LightProtocol.h"
#include "Common/struct/vertex_common.h"
#include <map>
#include <string>

namespace sys
{
	class ModelDetail;
}

namespace render
{
	class Meshes;
	class Materials;

	// ģ��
	class Model : 
		public DrawNode3D,
		public LightProtocol
	{
	public:
		Model();
		virtual ~Model();
	public:
		// ��ص��ã����������޸�ʱ֪ͨ
		virtual bool init();
	};
}