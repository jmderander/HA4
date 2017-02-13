#include <3d-space.h>

using namespace std;

// Insane time complexity of O(n^2)
void Space::alterSize() {
	this->size = this->sizeX * this->sizeY * this->sizeZ;
	matrix.resize(this->sizeX);
	for (auto &v : matrix) {
		v.resize(this->sizeY);
		for (auto &vs : v) {
			vs.resize(this->sizeZ);
		}
	}
}

	
Space::Space() {
	//50 * 50 * 50 default value for size
	this->sizeX = 50;
	this->sizeY = 50;
	this->sizeZ = 50;
	alterSize();
}

Space::Space(int x, int y, int z) {
	this->sizeX = x;
	this->sizeY = y;
	this->sizeZ = z;
	alterSize();
}
space_matrix Space::getSpace() {
	return this->matrix;
}
int Space::getSize(string o) {
	if (o == "X"){
		return this->sizeX;
	}
	else if (o == "Y") {
		return this->sizeY;
	}
	else if (o == "Z") {
		return this->sizeZ;
	}
	else if (o == "All") {
		return this->size;
	}
	else {
		return -1;
	}
}

int Space::getVatCoord(int x, int y, int z) {
	return matrix.at(x).at(y).at(z);
}

/*
	Usage: Give a string "X" "Y" or "Z" foolowed by an int to change it's respective
			size or "All" to change the size of all vectors 
*/
void Space::changeSize(string o, int s) {
	if (o == "X") {
		this->sizeX = s;
		alterSize();
	}
	else if (o == "Y") {
		this->sizeY = s;
		alterSize();
	}
	else if (o == "Z") {
		this->sizeZ = s;
		alterSize();
	}
	else if (o == "All") {
		this->sizeX = s;
		this->sizeY = s;
		this->sizeZ = s;
		alterSize();
	}
}
		
/*
	Usage: Use "Set" followed by coordinate to write 1 to it or "Purge" to write 0 
*/
void Space::alterCoord(string o, int x, int y, int z) {
	int v;
	if (o == "Set") {
		v = 1;
	}
	else if (o == "Purge") {
		v = 0;
	}
	matrix.at(x).at(y).at(z) = v;
}
