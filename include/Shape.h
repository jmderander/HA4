#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

typedef struct coord {
  int x,y,z;

}coord;

typedef struct color {
  char r,g,b;
}color;

class Shape {
  
 private:
  std::vector<coord> coords;
  color shapeColor;
  void matrixMul(double matrix[][3]);

 public:
  Shape();
  Shape(std::vector<coord> coords);
  Shape(std::vector<coord> coords, color shapeColor);

  color getColor();
  std::vector<coord> getCoords();

  void rotate(double x, double y, double z);
};

#endif
