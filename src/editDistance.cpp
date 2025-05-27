#include <iostream>
#include <string>

int editDistanceRecursive(std::string& s, std::string& t, int i, int j){
    //Caso base
   if(i==s.length()) return t.length()-j;
   if(j==t.length()) return s.length()-i;
   
   if(s[i]==t[j]) return editDistanceRecursive(s,t,i+1,j+1);
    else {
        int del = editDistanceRecursive(s, t, i + 1, j);   // eliminar S[i]
        int ins = editDistanceRecursive(s, t, i, j + 1);   // insertar T[j]
        return 1 + std::min(del, ins);
    }
    
}