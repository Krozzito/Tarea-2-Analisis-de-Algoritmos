#include <iostream>
#include "editDistance.h"
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "hello krossart como estas";
    string t = "hello krossart matate";
    vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));

    int result = editDistanceMemo(s,t,0,0,dp);
    
    cout << result;

    return 0;
}
