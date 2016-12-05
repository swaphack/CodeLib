#pragma once

#include <functional>
#include <map>
#include <vector>
#include <set>

namespace render
{
	// ���Ըı�ʱ��֪ͨ����
	enum NotifyProperty
	{
		// �ռ�����
		ENP_SPACE,
		// �ڵ�
		ENP_NODE,
		// ����
		ENP_TEXTURE_FRAME,
		// ����������
		ENP_CUBE_FRAME,
		// ����֡���ı�
		ENP_ANIMATION_FRAME,
		// ����
		ENP_USER_INTERFACE,
	};

	// ����ί��
	typedef std::function<void()> NotifyDelegate;
	// ֪ͨ
	class Notify
	{
	public:
		Notify();
		~Notify();
	public:
		// ��Ӽ���
		void addListen(int k, NotifyDelegate handler);
		// �Ƴ�ĳһ���͵ļ���
		void removeListens(int k);
		// ��ӱ��
		void addMark(int k);
		// ִ��
		void notify();
		// ִ��
		void notify(int k);
		// ���
		void clear();
	private:
		typedef std::map<int, std::vector<NotifyDelegate>> NotifyEvent;
		// �����¼�
		NotifyEvent _notifyEvent;
		// ��Ҫ�޸ĵı��
		std::set<int> _notifyMark;
	};
}