#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Struct to hold each coordinate and character
struct Coordinate {
    int x;
    int y;
    char character;
};

// Reads input file, fills coords vector, and updates maxX, maxY
void readInput(const string& filename, vector<Coordinate>& coords, int& maxX, int& maxY) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    int x, y;
    char ch;
    maxX = 0;
    maxY = 0;
    while (infile >> x >> y >> ch) {
        coords.push_back({x, y, ch});
        if (x > maxX) maxX = x;
        if (y > maxY) maxY = y;
    }
    infile.close();
}

// Creates a 2D grid initialized with spaces
vector<vector<char>> createGrid(int maxX, int maxY) {
    // +1 because coordinates start at 0
    return vector<vector<char>>(maxY + 1, vector<char>(maxX + 1, ' '));
}

// Fills the grid with characters from coords
void fillGrid(vector<vector<char>>& grid, const vector<Coordinate>& coords) {
    for (const auto& c : coords) {
        grid[c.y][c.x] = c.character;
    }
}

// Prints the grid to the console
void printGrid(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char ch : row) {
            cout << ch;
        }
        cout << endl;
    }
}

int main() {
    string filename = "input.txt";  // Replace with your actual input file name

    vector<Coordinate> coords;
    int maxX, maxY;

    // Read input and determine maxX, maxY
    readInput(filename, coords, maxX, maxY);

    // Create 2D grid
    vector<vector<char>> grid = createGrid(maxX, maxY);

    // Fill grid with characters
    fillGrid(grid, coords);

    // Print the final grid
    printGrid(grid);

    return 0;
}