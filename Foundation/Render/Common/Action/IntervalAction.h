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
		sys::Vector3 getPosition();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// Ŀ��λ��
		sys::Vector3 _destination;
		// ƫ������
		sys::Vector3 _offset;
	};

	class MoveByAction : public IntervalAction
	{
	public:
		MoveByAction();
		virtual ~MoveByAction();
	public:
		// ƫ��
		void setPosition(float x, float y, float z = 0);
		sys::Vector3 getPosition();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// ƫ������
		sys::Vector3 _offset;
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
		sys::Vector3 getRotation();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// ������ת�Ƕ�
		sys::Vector3 _rotation;
		// �ܸı���
		sys::Vector3 _offset;
	};

	class RotateByAction : public IntervalAction
	{
	public:
		RotateByAction();
		virtual ~RotateByAction();
	public:
		// ƫ��
		void setRotation(float x, float y, float z = 0);
		sys::Vector3 getRotation();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// ƫ������
		sys::Vector3 _offset;
	};

	// ����
	class ScaleToAction : public IntervalAction
	{
	public:
		ScaleToAction();
		virtual ~ScaleToAction();
	public:
		void setScale(float x, float y, float z = 0);
		sys::Vector3 getScale();
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// ��ʼ���ű���
		sys::Vector3 _src;
		// �������ű���
		sys::Vector3 _scale;
		// �ܸı���
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
		// ��ת
		virtual void reverse();
	protected:
		virtual void updateInterval(float percent);
	protected:
		// ƫ������
		sys::Vector3 _offset;
	};
}