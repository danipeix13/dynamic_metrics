/*
 *    Copyright (C) 2022 by YOUR NAME HERE
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
#include "specificworker.h"

/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(TuplePrx tprx, bool startup_check) : GenericWorker(tprx)
{
	this->startup_check_flag = startup_check;
}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker()
{
	qDebug() << __FUNCTION__;
}

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params)
{
	return true;
}

int pruebaSuma(TYPE data)
{
    qDebug() << "\t\tENTRAMOS :)";
	int ret = 0;
	std::vector<std::vector<int>> vec = std::any_cast<std::vector<std::vector<int>>>(data);
	for(std::vector<int> v: vec)
	{
        for(int i: v)
        {
            ret += i;
            qDebug() << "\t\t" << i;
        }
	}
    qDebug() << "\t\tRET: " << ret;
	return ret;
}

void SpecificWorker::initialize(int period)
{
	qDebug() << __FUNCTION__;
	this->Period = period;
	if(this->startup_check_flag)
	{
		this->startup_check();
	}
	else
	{
		timer.start(Period);
	}

	// Inicialización
	Dynamic_metrics m = Dynamic_metrics();
	m.addMetric("prueba", pruebaSuma);

	try
	{
        std::vector<int> a{0, 2, 4}, b{1, 3, 5};
        TYPE param = std::make_any<std::vector<std::vector<int>>>({a, b});
		TYPE res = m.getMetric("prueba", param);
		qDebug() << "RESULT Type:" << res.type().name();

		try
		{
			int resultado = std::any_cast<int>(res);
			qDebug() << "RESULTADO:" << resultado;
		} catch(std::exception &e){ qDebug() << "CASTING" << e.what();}
	} catch(std::exception &e){ qDebug() << "LLAMADA" << e.what();}
}

void SpecificWorker::compute()
{
	//qDebug() << __FUNCTION__;
}

int SpecificWorker::startup_check()
{
	qDebug() << __FUNCTION__;
	QTimer::singleShot(200, qApp, SLOT(quit()));
	return 0;
}




