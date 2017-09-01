#pragma once

class Property;

// ��λ
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
	// ���
	int m_nID = 0;
	// ���ô���
	int m_nRefCount = 0; 
	// ��̬���ü���
	static int s_nID;
};