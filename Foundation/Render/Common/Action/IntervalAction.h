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
		float getDuration();
		// �Ѿ���ʱ��
		float getElapsed();
		// ����
		virtual void reset();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// ��ʱ��
		float _totalTime;
		// ��ǰ���
		float _currentTime;
	};

	class DelayAction : public IntervalAction
	{

	};

	// �ƶ�
	class MoveToAction : public IntervalAction
	{
	public:
		MoveToAction();
		virtual ~MoveToAction();
	public:
		// Ŀ��λ��
		void setPosition(float x, float y, float z = 0);
		math::Vector3 getPosition();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// Ŀ��λ��
		math::Vector3 _destination;
		// ƫ������
		math::Vector3 _offset;
	};

	class MoveByAction : public IntervalAction
	{
	public:
		MoveByAction();
		virtual ~MoveByAction();
	public:
		// ƫ��
		void setPosition(float x, float y, float z = 0);
		math::Vector3 getPosition();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// ƫ������
		math::Vector3 _offset;
	};

	// ��ת
	class RotateToAction : public IntervalAction
	{
	public:
		RotateToAction();
		virtual ~RotateToAction();
	public:
		// ������ת�Ƕ�
		void setRotation(float x, float y, float z = 0);
		math::Vector3 getRotation();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// ������ת�Ƕ�
		math::Vector3 _rotation;
		// �ܸı���
		math::Vector3 _offset;
	};

	class RotateByAction : public IntervalAction
	{
	public:
		RotateByAction();
		virtual ~RotateByAction();
	public:
		// ƫ��
		void setRotation(float x, float y, float z = 0);
		math::Vector3 getRotation();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// ƫ������
		math::Vector3 _offset;
	};

	// ����
	class ScaleToAction : public IntervalAction
	{
	public:
		ScaleToAction();
		virtual ~ScaleToAction();
	public:
		void setScale(float x, float y, float z = 0);
		math::Vector3 getScale();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// ��ʼ���ű���
		math::Vector3 _src;
		// �������ű���
		math::Vector3 _scale;
		// �ܸı���
		math::Vector3 _offset;
	};

	class ScaleByAction : public IntervalAction
	{
	public:
		ScaleByAction();
		virtual ~ScaleByAction();
	public:
		void setScale(float x, float y, float z = 0);
		math::Vector3 getScale();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// ƫ������
		math::Vector3 _offset;
	};
}