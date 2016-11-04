#pragma once

namespace game
{
	class PropertySheet;
	class ComponentSheet;
	/**
	*	组件
	*/
	class IComponent
	{
	public:
		virtual ~IComponent() {}
	public:
		/**
		*	组件类型
		*/
		virtual const char* getType() = 0;
		/**
		*	获取属性列表
		*/
		virtual PropertySheet* getPropertySheet() = 0;
		/**
		*	获取组件列表
		*/
		virtual ComponentSheet* getComponentSheet() = 0;
		/**
		*	克隆
		*/
		virtual IComponent* clone() = 0;
		/**
		*	复制信息到目标组件
		*/
		virtual bool copyTo(IComponent*) = 0;
		/**
		*	复制组件信息
		*/
		virtual bool copy(IComponent* pComponent) = 0;
	};
}