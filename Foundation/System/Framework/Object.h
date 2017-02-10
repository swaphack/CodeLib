#pragma once

namespace sys
{
	class Object
	{
	public:
		Object(long id = 0);
		virtual ~Object();
	public:
		// ��ñ��
		virtual long getID() const;
		// �������ô���
		void retain();
		// �������ô���
		void release();
		// ����
		void dispose();
		// �Զ��ͷţ���Ҫ����G_AUTORELEASEPOOL�Ĺ���
		void autoRelease();
	public:
		// ���ô���
		int RetainCount;
	protected:
		// ���ñ��
		void setID(int id);
	private:
		// ���
		long _id;
		// �Ƿ��Զ��ͷ�
		bool _bAutoRelease;
	};
}