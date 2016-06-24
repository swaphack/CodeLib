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
		void setColor(sys::Color4B color);
		// 获取颜色
		sys::Color4B getColor();
	protected:
		// 混合
		sys::Color4B _color;
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
		
		void setPosition(float x, float y, float z);

		void setPosition(sys::Vector& position);
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

		void setScale(sys::Vector& scale);
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

		void setRotation(sys::Vector& rotation);
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
		// 设置描点
		void setAnchorPoint(float x, float y, float z);
		// 获取描点
		const sys::Vector& getAnchorPoint();
		// 设置体积
		void setWidth(float w);

		void setHeight(float h);

		void setDeep(float d);

		void setVolume(float w, float h, float d);
		// 获取体积
		float getWidth();

		float getHeight();

		float getDeep();

		const sys::Volume& getVolume();
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
		virtual void setString(const char* text);
		const char* getString();
	private:
		std::string _textBody;
	};
}