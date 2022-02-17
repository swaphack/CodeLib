#pragma once

#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

namespace alg
{
	/*
	*	任务路线
	*/

	typedef int LINE_NAME;
	typedef int POINT_VALUE;

	/*
	*	任务路线
	*/
	//template<typename LINE_NAME, typename POINT_VALUE>
	class TaskPath
	{
	public:
		/*
		*	节点
		*/
		struct Point
		{
			// 内容
			POINT_VALUE value;

			std::set<Point*> pre;
			std::set<Point*> next;

			Point() {}
			Point(const POINT_VALUE& val) :value(val) {}
			/**
			*	是否在a前面
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
			*	是否在a后边
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
		*	线路
		*/
		struct Line
		{
			// 名称
			LINE_NAME name;
			// 点
			std::vector<Point*> points;

			Line() {}
			Line(const LINE_NAME& nam) :name(nam) {}
		};

		/*
		*	线路上的点
		*/
		struct PathPoint
		{
			Point* point = nullptr;
			// 点
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
		*	查找所有线路的首个节点
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
		*	查找所有线路的首个独立节点,且这些节点不存在先后顺序
		*/
		std::vector<POINT_VALUE> findFirstIndependentPoints()
		{
			// 创建关系表
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
				{// 无前继，取出
					values.push_back(item->value);
				}
			}
			return values;
		}

		/*
		*	根据线路，所有线路上所有经过的节点
		*/
		std::vector<POINT_VALUE> findTriggerPointsWithLine(const std::vector<LINE_NAME>& triggerLines)
		{
			// 创建关系表
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
		*	获取点信息
		*/
		const Point* getPoint(const POINT_VALUE& value)
		{
			auto it = _points.find(value);
			if (it == _points.end()) return nullptr;
			return it->second;
		}
		/**
		*	获取线路信息
		*/
		const Line* getLine(const LINE_NAME& value)
		{
			auto it = _lines.find(value);
			if (it == _lines.end()) return nullptr;
			return it->second;
		}
	protected:
		/**
		*	获取点信息，如果不存在，创建一个
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
		*	获取路线信息，如果不存在，创建一个
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
		*	初始化点网
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
		*	清理
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
		// 线路
		std::map<LINE_NAME, Line*> _lines;
		// 点
		std::map<POINT_VALUE, Point*> _points;
	};
}
