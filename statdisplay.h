#ifndef STATDISPLAY_H
#define STATDISPLAY_H
#include <mutex>

std::mutex mtx;

int hpBar(int& currentHealth, int& maxHealth)
{
    double percentageHealth = static_cast<double>(currentHealth) / maxHealth * 100;

    int numFilledBlocks = percentageHealth / 10;
    int numEmptyBlocks = 10 - numFilledBlocks;

    mtx.lock();
    printf("\033[19;0f");
    std::cout << "[";
    for (int i = 0; i < numFilledBlocks; i++) {
        std::cout << "#";
    }
    for (int i = 0; i < numEmptyBlocks; i++) {
        std::cout << "=";
    }
    std::cout << "]    " << currentHealth << "/" << maxHealth << "\r";
    std::cout.flush();
    mtx.unlock();
    return currentHealth;
}

double manaBar(double& currentMana, double& maxMana)
{
    int percentageMana = currentMana / maxMana * 100;

    int numFilledBlocks = percentageMana / 10;
    int numEmptyBlocks = 10 - numFilledBlocks;

    mtx.lock();
    printf("\033[20;0f");
    std::cout << "[";
    for (int i = 0; i < numFilledBlocks; i++) {
        std::cout << "#";
    }
    for (int i = 0; i < numEmptyBlocks; i++) {
        std::cout << "=";
    }
    std::cout << "]    " << currentMana << "/" << maxMana << "\r";
    std::cout.flush();
    mtx.unlock();
    return currentMana;
}


#endif