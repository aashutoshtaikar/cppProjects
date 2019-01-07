/*
 * ZoomList.cpp
 *
 *  Created on: Dec 29, 2018
 *      Author: batman
 */

#include "ZoomList.h"
#include<iostream>
namespace caveofprogramming {
ZoomList::ZoomList(int width, int height):m_width(width),m_height(height) {}

void ZoomList::add(const Zoom& zoom){
	zooms.push_back(zoom);
	m_xCenter += (zoom.x - m_width/2)*m_scale;
	m_yCenter += -(zoom.y - m_height/2)*m_scale;
	m_scale *= zoom.scale;

	std::cout << m_xCenter << "," << m_yCenter << "," << m_scale << std::endl; 
}

//mapping bitmap co-ordinates to actual fractal co-ordinates(which combines list of zoom(zooms))
std::pair<double,double> ZoomList::doZoom(int x,int y){
	//xFractal = offset * scaling
 	double xFractal = (x - m_width/2) * m_scale + m_xCenter;      //0 to 800 (offset) to symmetric -1 to 1 * (scaled) to 2/width
    double yFractal = (y - m_height/2) * m_scale + m_yCenter;

	return std::pair<double,double> (xFractal,yFractal);
}

} /* namespace caveofprogramming */
