#include "Model.h"
#include "Resource/Detail/ModelDetail.h"
#include "Graphic/DCSample/DCModel.h"
#include "Graphic/Command/DrawCommander.h"

using namespace render;


Model::Model()
{
}

Model::~Model()
{
	SAFE_DELETE(_modelDetail);
}

void Model::draw()
{
	if (_modelDetail == nullptr)
	{
		return;
	}
	
	G_DRAWCOMMANDER->addCommand(DCModel::create(_modelDetail, _color, _opacity, _blend));
}

void Model::setModelData(const ModelDetail* detail)
{
	SAFE_DELETE(_modelDetail);
	_modelDetail = (ModelDetail*)detail;
}

const ModelDetail* Model::getModelData()
{
	return _modelDetail;
}
