// Copyright 2022 <Jordy Guzman>

#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Triangle : public sf::Drawable{
 public:
    Triangle();
    Triangle(double sideLength, double x, double y);
    void setSideLength(double x);
    void setWindow(double y, double z);
    void drawFromPoint(void);
    void InitBaseTriangle(void);
    sf::Vector2f getPoint(int index) const;
    void DrawL(sf::Vector2f p);
    void DrawR(sf::Vector2f p);
    void DrawB(sf::Vector2f p);
 private:
    double SideLength;
    double WindowSizeX;
    double WindowSizeY;
    double Height;
    sf::Vector2f one;
    sf::Vector2f two;
    sf::Vector2f three;
    sf::ConvexShape triangle;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // NOLINT
};

#endif
