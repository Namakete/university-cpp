#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class IReader {
   public:
    explicit IReader();

    static void readDataFromFile(std::vector<std::string> &item, const std::string &file);

    static void formTextData(std::vector<std::string> &item);

    static void outputTextData(std::vector<std::string> &item);
};

IReader::IReader() = default;

void IReader::readDataFromFile(std::vector<std::string> &item, const std::string &file) {
    std::string str;

    std::ifstream in(file);

    if (!in.is_open()) {
        std::cout << "File can not be opened" << std::endl;
    }

    int i = 0;
    while (!in.eof()) {
        in >> str;
        if (str.length() < 2) {
            continue;
        } else {
            item.push_back(str);
            i++;
        }
    }
}

void IReader::formTextData(std::vector<std::string> &item) {
    for (std::vector<std::string>::iterator iter = item.begin(); iter != item.end(); ++iter) {
        for (auto i = iter + 1; i != item.end();) {
            if (*iter == *i) {
                i = item.erase(i);
            } else {
                ++i;
            }
        }
    }
}

void IReader::outputTextData(std::vector<std::string> &item) {
    for (int i = 0; i < item.size(); i++) {
        std::cout << item[i] << "\n";
    }
}

struct Point {
    int x = 0;
    int y = 0;
};

int sqrDist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

namespace math {
struct Shape {
    int numberOfVertices;
    std::vector<Point> vertices;

    bool isTriangle() {
        return numberOfVertices == 3;
    }

    bool isSquare() {
        if (numberOfVertices == 4) {
            return (sqrDist(vertices[0], vertices[1]) - sqrDist(vertices[1], vertices[2]) + sqrDist(vertices[2], vertices[3]) - sqrDist(vertices[3], vertices[0])) == 0;
        } else {
            return false;
        }
    }

    bool isRectangle() {
        if (numberOfVertices == 4) {
            return sqrDist(vertices[0], vertices[2]) == sqrDist(vertices[1], vertices[3]);
        } else {
            return false;
        }
    }
};
}  // namespace math

void printFigures(std::vector<math::Shape> shapes) {
    for_each(shapes.begin(), shapes.end(), [&](math::Shape shape) {
        std::cout << std::endl
                  << "Vertex number: " << shape.numberOfVertices << std::endl;
        std::cout << "Points:" << std::endl;

        for_each(shape.vertices.begin(), shape.vertices.end(), [&](Point point) {
            std::cout << "x: " << point.x << ", y: " << point.y << std::endl;
        });
    });
}

void generationData(std::vector<math::Shape> figures) {
    for (int i = 0; i < 10; i++) {
        math::Shape shape;
        shape.numberOfVertices = rand() % 4 + 2;

        for (int j = 0; j < shape.numberOfVertices; j++) {
            Point point;
            point.x = rand() % 20 - 10;
            point.y = rand() % 20 - 10;

            shape.vertices.push_back(point);
        }
        figures.push_back(shape);
    }
}

int main() {
    std::vector<std::string> word(0);

    IReader::readDataFromFile(word, "../main.cpp");
    IReader::formTextData(word);
    IReader::outputTextData(word);

    std::vector<math::Shape> figures;

    generationData(figures);

    math::Shape shape;
    shape.numberOfVertices = 4;

    Point point;
    point.x = 0;
    point.y = 0;
    shape.vertices.push_back(point);

    point.x = 5;
    point.y = 0;
    shape.vertices.push_back(point);

    point.x = 5;
    point.y = 5;
    shape.vertices.push_back(point);

    point.x = 0;
    point.y = 5;
    shape.vertices.push_back(point);

    figures.push_back(shape);
    shape.vertices.clear();

    point.x = 0;
    point.y = 0;
    shape.vertices.push_back(point);

    point.x = 5;
    point.y = 0;
    shape.vertices.push_back(point);

    point.x = 5;
    point.y = 10;
    shape.vertices.push_back(point);

    point.x = 0;
    point.y = 10;
    shape.vertices.push_back(point);

    figures.push_back(shape);

    printFigures(figures);

    figures.erase(remove_if(figures.begin(), figures.end(), [&](math::Shape shape) { return shape.numberOfVertices >= 5; }), figures.end());

    printFigures(figures);

    int commonVertCount = 0;
    for_each(figures.begin(), figures.end(), [&](math::Shape shape) {
        commonVertCount += shape.numberOfVertices;
    });
    std::cout << std::endl
              << "Common vertex count: " << commonVertCount << std::endl;

    int triangles = count_if(figures.begin(), figures.end(), [&](math::Shape shape) {
        return shape.isTriangle();
    });

    int squares = count_if(figures.begin(), figures.end(), [&](math::Shape shape) {
        return shape.isSquare();
    });

    int rectangles = count_if(figures.begin(), figures.end(), [&](math::Shape shape) {
                         return shape.isRectangle();
                     }) -
                     squares;

    std::cout << std::endl
              << "Triangles: " << triangles << " Squares: " << squares << " Rectangles: " << rectangles << std::endl;

    sort(figures.begin(), figures.end(), [&](math::Shape a, math::Shape b) {
        return a.numberOfVertices < b.numberOfVertices;
    });

    printFigures(figures);
}