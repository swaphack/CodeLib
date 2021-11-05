#pragma once


#include "CtrlScrollView.h"

namespace ui
{
	/*
	*	数据源
	*/
	class TableDataProtocol
	{
	public:
		TableDataProtocol() {}
		virtual ~TableDataProtocol() {}
	public:
		/**
		*	总数量
		*/
		virtual int getDataCount() = 0;
		/**
		*  大小
		*/
		virtual math::Size getDataSize(int index) = 0;
		/**
		*  控件
		*/
		virtual ui::CtrlWidget* getDataCell(int index) = 0;
	};
	/*
	*	表格视图
	*/
	class CtrlTableView : public CtrlScrollView
	{
	public:
		CtrlTableView();
		virtual ~CtrlTableView();
	public:
		virtual bool init();
	public:
		/**
		*	数据源
		*/
		void setTableData(TableDataProtocol* tableData);
		/**
		*	数据源
		*/
		const TableDataProtocol* getTableData() const;
		/**
		*	数据源
		*/
		void reload();
	protected:
		/**
		*	处理数据
		*/
		void processData();
		/**
		*	处理触摸
		*/ 
		virtual void handMovedTouch(const math::Vector2& touchPoint);
	protected:
		struct TableCell
		{
			math::Vector2 position;
			math::Size size;
			ui::CtrlWidget* widget = nullptr;
		};
		/**
		*	数据源
		*/
		TableDataProtocol* _sourceData = nullptr;
		/**
		*	数据源项
		*/
		std::map<int, TableCell> _tabelCells;
	};
}