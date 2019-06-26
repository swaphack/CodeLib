#pragma once

#include "Base/Types.h"

namespace sys
{
	class Object
	{
	public:
		Object(int64 id = 0);
		virtual ~Object();
	public:
		// ��ñ��
		virtual int64 getID() const;
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
		int32 RetainCount;
	protected:
		// ���ñ��
		void setID(int32 id);
	private:
		// ���
		int64 _id;
		// �Ƿ��Զ��ͷ�
		bool _bAutoRelease;
	};
}