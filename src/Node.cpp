#include "include/Node.h"
#include <limits>

Node::Node(unsigned int x, unsigned int y) {
	this->x = x;
	this->y = y;
	this->visited = false;
	top = bottom = left = right = previous = nullptr;
	g = std::numeric_limits<int>::max();
}