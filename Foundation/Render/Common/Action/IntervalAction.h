#pragma once

#include "Action.h"

namespace render
{
	// 带时长的动作
	class IntervalAction : public Action
	{
	public:
		IntervalAction();
		virtual ~IntervalAction();
	public:
		virtual void update(float duration);

		// 设置动作时长
		void setInterval(float duration);
		// 获取动作时长
		float getInterval();
	protected:
		virtual void updateInterval(float duration);
	protected:
		// 总时长
		float _totalInterval;
		// 当前间隔
		float _currentInterval;
	};

	// 移动
	class MoveToAction : public IntervalAction
	{
	public:
		MoveToAction();
		virtual ~MoveToAction();
	public:
		// 目标位置
		void setDestination(float x, float y, float z = 0);
		sys::Vector getDestination();
	protected:
		virtual void updateInterval(float duration);
	protected:
		// 初始位置
		sys::Vector _src;
		// 目标位置
		sys::Vector _destination;
		// 偏移总量
		sys::Vector _offset;
	};

	// 旋转
	class RotateToAction : public IntervalAction
	{
	public:
		RotateToAction();
		virtual ~RotateToAction();
	public:
		// 最终旋转角度
		void setRotation(float x, float y, float z = 0);
		sys::Vector getRotation();
	protected:
		virtual void updateInterval(float duration);
	protected:
		// 初始旋转度数
		sys::Vector _src;
		// 最终旋转角度
		sys::Vector _rotation;
		// 总改变量
		sys::Vector _offset;
	};

	// 缩放
	class ScaleToAction : public IntervalAction
	{
	public:
		ScaleToAction();
		virtual ~ScaleToAction();
	public:
		void setScale(float x, float y, float z = 0);
		sys::Vector getScale();
	protected:
		virtual void updateInterval(float duration);
	protected:
		// 初始缩放比例
		sys::Vector _src;
		// 最终缩放比例
		sys::Vector _scale;
		// 总改变量
		sys::Vector _offset;
	};
}