// Copyright 2022 NNTU-CS
// cppcheck-suppress unusedStructMember
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "train.h"

int main() {
    std::cout << "n\tall_off\tall_on\trandom\n";
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::ofstream resultFile("result/experiment_data.csv");
    resultFile << "n,all_off,all_on,random\n";
    for (int n = 10; n <= 200; n += 10) {
        Train trainOff;
        for (int i = 0; i < n; ++i) trainOff.addCar(false);
        trainOff.getLength();
        int opsOff = trainOff.getOpCount();
        Train trainOn;
        for (int i = 0; i < n; ++i) trainOn.addCar(true);
        trainOn.getLength();
        int opsOn = trainOn.getOpCount();
        Train trainRand;
        for (int i = 0; i < n; ++i) trainRand.addCar(std::rand() % 2);
        trainRand.getLength();
        int opsRand = trainRand.getOpCount();
        std::cout << n << "\t" << opsOff << "\t" << opsOn << "\t" << opsRand << "\n";
        resultFile << n << "," << opsOff << "," << opsOn << "," << opsRand << "\n";
    }
    resultFile.close();
    return 0;
}
