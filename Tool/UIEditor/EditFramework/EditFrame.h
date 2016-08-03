#pragma once

namespace ui
{
	class EditFrame
	{
	public:
		EditFrame();
		virtual ~EditFrame();
	public:
		virtual bool loadConfig(const char* filepath);

	protected:
	private:
	};
}