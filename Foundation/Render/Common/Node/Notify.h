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
		// 立方体纹理
		ENP_CUBE_FRAME,
		// 动作帧数改变
		ENP_ANIMATION_FRAME,
		// 界面
		ENP_USER_INTERFACE,
	};

	// 推送委托
	typedef std::function<void()> NotifyDelegate;
	// 通知
	class Notify
	{
	public:
		Notify();
		~Notify();
	public:
		// 添加监听
		void addListen(int k, NotifyDelegate handler);
		// 移除某一类型的监听
		void removeListens(int k);
		// 添加标记
		void addMark(int k);
		// 执行
		void notify();
		// 执行
		void notify(int k);
		// 清空
		void clear();
	private:
		typedef std::map<int, std::vector<NotifyDelegate>> NotifyEvent;
		// 推送事件
		NotifyEvent _notifyEvent;
		// 需要修改的标记
		std::set<int> _notifyMark;
	};
}