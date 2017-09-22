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
		void setDuration(float duration);
		// 获取动作时长
		float getDuration();
		// 已经过时间
		float getElapsed();
		// 重置
		virtual void reset();
		// 反转
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// 总时长
		float _totalTime;
		// 当前间隔
		float _currentTime;
	};

	class DelayAction : public IntervalAction
	{

	};

	// 移动
	class MoveToAction : public IntervalAction
	{
	public:
		MoveToAction();
		virtual ~MoveToAction();
	public:
		// 目标位置
		void setPosition(float x, float y, float z = 0);
		sys::Vector3 getPosition();
		// 反转
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// 目标位置
		sys::Vector3 _destination;
		// 偏移总量
		sys::Vector3 _offset;
	};

	class MoveByAction : public IntervalAction
	{
	public:
		MoveByAction();
		virtual ~MoveByAction();
	public:
		// 偏移
		void setPosition(float x, float y, float z = 0);
		sys::Vector3 getPosition();
		// 反转
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// 偏移总量
		sys::Vector3 _offset;
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
		sys::Vector3 getRotation();
		// 反转
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// 最终旋转角度
		sys::Vector3 _rotation;
		// 总改变量
		sys::Vector3 _offset;
	};

	class RotateByAction : public IntervalAction
	{
	public:
		RotateByAction();
		virtual ~RotateByAction();
	public:
		// 偏移
		void setRotation(float x, float y, float z = 0);
		sys::Vector3 getRotation();
		// 反转
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// 偏移总量
		sys::Vector3 _offset;
	};

	// 缩放
	class ScaleToAction : public IntervalAction
	{
	public:
		ScaleToAction();
		virtual ~ScaleToAction();
	public:
		void setScale(float x, float y, float z = 0);
		sys::Vector3 getScale();
		// 反转
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// 初始缩放比例
		sys::Vector3 _src;
		// 最终缩放比例
		sys::Vector3 _scale;
		// 总改变量
		sys::Vector3 _offset;
	};

	class ScaleByAction : public IntervalAction
	{
	public:
		ScaleByAction();
		virtual ~ScaleByAction();
	public:
		void setScale(float x, float y, float z = 0);
		sys::Vector3 getScale();
		// 反转
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// 偏移总量
		sys::Vector3 _offset;
	};
}