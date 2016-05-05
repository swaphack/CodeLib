#pragma once

#include "../Node/import.h"
#include "../View/import.h"

namespace render
{
	// ����
	class Scene : public Node
	{
	public:
		Scene();
		virtual ~Scene();
	public:
		virtual bool init();
		
		// ��ȡ��ͼ
		View* getView();
		// ������ͼ
		void setView(View* view);

		// ��ȡ����ͷ
		Camera* getCamera();
	protected:
		// ��ͼ
		View* _view;
	};
}