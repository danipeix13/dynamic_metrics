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

// The struct Overload can have arbitrary many base classes (Ts ...).
// It derives from each class public and brings the call operator (Ts::operator...) of each base class into its scope.
//The base classes need an overloaded call operator (Ts::operator()).
//Lambdas provide this call operator.


using PAR = std::variant<int, float, std::string>;

/*
*	CÓMO Y CUÁNDO USAR
*	
*   La métrica será, por ejemplo, "CHC".
*   Se ha de implementar una función f() para calcular el CHC: 
*       - IN:  parámetros adecuados
*       - OUT: resultado de la métrica (uso de los de T)
*
*	initialize():
*		Dynamic_metrics metricCalculator();
*		addMetric("CHC", f);
*
*	compute():
*       T resultado = getMetric(name, std::vector<T>);
*/

class Dynamic_metrics
{
	private:
		std::map<std::string, std::function<PAR(PAR)>> metrics;

	public:
		Dynamic_metrics();
		~Dynamic_metrics();
		void addMetric(const std::string &metricName, std::function<PAR(PAR)> metricFunction);
		PAR getMetric(const std::string &name, const std::vector<PAR> &paramsList);



};

#endif
