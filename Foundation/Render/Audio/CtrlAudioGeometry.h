#pragma once

#include "macros.h"
#include "AudioProtocol.h"
#include "Common/struct/enum_common.h"
#include "Common/struct/shape_common.h"

namespace render
{
	class CtrlAudioGeometryPolygon;

	// 音频几何特性
	class CtrlAudioGeometry : public Node
	{
	public:
		CtrlAudioGeometry();
		virtual ~CtrlAudioGeometry();
	public:
		virtual bool init();
		// 加载
		bool load(const GeometryData* data);
		// 保存
		bool save(GeometryData* data);

		// 初始化
		bool init(int maxpolygons, int maxvertices);

		void setActive(bool active);
		bool getActive();

		void setForward(const math::Vector3& forward);
		const math::Vector3& getForward();

		void setUp(const math::Vector3& up);
		const math::Vector3& getUp();

		int getMaxPolygons();
		int getMaxVertices();

		int getPolygonsCount();
		int getVerticesCount();

		CtrlAudioGeometryPolygon* getPolygon(CubeFace face);
	protected:
		CtrlAudioGeometryPolygon* addPolygon(const std::vector<math::Vector3>& vertexes);
		CtrlAudioGeometryPolygon* addPolygon(const RectVectices& vertexes);
		const RectVectices& getRectVertex(int i);
		void onGeometryChange();
		void onPolygonsChange();
	private:
		// 几何特性
		FMOD::Geometry* _geometry;
		// 几何体信息
		AudioSpace _geometryBody;
		// 最大多边形数
		int _maxPolygonCount;
		// 最大多边形顶点数
		int _maxVerticesCount;
		// 六面
		CtrlAudioGeometryPolygon* _polygons[(uint8_t)CubeFace::MAX];
		// 立方体顶点
		CubeVectices _cubeVertex;
	};

	//////////////////////////////////////////////////////////////////////////
	// 音频几何体
	class CtrlAudioGeometryPolygon : public Node
	{
	public:
		CtrlAudioGeometryPolygon();
		virtual ~CtrlAudioGeometryPolygon();
	public:
		virtual bool init();

		void setGeometry(FMOD::Geometry* geometry);

		int getIndex();

		void setDirectOcclusion(float value);
		float getDirectOcclusion();

		void setReverbOcclusion(float value);
		float getReverbOcclusion();

		void setDoubleSided(bool value);
		bool isDoubleSided();

		// 设置顶点
		bool setVertexes(const math::Vector3* vertexes, int numvertices);
		bool setVertexes(const std::vector<math::Vector3>& vertexes);
		bool setVertexes(const RectVectices& vertexes);
		// 添加顶点
		bool updateVertex(int index, const math::Vector3& vertex);
	protected:
		void onPolygonChange();
		void onAttributeChange();
	private:
		int _index;
		// 几何特性
		FMOD::Geometry* _geometry;
		// 配置
		GeometrySettings _geometrySettings;
		// 顶点
		std::vector<math::Vector3> _vertexes;
		// 实际顶点坐标
		FMOD_VECTOR* _realVertexes;
		// 实际顶点坐标数
		int _realVerticeCount;

	};
}