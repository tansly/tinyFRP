#include <vector>
#include <cmath>

#define ABS(a) ((a)>0?(a):-1*(a))
#define RADIANS(a) (a*M_PI/180)
#ifndef TINYMATH_H
#define TINYMATH_H

namespace tinymath {
    class vec3;
}


class Translation{
public:
    double tx, ty, tz;
    
    Translation() :tx(0),ty(0),tz(0) {}
    Translation(double tx, double ty, double tz);
    Translation(const tinymath::vec3 & vec);
} ;

class Rotation {
public:
    double angle, ux, uy, uz;
    Rotation() :angle(0),ux(0),uy(0),uz(0) {}
    Rotation(double angle, double ux, double uy, double uz);
    Rotation(const tinymath::vec3 & vec);
};

class Scaling {
public:
    double sx, sy, sz;
    Scaling() :sx(0),sy(0),sz(0) {}
    Scaling(double sx, double sy, double sz);
    Scaling(const tinymath::vec3 & vec);
};


namespace tinymath {

class vec3 {
public:
    double x;
    double y;
    double z;
    
    int colorId;

    explicit vec3(double x = 0, double y = 0, double z = 0, int colorId = -1);
    vec3(const vec3 &) = default;
    vec3 & operator=(const vec3 &) = default;

    // equality
    friend bool operator==(const vec3 & lhs, const vec3 & rhs);
    friend bool operator!=(const vec3 & lhs, const vec3 & rhs);

    // addition
    vec3 & operator+=(const vec3 & rhs);
    friend vec3 operator+(vec3 lhs, const vec3 & rhs);

    // substraction
    vec3 & operator-=(const vec3 & rhs); 
    friend vec3 operator-(vec3 lhs, const vec3 & rhs); 

    // scalar multiplication
    vec3 & operator*=(double scalar);
    friend vec3 operator*(vec3 lhs, double scalar);
    friend vec3 operator*(double scalar, vec3 rhs);

    vec3 & operator/=(double scalar);
    friend vec3 operator/(vec3 lhs, double scalar);
};

double length(const vec3 & vec);
vec3 normalize(vec3 vec);
double dot(const vec3 & lhs, const vec3 & rhs);
vec3 cross(const vec3 & lhs, const vec3 & rhs);
void printVec3(const vec3 & vec);

void translate(vec3 &, const Translation & );
void rotate(vec3 &, const Rotation & );
void scale(vec3 &, const Scaling & );


} // namespace tinymath

#endif /* TINYMATH_H */

