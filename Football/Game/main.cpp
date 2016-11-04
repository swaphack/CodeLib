#include "instance/World.h"
#include "instance/Component.h"
#include "instance/Person.h"
#include "instance/Player.h"


using namespace game;

int main(int argc, char** argv)
{
	Person* pPerson = new Person();
	pPerson->setCountry(1);
	pPerson->setBirthDay(2);
	pPerson->getComponent<Body>()->setPositionX(0.5f);
	pPerson->getComponent<Body>()->setPositionY(0.5f);
	pPerson->getComponent<Body>()->setPositionZ(0.5f);

	Player* pPlayer = new Player();
	pPlayer->addCloneComponent(pPerson);

	Person* pComponent = pPlayer->getComponent<Person>();

	delete pPerson;
	delete pPlayer;

	return 0;
}