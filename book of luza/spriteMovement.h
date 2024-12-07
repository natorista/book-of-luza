#ifndef SPRITE_MOVEMENT_H
#define SPRITE_MOVEMENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

void skrolanje_pozicija(std::vector<sf::Sprite>& sprites, float offset, int nPokoloni, int chosenN, bool& scrolling);
void initializeSounds(sf::SoundBuffer& buffer, sf::Sound& sound);

#endif // SPRITE_MOVEMENT_H
