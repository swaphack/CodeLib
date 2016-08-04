#pragma once


#include "macros.h"

namespace ui
{
	// �ڵ���ؽ����ӿ�
	class INodeSave
	{
	public:
		virtual ~INodeSave() = 0;
	public:
		// ����ڵ�
		virtual void save(tinyxml2::XMLElement* pXmlNode, bool clean = true) = 0;
	protected:
		// ��������
		virtual void saveAttributes() = 0;
	};
}