#pragma once

#include "macros.h"
#include <map>

namespace nature
{
	
	/**
	*	��֯��Ӣ�Tissue���ǽ���ϸ����������֮���ϸ���ܹ����������̬���Ƶ�ϸ����ϸ����������ɡ�
	*	������ֱ���Ϊ������֯��
	*/
	class NCellTissue : public NObject
	{
	public:
		NCellTissue();
		virtual ~NCellTissue();
	public:
		// ���ϸ��
		void addCell(NCell* pCell);
		// �Ƴ�ϸ��
		void removeCell(NCell* pCell);
		// �Ƴ�����ϸ��
		void removeAllCells();
		// ͬ��
		virtual bool input(NObject* pObject);
	protected:
		// �컯�ص�
		virtual void onOuputHandler(NObject* pObject);
	private:
		// ϸ����
		std::map<int, NCell*> _cellDict;
	};
}