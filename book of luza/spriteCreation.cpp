#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <random>
#include <unordered_map>
#include <string>
#include <iostream>

struct aspectProperties {
	std::string textureFile;
	sf::Vector2f scale;
	sf::Vector2f position;
	sf::Vector2f origin;
};

std::unordered_map<std::string, aspectProperties> mapaSBlagom = {
	{"luza",	{"resources/luza_aspect.png",		{1.5f, 1.5f}, {1.0f, 1.0f}, {50.0f, 50.0f}}},
	{"jankula", {"resources/jankula_aspect.png",	{1.5f, 1.5f}, {1.0f, 1.0f}, {50.0f, 50.0f}}},
	{"glavas",  {"resources/glavas_aspect.png",		{1.5f, 1.5f}, {1.0f, 1.0f}, {50.0f, 50.0f}}},
	{"vasa",	{"resources/vasa_aspect.png",		{1.5f, 1.5f}, {1.0f, 1.0f}, {50.0f, 50.0f}}},
	{"paja",	{"resources/paja_aspect.png",		{1.5f, 1.5f}, {1.0f, 1.0f}, {50.0f, 50.0f}}},
	{"tamara",  {"resources/tamara_aspect.png",		{1.5f, 1.5f}, {1.0f, 1.0f}, {50.0f, 50.0f}}},
};	//str ime   //textureFile						//scale		  //position	//origin

std::unordered_map<std::string, sf::Texture> textureCache;

sf::Sprite createAspect(const std::string& aspectName) {
	sf::Sprite sprite;

	if (mapaSBlagom.find(aspectName) != mapaSBlagom.end()) {
		if (textureCache.find(aspectName) == textureCache.end()) {
			if (!textureCache[aspectName].loadFromFile(mapaSBlagom[aspectName].textureFile)) {
				std::cerr << "Failed to load texture: " << mapaSBlagom[aspectName].textureFile << std::endl;
				return sprite;
			}
		}
		sprite.setTexture(textureCache[aspectName]);
		sprite.setScale(mapaSBlagom[aspectName].scale);
		sprite.setPosition(mapaSBlagom[aspectName].position);
		sprite.setOrigin(mapaSBlagom[aspectName].origin);
	}
	else {
		std::cerr << "Aspect " << aspectName << " not found!" << std::endl;
	}

	return sprite;
}