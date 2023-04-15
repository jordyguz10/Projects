#include "CelestialBody.h"
#include <iomanip>

CelestialBody::CelestialBody(){
	universeRadius = 0.0;
	x_position = 0.0;
	y_position = 0.0;
	x_velocity = 0.0;
	y_velocity = 0.0;
	UniverseMass = 0.0;
	fileName = "NoName";
}

CelestialBody::CelestialBody(double x, double y, double x_velo, double y_velo, double mass, std::string name){
	x_position = x;
	y_position = y;
	x_velocity = x_velo;
	y_velocity = y_velo;
	UniverseMass = mass;
	fileName = name;
	MakeSprite(fileName);
}
void CelestialBody::setWindowSize(int x, int y){
	windowSize_X = x; 
	windowSize_Y = y;
}
void CelestialBody::setUniverseRadius(double size){
	universeRadius = size;
}
void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Sprite temp = sprite;
	double x = (universeRadius + x_position) * windowSize_Y / (2 * universeRadius);
	double y = (universeRadius - y_position) * windowSize_X / (2 * universeRadius);
	temp.setPosition(x, y);
	target.draw(temp, states);
}
std::istream& operator>>(std::istream& input, CelestialBody &obj){
	std::cin >> obj.x_position;
	std::cin >> obj.y_position;
	std::cin >> obj.x_velocity;
	std::cin >> obj.y_velocity;
	std::cin >> obj.UniverseMass;
	std::cin >> obj.fileName;
	obj.MakeSprite(obj.fileName);
	return input;
}
void CelestialBody::print(void){
	//Print all variables for one Body
	std::cout << std::scientific << std::setprecision(4) << std::setw(11) << x_position << std::setw(13) << y_position << std::setw(13) << 
	x_velocity << std::setw(13) << y_velocity << std::setw(13) << UniverseMass << std::setw(13) << fileName << std::endl;
}
void CelestialBody::MakeSprite(std::string name){
	texture.loadFromFile(name);
	sprite.setTexture(texture);
}
void CelestialBody::setVelocities(double x, double y){
	x_velocity = x;
	y_velocity = y;
}
void CelestialBody::setPositions(double x, double y){
	x_position = x;
	y_position = y;
}