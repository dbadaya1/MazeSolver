#include "header.h"
#include <iostream>

using namespace cimg_library;
using namespace std;

int main() {
    string file = "images/perfect4k.bmp";
	Node *start, *end;
	setupNodes(file, start, end);

	cout << "Start " << start->x << " " << start->y << "\n";
	cout << "End " << end->x << " " << end->y << "\n";

    while(1);
    /*
     vector<pair<int, int>> path;
	path = gbfs(start, end);			// Greedy Best First Search
	//path = dfs(start, end);           // Depth First  Search


	const char* outputPath = "output.bmp";
	printPathToImage(image, path, outputPath);
     */
	return 0;
}



