#pragma once

#include <functional>
#include <map>

namespace game
{
	// 通知
	template<typename T>
	class Notification
	{
	public:
		typedef std::function<void()> NotifyHandler;
	public:
		Notification();
		~Notification();
	public:
		/**
		*	添加推送监听
		*	@param key 标识
		*	@param handler 处理
		*/
		void add(T key, NotifyHandler handler);
		/**
		*	移除推送监听
		*	@param key 标识
		*/
		void remove(T key);
		/**
		*	移除所有推送监听
		*/
		void removeAllNotifications();
		/**
		*	推送
		*	@param key 标识
		*/
		void notify(T key);
	private:
		std::map<T, NotifyHandler> m_mListeners;
	};

	template<typename T>
	void Notification<T>::notify(T key)
	{
		if (m_mListeners.find(key) != m_mListeners.end())
		{
			m_mListeners[key]();
		}
	}

	template<typename T>
	void Notification<T>::removeAllNotifications()
	{
		m_mListeners.clear();
	}

	template<typename T>
	void Notification<T>::remove(T key)
	{
		m_mListeners.erase(key);
	}

	template<typename T>
	void Notification<T>::add(T key, NotifyHandler handler)
	{
		m_mListeners[key] = handler;
	}

	template<typename T>
	Notification<T>::~Notification()
	{
		
	}

	template<typename T>
	Notification<T>::Notification()
	{

	}

}