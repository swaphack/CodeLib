#pragma once

#include "system.h"

namespace render
{
	// ģ����Դ��ʽ
	enum ModelResourceFormat
	{
		EMRF_NONE,
		EMRF_3DS,	// 3ds
	};

	// 3dģ��
	class ModelDetail
	{
	public:
		ModelDetail();
		virtual ~ModelDetail();
	public:
		// ��ȡͼ���ʽ
		ModelResourceFormat getModelFormat();
		// ����
		virtual void load(const char* filename);
	protected:
		void setModelFormat(ModelResourceFormat format);
	private:
		ModelResourceFormat _format = EMRF_NONE;
	};
	//////////////////////////////////////////////////////////////////////////
	class File3DS;

	// 3ds��ʽģ��
	class Model3DSDetail : public ModelDetail
	{
	public:
		Model3DSDetail();
		virtual ~Model3DSDetail();
	public:
		// ����
		virtual void load(const char* filename);
		// ��ȡ����
		const File3DS* getData();
	protected:

	private:
		File3DS* _data = nullptr;
	};
}