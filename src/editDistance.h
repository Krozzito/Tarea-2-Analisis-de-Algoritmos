#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H

#include <iostream>
#include <string>
#include <vector>

int editDistanceRecursive(std::string& s, std::string& t, int i, int j);
int editDistanceMemo(std::string& s, std::string& t, int i, int j, std::vector<std::vector<int>> &dp);
int editDistanceDP(std::string &s, std::string &t);
int editDistanceDPOptimized();

#endif