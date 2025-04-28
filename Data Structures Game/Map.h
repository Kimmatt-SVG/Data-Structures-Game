#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <unordered_map>

class MapNode {
public:
    int id;
    std::string description;
    bool isPassable;

    // Pointers to adjacent nodes
    MapNode* up;
    MapNode* down;
    MapNode* left;
    MapNode* right;

    MapNode(int id, const std::string& desc, bool passable = true)
        : id(id), description(desc), isPassable(passable),
        up(nullptr), down(nullptr), left(nullptr), right(nullptr) {}
};

class GameMap {
private:
    std::unordered_map<int, MapNode*> nodes;
    MapNode* currentLocation;
    int width;
    int height;
    void getPlayerPosition(int& x, int& y) const;


public:
    GameMap(int width, int height);
    ~GameMap();
    void displayMap() const;

    // Map construction
    void addNode(int id, const std::string& description, bool passable = true);
    void connectNodes(int fromId, int toId, char direction);
    void setImpassable(int id);

    // Navigation
    bool move(char direction);
    MapNode* getCurrentLocation() const;
    void displayCurrentLocation() const;

    // Map validation
    bool isValidPosition(int x, int y) const;

private:
    void clearMap();
};

#endif // MAP_H#pragma once
