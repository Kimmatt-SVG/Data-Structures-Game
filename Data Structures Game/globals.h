#pragma once
#include "inventory.h"
#include <random>
#include <thread>
#include <chrono>
#include <cstdlib>

extern DLL inventory;

inline void pauseThenClear() {
	std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause for 2 seconds
	system("cls");
}