#pragma once

#include "Common/DrawNode/MultiDrawNode.h"

namespace render
{
	class Model;

	// �����ü���ģ��
	class ModelFile : public MultiDrawNode
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
		// ����
		std::vector<Model*> _models;
	};
}
