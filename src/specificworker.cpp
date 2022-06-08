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
SpecificWorker::~SpecificWorker() { }

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params) { return true; }

void SpecificWorker::initialize(int period)
{
    using suma_data = std::tuple<int, std::vector<int>>;
    using resta_data = std::tuple<int, std::vector<float>>;
    using data_types = std::variant<suma_data, resta_data>;

    auto prueba_suma = [](const data_types &data){
        auto &[i, v] = std::get<suma_data>(data);
        return std::accumulate(v.begin(), v.end(), 0) + i;
    };

    Dynamic_metrics<data_types> m;

    m.addMetric("prueba", prueba_suma);
    auto res = m.getMetric("prueba", std::make_tuple(4, std::vector<int>{1, 2, 3}));
    qDebug() << __FUNCTION__ << "\n\nRESULTADO:" << res;
}

void SpecificWorker::compute() { }

int SpecificWorker::startup_check()
{
	qDebug() << __FUNCTION__;
	QTimer::singleShot(200, qApp, SLOT(quit()));
	return 0;
}




