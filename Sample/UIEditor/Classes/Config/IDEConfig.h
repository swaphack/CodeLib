#pragma once

#include "system.h"
#include "toollib.h"
#include "Config.h"
#include <string>

namespace ue
{
	/// <summary>
	/// ide 配置
	/// </summary>
	class IDEConfig : public Config
	{
	public:
		struct IDESetting
		{
			/// <summary>
			/// 设计界面
			/// </summary>
			std::string Design;
			/// <summary>
			/// 控件配置
			/// </summary>
			std::string Control;
		};
		/// <summary>
		/// 文本配置
		/// </summary>
		struct TextSetting
		{
		public:
			/// <summary>
			/// 字体
			/// </summary>
			std::string FontPath;
			/// <summary>
			/// 字号
			/// </summary>
			int FontSize = 0;
			/// <summary>
			/// 颜色
			/// </summary>
			phy::Color3B TextColor;
		};
	public:
		/// <summary>
		/// 文本配置
		/// </summary>
		const TextSetting& getText() const;
		/// <summary>
		/// ide配置文件
		/// </summary>
		/// <returns></returns>
		const IDESetting& getIDE() const;
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
		/// 文本 配置
		/// </summary>
		TextSetting _text;
		/// <summary>
		/// ide 配置
		/// </summary>
		IDESetting _ide;
	};
}
