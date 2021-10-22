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
		// ��������
		BODY,
		// ����
		TEXTURE,
		// ģ��
		MODEL,
		// ����֡���ı�
		ANIMATION,
		// ��Ч
		AUDIO,
		// ����
		GEOMETRY,
		// �ı�����
		TEXT,
		// ��ɫ
		COLOR,
		// �Ӵ��ı�
		VIEWSIZE,
		// �ļ��ı�
		FILE,
		// ����
		MESH,
		// ���»���
		Draw,
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

			auto it = _notifyEvent.find(k);
			if (it == _notifyEvent.end())
			{
				_notifyEvent.insert(std::make_pair(k, std::vector<NotifyDelegate>()));
			}
			_notifyEvent[k].push_back(handler);
		}
		// ��Ӽ���
		void addTargetListen(T k, void* target, NotifyDelegate handler)
		{
			if (handler == nullptr || target == nullptr)
			{
				return;
			}

			auto it = _notifyTargetEvent.find(k);
			if (it == _notifyTargetEvent.end())
			{
				_notifyTargetEvent.insert(std::make_pair(k, std::map<void*, NotifyDelegate>()));
			}
			_notifyTargetEvent[k][target] = handler;
		}

		// �Ƴ�ĳһ���͵ļ���
		void removeTargetListen(T k, void* target)
		{
			if (target == nullptr) return;
			auto it = _notifyTargetEvent.find(k);
			if (it != _notifyTargetEvent.end())
			{
				auto it1 = it->second.find(target);
				if (it1 != it->second.end())
				{
					it->second.erase(it1);
				}
			}
		}

		// �Ƴ�ĳһ���͵ļ���
		void removeListens(T k)
		{
			if (_notifyEvent.find(k) != _notifyEvent.end())
			{
				_notifyEvent.erase(k);
			}
			if (_notifyTargetEvent.find(k) != _notifyTargetEvent.end())
			{
				_notifyTargetEvent.erase(k);
			}
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
			if (_notifyEvent.find(k) != _notifyEvent.end())
			{
				auto iter = _notifyEvent[k].begin();
				while (iter != _notifyEvent[k].end())
				{
					(*iter)();
					iter++;
				}
			}
			if (_notifyTargetEvent.find(k) != _notifyTargetEvent.end())
			{
				for (auto item : _notifyTargetEvent[k])
				{
					item.second();
				}
			}
			
		}
		// ���
		void clear()
		{
			_notifyTargetEvent.clear();
			_notifyEvent.clear();
			_notifyMark.clear();
		}
	private:
		typedef std::map<T, std::vector<NotifyDelegate>> NotifyEvent;
		typedef std::map<T, std::map<void*, NotifyDelegate>> NotifyTargetEvent;

		// �����¼�
		NotifyEvent _notifyEvent;
		// �����¼�
		NotifyTargetEvent _notifyTargetEvent;
		// ��Ҫ�޸ĵı��
		std::set<T> _notifyMark;
	};
}