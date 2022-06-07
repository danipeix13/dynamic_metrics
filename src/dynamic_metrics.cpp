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

Dynamic_metrics::Dynamic_metrics() { }

Dynamic_metrics::~Dynamic_metrics() { }

void Dynamic_metrics::addMetric(const std::string &name, std::function<TYPE(std::vector<TYPE>)> metricFunction)
{
	qDebug() << "\t" <<__FUNCTION__;
	metrics.insert(std::make_pair(name, metricFunction));
}

TYPE Dynamic_metrics::getMetric(const std::string &name, const std::vector<TYPE> &param)
{
	qDebug() << "\t" << __FUNCTION__;
    return metrics.find(name)->second(param);

    /* PARA DEPUTACIÓN */
    //	TYPE res;
    //	try
    //	{
    //		auto f = metrics.find(name);
    //		try
    //		{
    //			res = f->second(param);
    //            qDebug() << __FUNCTION__ << "\tTipo del resultado :" << res.type().name();
    //		} catch(std::exception &e){ qDebug() << __FUNCTION__ << "LLAMADA A LA FUNCIÓN" << e.what();}
    //	} catch(std::exception &e){ qDebug() << __FUNCTION__ << "OBTENCIÓN DE LA FUNCIÓN" << e.what();}
    //  return res;
}


