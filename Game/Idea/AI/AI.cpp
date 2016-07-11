#include "AI.h"

using namespace idea;


AI::AI()
{
	_analysis = new Analysis();
	_solution = new Solution();
	_experience = new Experience();
	_study = new Study();
}

AI::~AI()
{
	SAFE_DELETE(_analysis);
	SAFE_DELETE(_solution);
	SAFE_DELETE(_experience);
	SAFE_DELETE(_study);
}

Result* AI::run(Event* e)
{

}
