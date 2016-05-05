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
}