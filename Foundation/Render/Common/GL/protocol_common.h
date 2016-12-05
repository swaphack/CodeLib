#pragma once

#include "macros.h"

#include "system.h"

#include "enum_common.h"

// 接口
namespace render
{
	// 用于逻辑判断是否数据被修改
	class DirtyProtocol
	{
	public:
		DirtyProtocol();
		virtual ~DirtyProtocol();
	public:
		// 设置是否肮脏
		void setDirty(bool status);
		// 是否肮脏
		bool isDirty();
	private:
		bool _bDirty;
	};

	// 用于颜色设置
	class ColorProtocol
	{
	public:
		ColorProtocol();
		virtual ~ColorProtocol();
	public:
		// 设置颜色
		void setColor(uchar r, uchar g, uchar b);
		// 设置颜色
		void setColor(uchar r, uchar g, uchar b, uchar a);
		// 设置颜色
		void setColor(const sys::Color4B& color);
		// 设置颜色
		void setColor(const sys::Color3B& color);
		// 获取颜色
		const sys::Color4B& getColor();
	protected:
		// 混合
		sys::Color4B _color;
	};

	// 不透明度设置
	class OpacityProtocol
	{
	public:
		OpacityProtocol();
		virtual ~OpacityProtocol();
	public:
		// 设置不透明度
		void setOpacity(uchar opacity);
		// 设置不透明度
		uchar getOpacity();
	protected:
		// 不透明度
		uchar _opacity;
	};

	// 混合
	class BlendProtocol
	{
	public:
		BlendProtocol();
		virtual ~BlendProtocol();
	public:
		// 设置混合条件
		void setBlend(int src, int dest);
		// 设置混合条件
		void setBlend(const BlendParam& blend);
		// 获取混合参数
		const BlendParam& getBlend();
	protected:
		// 混合参数
		BlendParam _blend;
	};

	// 用于系统类
	class SystemProtocol
	{
	public:
		SystemProtocol();
		virtual ~SystemProtocol();
	public:
		// 暂停
		void pause();
		// 恢复
		void resume();
		// 开始
		void start();
		// 停止
		void stop();
		// 是否结束
		bool isFinish();
		// 是否正在运行
		bool isRunning();
	protected:
		// 动作状态
		ActionStatus _actionStatus;
	};

	// 空间属性
	class SpaceProtocol
	{
	public:
		SpaceProtocol();
		virtual ~SpaceProtocol();
	public:
		// 设置坐标
		void setPositionX(float x);

		void setPositionY(float y);

		void setPositionZ(float z);

		void setPosition(float x, float y);
		
		void setPosition(float x, float y, float z);

		void setPosition(const sys::Vector& position);
		// 获取坐标
		float getPositionX();

		float getPositionY();

		float getPositionZ();
		
		const sys::Vector& getPosition();
		// 设置缩放比
		void setScaleX(float x);

		void setScaleY(float y);

		void setScaleZ(float z);

		void setScale(float x, float y, float z);

		void setScale(const sys::Vector& scale);
		// 获取缩放比
		float getScaleX();

		float getScaleY();

		float getScaleZ();

		const sys::Vector& getScale();
		// 设置旋转系数
		void setRotationX(float x);

		void setRotationY(float y);

		void setRotationZ(float z);

		void setRotation(float x, float y, float z);

		void setRotation(const sys::Vector& rotation);
		// 获取旋转系数
		float getRotationX();

		float getRotationY();

		float getRotationZ();

		const sys::Vector& getRotation();
	public:
		virtual void onSpaceChange() {}
	protected:
		// 位置坐标
		sys::Vector _position;
		// 缩放比
		sys::Vector _scale;
		// 旋转
		sys::Vector _rotation;
	private:
	};


	// 物体属性
	class BodyProtocol
	{
	public:
		BodyProtocol();
		virtual ~BodyProtocol();
	public:
		// 设置锚点
		void setAnchorPoint(float x, float y, float z);
		// 设置锚点
		void setAnchorPoint(float x, float y);
		// 设置锚点
		void setAnchorPoint(const sys::Vector& anchor);
		// 获取锚点
		const sys::Vector& getAnchorPoint();
		// 设置宽度
		void setWidth(float w);
		// 设置高度
		void setHeight(float h);
		// 设置深度
		void setDeep(float d);
		// 设置体积
		void setVolume(float w, float h, float d);
		// 设置体积
		void setVolume(float w, float h);
		// 设置体积
		void setVolume(const sys::Volume& volume);
		// 设置面积，默认深度
		void setSize(const sys::Size& size);
		// 设置面积
		void setSize(float w, float h);
		// 获取宽度
		float getWidth();
		// 获取高度
		float getHeight();
		// 获取深度
		float getDeep();
		// 获取体积
		const sys::Volume& getVolume();
		// 获取面积
		sys::Size getSize();
	public:
		virtual void onBodyChange() {}
	protected:
		// 锚点
		sys::Vector _anchor;
		// 体积
		sys::Volume _volume;
	private:
	};

	// 用于文本
	class TextProtocol
	{
	public:
		TextProtocol();
		virtual ~TextProtocol();
	public:
		void setString(const char* text);
		const char* getString();
	private:
		std::string _textBody;
	};
}