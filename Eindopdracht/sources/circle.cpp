#include "../headers/circle.hpp"

circle::circle(sf::Vector2f position, float size, sf::Color color):
	position{position},
	size{size},
    color{color}
{
    object.setPosition(position);
    object.setRadius(size);
    object.setFillColor(color);
}

void circle::draw(sf::RenderWindow & window){
	object.setPosition(position);
	window.draw(object);
}

void circle::screen_object_write(std::string textfileName){
	std::ofstream myFile;
	std::string strColor;
	
	if(color == sf::Color::Black)strColor = "black";
	else if(color == sf::Color::Red)strColor = "red";
	else if(color == sf::Color::Green)strColor = "green";
	else if(color == sf::Color::Blue)strColor = "blue";
	else if(color == sf::Color::Yellow)strColor = "yellow";
	else if(color == sf::Color::Magenta)strColor = "magenta";

	myFile.open(textfileName, std::ios_base::app);
		myFile << "CIRCLE " << "(" << position.x << "," << position.y << ") " << strColor << ' ' << size << std::endl;
	myFile.close();
}

sf::Vector2f circle::getPos(){
	return object.getPosition();
}

bool circle::collisionCheck(sf::Vector2i target){
    if((target.x >= position.x && target.y >= position.y) && (target.x <= (position.x + (size * 2)) && target.y <= (position.y + (size * 2))))
		return 1;
	return 0;
}

void circle::jump(sf::Vector2f target){
	position = target;
    position.x -= size;
    position.y -= size;
}

void circle::jump(sf::Vector2i target){
	jump( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}

sf::Color circle::getColor(){
	return color; 
}
    
void circle::setColor(sf::Color newColor){
	color = newColor;
	object.setFillColor(color);
}