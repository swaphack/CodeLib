#include "CtrlTextAtlas.h"
#include "toollib.h"
#include "CtrlImage.h"

ui::CtrlTextAtlas::CtrlTextAtlas()
{
	_content = CREATE_NODE(ui::CtrlWidget);
	this->addProtectedWidget(_content);

	this->setTextHorizontalAlignment(sys::HorizontalAlignment::CENTER);
	this->setTextVerticalAlignment(sys::VerticalAlignment::MIDDLE);
}

ui::CtrlTextAtlas::~CtrlTextAtlas()
{
	SAFE_RELEASE(_shaderProgram);
}

bool ui::CtrlTextAtlas::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	addNotifyListener(render::NodeNotifyType::TEXT, [this]() {
		onTextChange();
		onTextBodyChange();
	});

	addNotifyListener(render::NodeNotifyType::BODY, [this]() {
		onTextBodyChange();
	});

	return true;
}

void ui::CtrlTextAtlas::setImagePath(const std::string& imagePath)
{
	_textDefine.filepath = imagePath;
	this->notify(render::NodeNotifyType::TEXT);
}

const std::string& ui::CtrlTextAtlas::getImagePath() const
{
	return _textDefine.filepath;
}

void ui::CtrlTextAtlas::setString(const std::string& text)
{
	TextProtocol::setString(text);
	_textDefine.text = text;

	this->notify(render::NodeNotifyType::TEXT);
}

void ui::CtrlTextAtlas::setHorizontalDistance(float distance)
{
	_textDefine.horizontalDistance = distance;

	this->notify(render::NodeNotifyType::TEXT);
}

float ui::CtrlTextAtlas::getHorizontalDistance() const
{
	return _textDefine.horizontalDistance;
}

void ui::CtrlTextAtlas::setVerticalDistance(float distance)
{
	_textDefine.verticalDistance = distance;

	this->notify(render::NodeNotifyType::TEXT);
}

float ui::CtrlTextAtlas::getVerticalDistance() const
{
	return _textDefine.verticalDistance;
}

void ui::CtrlTextAtlas::setBorder(bool bBorder)
{
	_textDefine.border = bBorder;
	this->notify(render::NodeNotifyType::TEXT);
}

bool ui::CtrlTextAtlas::isBorder() const
{
	return _textDefine.border;
}

void ui::CtrlTextAtlas::setTextHorizontalAlignment(sys::HorizontalAlignment alignment)
{
	_textDefine.horizontalAlignment = alignment;

	this->notify(render::NodeNotifyType::TEXT);
}

sys::HorizontalAlignment ui::CtrlTextAtlas::getTextHorizontalAlignment() const
{
	return _textDefine.horizontalAlignment;
}

void ui::CtrlTextAtlas::setTextVerticalAlignment(sys::VerticalAlignment alignment)
{
	_textDefine.verticalAlignment = alignment;

	this->notify(render::NodeNotifyType::TEXT);
}

sys::VerticalAlignment ui::CtrlTextAtlas::getTextVerticalAlignment() const
{
	return _textDefine.verticalAlignment;
}

void ui::CtrlTextAtlas::setTextDimensions(float width, float height)
{
	_textDefine.dimensions.setWidth(width);
	_textDefine.dimensions.setHeight(height);

	this->notify(render::NodeNotifyType::TEXT);
}

void ui::CtrlTextAtlas::setTextDimensions(const math::Size& size)
{
	_textDefine.dimensions = size;
	this->notify(render::NodeNotifyType::TEXT);
}

const math::Size& ui::CtrlTextAtlas::getTextDimensions() const
{
	return _textDefine.dimensions;
}

void ui::CtrlTextAtlas::setTextColor(const phy::Color3B& color)
{
	_textDefine.color = color;
	this->notify(render::NodeNotifyType::TEXT);
}

const phy::Color3B& ui::CtrlTextAtlas::getTextColor() const
{
	return _textDefine.color;
}

ui::CtrlWidget* ui::CtrlTextAtlas::getContent() const
{
	return _content;
}

math::Size ui::CtrlTextAtlas::getContentSize() const
{
	return _content->getSize();
}

void ui::CtrlTextAtlas::setTexShaderProgram(render::ShaderProgram* shaderProgram)
{
	SAFE_RETAIN(shaderProgram);
	SAFE_RELEASE(_shaderProgram);
	_shaderProgram = shaderProgram;
	_content->foreachChildWitchRecrusive([shaderProgram](Node* node) {
		render::DrawTexture2D* pTexture2D = node->as<render::DrawTexture2D>();
		if (pTexture2D)
		{
			pTexture2D->setShaderProgram(shaderProgram);
		}
	});
	
}

void ui::CtrlTextAtlas::setCamera(const render::Camera* camera)
{
	CtrlWidget::setCamera(camera);
	_content->setCamera(camera);
	_content->foreachChildWitchRecrusive([camera](Node* node) {
		node->setCamera(camera);
	});
}

void ui::CtrlTextAtlas::setUseDesignCamera(bool bUsed)
{
	CtrlWidget::setUseDesignCamera(bUsed);
	_content->setUseDesignCamera(bUsed);
	_content->foreachChildWitchRecrusive([bUsed](Node* node) {
		node->setUseDesignCamera(bUsed);
	});
}

void ui::CtrlTextAtlas::onTextBodyChange()
{
	if (_content == nullptr)
	{
		return;
	}

	float w = _content->getWidth();
	float h = _content->getHeight();

	if (_volume.getWidth() != 0 && _volume.getHeight() != 0)
	{
		math::Size srcSize = math::Size(w, h);
		math::Vector3 anchor;
		math::Vector3 orgin;

		getOrgin(srcSize, getSize(),
			_textDefine.horizontalAlignment, _textDefine.verticalAlignment,
			anchor, orgin);

		_content->setPosition(orgin);
		_content->setAnchorPoint(anchor);
	}
}

void ui::CtrlTextAtlas::onTextChange()
{
	_content->removeAllChildren();
	if (_textDefine.text.empty() || _textDefine.filepath.empty())
	{
		return;
	}

	auto pFontAtlas = G_TEXT_CACHE->getFontAtlas(_textDefine.filepath);
	if (pFontAtlas == nullptr)
	{
		return;
	}

	int length = -1;
	wchar_t* dest = sys::CharsetHelper::convertToWideCharWnd(_textDefine.text.c_str(), length);
	if (dest == nullptr || length == -1)
	{
		return;
	}

	float offsetX = 0;
	float offsetY = 0;
	
	float posX = 0;
	float posY = 0;

	float width = _textDefine.dimensions.getWidth();
	float height = _textDefine.dimensions.getHeight();

	float offsetHeight = pFontAtlas->getLineHeight();
	float fontSize = pFontAtlas->getFontSize();

	wchar_t* ptr = dest;
	int offset = 0;
	bool bBreak = false;
	int dataWidth = 0;
	int dataHeight = 0;
	uint64_t ch = 0;
	std::string name;

	while (*ptr != 0 && offset < length)
	{
		bBreak = false;
		ch = *ptr;
		if (ch == 10) {// 换行
			offsetY += offsetHeight;
			offsetX = 0;
			bBreak = true;
		} else if (ch == 13) { // 行首
			offsetX = 0;
			bBreak = true;
		} else if (ch == 32) { // 空格
			offsetX += 0.5f * fontSize;
			if (width > 0 && offsetX >= width)
			{
				offsetX = 0;
				offsetY += offsetHeight;
			}
			bBreak = true;
		}

		if (bBreak)
		{
			ptr++;
			offset++;
			continue;
		}

		name = G_TEXT_CACHE->getCharName(ch);
		auto data = pFontAtlas->getChip(name);
		if (data == nullptr)
		{// 空格
			ptr++;
			offset++;
			continue;
		}
		else
		{
			render::DrawTexture2D* pTexture2D = CREATE_NODE(render::DrawTexture2D);
			if (pTexture2D)
			{
				dataWidth = data->rotate ? data->height : data->width;
				dataHeight = data->rotate ? data->width : data->height;
				if (width > 0 && offsetX + dataWidth >= width)
				{
					offsetX = 0;
					offsetY += offsetHeight;
				}
				posX = offsetX;
				if (height == 0){
					if (width == 0) posY = data->deltaY;
					else posY = -offsetY + data->deltaY;
				} else {
					posY = height - offsetY + data->deltaY - offsetHeight;
				}
				//pTexture2D->setTextureRotateEnabled(false);
				//pTexture2D->setRotationZ(data->rotate ? 90 : 0);
				pTexture2D->setCamera(_content->getCamera());
				pTexture2D->setUseDesignCamera(_content->isUsedDesignCamera());
				pTexture2D->setShaderProgram(_shaderProgram);
				pTexture2D->loadImage(G_TEXT_CACHE->getAtlasName(_textDefine.filepath, name));
				pTexture2D->setPosition(posX, posY);
				pTexture2D->setAnchorPoint(0, 0);
				pTexture2D->setVolume(dataWidth, dataHeight);
				pTexture2D->setColor(_textDefine.color);
				pTexture2D->setNativeTextureSize();
				_content->addChild(pTexture2D);
				offsetX += dataWidth;
			}
		}
		
		ptr++;
		offset++;
	}
	free(dest);
	float w = width == 0 ? offsetX : width;
	float h = height == 0 ? offsetY + offsetHeight : height;
	_content->setAnchorPoint(0,0);
	_content->setVolume(w, h);
}


void ui::CtrlTextAtlas::getOrgin(
	const math::Size& srcSize, const math::Size& destSize,
	sys::HorizontalAlignment horizontal, sys::VerticalAlignment vertical,
	math::Vector3& anchor, math::Vector3& position)
{
	if (vertical == sys::VerticalAlignment::BOTTOM)
	{
		anchor.setY(0);
		position.setX(0);
	}
	else if (vertical == sys::VerticalAlignment::MIDDLE)
	{
		anchor.setY(0.5f);
		position.setY((destSize.getHeight() - srcSize.getHeight()) * 0.5f);
	}
	else if (vertical == sys::VerticalAlignment::TOP)
	{
		anchor.setY(1.0f);
		position.setY(destSize.getHeight() - srcSize.getHeight());
	}

	if (horizontal == sys::HorizontalAlignment::LEFT)
	{
		anchor.setX(0.0f);
		position.setX(0);
	}
	else if (horizontal == sys::HorizontalAlignment::CENTER)
	{
		anchor.setX(0.5f);
		position.setX((destSize.getWidth() - srcSize.getWidth()) * 0.5f);
	}
	else if (horizontal == sys::HorizontalAlignment::RIGHT)
	{
		anchor.setX(1.0f);
		position.setX(destSize.getWidth() - srcSize.getWidth());
	}
}