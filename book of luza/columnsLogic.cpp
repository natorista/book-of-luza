#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <random>
#include <unordered_map>
#include <string>
#include <iostream>
#include <Windows.h>

struct ImeIChanca {
    std::string ime;
    int chanca;
};
std::vector<ImeIChanca> imenaIChance = {
{ "luza", 2 },
{ "jankula", 8 },
{ "glavas", 16 },
{ "paja", 26 },
{ "vasa", 38 },
{ "tamara", 52 },
};
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(0, 52);



std::vector<std::string> imenaUkupno(int nPokoloni) {
    std::vector<std::string> ImenaUkupno;
    for (int i = 0; i < nPokoloni; i++) {
        int rand = dist(gen);

        for (const auto& item : imenaIChance) {
            if (rand <= item.chanca) {
                ImenaUkupno.push_back(item.ime);
                break;
            }
        }
    }
    return ImenaUkupno;
}

std::vector<int> checkForMatches(int nPokoloni, std::vector < std::string> kolona1, std::vector < std::string> kolona2, std::vector < std::string> kolona3) {
    std::vector<int> dobitci;
    for (int i = 0; i < nPokoloni; ++i) {

        if (kolona1[i] == kolona2[i] && kolona1[i] == kolona3[i] && kolona2[i] == kolona3[i]) {
            dobitci.push_back(3);
        }
        else if (kolona1[i] == kolona2[i] || kolona1[i] == kolona2[i] || kolona2[i] == kolona3[i]) {
            dobitci.push_back(2);
        }
        else {
            dobitci.push_back(0);
        }

    }

    return dobitci;


}