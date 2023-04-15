// Copyright 2022 <Jordy Guzman>

#include "Triangle.h"

using std::vector;

int TotalTriangles(int levels, int count, vector<int> *nums);
void fTree(const vector<Triangle*> &x, const vector<int> &T, double, int);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Command-Line Error! Two Arguments Only!" << std::endl;
        exit(1);
    }
    double side = atof(argv[1]);
    int levels = atoi(argv[2]);;
    double Screen = side * 4;

    vector<int> TriPerLevel;
    int Count = 0;
    int TotalTri = 0;
    TotalTri = TotalTriangles(levels, Count, &TriPerLevel);

    vector<Triangle*> drawTri;
    for (int i = 0; i < TotalTri; i++) {
        drawTri.push_back(new Triangle());
        drawTri[i]->setWindow(Screen, Screen);
    }

    int TriangleCount = 0;
    fTree(drawTri, TriPerLevel, side, TriangleCount);

    sf::Transform t;
    float middlePoint = static_cast<float> (Screen) / 2.f;

    sf::RenderWindow window(sf::VideoMode(Screen, Screen), "Triangle Fractal");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        t.rotate(0.5, {middlePoint, middlePoint});

        for (int i = 0; i < TotalTri; i++) {
            window.draw(*drawTri[i], t);
        }

        window.display();
    }

    // Deletes and clears vector to avoid memory leaks
    for (auto oneTri : drawTri) {
        delete oneTri;
    }
    drawTri.clear();

    return 0;
}
// Recursive function that gets total triangles to draw
int TotalTriangles(int levels, int count, vector<int> *nums) {
    int total = 0;
    int LastNum = count - 1;
    if (count == 0) {
        total++;
        count++;
        nums->push_back(total);
        return TotalTriangles(levels, count, nums);
    } else if (count <= levels) {
        total = pow(3, count) + nums->at(LastNum);
        count++;
        nums->push_back(total);
        return TotalTriangles(levels, count, nums);
    }
    return nums->at(LastNum);
}
void fTree(const vector<Triangle*> &x, const vector<int> &T, double l, int i) {
    // Recursively Drawing Each Triangle into Vector
    int Total = x.size();
    for (size_t j = 0; j < T.size(); j++) {
        if (T[j] == i) {
            l = l / 2;
        }
    }
    // BaseTriangle
    if (i == 0) {
        x[i]->setSideLength(l);
        x[i]->InitBaseTriangle();
        i++;
        fTree(x, T, l, i);
    // Making smaller triangles on each point of base triangle
    } else if (i < Total) {
        int BaseNum = (i - 1) / 3;
        int p = i % 3;
        sf::Vector2f temp = x[BaseNum]->getPoint(p);
        x[i]->setSideLength(l);
        if (p == 0) {
            x[i]->DrawL(temp);
        } else if (p == 1) {
            x[i]->DrawR(temp);
        } else {
            x[i]->DrawB(temp);
        }
        i++;
        fTree(x, T, l, i);
    }
}
