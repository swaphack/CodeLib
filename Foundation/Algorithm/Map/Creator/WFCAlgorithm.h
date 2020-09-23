#pragma once

#include <cstdint>
#include <map>
#include "MultiState.h"

namespace alg
{
	namespace map
	{
		class CreateMapProtocol;
		class MapProtocol;
		class Module;
		/**
		*	������̮���㷨
		*
		*
		ȷ��Ҫ���ɵ�ͼ�Ĵ�С��Ȼ�����ÿһ���̶���С��С���򣬿���ÿһ�֡��ֲ���Ϣ�����Ƿ���ܳ��֡���Щ���ʳ�Ϊ���С����ġ�����������
		��ÿ��С����ġ�����������ʼ����һ��ʼ������ͼ�����п������κ�λ�ó��֡�
		�������µ�ѭ����
			ѡ������С�ģ�δȷ����С�����ж���Ļ������ȡһ�������������С��۲⡱�����ݿ��ܵ�ͼ����Ƶ�����ȷ����ʹ�õ�ͼ�������������������ˡ�̮��������



			������е�С����ȷ���ˣ�����ѭ����
			�����һ������û���κεĿ��ܵ�״̬������ʧ�ܡ�


			�����µĹ۲���Ϊ��Χ��С�������ų����Ϸ���ͼ����Ӱ�쵽����Χ���ӵġ�������������

			����������п������µ�С�����ͼ������ȫȷ����

		����С����ʹ�õ�ͼ���õ�����ͼƬ��
		*/
		class WFCAlgorithm
		{
		public:
			WFCAlgorithm();
			virtual ~WFCAlgorithm();
		public:
			void initMap(uint32_t pointCount, const MultiState& states);

			bool autoFillMap(MapProtocol* map, CreateMapProtocol* creator);
		protected:
			/**
			*	������������������
			*/
			bool randomFillPoint(MapProtocol* map, CreateMapProtocol* creator);

			/**
			*	��ָ��Ŀ����Χ��ʼ���
			*/
			bool roundFillPoint(uint32_t nIndex, MapProtocol* map, CreateMapProtocol* creator);

			/**
			*	���õ���Ϣ
			*/
			void setPoint(MapProtocol* map, uint32_t index, uint32_t moduleID);
			/**
			*	���õ���Ϣ
			*/
			void resetPoint(MapProtocol* map, uint32_t index);
			/**
			*	�Ƿ�ȫ��������
			*/
			bool isFinish();

			/**
			*	�����ȡһ��δ����
			*/
			bool getRandomUnFillPoint(uint32_t& index);
			/**
			*	�����ȡһ��������,��ֵ��С
			*/
			bool getRandomFilledPoint(uint32_t& index);

			/**
			*	��ȡָ��λ�õ�ģ����
			*/
			const Module* getModule(CreateMapProtocol* creator, uint32_t index) const;

			/**
			*	��ȡָ��λ�õ�ģ����
			*/
			bool getModuleID(uint32_t index, uint32_t& moduleID) const;
		protected:
			// ��ͼ����
			uint32_t _pointCount = 0;
			// ��ͼ�� {�㣬 ģ��}
			std::map<uint32_t, uint32_t> _mapPoint;
			// δ���õ�
			std::set<uint32_t> _unFillPoint;
			// �����õ�
			std::set<uint32_t> _filledPoint;
			// λ��״̬��
			std::map<uint32_t, MultiState> _pointModules;
			// ״̬
			MultiState _moduleStates;
		};
	}
}
