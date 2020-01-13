#include "Node.h"

using namespace math;

Node::Node()
{

}

Node::~Node()
{

}

Node& Node::operator=(const Node& node)
{
	this->setName(node.getName());
	this->setUserData(node.getUserData());
	this->setTag(node.getTag());

	return *this;
}
