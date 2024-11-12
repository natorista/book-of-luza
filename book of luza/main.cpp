#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <iostream>


int main() {

    //Window, background and static sprites
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

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
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





        //final draws
        window.clear(sf::Color::White);
        window.draw(bag_sprite);
        window.draw(masina_sprite);
        window.display();
        //end of final draws
    }


}