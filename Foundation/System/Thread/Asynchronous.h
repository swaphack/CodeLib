#pragma once
#include <functional>
#include "Thread.h"

namespace sys
{
	// 异步回调
	struct AsynchronousResult;
	typedef std::function<void(AsynchronousResult*)> AsynchronousCallback;

	// 异步操作结果
	struct AsynchronousResult
	{
		// 是否结束
		bool finish;
		// 扩展
		void* object;
		// 回调处理
		AsynchronousCallback callback;

		AsynchronousResult()
			:finish(false)
			, object(nullptr)
			, callback(nullptr)
		{

		}
	};

	// 异步
	class Asynchronous
	{		
	private:
		Asynchronous() {}
		~Asynchronous() {}
	public:
		// 开始执行有参数的异步操作
		template<class _Fn>
		static AsynchronousResult* beginInvoke(AsynchronousCallback callback, _Fn&& handler, void* object);
		// 开始执行无参数的异步操作
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