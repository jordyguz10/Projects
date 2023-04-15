#include "PhotoMagic.h"

int main(int argc, char* argv[]){

	FibLFSR inputSeed(argv[3]);
	sf::Image input;
	sf::Image output;
	if (!input.loadFromFile(argv[1])){
		return EXIT_FAILURE;
	}
	if (!output.loadFromFile(argv[1])){
		return EXIT_FAILURE;
	}

	transform(output, &inputSeed);

	if (!output.saveToFile(argv[2])){
		return EXIT_FAILURE;
	}

	sf::Texture texture_In;
	texture_In.loadFromImage(input);
	sf::Texture texture_Out;
	texture_Out.loadFromImage(output);

	sf::Sprite sprite_In;
	sprite_In.setTexture(texture_In);
	sf::Sprite sprite_Out;
	sprite_Out.setTexture(texture_Out);

	sf::Vector2u size = output.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input Image");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output Image");

	while (window1.isOpen() && window2.isOpen()) {
		sf::Event event;
		while (window1.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window1.close();
			}
		while (window2.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window2.close();
			}
		window1.clear();
		window1.draw(sprite_In);
		window1.display();
		window2.clear();
		window2.draw(sprite_Out);
		window2.display();
	}

	return 0;
}
void transform(sf::Image& inputImg, FibLFSR* inputSeed){

	//Gets size of image
	sf::Vector2u size = inputImg.getSize();
	unsigned int width = size.x;
	unsigned int height = size.y;

	//Modifies the image one pixel at a time
	sf::Color onePixel;
	for (unsigned int x = 0; x < width; x++){
    	for (unsigned int y = 0; y < height; y++) {
    	onePixel = inputImg.getPixel(x, y);
    	onePixel.r = (onePixel.r ^ inputSeed->generate(8));
    	onePixel.g = (onePixel.g ^ inputSeed->generate(8));
    	onePixel.b = (onePixel.b ^ inputSeed->generate(8));
    	inputImg.setPixel(x, y, onePixel);
    	}
	}
}
