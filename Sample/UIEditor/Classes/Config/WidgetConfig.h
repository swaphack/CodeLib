#pragma once

#include "system.h"
#include "toollib.h"
#include "Config.h"
#include <string>

namespace ue
{
	/// <summary>
	/// �ؼ� ����
	/// </summary>
	class WidgetConfig : public Config
	{
	public:
		struct WidgetSetting
		{
			/// <summary>
			/// �ؼ�����
			/// </summary>
			std::string Name;
			/// <summary>
			/// �ؼ�����·��
			/// </summary>
			std::string ControlFilepath;
			/// <summary>
			/// ��������·��
			/// </summary>
			std::string PropertyFilepath;
		};
	public:
		/// <summary>
		/// �ؼ�����
		/// </summary>
		const WidgetSetting* getWidget(const std::string& name) const;
	public:
		/// <summary>
		/// ��������
		/// </summary>
		/// <param name="filepath"></param>
		void loadXml(const std::string& filepath);

		virtual void Dispose();
	private:
		/// <summary>
		/// xml����
		/// </summary>
		tool::XmlHelper _helper;
		/// <summary>
		/// ide ����
		/// </summary>
		std::map<std::string, WidgetSetting> _widgetSettings;
	};
}
