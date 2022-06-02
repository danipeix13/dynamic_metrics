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

#include "dynamic_metrics.h"

Dynamic_metrics::Dynamic_metrics()
{
	qDebug() << __FUNCTION__;
}

Dynamic_metrics::~Dynamic_metrics()
{
	qDebug() << __FUNCTION__;
}

void Dynamic_metrics::addMetric(string metricName, std::function metricFunction)
{
	qDebug() << __FUNCTION__;
	metrics.insert(std::pair<string, std::function>(metricName, metricFunction));
}

T Dynamic_metrics::getMetrics(string name, std::vector<T> paramsList)
{
	qDebug() << __FUNCTION__;
	std::function f = metrics.find(name);
	T result = f(paramsList); //Esto habrá q modificarlo, obviamente no se puede llamar así
	return result;
}


