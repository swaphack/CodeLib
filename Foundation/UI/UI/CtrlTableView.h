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
		virtual math::Size getDataSize(int index, int& tag) = 0;
		/**
		*  �ؼ�
		*/
		virtual ui::CtrlWidget* getDataCell(int index, int tag) = 0;
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
			int index = -1;
			math::Vector2 position;
			int type = 0;
			math::Size size;
			ui::CtrlWidget* widget = nullptr;
		};

		/**
		*	���ؿؼ�
		*/
		void hideWidget(TableCell* cell);
		/**
		*	��ȡ�ؼ�
		*/
		ui::CtrlWidget* getWidgetCell(int index);
	protected:
		/**
		*	����Դ
		*/
		TableDataProtocol* _sourceData = nullptr;
		/**
		*	����Դ��
		*/
		std::map<int, TableCell> _tabelCells;
		/**
		*	�ؼ� {���ͣ�{�ؼ�}}
		*/
		std::map<int, std::vector<ui::CtrlWidget*>> _tableWidgets;
	};
}