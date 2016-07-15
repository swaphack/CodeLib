#pragma once

#include "macros.h"

namespace ui
{
	// ui����ӿ�
	class IUIFace
	{
	public:
		IUIFace();
		virtual ~IUIFace();
	public:
		// ����xml����
		void load(tinyxml2::XMLElement* pXmlNode);

		// ���һ���µ�����
		void addAttribute(const char* name);
		// �Ƴ�һ����������
		void removeAttribute(const char* name);
		// �޸�����ֵ
		void setAttribute(const char* name, const char* value);
	protected:
	private:
	};
}