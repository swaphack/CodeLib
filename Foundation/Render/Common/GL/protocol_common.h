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
		void setColor(sys::Color4B color);
		// ��ȡ��ɫ
		sys::Color4B getColor();
	protected:
		// ���
		sys::Color4B _color;
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
		
		void setPosition(float x, float y, float z);

		void setPosition(sys::Vector& position);
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

		void setScale(sys::Vector& scale);
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

		void setRotation(sys::Vector& rotation);
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
		// �������
		void setAnchorPoint(float x, float y, float z);
		// ��ȡ���
		const sys::Vector& getAnchorPoint();
		// �������
		void setWidth(float w);

		void setHeight(float h);

		void setDeep(float d);

		void setVolume(float w, float h, float d);
		// ��ȡ���
		float getWidth();

		float getHeight();

		float getDeep();

		const sys::Volume& getVolume();
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
		virtual void setString(const char* text);
		const char* getString();
	private:
		std::string _textBody;
	};
}