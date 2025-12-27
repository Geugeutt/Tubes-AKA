#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "rekursif.hpp"
#include "iteratif.hpp"

using namespace std;
using namespace chrono;

int main() {
    ofstream csv("hasil_runtime.csv");
    csv << "N,Rekursif,Iteratif\n";

    cout << "+----+----------------------+----------------------+\n";
    cout << "| N  | Rekursif Time (s)    | Iteratif Time (s)    |\n";
    cout << "+----+----------------------+----------------------+\n";

    cout << fixed << setprecision(6);

    for (int n = 1; n <= 15; n++) {
        auto startRec = high_resolution_clock::now();
        solveRecursive(n);
        auto endRec = high_resolution_clock::now();
        double recTime = duration<double>(endRec - startRec).count();

        auto startIt = high_resolution_clock::now();
        solveIterative(n);
        auto endIt = high_resolution_clock::now();
        double itTime = duration<double>(endIt - startIt).count();

        cout << "| " << setw(2) << n << " "
             << "| " << setw(20) << recTime << " "
             << "| " << setw(20) << itTime << " |\n";

        csv << n << "," << recTime << "," << itTime << "\n";
    }

    cout << "+----+----------------------+----------------------+\n";

    csv.close();
    cout << "\nData runtime disimpan ke file: hasil_runtime.csv\n";

    return 0;
}