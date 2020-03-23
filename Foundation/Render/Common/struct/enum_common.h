#pragma once

// 枚举
namespace render
{
	// 动作状态
	enum ActionStatus
	{
		EAS_NONE,		// 无状态
		EAS_RUNNING,	// 正在运行中
		EAS_PAUSE,		// 暂停
		EAS_STOP,		// 停止
	};

	// 六个面
	enum ModelFace
	{
		EMF_FRONT,		// 前面
		EMF_BACK,		// 背面
		EMF_LEFT,		// 左面
		EMF_RIGHT,		// 右面
		EMF_TOP,		// 上面
		EMF_BOTTOM,		// 下面
		EMF_MAX,
	};
}