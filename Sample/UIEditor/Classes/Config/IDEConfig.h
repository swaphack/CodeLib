#pragma once

#include "system.h"
#include "toollib.h"
#include "Config.h"
#include <string>

namespace ue
{
	// ide 配置
	class IDEConfig : public Config
	{
	public:
		struct IDESetting
		{
			// 设计界面
			std::string Design;
			// 控件配置
			std::string Control;
			// 着色器模式 0-默认，1-合批，2-合图
			int ShaderMode = 0;
		};

		struct ShaderSetting
		{
			// 纹理顶点着色器
			std::string TexVertex;
			// 纹理片元着色器
			std::string TexFragment;
			// 颜色顶点着色器
			std::string ColorVertex;
			// 颜色片元着色器
			std::string ColorFragment;
		};

		struct TextSetting
		{
		public:
			// 字体
			std::string FontPath;
			// 字号
			int FontSize = 0;
			//颜色
			phy::Color3B TextColor;
		};
	public:
		// 文本配置
		const TextSetting& getText() const;
		// ide配置文件
		const IDESetting& getIDE() const;
		// 着色器配置
		const ShaderSetting* getShader() const;
	public:
		// 加载配置
		void loadXml(const std::string& filepath);

		virtual void Dispose();
	private:
		// xml工具
		tool::XmlHelper _helper;
		// 文本 配置
		TextSetting _text;
		// 着色器配置
		std::vector<ShaderSetting> _shaders;
		// ide 配置
		IDESetting _ide;
	};
}
