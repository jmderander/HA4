# HA4
C++ application to convert coordinates in the 3 dimensional space to a visual representation in the 2 dimensional plane.
### To do
* Create class to represent a 3d space
  * Could be implemented with a three dimensional vector
  * Should consist of functions which set/resets coordinates
  * Should consist of functions to resize the space
* Create class to represent a 2d plane
  * Could be implemented with a two dimensional vector
  * Should consist of a constructor/function which takes a Space and converts it to a plane
* Create class to represent a shape
  * Should have support for rgb color
  * Should consist of a set of coordinates which defines corners of shape
  * Should consist of function/s which rotates the shape given any axis(X,Y or Z)
  * Should consist of function which transforms the shape in some way (like scale)
* Create shapes or subclasses to shape i.e. cube, sphere etc.
  * Should consist of a set of predefined coordinates for a shape
* Create class/function that converts given Space/Plane to bitmap
  * Self explanatory
* Merge everything together into a nice program 
* Make a user friendly GUI? 
  * Could be implemented in any language 
