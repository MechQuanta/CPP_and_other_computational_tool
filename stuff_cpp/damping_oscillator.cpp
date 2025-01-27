#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  double pi = M_PI;
  double w = 2 * pi;
  double d = 0.25;
  vector<double> x0 = {1, 0};

  // Print initial state
  for (int i = 0; i < 2; i++) {
    cout << x0[i] << endl;
  }

  vector<double> t(1001, 0.0); // Initialize time vector with size 1001
  double A[2][2];
  A[0][0] = 0, A[0][1] = 1;
  A[1][0] = -w * w, A[1][1] = -2 * d * w;

  // Print matrix A
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }

  double dt = 0.01;
  int T = 10;

  // Define xF as a 2D matrix with 1001 rows and 2 columns
  vector<vector<double>> xF(1001, vector<double>(2, 0.0));

  ofstream write_output("system_matrix.dat");
  if (!write_output.is_open()) {
    cerr << "Error opening file.\n";
    return -1;
  }

  // Set initial conditions
  for (int j = 0; j < 2; j++) {
    xF[0][j] = x0[j];
  }

  // Time-stepping loop
  for (int i = 1; i <= 1000; i++) {
    t[i] = i * dt;
    vector<double> x_new(2, 0.0); // Temporary state vector for updates
    for (int j = 0; j < 2; j++) {
      double temp = 0.0;
      for (int k = 0; k < 2; k++) {
        temp += x0[k] * A[j][k] * dt;
      }
      x_new[j] = x0[j] + temp; // Update state
      xF[i][j] = x_new[j];
    }
    x0 = x_new; // Update x0 with the new state

    // Write to file
    write_output << i << "|" << t[i];
    for (int j = 0; j < 2; j++) {
      write_output << "|" << xF[i][j];
    }
    write_output << endl;
  }

  write_output.close();
  return 0;
}
