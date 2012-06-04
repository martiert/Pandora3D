%module PyMath
%{
#include "../include/vector2.h"
%}

template<typename T> class Vector2;

%template(Vec2f) Vector2<float>;
%template(Vec2d) Vector2<double>;
