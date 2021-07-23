#include "MeshProtocol.h"
#include "PointSet.h"


alg::MeshProtocol::MeshProtocol()
{
}

alg::MeshProtocol::~MeshProtocol()
{
	
}

void alg::MeshProtocol::setPointSet(PointSet* pointSet)
{ 
	_pointSet = pointSet; 
}

alg::PointSet* alg::MeshProtocol::getPointSet() const
{ 
	return _pointSet; 
}
