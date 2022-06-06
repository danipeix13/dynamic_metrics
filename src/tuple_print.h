//
// Created by robolab-kinova on 6/06/22.
//

#ifndef BASE_TUPLE_PRINT_H
#define BASE_TUPLE_PRINT_H


#include <cppitertools/enumerate.hpp>
#include <filesystem>
#include <iostream>

template<typename ... Ts>
struct Overload : Ts ... { using Ts::operator() ...; };
template<class... Ts> Overload(Ts...) -> Overload<Ts...>;   // custom deduction rule

template<typename TU> void print(TU t)
{
    auto vector_to_str = []<typename T>(const T &vec)
    {   std::stringstream str;
        str << "[";
        for(auto &&[i, elem]: vec | iter::enumerate)
            str << std::to_string(elem) << ", ";
        auto s = str.str();
        s.pop_back();s.pop_back();  // remove last comma
        s += "]";
        return s;
    };
    auto TypeOfIntegral = Overload {
            [](char c) { return "[char] " + std::to_string(c); },
            [](int &i) { return "int"; },
            [](auto) { return "unknown type"; },
            [vector_to_str](std::vector<int> &v) { return vector_to_str(v); },
    };
    auto s = std::visit(TypeOfIntegral, t);
    std::cout << s << std::endl;
};
#endif //BASE_TUPLE_PRINT_H
