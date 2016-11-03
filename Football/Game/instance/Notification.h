#pragma once

#include <functional>
#include <map>

namespace game
{
	// ֪ͨ
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
		*	������ͼ���
		*	@param key ��ʶ
		*	@param handler ����
		*/
		void add(T key, NotifyHandler handler);
		/**
		*	�Ƴ����ͼ���
		*	@param key ��ʶ
		*/
		void remove(T key);
		/**
		*	�Ƴ��������ͼ���
		*/
		void removeAllNotifications();
		/**
		*	����
		*	@param key ��ʶ
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