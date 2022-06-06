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

void Dynamic_metrics::addMetric(const std::string &metricName, std::function<PAR(PAR)> metricFunction)
{
	qDebug() << __FUNCTION__;
	//metrics.insert(std::make_pair(metricName, metricFunction));
}

PAR Dynamic_metrics::getMetric(const std::string &name, const std::vector<PAR> &params_list)
{
	qDebug() << __FUNCTION__;
	auto f = metrics.find(name);
	auto res = f->second(params_list[0]);

    PAR kk = 4;
	return res;
}


