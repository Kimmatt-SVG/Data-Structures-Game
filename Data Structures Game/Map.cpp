#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include "shop.h"
#include "shop.cpp"
#include "talkingNPC.h"


enum class LocationType { EMPTY, SHOP, ENEMY, NPC };

struct Node {
    int id;
    LocationType type;
    std::shared_ptr<shop> shop = nullptr;
    std::shared_ptr<enemy> enemy = nullptr;
    std::shared_ptr<talkingNPC> NPC = nullptr;
    std::vector<int> neighbors; // Connected node IDs

    Node(int id, LocationType type) : id(id), type(type) {}
};

class Graph {
public:
    void addNode(int id, LocationType type) {
        nodes[id] = std::make_shared<Node>(id, type);
    }

    void addEdge(int from, int to) {
        nodes[from]->neighbors.push_back(to);
        nodes[to]->neighbors.push_back(from); // Assume undirected graph
    }

    std::shared_ptr<Node> getNode(int id) {
        if (nodes.count(id)) {
            return nodes[id];
        }
        return nullptr;
    }

    void displayNode(int id) {
        auto node = getNode(id);
        if (!node) {
            std::cout << "Node not found.\n";
            return;
        }
        std::cout << "Node " << id << ": ";
        switch (node->type) {
        case LocationType::SHOP: std::cout << "Shop"; break;
        case LocationType::ENEMY: std::cout << "Enemy"; break;
        case LocationType::NPC: std::cout << "NPC"; break;
        case LocationType::EMPTY: std::cout << "Empty"; break;
        }
        std::cout << "\nConnected to: ";
        for (int neighbor : node->neighbors) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }

private:
    std::unordered_map<int, std::shared_ptr<Node>> nodes;
};