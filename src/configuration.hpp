#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Vector2.hpp>
namespace conf
{
	// Window Configuration
	sf::Vector2u const window_size = {1920, 1080};
	sf::Vector2f const window_size_f = static_cast<sf::Vector2f>(window_size);

	// Program Variables
	double const radius = 40.f;
	sf::Vector2u const margin = {32, 32};
	double const angular_frequency = 1.f;

	sf::Font const default_font("assets/fonts/HackNerdFont-Regular.ttf"); 
}
