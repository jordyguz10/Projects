#pragma once
#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "CelestialBody.h"
#include <vector>
#include <memory>
#include <sstream>

class Universe : public sf::Drawable {
public:
	Universe();
	//~Universe();
	void setUniverseSize(double a);
	void setWindowSize(int x, int y);
	void InitializeVector(void);
	void print();
	void step(double seconds);
	friend std::istream& operator>>(std::istream& input, Universe& obj){
		input >> obj.CelestialBodies;
		input >> obj.UniverseSize;
		obj.InitializeVector();
		return input;
	}
private:
	int CelestialBodies;
	double UniverseSize;
	int WindowSizeX;
	int WindowSizeY;
	std::vector<std::unique_ptr<CelestialBody>> planets;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif