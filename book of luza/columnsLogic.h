#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <random>
#include <unordered_map>
#include <string>
#include <iostream>
std::vector<std::string> imenaUkupno(int nPokoloni);
std::vector<int> checkForMatches(int nPokoloni, std::vector < std::string> kolona1, std::vector < std::string> kolona2, std::vector < std::string> kolona3);