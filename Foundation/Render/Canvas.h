#pragma once

#include "Common/common.h"

namespace render
{
	enum Dimensions
	{
		ED_NONE,
		ED_2D,
		ED_3D
	};

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
		void setDimensions(Dimensions d);
		// 获取维度
		Dimensions getDimensions();
		// 设置视窗
		void setViewPort(float x, float y, float width, float height);
		// 获取场景
		Scene* getRoot();
	private:
		// 场景
		Scene* _root;
		// 视图
		View* _view;
		// 维度
		Dimensions _dimensions;
		// 动作管理
		ActionManager* _actionManager;
	};
}