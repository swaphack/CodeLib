#pragma once

#include "Common/DrawNode/MultiDrawNode.h"
#include "Box/BoxProtocol.h"

namespace render
{
	class ModelFile;
	typedef std::function<void(ModelFile*)> LoadedModelCallback;

	// �����ü���ģ��
	class ModelFile :
		public MultiDrawNode,
		public Box3DProtocol
	{	
	public:
		ModelFile();
		virtual ~ModelFile();
	public:
		// ��ص��ã����������޸�ʱ֪ͨ
		virtual bool init();

		/**
		*	�����Ƿ��ڵ�ǰ������
		*/
		virtual bool containPoint(const math::Vector2& touchPoint);
	public:
		// ����ģ������
		void setModelData(sys::ModelDetail* detail);
		// ������Ϻ�ص�
		void setAsynLoadedCallback(const LoadedModelCallback& func);
	protected:
		virtual void onDraw();
		// ����ģ������
		void onLoadModelDetail();
	protected:
		bool _bloadedModel = false;
		// ģ������
		sys::ModelDetail* _modelDetail = nullptr;
		// ������Ϻ�ص�
		LoadedModelCallback _loadFinishedCallback = nullptr;
	};
}
