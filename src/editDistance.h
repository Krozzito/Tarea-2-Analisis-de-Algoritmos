#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H

#include <iostream>
#include <string>


int editDistanceRecursive(std::string& s, std::string& t, int i, int j);
int editDistanceMemo();
int editDistanceDP();
int editDistanceDPOptimized();

#endif