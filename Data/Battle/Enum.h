#pragma once

// ְλ����
enum class JOB
{
	// ��ʿ
	SWORD,
	// ����
	ARCHER,
	// ���
	KNIGHT,
};

// ����
enum class ATTRIBUTE
{
	NONE,
	// ����
	ATK,
	// ����
	DEF,
	// Ѫ��
	HP,
	// ������Χ
	RNG,
	// �ƶ��ٶ�
	MOV,
	// �������
	ITV,
};

// ״̬
enum class Status
{
	NONE,
	// ����
	ATTRIBUTE,
	// ��Ĭ
	SILENCE,
	// ѣ�� 
	DIZZINESS,
	// ����
	TAUNT,
	// �־�
	FEAR,
	// ����
	IMPRISONED,
	// ��ä
	BLINDING,
	// ����
	STEALTH,
};