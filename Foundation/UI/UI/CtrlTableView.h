#pragma once


#include "CtrlScrollView.h"

namespace ui
{
	/*
	*	����Դ
	*/
	class TableDataProtocol
	{
	public:
		TableDataProtocol() {}
		virtual ~TableDataProtocol() {}
	public:
		/**
		*	������
		*/
		virtual int getDataCount() = 0;
		/**
		*  ��С
		*/
		virtual math::Size getDataSize(int index) = 0;
		/**
		*  �ؼ�
		*/
		virtual ui::CtrlWidget* getDataCell(int index) = 0;
	};
	/*
	*	�����ͼ
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
		*	����Դ
		*/
		void setTableData(TableDataProtocol* tableData);
		/**
		*	����Դ
		*/
		const TableDataProtocol* getTableData() const;
		/**
		*	����Դ
		*/
		void reload();
	protected:
		/**
		*	��������
		*/
		void processData();
		/**
		*	������
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
		*	����Դ
		*/
		TableDataProtocol* _sourceData = nullptr;
		/**
		*	����Դ��
		*/
		std::map<int, TableCell> _tabelCells;
	};
}