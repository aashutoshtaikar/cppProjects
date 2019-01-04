/*
 * Zoom.h
 *
 *  Created on: Dec 29, 2018
 *      Author: batman
 */

#ifndef ZOOM_H_
#define ZOOM_H_

namespace caveofprogramming {

/*
class to store co-ordinates to zoom to
*/
class Zoom {
public:
	int x{0},y{0};
	double scale{0.0};	
	Zoom(int x,int y,double scale):x(x),y(y),scale(scale){}	
};

} /* namespace caveofprogramming */

#endif /* ZOOM_H_ */
