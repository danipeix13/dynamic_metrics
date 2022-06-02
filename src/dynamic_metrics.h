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

typedef std::variant<int, float, string, Eigen2f, Eigen3f> T;

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

class Dynamic_metrics()
{
	private:
		std::map<string, std::function> metrics;

	public:
		Dynamic_metrics();
		~Dynamic_metrics();
		void addMetric(string metricName, std::function metricFunction);
		T getMetric(string name, std::vector<T> paramsList)
}

#endif
