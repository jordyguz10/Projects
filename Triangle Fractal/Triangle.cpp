// Copyright 2022 <Jordy Guzman>

#include "Triangle.h"

Triangle::Triangle() {
    SideLength = 0.0;
    WindowSizeX = 0.0;
    WindowSizeY = 0.0;
    Height = 0.0;
    triangle.setFillColor(sf::Color::Transparent);
}
Triangle::Triangle(double sideLength, double x, double y) {
    SideLength = sideLength;
    WindowSizeX = x;
    WindowSizeY = y;
    Height = (sqrt(3) / 2) * SideLength;
}
void Triangle::setSideLength(double x) {
    SideLength = x;
    Height = (sqrt(3) / 2) * SideLength;
}
void Triangle::setWindow(double y, double z) {
    WindowSizeX = y;
    WindowSizeY = z;
}
void Triangle::InitBaseTriangle(void) {
    double middleX = WindowSizeX / 2.0;
    double middleY = WindowSizeY / 2.0;
    double HalfSideL = SideLength / 2.0;
    double OneFourthSideL = SideLength / 4.0;
    one = sf::Vector2f(middleX - HalfSideL, middleY - OneFourthSideL);
    two = sf::Vector2f(middleX + HalfSideL, middleY - OneFourthSideL);
    three = sf::Vector2f(middleX, middleY - OneFourthSideL + Height);
    triangle.setPointCount(3);
    triangle.setPoint(0, one);
    triangle.setPoint(1, two);
    triangle.setPoint(2, three);
    triangle.setOutlineColor(sf::Color::Black);
    triangle.setOutlineThickness(2);
}
sf::Vector2f Triangle::getPoint(int index) const {
    return triangle.getPoint(index);
}
void Triangle::DrawL(sf::Vector2f p) {
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(p.x - (SideLength / 2), p.y - Height));
    triangle.setPoint(1, sf::Vector2f(p.x + (SideLength / 2), p.y - Height));
    triangle.setPoint(2, p);
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(2);
}
void Triangle::DrawR(sf::Vector2f p) {
    double HalfSide = SideLength / 2.0;
    triangle.setPointCount(3);
    triangle.setPoint(0, p);
    triangle.setPoint(1, sf::Vector2f(p.x + (SideLength), p.y));
    triangle.setPoint(2, sf::Vector2f(p.x + HalfSide, p.y + Height));
    triangle.setOutlineColor(sf::Color::Green);
    triangle.setOutlineThickness(2);
}
void Triangle::DrawB(sf::Vector2f p) {
    double HalfSide = SideLength / 2.0;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(p.x - SideLength, p.y));
    triangle.setPoint(1, p);
    triangle.setPoint(2, sf::Vector2f(p.x - HalfSide, p.y + Height));
    triangle.setOutlineColor(sf::Color::Blue);
    triangle.setOutlineThickness(2);
}
void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(triangle, states);
}
