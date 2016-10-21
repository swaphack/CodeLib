#include "Jackpot/import.h"

#include <Windows.h>

#include <cstdlib>
#include <ctime>

using namespace lottery;

struct DrawData
{
	float Probablity;
	int ItemID;
	int ItemCount;
};

static DrawData DataAry[10] = {
	{ 0.01f, 1, 2 },
	{ 0.02f, 2, 2 },
	{ 0.1f, 3, 2 },
	{ 0.2f, 4, 2 },
	{ 0.11f, 5, 2 },
	{ 0.21f, 6, 2 },
	{ 0.012f, 7, 2 },
	{ 0.018f, 8, 2 },
	{ 0.01f, 9, 2 },
	{ 0.3f, 10, 2 },
};

#define MAX_RANDOM 1000

int main(int argc, char** argv)
{
	Draw* pDraw = new Draw();
	pDraw->setJackpot(new Jackpot());
	pDraw->setProbablity(new Probablity());

	for (int i = 0; i < 10; i++)
	{
		pDraw->addReward(DataAry[i].Probablity, DataAry[i].ItemID, DataAry[i].ItemCount);
	}

	srand(time(NULL));

	float random = 0;
	const ItemDetail* pDetail = nullptr;

	while (true)
	{
		Sleep(500);

		random = 1.0f * (rand() % MAX_RANDOM) / MAX_RANDOM;

		printf("random %f\n", random);
		pDetail = pDraw->pick(random);
		if (pDetail)
		{
			printf("I got item!!!\nDetail ID : %d, Count: %d\r\n\r\n", pDetail->ItemID, pDetail->ItemCount);
		}
		else
		{
			printf("Got Noting! It's sad.\r\n\r\n");
		}
	}

	delete pDraw;

	return 0;
}