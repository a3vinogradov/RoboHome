#pragma once

#include <string>
#include <sstream>
#include <iomanip>
using String = std::string;

#define INT_TO_STRING(x) std::to_string(x)
#define FLOAT_TO_STRING(x, p) [](float val, int prec) { std::ostringstream oss; oss << std::fixed << std::setprecision(prec) << val; return oss.str();}(x, p)