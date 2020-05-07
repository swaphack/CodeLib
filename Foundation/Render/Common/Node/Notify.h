#pragma once

#include <functional>
#include <map>
#include <vector>
#include <set>

namespace render
{
	// 属性改变时的通知类型
	enum NotifyProperty
	{
		// 空间属性
		ENP_SPACE,
		// 节点
		ENP_NODE,
		// 纹理
		ENP_TEXTURE_FRAME,
		// 模型纹理
		ENP_MODEL_FRAME,
		// 动作帧数改变
		ENP_ANIMATION_FRAME,
		// 界面
		ENP_USER_INTERFACE,
		// 音效
		ENP_AUDIO,
		// 几何
		ENP_GEOMETRY,
		// 文本纹理
		ENP_TEXT_FRAME,
		// 视窗改变
		ENP_VIEWSIZE,
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

			_notifyEvent[k].push_back(handler);
		}
		// 移除某一类型的监听
		void removeListens(T k)
		{
			if (_notifyEvent.find(k) == _notifyEvent.end())
			{
				return;
			}

			_notifyEvent.erase(k);
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

			std::set<int>::const_iterator citer = _notifyMark.begin();

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
		// 清空
		void clear()
		{
			_notifyEvent.clear();
			_notifyMark.clear();
		}
	private:
		typedef std::map<T, std::vector<NotifyDelegate>> NotifyEvent;
		// 推送事件
		NotifyEvent _notifyEvent;
		// 需要修改的标记
		std::set<T> _notifyMark;
	};
}