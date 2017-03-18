#pragma once

#include "CImg.h"
#include <vector>
#include <string>

struct Node {
	Node* top;
	Node* bottom;
	Node* left;
	Node* right;
	Node* previous;
	unsigned int heuristic;
	//int ctop, cbottom, cleft, cright;
	unsigned short  x, y;
	bool visited;
};

typedef struct Node Node;


//setup.cpp
void setupNodes(std::string file, Node* &start, Node* &end);
std::vector<std::pair<int, int>> backtrack(Node* start);



//dfs.cpp
std::vector<std::pair<int, int>> dfs(Node * start, Node* end);

//gbfs.cpp
std::vector<std::pair<int, int>> gbfs(Node * start, Node* end);

//common.cpp
void printPathToImage(std::string image, const std::vector<std::pair<int, int>> &path, const char * outputPath);

void setupNodes(const cimg_library::CImg<unsigned char> &image, Node* &start, Node* &end);

std::vector<std::pair<int, int>> backtrack(Node* start);


