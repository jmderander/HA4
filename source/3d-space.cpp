#include "3d-space.h"

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
	//51 * 51 * 51 default value for size
	this->sizeX = 51;
	this->sizeY = 51;
	this->sizeZ = 51;
	alterSize();
}

Space::Space(int x, int y, int z) {
    if(x%2==0){
        this->sizeX = x+1;
    }
    else{
        this->sizeX = x;
    }
    if(y%2==0){
        this->sizeY = y+1;
    }
    else{
        this->sizeY = y;
    }
    if(z%2==0){
        this->sizeZ = z+1;
    }
    else{
        this->sizeZ = z;
    }
	alterSize();
}

space_matrix Space::getSpace() {
	return this->matrix;
}

/*
	Converts the Space to a plane, projecting all coordinates 
	to the X,Y plane and returns a reference to the plane.
	Important to destruct it when done!

	This needs improvement, too slow atm!
*/
plane_matrix* Space::toSpace() {
	plane_matrix* pm = new plane_matrix();
	int x = 0;
	int y = 0;
	pm->resize(this->sizeX);
	for (auto &v : *pm) {
		v.resize(this->sizeY);
	}

	for (auto &vx : this->matrix) {
		for (auto &vy : vx) {
			for (int i : vy) {
                int z = 0;
				if (i) {
                    if( x!= ((sizeX-1) / 2) || y != ((sizeY-1) / 2)){
                        pm->at(x).at(y) = 1;
                    }else if(z < ((sizeZ-1) / 2)){
                        pm->at(x).at(y) = 1;
                    }

					break;
				}
                z++;
			}
			++y;
		}
		y = 0;
		++x;
	}
	return pm;
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
        if(s%2==0){
            this->sizeX = s+1;
        }else{
            this->sizeX = s;
        }
		alterSize();
	}
	else if (o == "Y") {
        if(s%2==0){
            this->sizeY = s+1;
        }else{
            this->sizeY = s;
        }
		alterSize();
	}
	else if (o == "Z") {
        if(s%2==0){
            this->sizeZ = s+1;
        }else{
            this->sizeZ = s;
        }
	}
	else if (o == "All") {
        if(s%2==0){
            this->sizeX = s+1;
            this->sizeY = s+1;
            this->sizeZ = s+1;
        }else{
            this->sizeX = s;
            this->sizeY = s;
            this->sizeZ = s;
        }

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

    if(x >= 0){
        x = x + ((this->sizeX-1) / 2);
    }else{
        x = ((this->sizeX-1) / 2) - abs(x);
    }
    if(y >= 0){
        y = y + ((this->sizeY-1) / 2);
    }else{
        y = ((this->sizeY-1) / 2) - abs(y);
    }
    if(z >= 0){
        z = z + ((this->sizeZ-1) / 2);
    }else{
        z = ((this->sizeZ-1) / 2) - abs(z);
    }

    if(x>this->sizeX-1){
        x=this->sizeX-1;
    }else if(x<0){
        x=0;
    }
    if(y>this->sizeY-1){
        y=this->sizeY-1;
    }else if(y<0){
        y=0;
    }
    if(z>this->sizeZ-1){
        z=this->sizeZ-1;
    }else if(z<0){
        z=0;
    }
	matrix.at(x).at(y).at(z) = v;
}

void print_space(Space s){
    plane_matrix* pm = s.toSpace();

    for(int i = 0; i < s.getSize("Y"); ++i){
        for(int j = 0; j < s.getSize("X"); ++j){
            if(pm->at(j).at(i) == 0){
                if(i != ((s.getSize("X")-1) / 2)){
                    if(j != ((s.getSize("X")-1) / 2)){
                        cout << "  ";
                    }else{
                        cout << " |";
                    }
                }else{
                    cout << " -";
                }

            }
            else{
                cout << " *";
            }

        }
        cout << "\r\n";

    }
    delete pm;
}

void test_space() {
	Space sp = Space();
	for (int i = 1; i < 1000; i++) {
		sp.alterCoord("Set", (int)(rand() % sp.getSize("X")), (int)(rand() % sp.getSize("Y")), (int)(rand() % sp.getSize("Z")));
	}
    print_space(sp);

    string str;
    while (str != "exit") {
        cin >> str;
    }
}
