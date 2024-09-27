#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "columnsLogic.h"
#include "spriteCreation.h"
#include "spriteMovement.h"



int kolonaRandomizer(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    int broj = dist(gen);
    return broj;
};

// Function to reset and regenerate the sprites and vectors
void resetSprites(std::vector<sf::Sprite>& current_sprites1,
    std::vector<sf::Sprite>& current_sprites2,
    std::vector<sf::Sprite>& current_sprites3,
    int nPokoloni,
    const sf::Vector2f& nultaPozicija1,
    const sf::Vector2f& nultaPozicija2,
    const sf::Vector2f& nultaPozicija3,
    int& kolona1Choice,
    int& kolona2Choice,
    int& kolona3Choice)
{
    current_sprites1.clear();  // Clear existing sprites
    current_sprites2.clear();  // Clear existing sprites
    current_sprites3.clear();  // Clear existing sprites

    std::vector<std::string> ImenaUKoloni1 = imenaUkupno(nPokoloni);
    std::vector<std::string> ImenaUKoloni2 = imenaUkupno(nPokoloni);
    std::vector<std::string> ImenaUKoloni3 = imenaUkupno(nPokoloni);

    for (int i = 0; i < nPokoloni; ++i) {
        sf::Sprite new_sprite = createAspect(ImenaUKoloni1[i]);
        new_sprite.setPosition(nultaPozicija1.x, nultaPozicija1.y + i * 160.0f);
        current_sprites1.push_back(new_sprite);
    }
    for (int i = 0; i < nPokoloni; ++i) {
        sf::Sprite new_sprite = createAspect(ImenaUKoloni2[i]);
        new_sprite.setPosition(nultaPozicija2.x, nultaPozicija2.y + i * 160.0f);
        current_sprites2.push_back(new_sprite);
    }
    for (int i = 0; i < nPokoloni; ++i) {
        sf::Sprite new_sprite = createAspect(ImenaUKoloni3[i]);
        new_sprite.setPosition(nultaPozicija3.x, nultaPozicija3.y + i * 160.0f);
        current_sprites3.push_back(new_sprite);
    }

    // Regenerate kolona choices based on the new randomization logic
    kolona1Choice = kolonaRandomizer(67 * (nPokoloni / 100), 100 * (nPokoloni / 100));
    kolona2Choice = kolonaRandomizer(34 * (nPokoloni / 100), 66 * (nPokoloni / 100));
    kolona3Choice = kolonaRandomizer(1 * (nPokoloni / 100), 33 * (nPokoloni / 100));
}


float brzinavrcenja = 4.0f;

int main() {

    //Window and background
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
    //End of window and background

    //defining and initializing aspect properties
    int nPokoloni = 100;

    int kolona3choice = kolonaRandomizer(1, 33 * (nPokoloni / 100));
    int kolona2choice = kolonaRandomizer(34 * (nPokoloni / 100), 66 * (nPokoloni / 100));
    int kolona1choice = kolonaRandomizer(67 * (nPokoloni / 100), 100 * (nPokoloni / 100));

    const sf::Vector2f nultaPozicija1 = { 160.0f, -19500.0f };
    const sf::Vector2f nultaPozicija2 = { 310.0f, -20050.0f };
    const sf::Vector2f nultaPozicija3 = { 460.0f, -19500.0f };

    //std::vector<sf::Sprite> current_sprites;
    std::vector<sf::Sprite> kolona1sprites;
    std::vector<sf::Sprite> kolona2sprites;
    std::vector<sf::Sprite> kolona3sprites;
    //end of def. aspect properties

    // Initial sprite setup
    resetSprites(kolona1sprites, kolona2sprites, kolona3sprites, nPokoloni, nultaPozicija1, nultaPozicija2, nultaPozicija3, kolona1choice, kolona2choice, kolona3choice);
    bool skoroStisnuto = false;
    bool scrolling = true;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Detect space key press
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                resetSprites(kolona1sprites, kolona2sprites, kolona3sprites, nPokoloni, nultaPozicija1, nultaPozicija2, nultaPozicija3, kolona1choice, kolona2choice, kolona3choice);
                skoroStisnuto = true;
            }

            //debugging, shows current mouse position when scroll is pressed
            if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
            {
                sf::Vector2i current_mouse_position = sf::Mouse::getPosition(window);
                int mishX = current_mouse_position.x;
                int mishY = current_mouse_position.y;
                std::cout << "mishx: " << mishX << " mish y: " << mishY << std::endl;
            }
            //end of debugging
        }
        if(skoroStisnuto==true){
            skrolanje_pozicija(kolona1sprites, brzinavrcenja,nPokoloni,kolona1choice, scrolling);
            skrolanje_pozicija(kolona2sprites, brzinavrcenja,nPokoloni,kolona2choice, scrolling);
            skrolanje_pozicija(kolona3sprites, brzinavrcenja,nPokoloni,kolona3choice, scrolling);
        }

        //drawing aspects
        window.clear(sf::Color::White);
        for (const auto& sprite : kolona1sprites) {
            window.draw(sprite);
        }        
        for (const auto& sprite : kolona2sprites) {
            window.draw(sprite);
        }        
        for (const auto& sprite : kolona3sprites) {
            window.draw(sprite);
        }
        //end of drawing aspects


        //final draws
         window.draw(bag_sprite);
         window.draw(masina_sprite);
         window.display();
         //end of final draws
    }

    return 0;
}
