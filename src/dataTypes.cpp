#include "dataTypes.h"
#include <vector>
#include <array>
#include <cmath>

//=======Point Class===========

Point::Point(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
    id = -1;
}

Point::Point(){}

int Point::getId()
{
    return id;
}
	
void Point::setId(int n)
{
    id = n;
}

std::vector<int> Point::getRGB()
{ 
    return {r,g,b};
}

int Point::sumRGB()
{
    return r+g+b;
}

//====Cluster Class======

Cluster::Cluster(Point& p, int id)
{
    centroid = p;
    this->id = id;
}

int Cluster::getId()
{
    return id;
}

void Cluster::calculateNewCentroid()
{

    std::array<int,3> averages ={0,0,0};
    int size{0};

    for(uint p{0}; p < data.size(); ++p)
	{		
        std::vector<int> colorData {data[p].getRGB()};
                
        int r = colorData[0];
        int g = colorData[1];
        int b = colorData[2];
        averages[0] += r*r;
		averages[1] += g*g;
		averages[2] += b*b;
		++size;	
	}
	this->reset();
    Point newCentroid = Point(std::sqrt(averages[0]/size), std::sqrt(averages[1]/size), std::sqrt(averages[2]/size));
    this->centroid = newCentroid;
    addPoint(newCentroid);
}



std::vector<Point>& Cluster::getData()
{
    return data;
}

void Cluster::reset()
{
    data.clear();
}

