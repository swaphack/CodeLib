#pragma once

#include "system.h"

#include "enum_common.h"
#include "texture_common.h"

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
		void setColor(uint8 r, uint8 g, uint8 b);
		// ������ɫ
		void setColor(uint8 r, uint8 g, uint8 b, uint8 a);
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
		void setOpacity(uint8 opacity);
		// ���ò�͸����
		uint8 getOpacity();
	protected:
		// ��͸����
		uint8 _opacity;
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

		void setPosition(const sys::Vector3& position);

		void setPosition(const sys::Vector2& position);
		// ��ȡ����
		float getPositionX();

		float getPositionY();

		float getPositionZ();
		
		const sys::Vector3& getPosition();
		// �������ű�
		void setScaleX(float x);

		void setScaleY(float y);

		void setScaleZ(float z);

		void setScale(float x, float y, float z);

		void setScale(const sys::Vector3& scale);

		void setScale(float scale);
		// ��ȡ���ű�
		float getScaleX();

		float getScaleY();

		float getScaleZ();

		const sys::Vector3& getScale();
		// ������תϵ��
		void setRotationX(float x);

		void setRotationY(float y);

		void setRotationZ(float z);

		void setRotation(float x, float y, float z);

		void setRotation(const sys::Vector3& rotation);
		// ��ȡ��תϵ��
		float getRotationX();

		float getRotationY();

		float getRotationZ();

		const sys::Vector3& getRotation();
	public:
		virtual void onSpaceChange() {}
	protected:
		// λ������
		sys::Vector3 _position;
		// ���ű�
		sys::Vector3 _scale;
		// ��ת
		sys::Vector3 _rotation;
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
		void setAnchorPoint(const sys::Vector3& anchor);
		// ����ê��
		void setAnchorPoint(const sys::Vector2& anchor);
		// ��ȡê��
		const sys::Vector3& getAnchorPoint();
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
		void setVolume(const sys::Size& size);
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
		sys::Vector3 _anchor;
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

	// ����
	class ControlProtocol
	{
	public:
		virtual ~ControlProtocol() {}
	public:
		// ��ʼ
		virtual void start() = 0;
		// �ָ�
		virtual void pause() = 0;
		// ��ͣ
		virtual void resume() = 0;
		// ����
		virtual void stop() = 0;
	};

	// ����ϵͳ��
	class SystemProtocol : public ControlProtocol
	{
	public:
		SystemProtocol();
		virtual ~SystemProtocol();
	public:
		// ��ͣ
		virtual void pause();
		// �ָ�
		virtual void resume();
		// ��ʼ
		virtual void start();
		// ֹͣ
		virtual void stop();
		// �Ƿ����
		bool isFinish();
		// �Ƿ���������
		bool isRunning();
	protected:
		// ����״̬
		ActionStatus _actionStatus;
	};

	// �ռ�����
	struct BodySpace
	{
		// �ռ�λ�ã�ʵ�ʣ�
		sys::Vector3 position;
		// �ռ��С
		sys::Volume volume;
	};

}