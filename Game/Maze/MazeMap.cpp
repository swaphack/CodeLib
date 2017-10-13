#include "MazeMap.h"
#include "Maze.h"

MazeMap::MazeMap()
{

}

MazeMap::~MazeMap()
{

}

bool MazeMap::init()
{
	return render::Node::init();
}

void MazeMap::flush(Maze* maze)
{
	if (maze == nullptr)
	{
		return;
	}

	this->removeAllChildren();

	sys::Size cellSize;
	cellSize.width = this->getVolume().width / (maze->getSize().width - 1);
	cellSize.height = this->getVolume().height / (maze->getSize().height - 1);

	std::list<MazeNode*>::const_iterator cit = maze->beginNode();
	while (cit != maze->endNode())
	{
		MazeDrawNode* node = CREATE_NODE(MazeDrawNode);
		node->setData(*cit, cellSize);
		this->addChild(node);
		cit++;
	}
}

//////////////////////////////////////////////////////////////////////////
MazeDrawNode::MazeDrawNode()
{

}

MazeDrawNode::~MazeDrawNode()
{

}

bool MazeDrawNode::init()
{
	return render::Node::init();
}

void MazeDrawNode::setData(MazeNode* data, const sys::Size& cellSize)
{
	if (data == nullptr)
	{
		return;
	}

	sys::Vector2 pos;
	pos.x = data->pos.x * cellSize.width;
	pos.y = data->pos.y * cellSize.height;

	this->setPosition(pos);

	render::CtrlText* pCtrlText = CREATE_NODE(render::CtrlText);
	pCtrlText->setFontPath("font_1.ttf");
	pCtrlText->setFontSize(24);
	pCtrlText->setString(getCString("%d-%d", (int)data->pos.x, (int)data->pos.y));
	pCtrlText->setVerticalAlignment(render::EVA_CENTER);
	pCtrlText->setColor(sys::Color4B(200, 200, 200, 255));
	this->addChild(pCtrlText);

	if (data->value == 1)
	{
		return;
	}

	std::set<MazeNode*>::const_iterator cit = data->adjacents.begin();
	while (cit != data->adjacents.end())
	{
		if ((*cit)->value == 0)
		{
			render::DrawNode* pDrawNode = CREATE_NODE(render::DrawNode);
			pDrawNode->setDrawMode(EBM_LINES);
			pDrawNode->setWidth(cellSize.width);
			pDrawNode->setColor(sys::Color3B(0, 255, 255));

			sys::Vector2 point;
			pDrawNode->appendPoint(point);

			point.x = ((*cit)->pos.x - data->pos.x) * cellSize.width;
			point.y = ((*cit)->pos.y - data->pos.y) * cellSize.height;
			pDrawNode->appendPoint(point);

			this->addChild(pDrawNode);
		}
		cit++;
	}
}
