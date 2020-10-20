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
		float getDuration() const;
		// 已经过时间
		float getElapsed() const;
		// 重置
		virtual void reset();
		// 反转
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void endAction();
		virtual void updateInterval(float percent);
		virtual void updatePercent(float curPercent);
	protected:
		// 总时长
		float _totalTime = 0;
		// 当前间隔
		float _currentTime = 0;
		// 是否初始化
		bool _bInitData = false;
	};

	class DelayAction : public IntervalAction
	{
	public:
		static DelayAction* create(float duration);
	};

	// 移动
	class MoveToAction : public IntervalAction
	{
	public:
		MoveToAction();
		virtual ~MoveToAction();
	public:
		static MoveToAction* create(float duration, const math::Vector3& pos);

		// 目标位置
		void setDestPosition(float x, float y, float z = 0);
		void setDestPosition(const math::Vector3& pos);
		const math::Vector3& getDestPosition() const;
		// 反转
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void updatePercent(float percent);
	protected:
		// 起始位置
		math::Vector3 _srcPosition;
		// 目标位置
		math::Vector3 _desPosition;
		// 偏移总量
		math::Vector3 _differentPosition;
	};

	class MoveByAction : public IntervalAction
	{
	public:
		MoveByAction();
		virtual ~MoveByAction();
	public:
		static MoveByAction* create(float duration, const math::Vector3& pos);

		// 偏移
		void setDifferentPosition(float x, float y, float z = 0);
		void setDifferentPosition(const math::Vector3& pos);

		const math::Vector3& getDifferentPosition() const;
		// 反转
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void endAction();
		virtual void updatePercent(float percent);
	protected:
		// 起始位置
		math::Vector3 _srcPosition;
		// 目标位置
		math::Vector3 _desPosition;
		// 偏移总量
		math::Vector3 _differentPosition;
	};

	// 旋转
	class RotateToAction : public IntervalAction
	{
	public:
		RotateToAction();
		virtual ~RotateToAction();
	public:
		static RotateToAction* create(float duration, const math::Vector3& rotation);

		// 最终旋转角度
		void setDestRotation(float x, float y, float z = 0);
		void setDestRotation(const math::Vector3& rotation);
		const math::Vector3& getDestRotation() const;
		// 反转
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void updatePercent(float percent);
	protected:
		// 起始旋转角度
		math::Vector3 _srcRotation;
		// 最终旋转角度
		math::Vector3 _destRotation;
		// 总改变量
		math::Vector3 _differentRotation;
	};

	class RotateByAction : public IntervalAction
	{
	public:
		RotateByAction();
		virtual ~RotateByAction();
	public:
		static RotateByAction* create(float duration, const math::Vector3& rotation);

		// 偏移
		void setDifferentRotation(float x, float y, float z = 0);
		void setDifferentRotation(const math::Vector3& rotation);
		const math::Vector3& getDifferentRotation() const;
		// 反转
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void endAction();
		virtual void updatePercent(float percent);
	protected:
		// 起始旋转角度
		math::Vector3 _srcRotation;
		// 最终旋转角度
		math::Vector3 _destRotation;
		// 总改变量
		math::Vector3 _differentRotation;
	};

	// 缩放
	class ScaleToAction : public IntervalAction
	{
	public:
		ScaleToAction();
		virtual ~ScaleToAction();
	public:
		static ScaleToAction* create(float duration, const math::Vector3& scale);

		void setDestScale(float x, float y, float z = 0);
		void setDestScale(const math::Vector3& scale);
		const math::Vector3& getDestScale() const;
		// 反转
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void updatePercent(float percent);
	protected:
		// 初始缩放比例
		math::Vector3 _srcScale;
		// 最终缩放比例
		math::Vector3 _destScale;
		// 总改变量
		math::Vector3 _differentScale;
	};

	class ScaleByAction : public IntervalAction
	{
	public:
		ScaleByAction();
		virtual ~ScaleByAction();
	public:
		static ScaleByAction* create(float duration, const math::Vector3& scale);

		void setDifferentScale(float x, float y, float z = 0);
		void setDifferentScale(const math::Vector3& scale);
		const math::Vector3& getDifferentScale() const;
		// 反转
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void endAction();
		virtual void updatePercent(float percent);
	protected:
		// 初始缩放比例
		math::Vector3 _srcScale;
		// 最终缩放比例
		math::Vector3 _destScale;
		// 总改变量
		math::Vector3 _differentScale;
	};
}