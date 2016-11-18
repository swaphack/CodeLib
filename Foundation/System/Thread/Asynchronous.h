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
		bool finish;
		// ��չ
		void* object;
		// �ص�����
		AsynchronousCallback callback;

		AsynchronousResult()
			:finish(false)
			, object(nullptr)
			, callback(nullptr)
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
		template<class _Fn>
		static AsynchronousResult* beginInvoke(AsynchronousCallback callback, _Fn&& handler, void* object);
		// ��ʼִ���޲������첽����
		template<class _Fn>
		static AsynchronousResult* beginInvoke(AsynchronousCallback callback, _Fn&& handler);

	};

	template<class _Fn>
	AsynchronousResult* Asynchronous::beginInvoke(AsynchronousCallback callback, _Fn&& handler)
	{
		if (callback == nullptr)
		{
			return nullptr;
		}
		AsynchronousResult* pResult = new AsynchronousResult();
		pResult->callback = callback;
		Thread thread;
		thread.startWithParams([&](AsynchronousResult* asynResult) {
			if (asynResult == nullptr) return;
			handler();
			asynResult->finish = true;
			if (asynResult->callback)
				asynResult->callback(asynResult);
			delete asynResult;
		}, pResult);
		thread.detach();

		return pResult;
	}

	template<class _Fn>
	AsynchronousResult* Asynchronous::beginInvoke(AsynchronousCallback callback, _Fn&& handler, void* object)
	{
		if (callback == nullptr)
		{
			return nullptr;
		}
		AsynchronousResult* pResult = new AsynchronousResult();
		pResult->object = object;
		pResult->callback = callback;
		Thread thread;
		thread.startWithParams([&](AsynchronousResult* asynResult) {
			if (asynResult == nullptr) return;
			handler(asynResult->object);
			asynResult->finish = true;
			if (asynResult->callback)
				asynResult->callback(asynResult);
			delete asynResult;
		}, pResult);
		thread.detach();

		return pResult;
	}

}