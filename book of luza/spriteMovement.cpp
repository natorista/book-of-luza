#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>


//vertikalna sredina masine je y360, 380otkad je povecan monitor na masini
void skrolanje_pozicija(std::vector<sf::Sprite>& sprites, float offset, int nPokoloni, int chosenN, bool& scrolling) {
    // Check if the chosen sprite is at the target position
    sf::Vector2f chosen_pos = sprites[chosenN].getPosition();
    if (chosen_pos.y >= 380.0f) {
        scrolling = false; // Stop scrolling if the chosen sprite is locked
        return; // Exit the function
    }

    // Continue scrolling if the chosen sprite is not at the target position
    for (int i = 0; i < nPokoloni; ++i) {
        sf::Vector2f cur_pos = sprites[i].getPosition();
        cur_pos.y += offset; // Apply offset
        sprites[i].setPosition(cur_pos); // Update the position directly

    }
}
