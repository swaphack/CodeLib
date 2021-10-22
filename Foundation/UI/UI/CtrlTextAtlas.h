#pragma once


#include "CtrlWidget.h"
#include "TextProtocol.h"
#include "system.h"

namespace ui
{
	/**
	*	2d文本, 使用图集访问
	*
	*	生成在指定区域的文字
	*	水平对齐方式：左对齐，右对齐， 居中
	*
	*	在指定框内显示
	*	垂直对齐方式：顶对齐，底对齐，居中
	*/

	class CtrlTextAtlas : public CtrlWidget, public TextProtocol
	{
	public:
		CtrlTextAtlas();
		virtual ~CtrlTextAtlas();
	public:
		virtual bool init();
	public:
		/**
		*	设置图集名称
		*/
		void setAtlas(const std::string& atlasName);
		/**
		*	获取图集名称
		*/
		const std::string& getAtlasName() const;
		/**
		*	设置显示的文本
		*/
		virtual void setString(const std::string& text);
	public:
		/**
		*	设置水平字间距
		*/
		void setHorizontalDistance(float distance);
		/**
		*	获取水平间距
		*/
		float getHorizontalDistance() const;
		/**
		*	设置垂直间距
		*/
		void setVerticalDistance(float distance);
		/**
		*	获取垂直间距
		*/
		float getVerticalDistance() const;
		/**
		*	加粗
		*/
		void setBorder(bool bBorder);
		/**
		*	加粗
		*/
		bool isBorder() const;
		/**
		*	设置文本水平对齐方式
		*/
		void setTextHorizontalAlignment(sys::HorizontalAlignment alignment);
		/**
		*	获取文本水平对齐方式
		*/
		sys::HorizontalAlignment getTextHorizontalAlignment() const;
		/**
		*	设置文本垂直对齐方式
		*/
		void setTextVerticalAlignment(sys::VerticalAlignment alignment);
		/**
		*	获取文本垂直对齐方式
		*/
		sys::VerticalAlignment getTextVerticalAlignment() const;
		/**
		*	设置显示区域
		*/
		void setDimensions(float width, float height);
		/**
		*	设置显示区域
		*/
		void setDimensions(const math::Size& size);
		/**
		*	获取显示区域
		*/
		const math::Size& getDimensions() const;
		/**
		*	设置颜色
		*/
		void setTextColor(const phy::Color3B& color);
		/**
		*	颜色
		*/
		const phy::Color3B& getTextColor() const;
	public:
		/**
		*	设置着色器
		*/
		virtual void setTexShaderProgram(render::ShaderProgram* shaderProgram);
		/**
		*	设置摄像机
		*/
		virtual void setCamera(const render::Camera* camera);
		/**
		*	使用设计摄像头
		*/
		virtual void setUseDesignCamera(bool bUsed);
	protected:
		/**
		*	文字图片信息
		*/
		void getOrgin(const math::Size& size, math::Vector3& anchor, math::Vector3& position);

		virtual void onTextBodyChange();
		virtual void onTextTextureChange();
	private:
		// 文本结构
		sys::TextDefine _textDefine;
		// 图集名称
		std::string _atlasName;
	};
}