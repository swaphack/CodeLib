#pragma once

#include <math.h>
#include "Resource/Loader/IResourceLoader.h"
#include "Resource/Detail/ModelDetail.h"

namespace render
{
	class File3DS : public ModelDetail, public IResourceLoader
	{
	public:
		File3DS();								// ��ʼ�����ݳ�Ա
		virtual ~File3DS();
	public:
		virtual void load(const std::string& filename);
	};
}