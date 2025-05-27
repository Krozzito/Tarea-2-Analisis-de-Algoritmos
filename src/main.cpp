#include <iostream>
#include "editDistance.h"
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string a1 = "hola";
    string a2 = "halo";

    int result = editDistanceRecursive(a1,a2,0,0);
    cout << result;
    return 0;
}
