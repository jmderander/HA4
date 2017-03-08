#include <iostream>
#include <zconf.h>
#include "3d-space.h"
#include "Shape.h"

using namespace std;

int main() {
    Space s = Space();
    vector<coord> coords = {{10,1,1},{11,1,1},{12,1,1},{13,1,1},{14,1,1},{15,1,1},
                            {10,1,6},{11,1,6},{12,1,6},{13,1,6},{14,1,6},{15,1,6},
                            {10,1,1},{10,1,2},{10,1,3},{10,1,4},{10,1,5},{10,1,6},
                            {15,1,2},{15,1,2},{15,1,3},{15,1,4},{15,1,5},{15,1,6},
                            {10,1,1},{10,2,1},{10,3,1},{10,4,1},{10,5,1},{10,6,1},
                            {15,1,1},{15,2,1},{15,3,1},{15,4,1},{15,5,1},{15,6,1},
                            {10,1,6},{10,2,6},{10,3,6},{10,4,6},{10,5,6},{10,6,6},
                            {15,1,6},{15,2,6},{15,3,6},{15,4,6},{15,5,6},{15,6,6},
                            {10,6,1},{11,6,1},{12,6,1},{13,6,1},{14,6,1},{15,6,1},
                            {10,6,6},{11,6,6},{12,6,6},{13,6,6},{14,6,6},{15,6,6},
                            {10,6,1},{10,6,2},{10,6,3},{10,6,4},{10,6,5},{10,6,6},
                            {15,6,2},{15,6,2},{15,6,3},{15,6,4},{15,6,5},{15,6,6}};

    for (coord c : coords){
        s.alterCoord("Set", c.x, c.y, c.z);
    }

    vector<coord> line = draw_line({-25,0,0},{25,0,0});

    for (coord c : line){
        s.alterCoord("Set", c.x, c.y, c.z);
    }

    line = draw_line({0,-25,0},{0,25,0});

    for (coord c : line){
        s.alterCoord("Set", c.x, c.y, c.z);
    }

    line = draw_line({0,0,-25},{0,0,25});

    for (coord c : line){
        s.alterCoord("Set", c.x, c.y, c.z);
    }

    Shape rs = Shape(s.getActiveCoords());
    rs.rotate(1,1,0);

    for(coord c : s.getActiveCoords()){
        //cout << c.x << ", " << c.y << ", " << c.z << "\r\n";
        s.alterCoord("Purge", c.x, c.y, c.z);
    }

    for(coord c : rs.getCoords()){
        s.alterCoord("Set", c.x, c.y, c.z);
    }

    print_space(s);


    return 0;
}