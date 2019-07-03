#include "people/Person.h"
#include "object/Cube.h"
#include "base/Identity.h"
#include "base/Dictionary.h"
#include "base/List.h"
#include "world/HumanSheet.h"
#include "base/DataTable.h"

using namespace game;

void testComponent()
{
	Person* p1 = new Person();
	p1->setGender(EG_FEMALE);
	p1->setCountry(1);
	p1->setBirthDay(2);
	p1->setName("fsdafas");

	Cube* c1 = p1->addComponent<Cube>();
	c1->setScale({ 0.5f, 0.5f, 0.3f });

	Person* p2 = p1->clone();
	eGender e = p2->getGender();
	uint64_t c = p2->getCountry();
	uint64_t b = p2->getBirthDay();
	std::string n = p2->getName();

	Cube* c2 = p2->getComponent<Cube>();
	auto scale = c2->getScale();

	delete p1;
	delete p2;
}

void testCollect()
{
	int32_t ary[10] = { 1212, 323, 22, 3123, 232, 3623, 2323, 33, 112, 3333 };
	Dictionary<int32_t, int32_t>* pContainer = new Dictionary<int32_t, int32_t>();
	for (int32_t i = 0; i < 10; i++)
	{
		pContainer->add(ary[i], i);
	}

	pContainer->remove(3623);

	delete pContainer;

	
	List<uint32_t>* pList = new List<uint32_t>();
	pList->add(1212);
	pList->add(121);
	pList->add(321);

	pList->remove(123);
	pList->removeAt(1);

	delete pList;
}

void testContainer()
{
	HumanSheet* pHumanSheet = new HumanSheet();
	Person* pPerson = pHumanSheet->generate();
	pHumanSheet->purge(pPerson);

	delete pHumanSheet;
}

void testData()
{
	RecordHandler func = [](int type, float newValue, float lastValue){
		printf("%d, %f, %f", type, newValue, lastValue);
	};
	DataRecord* pRecord = new DataRecord();
	pRecord->setType(1233);
	pRecord->setValue(121322);
	pRecord->setValueChangedHand(func);
	pRecord->addValue(12);

	delete pRecord;
}

void testMemory()
{
	class A { int a = 1; };
	struct B { int b = 1; };

	printf("%d", sizeof(A));
	printf("%d", sizeof(B));
}

int main(int argc, char** argv)
{
	testMemory();
	return 0;
}