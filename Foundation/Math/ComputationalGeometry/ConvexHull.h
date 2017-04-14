#pragma once

namespace sys
{
	struct Vector2;
	struct Polygon;
}

namespace math
{
	namespace cg
	{
		/**
		*	Í¹°ü
		*/
		class ConvexHull
		{
		public:
			ConvexHull(Vector2* points, int length);
		protected:
		private:
			Polygon m_Polygon;
		};
	}
}