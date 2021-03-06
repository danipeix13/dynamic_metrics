/*
 *    Copyright (C) 2022 by Daniel Peix del Río
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
	\brief
	@author Daniel Peix del Río
*/

#ifndef DYNAMIC_METRICS_H
#define DYNAMIC_METRICS_H

#include <variant>
#include <QtCore>
#include <functional>

template<typename T>
class Dynamic_metrics
{
	private:
		std::map<std::string, std::function<float(T)>> metrics;

	public:
		Dynamic_metrics() {};

		~Dynamic_metrics() {};

		void addMetric(const std::string &name, std::function<float(T)> metricFunction)
        {
            metrics.insert(std::make_pair(name, metricFunction));
        }

        float getMetric(const std::string &name, const T &param)
        {
            return metrics.find(name)->second(param);
        }
};

#endif
