#pragma once

#include "NProperty.h"
#include "NStatus.h"
#include "NMark.h"
#include <string>

namespace nature
{
	class INObject
	{
	public:
		virtual ~INObject() {}
	public:
		// ��ʼ��
		virtual bool init() = 0;
		// ����
		virtual void destory() = 0;
	};

	// ��Ȼ����
	class NObject : public INObject
	{
	public:
		NObject();
		virtual ~NObject();
	public:
		// ��ʼ��
		virtual bool init();
		// ����
		virtual void destory();
	};
}