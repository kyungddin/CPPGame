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

void Snake::updateDirection(Direction dir)
{
	m_dir = dir;
}

void Snake::updateSnake()
{
	Point oldHead;

	switch (m_dir) {
	case Direction::UP:
		oldHead = m_head;

		for (int i = (m_bodyLength-1); i > 0; i--)
		{
			m_body[i] = { m_body[i-1].row, m_body[i - 1].col };
		}
		m_body[0] = { oldHead.row, oldHead.col };

		m_head = { oldHead.row - 1, oldHead.col };

		break;

	case Direction::DOWN:
		oldHead = m_head;

		for (int i = (m_bodyLength - 1); i > 0; i--)
		{
			m_body[i] = { m_body[i - 1].row, m_body[i - 1].col };
		}
		m_body[0] = { oldHead.row, oldHead.col };

		m_head = { oldHead.row + 1, oldHead.col };

		break;

	case Direction::LEFT:
		oldHead = m_head;

		for (int i = (m_bodyLength - 1); i > 0; i--)
		{
			m_body[i] = { m_body[i - 1].row, m_body[i - 1].col };
		}
		m_body[0] = { oldHead.row, oldHead.col };

		m_head = { oldHead.row, oldHead.col - 1 };

		break;

	case Direction::RIGHT:
		oldHead = m_head;

		for (int i = (m_bodyLength - 1); i > 0; i--)
		{
			m_body[i] = { m_body[i - 1].row, m_body[i - 1].col };
		}
		m_body[0] = { oldHead.row, oldHead.col };

		m_head = { oldHead.row, oldHead.col + 1 };

		break;
	}
}

Point Snake::getHead()
{
	return m_head;
}

std::vector<Point> Snake::getBody()
{
	return m_body;
}