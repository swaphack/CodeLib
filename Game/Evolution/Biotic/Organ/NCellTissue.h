#pragma once

#include "macros.h"
#include <map>

namespace nature
{
	
	/**
	*	组织（英语：Tissue）是界于细胞，及器官之间的细胞架构，由许多形态相似的细胞及细胞间质所组成。
	*	因此它又被称为生物组织。
	*/
	class NCellTissue : public NObject
	{
	public:
		NCellTissue();
		virtual ~NCellTissue();
	public:
		// 添加细胞
		void addCell(NCell* pCell);
		// 移除细胞
		void removeCell(NCell* pCell);
		// 移除所有细胞
		void removeAllCells();
		// 同化
		virtual bool input(NObject* pObject);
	protected:
		// 异化回调
		virtual void onOuputHandler(NObject* pObject);
	private:
		// 细胞集
		std::map<int, NCell*> _cellDict;
	};
}