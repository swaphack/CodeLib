#include "people/Person.h"

using namespace game;

int main(int argc, char** argv)
{
	Person* pPerson = new Person();
	pPerson->setGender(EG_MALE);
	pPerson->setCountry(1);
	pPerson->setBirthDay(2);

	delete pPerson;
	return 0;
}