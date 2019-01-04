/*
 * ZoomList.h
 *
 *  Created on: Dec 29, 2018
 *      Author: batman
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_
#include<vector>
#include<utility>
#include"Zoom.h"

namespace caveofprogramming {

class ZoomList {
private:
	int m_width{0},m_height{0};
	std::vector<Zoom> zooms;
public:
	ZoomList(int width, int height);
	void add(const Zoom& zoom);
	std::pair<double,double> doZoom(int x,int y);
};

} /* namespace caveofprogramming */

#endif /* ZOOMLIST_H_ */
