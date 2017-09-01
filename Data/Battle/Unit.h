#pragma once

class Property;

// 单位
class Unit
{
public:
	Unit();
	virtual ~Unit();
public:
	void SetID(int nID);
	int GetID();

	void retain();
	void release();
public:
	Property* getProperty();
private:
	Property* m_pProperty = nullptr;
	// 编号
	int m_nID = 0;
	// 引用次数
	int m_nRefCount = 0; 
	// 静态引用计数
	static int s_nID;
};