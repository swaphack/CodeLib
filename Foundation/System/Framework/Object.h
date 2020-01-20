#pragma once

#include <cstdint>

namespace sys
{
	class Object
	{
	public:
		Object(int64_t id = 0);
		virtual ~Object();
	public:
		// ��ñ��
		virtual int64_t getID() const;
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
		int32_t RetainCount;
	protected:
		// ���ñ��
		void setID(int32_t id);
	private:
		// ���
		int64_t _id;
		// �Ƿ��Զ��ͷ�
		bool _bAutoRelease;
	};
}