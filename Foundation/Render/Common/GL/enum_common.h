#pragma once

// 枚举
namespace render
{
	// 维度模式
	enum Dimensions
	{
		ED_NONE,
		ED_2D,
		ED_3D
	};

	// 动作状态
	enum ActionStatus
	{
		EAS_NONE,		// 无状态
		EAS_RUNNING,	// 正在运行中
		EAS_PAUSE,		// 暂停
		EAS_STOP,		// 停止
	};
}