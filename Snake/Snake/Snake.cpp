#include "Snake.h"

Snake::Snake() 
{
	m_head = { ROW / 2, COL / 2 };
	m_bodyLength = 3;
	m_body.resize(m_bodyLength);

	for (int i = 0; i < m_bodyLength; i++)
	{
		m_body[i] = { ROW / 2 , COL / 2 - (i + 1) };
	}
}

Snake::~Snake()
{
	m_body.clear();
}

Point Snake::getHead()
{
	return m_head;
}

std::vector<Point> Snake::getBody()
{
	return m_body;
}