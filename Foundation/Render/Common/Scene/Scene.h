#pragma once

#include "../Node/import.h"
#include "../View/import.h"

namespace render
{
	// 场景
	class Scene : public Node
	{
	public:
		Scene();
		virtual ~Scene();
	public:
		virtual bool init();
		// 获取视图
		View* getView();
		// 设置视图
		void setView(View* view);
	protected:
		// 视图
		View* _view;
	};
}