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
}