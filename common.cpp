#include "header.h"
#include<algorithm>
#include <unordered_map>


using namespace std;
using namespace cimg_library;

/* Create adjacency list*/
void setupNodes(string file, Node* &start, Node* &end) {
    unordered_map<unsigned int, Node*> nodes;  //Use Hash Table
    CImg<unsigned char> image(file.c_str());

    const auto rows = image.height();
    const auto column = image.width();
    Node *temp, *previous = nullptr;
    auto iterator = nodes.cend();

    /* Find start and end node*/
    start = end = nullptr;
    for (int i = 0; i < column; i++) {
        if (!start && (image(i, 0, 0, 0) == 255)) {
            temp = new Node;
            temp->x = i;
            temp->y = 0;
            temp->visited = false;
            temp->top = temp->bottom = temp->left = temp->right = temp->previous = nullptr;
            nodes.insert(make_pair(i, temp));

            start = temp;
        }

        if (!end && (image(i, rows - 1, 0, 0) == 255)) {
            temp = new Node;
            temp->x = i;
            temp->y = rows - 1;
            temp->visited = false;
            temp->top = temp->bottom = temp->left = temp->right = temp->previous = nullptr;
            nodes.insert(make_pair((rows - 1) * column + i, temp));

            end = temp;
        }
    }

    /*
        *Initialize top and left of current node
        *Initialize bottom of top of current node
        *Initialize right of previous node
        *Insert node into nodes table
        *Note that loop doesn't run for boundry rows and columns
    */
    for (int i = 1; i < rows - 1; i++){
        for (int j = 1; j < column - 1; j++) {
            if ((image(j, i, 0, 0) == 255)) {
                temp = new Node;
                temp->x = j;
                temp->y = i;
                temp->visited = false;
                temp->heuristic = abs(end->x - temp->x) + abs(end->y - temp->y);
                temp->top = temp->bottom = temp->left = temp->right = temp->previous = nullptr;

                iterator = nodes.find((i - 1) * column + j);
                if (iterator != nodes.end()) {
                    temp->top = iterator->second;
                    temp->top->bottom = temp;
                }

                if (j != 1) {
                    temp->left = previous;
                    if (previous) {
                        previous->right = temp;
                    }
                }

                nodes.insert(make_pair(i*column + j, temp));
                previous = temp;
            }
            else {
                previous = nullptr;
            }
        }
    }

    /* Initialize top of end and bottom of top of end*/
    iterator = nodes.find((end->y - 1) * column + end->x);
    if (iterator != nodes.end()) {
        end->top = iterator->second;
        end->top->bottom = end;
    }

    end->heuristic = 0;
    start->heuristic = abs(end->x - start->x) + abs(end->y - start->y);

}


void printPathToImage(string file, const std::vector<std::pair<int, int>> &path, const char * outputPath) {
    cimg_library::CImg<unsigned char> outputImage(file.c_str());
    for (int i = 0; i < path.size(); i++) {
        outputImage(path[i].first, path[i].second, 0, 0) = 255;  //Set Red component to 255
        outputImage(path[i].first, path[i].second, 0, 1)
                = outputImage(path[i].first, path[i].second, 0, 2) = 0; //Set Blue and Green component to 0
    }

    outputImage.save(outputPath);
}

vector<pair<int, int>> backtrack(Node* start) {
    vector<pair<int, int>> path;

    Node* current = start;
    while (current) {
        //cout << current->x << " " << current->y << "\n";
        path.push_back(make_pair(current->x, current->y));
        current = current->previous;
    }
    reverse(path.begin(), path.end());
    return path;
}

