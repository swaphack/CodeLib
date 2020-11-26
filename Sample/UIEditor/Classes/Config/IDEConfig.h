#pragma once

#include "system.h"
#include "toollib.h"
#include <string>

namespace ue
{
	/// <summary>
	/// ide 配置
	/// </summary>
	class IDEConfig
	{
	public:
		/// <summary>
		/// 文本配置
		/// </summary>
		struct Text
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
		const Text& getText() const;
	public:
		/// <summary>
		/// 加载配置
		/// </summary>
		/// <param name="filepath"></param>
		void loadXml(const std::string& filepath);
	private:
		/// <summary>
		/// 文本配置
		/// </summary>
		Text _text;
		/// <summary>
		/// xml工具
		/// </summary>
		tool::XmlHelper _helper;
	};
}
