#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <random>
#include <unordered_map>
#include <string>
#include <iostream>

sf::Sprite createAspect(const std::string& aspectName);
bool loadTextureFromResource(sf::Texture& texture, int resourceId);