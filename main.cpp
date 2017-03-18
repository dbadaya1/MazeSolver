#include "header.h"
#include <iostream>

using namespace cimg_library;
using namespace std;

int main() {
    string file = "images/braid200.bmp";
	Node *start, *end;
	setupNodes(file, start, end);

	cout << "Start " << start->x << " " << start->y << "\n";
	cout << "End " << end->x << " " << end->y << "\n";

     vector<pair<int, int>> path;
	//path = gbfs(start, end);			// Greedy Best First Search
	path = dfs(start, end);           // Depth First  Search


	const char* outputPath = "output.bmp";
	printPathToImage(file, path, outputPath);
 
	return 0;
}



