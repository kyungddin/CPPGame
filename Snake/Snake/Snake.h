#pragma once
#include <vector>

#include "Config.h"

#include "Point.h"
#include "Direction.h"

class Snake
{
private:
	Point m_head;
	int m_bodyLength;
	std::vector<Point> m_body;
	Direction m_dir;

public:
	Snake();
	~Snake();
	
	void updateDirection(Direction dir);
	void updateSnake();

	Point getHead();
	std::vector<Point> getBody();
};
