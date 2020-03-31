#pragma once

#include "Common/import.h"
#include "Graphic/import.h"

namespace render
{
	class Canvas
	{
	public:
		Canvas();
		virtual ~Canvas();
	public:
		// 绘制图形
		void draw();
		// 更新动作
		void update(float interval);
		// 设置维度
		void setDimensions(CameraDimensions d);
		// 获取维度
		CameraDimensions getDimensions();
		// 设置视窗
		void setViewPort(float x, float y, float width, float height);
		// 获取场景
		Scene* getRoot();
		// 获取视图
		View* getView();
		// 动作管理
		inline const ActionManager* getActionManager() { return _actionManager; }
		// 触摸管理
		inline const TouchManager* getTouchManager() { return _touchManager; }
		// 绘制管理
		inline const DrawCommander* getDrawCommander() { return _drawCommander; }
	private:
		// 场景
		Scene* _root;
		// 视图
		View* _view;
		// 维度
		CameraDimensions _dimensions;
		// 动作管理
		ActionManager* _actionManager;
		// 触摸管理
		TouchManager* _touchManager;
		// 绘制管理
		DrawCommander* _drawCommander;
	};
}