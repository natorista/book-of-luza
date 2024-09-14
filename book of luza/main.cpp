#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "columnsLogic.h"
#include "spriteCreation.h"

// Function to reset and regenerate the sprites and vectors
void resetSprites(std::vector<sf::Sprite>& current_sprites, int nPokoloni,
    const sf::Vector2f& nultaPozicija1, const sf::Vector2f& nultaPozicija2, const sf::Vector2f& nultaPozicija3)
{
    current_sprites.clear();  // Clear existing sprites

    std::vector<std::string> ImenaUKoloni1 = imenaUkupno(nPokoloni);
    std::vector<std::string> ImenaUKoloni2 = imenaUkupno(nPokoloni);
    std::vector<std::string> ImenaUKoloni3 = imenaUkupno(nPokoloni);

    for (int i = 0; i < nPokoloni; ++i) {
        sf::Sprite new_sprite = createAspect(ImenaUKoloni1[i]);
        new_sprite.setPosition(nultaPozicija1.x, nultaPozicija1.y + i * 160.0f);
        current_sprites.push_back(new_sprite);
    }
    for (int i = 0; i < nPokoloni; ++i) {
        sf::Sprite new_sprite = createAspect(ImenaUKoloni2[i]);
        new_sprite.setPosition(nultaPozicija2.x, nultaPozicija2.y + i * 160.0f);
        current_sprites.push_back(new_sprite);
    }
    for (int i = 0; i < nPokoloni; ++i) {
        sf::Sprite new_sprite = createAspect(ImenaUKoloni3[i]);
        new_sprite.setPosition(nultaPozicija3.x, nultaPozicija3.y + i * 160.0f);
        current_sprites.push_back(new_sprite);
    }
}

int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 600), "Book of Luzha");

    sf::Texture background;
    if (!background.loadFromFile("resources/book_of_luza_bg.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite bag_sprite;
    bag_sprite.setTexture(background);

    sf::Texture masina;
    if (!masina.loadFromFile("resources/masina.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite masina_sprite;
    masina_sprite.setTexture(masina);

    int nPokoloni = 100;

    const sf::Vector2f nultaPozicija1 = { 160.0f, 195.0f };
    const sf::Vector2f nultaPozicija2 = { 310.0f, 195.0f };
    const sf::Vector2f nultaPozicija3 = { 460.0f, 195.0f };

    std::vector<sf::Sprite> current_sprites;

    // Initial sprite setup
    resetSprites(current_sprites, nPokoloni, nultaPozicija1, nultaPozicija2, nultaPozicija3);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Detect space key press
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                resetSprites(current_sprites, nPokoloni, nultaPozicija1, nultaPozicija2, nultaPozicija3); // Reset logic
            }
        }

        window.clear(sf::Color::White);
        for (const auto& sprite : current_sprites) {
            window.draw(sprite);
        }
        window.draw(bag_sprite);
        window.draw(masina_sprite);
        window.display();
    }

    return 0;
}
