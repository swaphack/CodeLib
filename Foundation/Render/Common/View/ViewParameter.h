#pragma once

namespace render
{
	// �Ӵ�����
	struct ViewParameter
	{
		float xLeft = 0;
		float xRight = 0;
		float yBottom = 0;
		float yTop = 0;
		float zNear = 0.1f;
		float zFar = 1000;
	};
}
