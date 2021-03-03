#pragma once

#include "system.h"
#include "toollib.h"
#include "Config.h"
#include <string>

namespace ue
{
	/// <summary>
	/// 控件 配置
	/// </summary>
	class WidgetConfig : public Config
	{
	public:
		struct WidgetSetting
		{
			/// <summary>
			/// 控件名称
			/// </summary>
			std::string Name;
			/// <summary>
			/// 控件参数路径
			/// </summary>
			std::string ControlFilepath;
			/// <summary>
			/// 属性配置路径
			/// </summary>
			std::string PropertyFilepath;
		};
	public:
		/// <summary>
		/// 控件配置
		/// </summary>
		const WidgetSetting* getWidget(const std::string& name) const;
	public:
		/// <summary>
		/// 加载配置
		/// </summary>
		/// <param name="filepath"></param>
		void loadXml(const std::string& filepath);

		virtual void Dispose();
	private:
		/// <summary>
		/// xml工具
		/// </summary>
		tool::XmlHelper _helper;
		/// <summary>
		/// ide 配置
		/// </summary>
		std::map<std::string, WidgetSetting> _widgetSettings;
	};
}
