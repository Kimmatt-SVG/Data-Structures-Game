#include "map.h"
#include <iostream>
#include <stdexcept>

GameMap::GameMap(int width, int height) : width(width), height(height), currentLocation(nullptr) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int id = y * width + x;
            std::string desc = "Location (" + std::to_string(x) + ", " + std::to_string(y) + ")";
            addNode(id, desc);
        }
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int currentId = y * width + x;

            if (x > 0) {
                int leftId = y * width + (x - 1);
                connectNodes(currentId, leftId, 'a');
            }

            if (x < width - 1) {
                int rightId = y * width + (x + 1);
                connectNodes(currentId, rightId, 'd');
            }

            if (y > 0) {
                int upId = (y - 1) * width + x;
                connectNodes(currentId, upId, 'w');
            }

            if (y < height - 1) {
                int downId = (y + 1) * width + x;
                connectNodes(currentId, downId, 's');
            }
        }
    }

    int startId = (height / 2) * width + (width / 2);
    currentLocation = nodes[startId];

    setImpassable((height / 3) * width + (width / 3)); // Top-left area
    setImpassable((2 * height / 3) * width + (2 * width / 3)); // Bottom-right area


}

GameMap::~GameMap() {
    clearMap();
}

void GameMap::addNode(int id, const std::string& description, bool passable) {
    if (nodes.find(id) != nodes.end()) {
        delete nodes[id];
    }
    nodes[id] = new MapNode(id, description, passable);
}

void GameMap::connectNodes(int fromId, int toId, char direction) {

    if (nodes.find(fromId) == nodes.end() || nodes.find(toId) == nodes.end()) {
        throw std::runtime_error("Attempted to connect non-existent nodes");
    }

    MapNode* fromNode = nodes[fromId];
    MapNode* toNode = nodes[toId];

    switch (tolower(direction)) {
    case 'w':  
        fromNode->up = toNode;
        toNode->down = fromNode;
        break;
    case 's':           
        fromNode->down = toNode;
        toNode->up = fromNode;
        break;
    case 'a': 
        fromNode->left = toNode;
        toNode->right = fromNode;
        break;
    case 'd': 
        fromNode->right = toNode;
        toNode->left = fromNode;
        break;
    default:
        throw std::runtime_error("Invalid direction for node connection");
    }
}
void GameMap::getPlayerPosition(int& x, int& y) const {

   //td::cout << "Debug: Node 18 exists? " << (nodes.count(18) ? "Yes" : "No") << std::endl;
    if (!currentLocation) {
        x = y = -1;
        return;
    }
    y = currentLocation->id / width;
    x = currentLocation->id % width;
}


void GameMap::displayMap() const {
    int playerX, playerY;
    getPlayerPosition(playerX, playerY);

    std::cout << "\nMap:\n";
    std::cout << "+";
    for (int x = 0; x < width; ++x) std::cout << "---+";
    std::cout << "\n";

    for (int y = 0; y < height; ++y) {
        std::cout << "|";
        for (int x = 0; x < width; ++x) {
            int id = y * width + x;
            if (x == playerX && y == playerY) {
                std::cout << " P |";
            }
            else if (nodes.at(id)->isPassable) {
                std::cout << "   |";
            }
            else {
                std::cout << "###|";
            }
        }
        std::cout << "\n+";
        for (int x = 0; x < width; ++x) std::cout << "---+";
        std::cout << "\n";
    }
}

void GameMap::setImpassable(int id) {
    if (nodes.find(id) != nodes.end()) {
        nodes[id]->isPassable = false;
    }
}

bool GameMap::move(char direction) {
    if (!currentLocation) {
        std::cerr << "Error: Current location is null!\n";
        return false;
    }

    MapNode* target = nullptr;
    switch (tolower(direction)) {
    case 'w': target = currentLocation->up; break;
    case 's': target = currentLocation->down; break;
    case 'a': target = currentLocation->left; break;
    case 'd': target = currentLocation->right; break;
    }

    if (!target) {
        std::cerr << "Error: Cannot move " << direction << " (target is null)\n";
        return false;
    }

    if (!target->isPassable) {
        std::cerr << "Error: Target node " << target->id << " is impassable!\n";
        return false;
    }

    currentLocation = target;
    return true;
}
MapNode* GameMap::getCurrentLocation() const {
    return currentLocation;
}

void GameMap::displayCurrentLocation() const {

    if (currentLocation) {
        std::cout << currentLocation->description << "\n";

        std::cout << "Exits: ";
        if (currentLocation->up && currentLocation->up->isPassable) std::cout << "North ";
        if (currentLocation->down && currentLocation->down->isPassable) std::cout << "South ";
        if (currentLocation->left && currentLocation->left->isPassable) std::cout << "West ";
        if (currentLocation->right && currentLocation->right->isPassable) std::cout << "East ";
        std::cout << "\n";
    }
    else {
        std::cout << "Unknown location\n";
    }
}

bool GameMap::isValidPosition(int x, int y) const {
    int id = y * width + x;
    return x >= 0 && x < width && y >= 0 && y < height && nodes.find(id) != nodes.end();
}

void GameMap::clearMap() {
    for (auto& pair : nodes) {
        delete pair.second;
    }
    nodes.clear();
    currentLocation = nullptr;
}