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

void Dynamic_metrics::addMetric(const std::string &name, std::function<TYPE(TYPE)> metricFunction)
{
	qDebug() << __FUNCTION__;
	metrics.insert(std::make_pair(name, metricFunction));
}

TYPE Dynamic_metrics::getMetric(const std::string &name, const TYPE &param)
{
	qDebug() << __FUNCTION__;
	
	qDebug() << "\tPARAM CHECKING";
	qDebug() << "\tparam type:" << param.type().name();
	// std::vector<int> value = std::any_cast<std::vector<int>>(param);
	// for (int i: value)
	//	 qDebug() << "\t" << i;

	TYPE res;
	try
	{
		auto f = metrics.find(name); 

		try
		{ 
			qDebug() << "\tSTART CALLING";
			res = f->second(param);
            qDebug() << "\tRESULT TYPE :" << res.type().name();
			// qDebug() << "\tRESULT PRINT :" << std::any_cast<int>(res);
			qDebug() << "\tEND CALLING";
		} catch(std::exception &e){ qDebug() << "LLAMAR" << e.what();}
	} catch(std::exception &e){ qDebug() << "OBTENER" << e.what();}

	return res;
}


