#pragma once

#include "Common/import.h"
#include "Graphic/import.h"
#include <stack>

namespace render
{
	class Canvas
	{
	public:
		Canvas();
		virtual ~Canvas();
	public:
		static Canvas* getInstance();
	public:
		// 绘制图形
		void draw();
		// 更新动作
		void update(float interval);
	public:
		// 设置视窗
		void setViewPort(float x, float y, float width, float height);
	public:
		// 获取视图
		View* getView();
	public:
		// 是否存在场景
		bool hasScene();
		// 压入场景
		void pushScene(Scene* scene);
		// 推出场景
		Scene* popScene();
		// 替换场景
		void replaceScene(Scene* scene);
		// 移除所有场景
		void removeAllScenes();
		// 获取当前场景
		Scene* getCurScene();
	private:
		// 视图
		View* _view;
		// 场景
		std::stack<Scene*> _scenes;

		static Canvas* _sCanvas;
	};
}