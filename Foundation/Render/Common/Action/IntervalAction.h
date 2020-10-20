#pragma once

#include "Action.h"

namespace render
{
	// ��ʱ���Ķ���
	class IntervalAction : public Action
	{
	public:
		IntervalAction();
		virtual ~IntervalAction();
	public:
		virtual void update(float duration);

		// ���ö���ʱ��
		void setDuration(float duration);
		// ��ȡ����ʱ��
		float getDuration() const;
		// �Ѿ���ʱ��
		float getElapsed() const;
		// ����
		virtual void reset();
		// ��ת
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void endAction();
		virtual void updateInterval(float percent);
		virtual void updatePercent(float curPercent);
	protected:
		// ��ʱ��
		float _totalTime = 0;
		// ��ǰ���
		float _currentTime = 0;
		// �Ƿ��ʼ��
		bool _bInitData = false;
	};

	class DelayAction : public IntervalAction
	{
	public:
		static DelayAction* create(float duration);
	};

	// �ƶ�
	class MoveToAction : public IntervalAction
	{
	public:
		MoveToAction();
		virtual ~MoveToAction();
	public:
		static MoveToAction* create(float duration, const math::Vector3& pos);

		// Ŀ��λ��
		void setDestPosition(float x, float y, float z = 0);
		void setDestPosition(const math::Vector3& pos);
		const math::Vector3& getDestPosition() const;
		// ��ת
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void updatePercent(float percent);
	protected:
		// ��ʼλ��
		math::Vector3 _srcPosition;
		// Ŀ��λ��
		math::Vector3 _desPosition;
		// ƫ������
		math::Vector3 _differentPosition;
	};

	class MoveByAction : public IntervalAction
	{
	public:
		MoveByAction();
		virtual ~MoveByAction();
	public:
		static MoveByAction* create(float duration, const math::Vector3& pos);

		// ƫ��
		void setDifferentPosition(float x, float y, float z = 0);
		void setDifferentPosition(const math::Vector3& pos);

		const math::Vector3& getDifferentPosition() const;
		// ��ת
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void endAction();
		virtual void updatePercent(float percent);
	protected:
		// ��ʼλ��
		math::Vector3 _srcPosition;
		// Ŀ��λ��
		math::Vector3 _desPosition;
		// ƫ������
		math::Vector3 _differentPosition;
	};

	// ��ת
	class RotateToAction : public IntervalAction
	{
	public:
		RotateToAction();
		virtual ~RotateToAction();
	public:
		static RotateToAction* create(float duration, const math::Vector3& rotation);

		// ������ת�Ƕ�
		void setDestRotation(float x, float y, float z = 0);
		void setDestRotation(const math::Vector3& rotation);
		const math::Vector3& getDestRotation() const;
		// ��ת
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void updatePercent(float percent);
	protected:
		// ��ʼ��ת�Ƕ�
		math::Vector3 _srcRotation;
		// ������ת�Ƕ�
		math::Vector3 _destRotation;
		// �ܸı���
		math::Vector3 _differentRotation;
	};

	class RotateByAction : public IntervalAction
	{
	public:
		RotateByAction();
		virtual ~RotateByAction();
	public:
		static RotateByAction* create(float duration, const math::Vector3& rotation);

		// ƫ��
		void setDifferentRotation(float x, float y, float z = 0);
		void setDifferentRotation(const math::Vector3& rotation);
		const math::Vector3& getDifferentRotation() const;
		// ��ת
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void endAction();
		virtual void updatePercent(float percent);
	protected:
		// ��ʼ��ת�Ƕ�
		math::Vector3 _srcRotation;
		// ������ת�Ƕ�
		math::Vector3 _destRotation;
		// �ܸı���
		math::Vector3 _differentRotation;
	};

	// ����
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
		// ��ת
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void updatePercent(float percent);
	protected:
		// ��ʼ���ű���
		math::Vector3 _srcScale;
		// �������ű���
		math::Vector3 _destScale;
		// �ܸı���
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
		// ��ת
		virtual void reverse();
	protected:
		virtual void initAction();
		virtual void endAction();
		virtual void updatePercent(float percent);
	protected:
		// ��ʼ���ű���
		math::Vector3 _srcScale;
		// �������ű���
		math::Vector3 _destScale;
		// �ܸı���
		math::Vector3 _differentScale;
	};
}