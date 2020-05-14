#pragma once

#include <functional>
#include <map>
#include <vector>
#include <set>

namespace render
{
	// ���Ըı�ʱ��֪ͨ����
	enum class NodeNotifyType
	{
		// �ڵ�
		NODE,
		// �ռ�����
		SPACE,
		// ����
		TEXTURE,
		// ģ��
		MODEL,
		// ����֡���ı�
		ANIMATION,
		// ����
		USER_INTERFACE,
		// ��Ч
		AUDIO,
		// ����
		GEOMETRY,
		// �ı�����
		TEXT,
		// �Ӵ��ı�
		VIEWSIZE,
	};

	// ����ί��
	typedef std::function<void()> NotifyDelegate;

	// ֪ͨ
	template<typename T>
	class Notify
	{
	public:
		Notify()
		{}
		~Notify()
		{}
	public:
		// ��Ӽ���
		void addListen(T k, NotifyDelegate handler)
		{
			if (handler == nullptr)
			{
				return;
			}

			_notifyEvent[k].push_back(handler);
		}
		// �Ƴ�ĳһ���͵ļ���
		void removeListens(T k)
		{
			if (_notifyEvent.find(k) == _notifyEvent.end())
			{
				return;
			}

			_notifyEvent.erase(k);
		}
		// ��ӱ��
		void addMark(T k)
		{
			if (_notifyMark.find(k) != _notifyMark.end())
			{
				return;
			}
			_notifyMark.insert(k);
		}
		// ִ��
		void run()
		{
			if (_notifyMark.size() == 0)
			{
				return;
			}

			auto citer = _notifyMark.begin();

			while (citer != _notifyMark.end())
			{
				run(*citer);

				citer++;
			}

			_notifyMark.clear();
		}
		// ִ��
		void run(T k)
		{
			if (_notifyEvent.find(k) == _notifyEvent.end())
			{
				return;
			}

			std::vector<NotifyDelegate>::iterator iter = _notifyEvent[k].begin();
			while (iter != _notifyEvent[k].end())
			{
				(*iter)();
				iter++;
			}
		}
		// ���
		void clear()
		{
			_notifyEvent.clear();
			_notifyMark.clear();
		}
	private:
		typedef std::map<T, std::vector<NotifyDelegate>> NotifyEvent;
		// �����¼�
		NotifyEvent _notifyEvent;
		// ��Ҫ�޸ĵı��
		std::set<T> _notifyMark;
	};
}