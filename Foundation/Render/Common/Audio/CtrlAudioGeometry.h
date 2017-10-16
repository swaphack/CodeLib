#pragma once

#include "macros.h"
#include "AudioProtocol.h"

namespace render
{
	class DrawNode;
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

		void setForward(const sys::Vector3& forward);
		const sys::Vector3& getForward();

		void setUp(const sys::Vector3& up);
		const sys::Vector3& getUp();

		int getMaxPolygons();
		int getMaxVertices();

		int getPolygonsCount();
		int getVerticesCount();

		CtrlAudioGeometryPolygon* getPolygon(ModelFace face);
	protected:
		CtrlAudioGeometryPolygon* addPolygon(const std::vector<sys::Vector3>& vertexes);
		CtrlAudioGeometryPolygon* addPolygon(const RectVertex& vertexes);
		const RectVertex& getRectVertex(int i);
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
		CtrlAudioGeometryPolygon* _polygons[EMF_MAX];
		// 立方体顶点
		CubeVertex _cubeVertex;
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
		bool setVertexes(const sys::Vector3* vertexes, int numvertices);
		bool setVertexes(const std::vector<sys::Vector3>& vertexes);
		bool setVertexes(const RectVertex& vertexes);
		// 添加顶点
		bool updateVertex(int index, const sys::Vector3& vertex);
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
		std::vector<sys::Vector3> _vertexes;
		// 实际顶点坐标
		FMOD_VECTOR* _realVertexes;
		// 实际顶点坐标数
		int _realVerticeCount;

	};
}