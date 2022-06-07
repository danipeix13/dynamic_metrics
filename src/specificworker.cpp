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

int pruebaSuma(std::vector<TYPE> data)
{
    qDebug() << "\t\t" << __FUNCTION__;

    /* RESPONSABILIDAD DEL PROGRAMADOR
     *      - Definir el tipo de retorno
     *      - Parmámetro de entrada siempre std::vector<TYPE>
     *      - Lectura (con casting) adecuada de los parámetros
     */

    int value_i = std::any_cast<int>(data[0]);
    std::vector<int> value_vec = std::any_cast<std::vector<int>>(data[1]);

    return std::accumulate(value_vec.begin(), value_vec.end(), 0) + value_i;
}

void SpecificWorker::initialize(int period)
{
    /* RESPONSABILIDAD DEL PROGRAMADOR
     *      - Crear un objeto de tipo Dynamic_metrics
     *      - Declarar las funciones de las métricas a utilizar
     *      - Usar addMetric() para añadir las funciones con un nombre
     *      - Crear el std::vector<TYPE>, el orden de elementos importa
     */

	qDebug() << "\n\n\b" << __FUNCTION__ << "DATOS: int(4) y std::vector<int>({1, 2, 3})";
    qDebug() << __FUNCTION__ << "RESULTADO ESPERADO: 4 + 1 + 2 + 3 = 10";
    Dynamic_metrics m = Dynamic_metrics();
    m.addMetric("prueba", pruebaSuma);
    TYPE res = m.getMetric("prueba", {4, std::vector<int>{1, 2, 3}});
    qDebug() << __FUNCTION__ << "RESULTADO OBTENIDO:" << std::any_cast<int>(res);

    /* PARA DEPURACIÓN */
    //	try
    //	{
    //        std::vector<TYPE> param = {4, std::vector<int>{1, 2, 3}};
    //		TYPE res = m.getMetric("prueba", param);
    //		qDebug() << "RESULT Type:" << res.type().name();
    //
    //		try
    //		{
    //			int resultado = std::any_cast<int>(res);
    //			qDebug() << "RESULTADO:" << resultado;
    //		} catch(std::exception &e){ qDebug() << "CASTING" << e.what();}
    //	} catch(std::exception &e){ qDebug() << "LLAMADA" << e.what();}

    /* NO NECESARIO PARA LA PRUEBA */
    //	this->Period = period;
    //	if(this->startup_check_flag)
    //		this->startup_check();
    //	else
    //		timer.start(Period);
}

void SpecificWorker::compute() { }

int SpecificWorker::startup_check()
{
	qDebug() << __FUNCTION__;
	QTimer::singleShot(200, qApp, SLOT(quit()));
	return 0;
}




