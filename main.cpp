#include <iostream>
#include <chrono>
#include <fstream>
#include <math.h>
#include "Matrix.h"
using namespace std;

int main() {
    auto start = chrono::system_clock::now();

    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "\nexecution time: " << duration.count() << " nanoseconds";
    return 0;
}
