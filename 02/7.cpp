#include <iostream>
#include "7_class.cpp"

using namespace std;

int main() 
{
   Matrix m;
   m[1, 1] = 5;

   for (const auto &row : m) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
   }
}