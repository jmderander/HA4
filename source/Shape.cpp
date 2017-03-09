#include "Shape.h"
#include <math.h>
#include <iostream>
#include <cmath>

using namespace std;

Shape::Shape() {
  this->coords.resize(10);
}

Shape::Shape(vector<coord> coords) {
  this->coords = coords;
}

Shape::Shape(vector<coord> coords, color shapeColor) {
  this->coords = coords;
  this->shapeColor = shapeColor;
}

color Shape::getColor()  {
  return this->shapeColor;
}

vector<coord> Shape::getCoords() {
  return this->coords;
}

void Shape::matrixMul(double matrix[][3]) {
  
    for(coord &c : this->coords) {

      c.x = (int) round((matrix[0][0]*c.x)+(matrix[0][1]*c.y)+(matrix[0][2]*c.z));
      c.y = (int) round((matrix[1][0]*c.x)+(matrix[1][1]*c.y)+(matrix[1][2]*c.z));
      c.z = (int) round((matrix[2][0]*c.x)+(matrix[2][1]*c.y)+(matrix[2][2]*c.z));

    }

}


void Shape::rotate(double x, double y, double z) {
  /*[1,   0,      0,
     0,  sin(a),  cos(a),
     0,  cos(a),  sin(a)]*/

  double XrotateMatrix[3][3] = {{1,            0,            0},
                              {0, sin(x * 1.0), cos(x * 1.0)},
                              {0 ,cos(x * 1.0), sin(x * 1.0)}};
  
  double YrotateMatrix[3][3] = {{sin(y * 1.0), 0, cos(y * 1.0)},
                              {0,            1,            0},
                              {cos(y * 1.0), 0, sin(y * 1.0)}};
        
  double ZrotateMatrix[3][3] = {{sin(z * 1.0), cos(z * 1.0), 0},
                              {cos(z * 1.0), sin(z * 1.0), 0},
                              {0,            0,            1}};
  
  if(x > 0) {
    this->matrixMul(XrotateMatrix);
  }
  
  if(y > 0) {
     this->matrixMul(YrotateMatrix);
  }
  if(z > 0) {
     this->matrixMul(ZrotateMatrix);
  }
}
