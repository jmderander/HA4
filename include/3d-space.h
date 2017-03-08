#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include <vector>
#include <string>
#include "Shape.h"

typedef std::vector<std::vector<std::vector<int>>> space_matrix;
typedef std::vector<std::vector<int>> plane_matrix;


class Space {
private:
	space_matrix matrix;
    int activeCoords;
	int sizeX;
	int sizeY;
	int sizeZ;
	int size;
	void alterSize();


public:
	Space();

	Space(int x, int y, int z);

	space_matrix getSpace();

	plane_matrix* toSpace();

	int getSize(std::string o);

    std::vector<coord> getActiveCoords();

	int getVatCoord(int x, int y, int z);
	
	void changeSize(std::string o, int s);

	void alterCoord(std::string o, int x, int y, int z);
};

void print_space(Space s);
void test_space();
std::vector<coord> draw_line(coord start, coord end);

#endif
