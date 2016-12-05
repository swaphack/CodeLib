#pragma once

#include "macros.h"

#include "system.h"

#include "enum_common.h"

// �ӿ�
namespace render
{
	// �����߼��ж��Ƿ����ݱ��޸�
	class DirtyProtocol
	{
	public:
		DirtyProtocol();
		virtual ~DirtyProtocol();
	public:
		// �����Ƿ���
		void setDirty(bool status);
		// �Ƿ���
		bool isDirty();
	private:
		bool _bDirty;
	};

	// ������ɫ����
	class ColorProtocol
	{
	public:
		ColorProtocol();
		virtual ~ColorProtocol();
	public:
		// ������ɫ
		void setColor(uchar r, uchar g, uchar b);
		// ������ɫ
		void setColor(uchar r, uchar g, uchar b, uchar a);
		// ������ɫ
		void setColor(const sys::Color4B& color);
		// ������ɫ
		void setColor(const sys::Color3B& color);
		// ��ȡ��ɫ
		const sys::Color4B& getColor();
	protected:
		// ���
		sys::Color4B _color;
	};

	// ��͸��������
	class OpacityProtocol
	{
	public:
		OpacityProtocol();
		virtual ~OpacityProtocol();
	public:
		// ���ò�͸����
		void setOpacity(uchar opacity);
		// ���ò�͸����
		uchar getOpacity();
	protected:
		// ��͸����
		uchar _opacity;
	};

	// ���
	class BlendProtocol
	{
	public:
		BlendProtocol();
		virtual ~BlendProtocol();
	public:
		// ���û������
		void setBlend(int src, int dest);
		// ���û������
		void setBlend(const BlendParam& blend);
		// ��ȡ��ϲ���
		const BlendParam& getBlend();
	protected:
		// ��ϲ���
		BlendParam _blend;
	};

	// ����ϵͳ��
	class SystemProtocol
	{
	public:
		SystemProtocol();
		virtual ~SystemProtocol();
	public:
		// ��ͣ
		void pause();
		// �ָ�
		void resume();
		// ��ʼ
		void start();
		// ֹͣ
		void stop();
		// �Ƿ����
		bool isFinish();
		// �Ƿ���������
		bool isRunning();
	protected:
		// ����״̬
		ActionStatus _actionStatus;
	};

	// �ռ�����
	class SpaceProtocol
	{
	public:
		SpaceProtocol();
		virtual ~SpaceProtocol();
	public:
		// ��������
		void setPositionX(float x);

		void setPositionY(float y);

		void setPositionZ(float z);

		void setPosition(float x, float y);
		
		void setPosition(float x, float y, float z);

		void setPosition(const sys::Vector& position);
		// ��ȡ����
		float getPositionX();

		float getPositionY();

		float getPositionZ();
		
		const sys::Vector& getPosition();
		// �������ű�
		void setScaleX(float x);

		void setScaleY(float y);

		void setScaleZ(float z);

		void setScale(float x, float y, float z);

		void setScale(const sys::Vector& scale);
		// ��ȡ���ű�
		float getScaleX();

		float getScaleY();

		float getScaleZ();

		const sys::Vector& getScale();
		// ������תϵ��
		void setRotationX(float x);

		void setRotationY(float y);

		void setRotationZ(float z);

		void setRotation(float x, float y, float z);

		void setRotation(const sys::Vector& rotation);
		// ��ȡ��תϵ��
		float getRotationX();

		float getRotationY();

		float getRotationZ();

		const sys::Vector& getRotation();
	public:
		virtual void onSpaceChange() {}
	protected:
		// λ������
		sys::Vector _position;
		// ���ű�
		sys::Vector _scale;
		// ��ת
		sys::Vector _rotation;
	private:
	};


	// ��������
	class BodyProtocol
	{
	public:
		BodyProtocol();
		virtual ~BodyProtocol();
	public:
		// ����ê��
		void setAnchorPoint(float x, float y, float z);
		// ����ê��
		void setAnchorPoint(float x, float y);
		// ����ê��
		void setAnchorPoint(const sys::Vector& anchor);
		// ��ȡê��
		const sys::Vector& getAnchorPoint();
		// ���ÿ��
		void setWidth(float w);
		// ���ø߶�
		void setHeight(float h);
		// �������
		void setDeep(float d);
		// �������
		void setVolume(float w, float h, float d);
		// �������
		void setVolume(float w, float h);
		// �������
		void setVolume(const sys::Volume& volume);
		// ���������Ĭ�����
		void setSize(const sys::Size& size);
		// �������
		void setSize(float w, float h);
		// ��ȡ���
		float getWidth();
		// ��ȡ�߶�
		float getHeight();
		// ��ȡ���
		float getDeep();
		// ��ȡ���
		const sys::Volume& getVolume();
		// ��ȡ���
		sys::Size getSize();
	public:
		virtual void onBodyChange() {}
	protected:
		// ê��
		sys::Vector _anchor;
		// ���
		sys::Volume _volume;
	private:
	};

	// �����ı�
	class TextProtocol
	{
	public:
		TextProtocol();
		virtual ~TextProtocol();
	public:
		void setString(const char* text);
		const char* getString();
	private:
		std::string _textBody;
	};
}