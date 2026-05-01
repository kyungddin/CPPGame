#pragma once
#include <vector>

#include "Config.h"
#include "Point.h"

class Snake
{
private:
	Point m_head;
	int m_bodyLength;
	std::vector<Point> m_body;

public:
	Snake();
	~Snake();
	
	Point getHead();
	std::vector<Point> getBody();
};
