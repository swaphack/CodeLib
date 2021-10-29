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
		bool completed = false;
		// 扩展
		void* object = nullptr;
		// 回调处理
		AsynchronousCallback callback = nullptr;

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
		_Fn handler = nullptr;

		AsynchronousHandler()
			:handler(nullptr)
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
		template<class _Fn, class... _Args>
		static AsynchronousResult* beginInvoke(AsynchronousCallback callback, _Fn&& handler, _Args&&... _Ax);
		// 开始执行无参数的异步操作
		template<class _Fn>
		static AsynchronousResult* beginInvoke(AsynchronousCallback callback, _Fn&& handler);

		// 结束异步操作
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