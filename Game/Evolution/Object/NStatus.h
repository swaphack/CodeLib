#pragma once

#include "NMark.h"
#include <string>

namespace nature
{
	class NObject;
	class NStatus;
	typedef void (NObject::*NStatusChanged)(NStatus* pStatus);

	// ×´Ì¬
	class NStatus : public NMark
	{
	public:
		NStatus();
		~NStatus();
	public:
		// µ±Ç°×´Ì¬
		void setStatus(bool status);
		bool getStatus();

		// ×¢²á¼àÌı
		void registerChangedHandler(NObject* pTarget, NStatusChanged handler);
		// ÖØÖÃ¼àÌı
		void resetChangedHandler();
	protected:
		virtual void onRunChangedHand();
	private:
		bool _status; // µ±Ç°×´Ì¬
		std::pair<NObject*, NStatusChanged> _trigger; // ´¥·¢Æ÷
	};
}