#pragma once

#include "Model.h"

namespace render
{
	class ModelFile : public Model
	{
	public:
		ModelFile();
		virtual ~ModelFile();
	public:
		// ��ص��ã����������޸�ʱ֪ͨ
		virtual bool init();
	public:
		// ����ģ������
		void setModelData(sys::ModelDetail* detail);
	protected:
		virtual void onDraw();
	protected:
		bool _bloadedModel = false;
	};
}
