#pragma once

#include "macros.h"
#include "NodeProperty.h"
#include "helper.h"
#include "INodeLoad.h"
#include "INodeSave.h"

namespace ui
{
	// �ڵ������
	class INodeParser : 
		public INodeLoad, 
		public INodeSave
	{
	public:
		INodeParser();
		virtual ~INodeParser();
	public:
		// ���ؽڵ�
		virtual render::Node* load(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// ����ڵ�
		virtual void save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
	protected:
		// ����
		NodeProperty* getNodeProperty();
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
		// ��ȡui�ڵ�
		virtual render::Node* getNode() = 0;
		// ע�����
		virtual void registerNodeParser() = 0;
	private:
		// �ڵ�����
		NodeProperty* _nodeProperty;
	};
}