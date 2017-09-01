#pragma once

// 职位类型
enum class JOB
{
	// 剑士
	SWORD,
	// 弓兵
	ARCHER,
	// 骑兵
	KNIGHT,
};

// 特性
enum class ATTRIBUTE
{
	NONE,
	// 攻击
	ATK,
	// 防御
	DEF,
	// 血量
	HP,
	// 攻击范围
	RNG,
	// 移动速度
	MOV,
	// 攻击间隔
	ITV,
};

// 状态
enum class Status
{
	NONE,
	// 属性
	ATTRIBUTE,
	// 沉默
	SILENCE,
	// 眩晕 
	DIZZINESS,
	// 嘲讽
	TAUNT,
	// 恐惧
	FEAR,
	// 禁锢
	IMPRISONED,
	// 致盲
	BLINDING,
	// 隐身
	STEALTH,
};