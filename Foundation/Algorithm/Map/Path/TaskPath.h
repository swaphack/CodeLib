#pragma once

#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

namespace alg
{
	/*
	*	����·��
	*/

	typedef int LINE_NAME;
	typedef int POINT_VALUE;

	/*
	*	����·��
	*/
	//template<typename LINE_NAME, typename POINT_VALUE>
	class TaskPath
	{
	public:
		/*
		*	�ڵ�
		*/
		struct Point
		{
			// ����
			POINT_VALUE value;

			std::set<Point*> pre;
			std::set<Point*> next;

			Point() {}
			Point(const POINT_VALUE& val) :value(val) {}
			/**
			*	�Ƿ���aǰ��
			*/
			bool isFrontOf(Point* a)
			{
				if (a == nullptr) return false;
				if (a->pre.size() == 0) return false;
				auto ret = a->pre.find(this) != a->pre.end();
				if (ret) return ret;
				for (auto point : a->pre)
				{
					if (this->isFrontOf(point)) return true;
				}

				return false;
			}
			/**
			*	�Ƿ���a���
			*/
			bool isNextTo(Point* a)
			{
				if (a == nullptr) return false;
				if (a->next.size() == 0) return false;
				auto ret = a->next.find(this) != a->next.end();
				if (ret) return ret;
				for (auto point : a->next)
				{
					if (this->isNextTo(point)) return true;
				}

				return false;
			}
		};
		/*
		*	��·
		*/
		struct Line
		{
			// ����
			LINE_NAME name;
			// ��
			std::vector<Point*> points;

			Line() {}
			Line(const LINE_NAME& nam) :name(nam) {}
		};

		/*
		*	��·�ϵĵ�
		*/
		struct PathPoint
		{
			Point* point = nullptr;
			// ��
			std::vector<PathPoint*> nextPoints;
		};
	public:
		TaskPath() 
		{
		}
		~TaskPath() 
		{
			this->cleanup();
		}
	public:
		void addLine(const LINE_NAME& name, const POINT_VALUE& value0)
		{
			std::vector<POINT_VALUE> points;
			points.push_back(value0);
			this->addLine(name, points);
		}
		void addLine(const LINE_NAME& name, const POINT_VALUE& value0, const POINT_VALUE& value1)
		{
			std::vector<POINT_VALUE> points;
			points.push_back(value0);
			points.push_back(value1);
			this->addLine(name, points);
		}
		void addLine(const LINE_NAME& name, const POINT_VALUE& value0, const POINT_VALUE& value1, const POINT_VALUE& value2)
		{
			std::vector<POINT_VALUE> points;
			points.push_back(value0);
			points.push_back(value1);
			points.push_back(value2);
			this->addLine(name, points);
		}
		void addLine(const LINE_NAME& name, const std::vector<POINT_VALUE>& points)
		{
			auto pLine = getOrCreateLine(name);

			for (const auto& item : points)
			{
				auto pPoint = getOrCreatePoint(item);
				pLine->points.push_back(pPoint);
			}
		}
	public:
		/*
		*	����������·���׸��ڵ�
		*/
		std::vector<POINT_VALUE> findFirstPointsOfAllLines()
		{
			std::vector<POINT_VALUE> values;
			for (const auto& item : _lines)
			{
				if (item.second->points.size() > 0)
				{
					values.push_back(item.second->points[0]->value);
				}
			}
			return values;
		}
		/*
		*	����������·���׸������ڵ�,����Щ�ڵ㲻�����Ⱥ�˳��
		*/
		std::vector<POINT_VALUE> findFirstIndependentPoints()
		{
			// ������ϵ��
			initPointMap();

			std::vector<Point*> firstPoints;
			for (const auto& item : _lines)
			{
				if (item.second->points.size() > 0)
				{
					const auto& point = item.second->points[0];
					firstPoints.push_back(_points[point->value]);
				}
			}
			std::vector<POINT_VALUE> values;
			for (const auto& item : firstPoints)
			{
				if (item->pre.size() == 0)
				{// ��ǰ�̣�ȡ��
					values.push_back(item->value);
				}
			}
			return values;
		}

		/*
		*	������·��������·�����о����Ľڵ�
		*/
		std::vector<POINT_VALUE> findTriggerPointsWithLine(const std::vector<LINE_NAME>& triggerLines)
		{
			// ������ϵ��
			initPointMap();

			std::vector<const Line*> lines;
			for (const auto& item : triggerLines)
			{
				auto line = getLine(item);
				if (line) lines.push_back(line);
			}
			std::vector<Point*> points;
			for (const auto& item : lines)
			{

			}

			return values;
		}

		/**
		*	��ȡ����Ϣ
		*/
		const Point* getPoint(const POINT_VALUE& value)
		{
			auto it = _points.find(value);
			if (it == _points.end()) return nullptr;
			return it->second;
		}
		/**
		*	��ȡ��·��Ϣ
		*/
		const Line* getLine(const LINE_NAME& value)
		{
			auto it = _lines.find(value);
			if (it == _lines.end()) return nullptr;
			return it->second;
		}
	protected:
		/**
		*	��ȡ����Ϣ����������ڣ�����һ��
		*/
		Point* getOrCreatePoint(const POINT_VALUE& value)
		{
			auto it = _points.find(value);
			if (it != _points.end()) return it->second;
			auto point = new Point(value);
			_points[value] = point;
			return point;
		}
		/**
		*	��ȡ·����Ϣ����������ڣ�����һ��
		*/
		Line* getOrCreateLine(const LINE_NAME& value)
		{
			auto it = _lines.find(value);
			if (it != _lines.end()) return it->second;
			auto line = new Line(value);
			_lines[value] = line;
			return line;
		}
		/**
		*	��ʼ������
		*/
		void initPointMap()
		{
			if (_points.size() != 0)
			{
				return;
			}
			for (const auto& item : _lines)
			{
				Point* pre = nullptr;
				for (const auto& point : item.second->points)
				{
					Point* point = _points[point->value];
					if (pre == nullptr)
					{
						pre = point;
						continue;
					}
					else
					{
						point->pre.insert(pre);
						pre->next.insert(point);
					}
				}
			}
		}
		/**
		*	����
		*/
		void cleanup()
		{
			for (auto& item :_lines)
			{
				delete item.second;
			}

			for (auto& item : _points)
			{
				delete item.second;
			}

			_lines.clear();
			_points.clear();
		}
	private:
		// ��·
		std::map<LINE_NAME, Line*> _lines;
		// ��
		std::map<POINT_VALUE, Point*> _points;
	};
}
