#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::vector<std::vector<int>>> space_matrix;
typedef std::vector<std::vector<int>> plane_matrix;
void test_space();

class Space {
private:
	space_matrix matrix;
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

	int getVatCoord(int x, int y, int z);
	
	void changeSize(std::string o, int s);

	void alterCoord(std::string o, int x, int y, int z);
};

#endif
