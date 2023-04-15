#include "Universe.h"
#include <cmath>

Universe::Universe(){
	UniverseSize = 0;
	CelestialBodies = 0;
}
void Universe::setUniverseSize(double a){
	UniverseSize = a;
}
void Universe::setWindowSize(int x, int y){
	WindowSizeX = x;
	WindowSizeY = y;
}
void Universe::InitializeVector(void){
	for (int i = 0; i < CelestialBodies; i++){
		planets.push_back(std::make_unique<CelestialBody>());
		std::cin >> *planets[i];
		planets[i]->setWindowSize(WindowSizeX, WindowSizeY);
		planets[i]->setUniverseRadius(UniverseSize);
	}
}
void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	for(int i = 0; i < CelestialBodies; i++){
		target.draw(*planets[i]);
	}
}
/*
Universe::~Universe(){
	for (int i = 0; i < CelestialBodies; i++){
		delete planets[i];
	}
	planets.clear();
}
*/
void Universe::print(){
	//Print the state of the universe
	std::cout << CelestialBodies << std::endl;
	std::cout << UniverseSize << std::endl;
	for(int i = 0; i < CelestialBodies; i++){
		planets[i]->print();
	}
}
void Universe::step(double seconds){
	const double G = 6.67e-11;
	//Create the Force Vectors
	std::vector<double>Net_ForceX;
	std::vector<double>Net_ForceY;
	//Initialize total force on X and Y for each planet to 0.
	for(int i = 0; i < CelestialBodies; i++){
		Net_ForceX.push_back(0.0);
		Net_ForceY.push_back(0.0);
	}
	for(int i = 0; i < CelestialBodies; i++){
		for(int j = 0; j < CelestialBodies; j++){
			//Planet applies force to every other planet, not to itself.
			if (i != j){
				double DeltaX = planets[j]->getXPosition() - planets[i]->getXPosition();
				double DeltaY = planets[j]->getYPosition() - planets[i]->getYPosition();
				double r = sqrt(pow(DeltaX, 2) + pow(DeltaY, 2));
				double force = ((G * planets[j]->getMass()) * planets[i]->getMass()) / pow(r, 2);
				double Fx = force * (DeltaX / r);
				double Fy = force * (DeltaY / r);
				Net_ForceX[i] += Fx;
				Net_ForceY[i] += Fy;
			}
		}
		//Calculating New positions and velocities, Acceleration = Force / Mass
		double Ax = Net_ForceX[i] / planets[i]->getMass();
		double Ay = Net_ForceY[i] / planets[i]->getMass();
		double VeloX = planets[i]->getXVelocity() + (Ax * seconds);
		double VeloY = planets[i]->getYVelocity() + (Ay * seconds);
		double newXPos = planets[i]->getXPosition() + (VeloX * seconds);
		double newYPos = planets[i]->getYPosition() + (VeloY * seconds);
		planets[i]->setVelocities(VeloX, VeloY);
		planets[i]->setPositions(newXPos, newYPos);
	}
}
