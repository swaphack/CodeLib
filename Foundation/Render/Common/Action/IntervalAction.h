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
		void setInterval(float duration);
		// ��ȡ����ʱ��
		float getInterval();
	protected:
		virtual void updateInterval(float duration);
	protected:
		// ��ʱ��
		float _totalInterval;
		// ��ǰ���
		float _currentInterval;
	};

	// �ƶ�
	class MoveToAction : public IntervalAction
	{
	public:
		MoveToAction();
		virtual ~MoveToAction();
	public:
		// Ŀ��λ��
		void setDestination(float x, float y, float z = 0);
		sys::Vector3 getDestination();
	protected:
		virtual void updateInterval(float duration);
	protected:
		// ��ʼλ��
		sys::Vector3 _src;
		// Ŀ��λ��
		sys::Vector3 _destination;
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
	protected:
		virtual void updateInterval(float duration);
	protected:
		// ��ʼ��ת����
		sys::Vector3 _src;
		// ������ת�Ƕ�
		sys::Vector3 _rotation;
		// �ܸı���
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
	protected:
		virtual void updateInterval(float duration);
	protected:
		// ��ʼ���ű���
		sys::Vector3 _src;
		// �������ű���
		sys::Vector3 _scale;
		// �ܸı���
		sys::Vector3 _offset;
	};
}