#pragma once

class Node {
public:
	Node* top;
	Node* bottom;
	Node* left;
	Node* right;
	Node* previous;
	int  x, y, h, g;
	bool visited;
	int tcost, bcost, lcost, rcost;

	Node::Node(unsigned int x, unsigned int y);
};