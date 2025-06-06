#include <iostream>
#include <string>
#include <vector>

int editDistanceRecursive(std::string &s, std::string &t, int i, int j)
{
    // Caso base
    if (i == s.length())
        return t.length() - j;
    if (j == t.length())
        return s.length() - i;

    if (s[i] == t[j])
        return editDistanceRecursive(s, t, i + 1, j + 1);
    else
    {
        int del = editDistanceRecursive(s, t, i + 1, j); // eliminar S[i]
        int ins = editDistanceRecursive(s, t, i, j + 1); // insertar T[j]
        return 1 + std::min(del, ins);
    }
}
int editDistanceMemo(std::string &s, std::string &t, int i, int j, std::vector<std::vector<int>> &dp)
{
    if(i == s.length()) return t.length() - j;
    if(j == t.length()) return s.length() - i;

    // Si ya esta calculado lo devolvemos
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]){
        dp[i][j] = editDistanceMemo(s,t,i+1,j+1,dp);
    }
    else{
        int del = editDistanceMemo(s,t,i+1,j,dp); // eliminamos
        int ins = editDistanceMemo(s,t,i,j+1,dp); // insertamos

        dp[i][j] = 1 + std::min(del,ins);
    }

    return dp[i][j];
}
int editDistanceInsertDelete(const std::string& s, const std::string& t) {
    int n = s.length();
    int m = t.length();

    // Matriz DP de (n+1)x(m+1)
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    // Casos base:
    for(int i = 0; i <= n; ++i) dp[i][0] = i; // Eliminar todo s[0..i]
    for(int j = 0; j <= m; ++j) dp[0][j] = j; // Insertar todo t[0..j]

    // Llenar la tabla
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s[i - 1] == t[j - 1]) {
                // Si los caracteres coinciden, no hacemos nada
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Insertar t[j-1] o eliminar s[i-1]
                int insertOp = dp[i][j - 1];
                int deleteOp = dp[i - 1][j];
                dp[i][j] = 1 + std::min(insertOp, deleteOp);
            }
        }
    }
    return dp[n][m];
}