#pragma once

#include "system.h"
#include "mathlib.h"
#include "enum_common.h"
#include "texture_common.h"

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
		void setColor(uint8_t r, uint8_t g, uint8_t b);
		// 设置颜色
		void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
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
		void setOpacity(uint8_t opacity);
		// 设置不透明度
		uint8_t getOpacity();
	protected:
		// 不透明度
		uint8_t _opacity;
	};

	// 混合
	class BlendProtocol
	{
	public:
		BlendProtocol();
		virtual ~BlendProtocol();
	public:
		// 设置混合条件
		void setBlend(BlendingFactorSrc src, BlendingFactorDest dest);
		// 设置混合条件
		void setBlend(const BlendParam& blend);
		// 获取混合参数
		const BlendParam& getBlend();
	protected:
		// 混合参数
		BlendParam _blend;
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

		void setPosition(const math::Vector3& position);

		void setPosition(const math::Vector2& position);
		// 获取坐标
		float getPositionX();

		float getPositionY();

		float getPositionZ();
		
		const math::Vector3& getPosition();
		// 设置缩放比
		void setScaleX(float x);

		void setScaleY(float y);

		void setScaleZ(float z);

		void setScale(float x, float y, float z);

		void setScale(const math::Vector3& scale);

		void setScale(float scale);
		// 获取缩放比
		float getScaleX();

		float getScaleY();

		float getScaleZ();

		const math::Vector3& getScale();
		// 设置旋转系数
		void setRotationX(float x);

		void setRotationY(float y);

		void setRotationZ(float z);

		void setRotation(float x, float y, float z);

		void setRotation(const math::Vector3& rotation);
		// 获取旋转系数
		float getRotationX();

		float getRotationY();

		float getRotationZ();

		const math::Vector3& getRotation();
	public:
		virtual void onSpaceChange() {}
	protected:
		// 位置坐标
		math::Vector3 _position;
		// 缩放比
		math::Vector3 _scale;
		// 旋转
		math::Vector3 _rotation;
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
		void setAnchorPoint(const math::Vector3& anchor);
		// 设置锚点
		void setAnchorPoint(const math::Vector2& anchor);
		// 获取锚点
		const math::Vector3& getAnchorPoint();
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
		void setVolume(const math::Volume& volume);
		// 设置面积，默认深度
		void setVolume(const math::Size& size);
		// 获取宽度
		float getWidth();
		// 获取高度
		float getHeight();
		// 获取深度
		float getDeep();
		// 获取体积
		const math::Volume& getVolume();
		// 获取面积
		math::Size getSize();
	public:
		virtual void onBodyChange() {}
	protected:
		// 锚点
		math::Vector3 _anchor;
		// 体积
		math::Volume _volume;
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

	// 控制
	class ControlProtocol
	{
	public:
		virtual ~ControlProtocol() {}
	public:
		// 开始
		virtual void start() = 0;
		// 恢复
		virtual void pause() = 0;
		// 暂停
		virtual void resume() = 0;
		// 结束
		virtual void stop() = 0;
	};

	// 用于系统类
	class SystemProtocol : public ControlProtocol
	{
	public:
		SystemProtocol();
		virtual ~SystemProtocol();
	public:
		// 暂停
		virtual void pause();
		// 恢复
		virtual void resume();
		// 开始
		virtual void start();
		// 停止
		virtual void stop();
		// 是否结束
		bool isFinish();
		// 是否正在运行
		bool isRunning();
	protected:
		// 动作状态
		ActionStatus _actionStatus;
	};

	// 空间属性
	struct BodySpace
	{
		// 空间位置（实际）
		math::Vector3 position;
		// 空间大小
		math::Volume volume;
	};

}