#pragma once
#include "inventory.h"
#include <random>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <mutex>
#pragma comment(lib, "Winmm.lib")

extern DLL inventory;

inline void pauseThenClear() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause for 2 seconds
    system("cls");
}

inline void playSoundEffect(const std::string& soundFile) {
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx);

    std::wstring wideCommand = L"play " + std::wstring(soundFile.begin(), soundFile.end()) + L" from 0";
    if (mciSendString(wideCommand.c_str(), NULL, 0, NULL) != 0) {
        std::cerr << "Error: Failed to play sound file: " << soundFile << std::endl;
    }
}
