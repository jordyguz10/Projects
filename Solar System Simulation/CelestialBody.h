#pragma once
#ifndef CELESTIAL_H
#define CELESTIAL_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class CelestialBody: public sf::Drawable {
public:
	CelestialBody();
	CelestialBody(double x, double y, double x_velo, double y_velo, double mass, std::string name);
	double getXPosition(void) { return x_position; }
	double getYPosition(void) { return y_position; }
	double getXVelocity(void) { return x_velocity; }
	double getYVelocity(void) { return y_velocity; }
	double getMass(void) { return UniverseMass; }
	void setWindowSize(int x, int y);
	void setVelocities(double x, double y);
	void setPositions(double x, double y);
	void setUniverseRadius(double size);
	void print(void);
	void MakeSprite(std::string name);
	friend std::istream& operator>>(std::istream& input, CelestialBody &obj);
private:
	double x_position;
	double y_position;
	double x_velocity;
	double y_velocity;
	double UniverseMass;
	double universeRadius;
	int windowSize_X;
	int windowSize_Y;
	std::string fileName;
	sf::Texture texture;
	sf::Sprite sprite;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif