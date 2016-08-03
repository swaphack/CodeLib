#pragma once

#include "macros.h"
#include "NodeProperty.h"

namespace ui
{
	// �ڵ���ؽ����ӿ�
	class INodeLoader
	{
	public:
		INodeLoader();
		virtual ~INodeLoader();
	public:
		// ���ؽڵ�
		render::Node* load(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// ����ڵ�����
		void save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
	protected:
		// ��ȡ�ڵ�����
		NodeProperty* getAttributeLoader();
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
		// ��ȡui�ڵ�
		virtual render::Node* getNode() = 0;
		// ע�����
		virtual void registerNodeParser() = 0;
	protected:
		// ui�ڵ�
		render::Node* _node;
		// �ڵ�����
		NodeProperty* _elementLoader;
	};
}