#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <cmath>
//#include <iostream>
#include <SFML/Graphics.hpp>
#include "events.hpp"
#include "configuration.hpp"
#include <string>

using namespace std;

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(conf::window_size), "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	window.setFramerateLimit(60);
	
	// start initial clock
	sf::Clock clock;


    // run the program as long as the window is open
    while (window.isOpen())
    {
		processEvents(window);

        // clear the window
        window.clear(sf::Color::White);

		// set up circle
        sf::CircleShape shape(conf::radius);
		// find sin of frequency during time elapsed
		double x_coord = sin(conf::angular_frequency * clock.getElapsedTime().asSeconds() * 2);
		shape.setPosition(sf::Vector2f((x_coord + 1.f) * (conf::window_size_f.x / 2.f - conf::radius), conf::window_size_f.y / 2.f - conf::radius));
		shape.setFillColor(sf::Color(100, 250, 50));
		
		// make ui text
		sf::Text info(conf::default_font);
		info.setString("X Position: " + to_string(x_coord));
		info.setFillColor(sf::Color::Red);

		// draw
		window.draw(shape);
		window.draw(info);

        // end the current frame
        window.display();
    }
}
