#pragma once

#include "macros.h"
#include "AudioProtocol.h"
#include "Common/struct/enum_common.h"
#include "Common/struct/shape_common.h"

namespace render
{
	class CtrlAudioGeometryPolygon;

	// ��Ƶ��������
	class CtrlAudioGeometry : public Node
	{
	public:
		CtrlAudioGeometry();
		virtual ~CtrlAudioGeometry();
	public:
		virtual bool init();
		// ����
		bool load(const GeometryData* data);
		// ����
		bool save(GeometryData* data);

		// ��ʼ��
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
		// ��������
		FMOD::Geometry* _geometry;
		// ��������Ϣ
		AudioSpace _geometryBody;
		// ���������
		int _maxPolygonCount;
		// ������ζ�����
		int _maxVerticesCount;
		// ����
		CtrlAudioGeometryPolygon* _polygons[(uint8_t)CubeFace::MAX];
		// �����嶥��
		CubeVectices _cubeVertex;
	};

	//////////////////////////////////////////////////////////////////////////
	// ��Ƶ������
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

		// ���ö���
		bool setVertexes(const math::Vector3* vertexes, int numvertices);
		bool setVertexes(const std::vector<math::Vector3>& vertexes);
		bool setVertexes(const RectVectices& vertexes);
		// ��Ӷ���
		bool updateVertex(int index, const math::Vector3& vertex);
	protected:
		void onPolygonChange();
		void onAttributeChange();
	private:
		int _index;
		// ��������
		FMOD::Geometry* _geometry;
		// ����
		GeometrySettings _geometrySettings;
		// ����
		std::vector<math::Vector3> _vertexes;
		// ʵ�ʶ�������
		FMOD_VECTOR* _realVertexes;
		// ʵ�ʶ���������
		int _realVerticeCount;

	};
}