#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "Number of command line arguments: " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "Argument " << i << ": " << argv[i] << "\n";
    }

    // Ensure sufficient arguments are provided
    if (argc < 3) {
        cerr << "Error: Insufficient command line arguments.\n";
        cerr << "Usage: " << argv[0] << " <number_of_nodes> <conductivity>\n";
        return 1;
    }

    string program_name = argv[0];
    int number_of_nodes = atoi(argv[1]);  // Convert argument to integer
    double conductivity = atof(argv[2]); // Convert argument to double

    cout << "Program name: " << program_name << endl;
    cout << "Number of nodes: " << number_of_nodes << endl;
    cout << "Conductivity: " << conductivity << endl;

    return 0;
}
