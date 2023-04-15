#include "Universe.h"

int main(int argc, char* argv[]){

	if(argc != 3){
		std::cout << "Command Line Reading Error!" << std::endl;
		exit(1);
	}
	//atof converts string to a double.
	double T = atof(argv[1]);
	double DeltaT = atof(argv[2]);
	double TimeElapsed = 0.0;
	
	Universe solar_system;
	int Width = 500;
	int Height = 500;
	solar_system.setWindowSize(Width, Height);
	std::cin >> solar_system;

	sf::Font font;
	if (!font.loadFromFile("arial.ttf")){
		return EXIT_FAILURE;
	}
	
	//Sets font color and style
	sf::Text time;
	time.setFont(font);
	time.setCharacterSize(20);
	time.setFillColor(sf::Color::White);
	time.setStyle(sf::Text::Bold);
	
	sf::Texture texture;
	if (!texture.loadFromFile("ISpace.jpg")){
        return EXIT_FAILURE;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("daylight.wav")){
        return EXIT_FAILURE;
	}
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	sf::RenderWindow window(sf::VideoMode(Width, Height), "The Universe");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		std::ostringstream sstream;
		sstream.precision(1);
		sstream << std::fixed << TimeElapsed;
		std::string Time = "Time:  " + sstream.str() + "s";
		time.setString(Time);

		window.clear();

		window.draw(sprite);

		window.draw(time);
	
		window.draw(solar_system);
		
		solar_system.step(DeltaT);
		
		//Increment Time Elapsed by DeltaT
		TimeElapsed += DeltaT;

		if(TimeElapsed > T){
			window.close();
		}

		window.display();
	}

	//print final state of universe.
	solar_system.print();
	
	return 0;
}