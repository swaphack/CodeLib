#pragma once
#include <functional>
#include "Thread.h"

namespace sys
{
	// �첽�ص�
	struct AsynchronousResult;
	typedef std::function<void(AsynchronousResult*)> AsynchronousCallback;

	// �첽�������
	struct AsynchronousResult
	{
		// �Ƿ����
		bool completed;
		// ��չ
		void* object;
		// �ص�����
		AsynchronousCallback callback;

		AsynchronousResult()
			:completed(false)
			, object(nullptr)
			, callback(nullptr)
		{

		}
	};

	template<class _Fn>
	struct AsynchronousHandler : public AsynchronousResult
	{
		_Fn handler;

		AsynchronousHandler()
			:handler(nullptr)
		{
		}
	};

	// �첽
	class Asynchronous
	{
	private:
		Asynchronous() {}
		~Asynchronous() {}
	public:
		// ��ʼִ���в������첽����
		template<class _Fn, class... _Args>
		static AsynchronousResult* beginInvoke(AsynchronousCallback callback, _Fn&& handler, _Args&&... _Ax);
		// ��ʼִ���޲������첽����
		template<class _Fn>
		static AsynchronousResult* beginInvoke(AsynchronousCallback callback, _Fn&& handler);

		// �����첽����
		static void endInvoke(AsynchronousResult* asynResult)
		{
			if (asynResult == nullptr || asynResult->completed)
			{
				return;
			}

			asynResult->completed = true;
		}

	};

	template<class _Fn>
	AsynchronousResult* Asynchronous::beginInvoke(AsynchronousCallback callback, _Fn&& handler)
	{
		if (callback == nullptr)
		{
			return nullptr;
		}
		AsynchronousHandler* pResult = new AsynchronousHandler();
		pResult->callback = callback;
		pResult->handler = handler;
		Thread thread;
		thread.startWithParams([&](AsynchronousHandler* asynResult) {
			if (asynResult == nullptr) return;
			if (!asynResult->completed)
			{
				asynResult->completed = true;
				if (asynResult->handler)
					asynResult->handler();
				if (asynResult->callback)
					asynResult->callback(asynResult);
				delete asynResult;
			}
		}, pResult);
		thread.detach();

		return pResult;
	}

	template<class _Fn, class... _Args>
	AsynchronousResult* Asynchronous::beginInvoke(AsynchronousCallback callback, _Fn&& handler, _Args&&... _Ax)
	{
		if (callback == nullptr)
		{
			return nullptr;
		}
		AsynchronousHandler* pResult = new AsynchronousHandler();
		pResult->callback = callback;
		pResult->handler = handler;

		Thread thread;
		thread.startWithParams([&](AsynchronousHandler* asynResult) {
			if (asynResult == nullptr) return;
			if (!asynResult->completed)
			{
				asynResult->completed = true;
				if (asynResult->handler)
					asynResult->handler(_Ax...);
				if (asynResult->callback)
					asynResult->callback(asynResult);
				delete asynResult;
			}
		}, pResult);
		thread.detach();

		return pResult;
	}

}