#pragma once

class Random
{
private:
	Random();
	~Random();
public:
	static Random* GetInstance();
public:
	void SetSeed(int seed);
	int Next(int minVal, int maxVal);
	float Next(float minVal, float maxVal);
	float Next();
};