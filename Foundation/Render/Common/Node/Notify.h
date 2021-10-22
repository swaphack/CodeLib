#pragma once

#include <functional>
#include <map>
#include <vector>
#include <set>

namespace render
{
	// 属性改变时的通知类型
	enum class NodeNotifyType
	{
		// 节点
		NODE,
		// 空间属性
		SPACE,
		// 自身属性
		BODY,
		// 纹理
		TEXTURE,
		// 模型
		MODEL,
		// 动作帧数改变
		ANIMATION,
		// 音效
		AUDIO,
		// 几何
		GEOMETRY,
		// 文本纹理
		TEXT,
		// 颜色
		COLOR,
		// 视窗改变
		VIEWSIZE,
		// 文件改变
		FILE,
		// 网格
		MESH,
		// 重新绘制
		Draw,
	};

	// 推送委托
	typedef std::function<void()> NotifyDelegate;

	// 通知
	template<typename T>
	class Notify
	{
	public:
		Notify()
		{}
		~Notify()
		{}
	public:
		// 添加监听
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
		// 添加监听
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

		// 移除某一类型的监听
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

		// 移除某一类型的监听
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
		// 添加标记
		void addMark(T k)
		{
			if (_notifyMark.find(k) != _notifyMark.end())
			{
				return;
			}
			_notifyMark.insert(k);
		}
		// 执行
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
		// 执行
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
		// 清空
		void clear()
		{
			_notifyTargetEvent.clear();
			_notifyEvent.clear();
			_notifyMark.clear();
		}
	private:
		typedef std::map<T, std::vector<NotifyDelegate>> NotifyEvent;
		typedef std::map<T, std::map<void*, NotifyDelegate>> NotifyTargetEvent;

		// 推送事件
		NotifyEvent _notifyEvent;
		// 推送事件
		NotifyTargetEvent _notifyTargetEvent;
		// 需要修改的标记
		std::set<T> _notifyMark;
	};
}