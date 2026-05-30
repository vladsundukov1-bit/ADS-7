// Copyright 2021 NNTU-CS
#include "train.h"
#include <stdexcept>

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car *newCar = new Car{light, nullptr, nullptr};
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        newCar->next = first;
        newCar->prev = first->prev;
        first->prev->next = newCar;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;
    countOp = 0;
    bool initialLight = first->light;
    if (!initialLight) {
        first->light = true;
        Car *cur = first;
        do {
            cur = cur->next;
            ++countOp;
            cur->light = false;
        } while (cur != first);
        first->light = true;
        int length = 0;
        cur = first;
        do {
            cur = cur->next;
            ++countOp;
            ++length;
        } while (!cur->light);
        return length;
    } else {
        int k = 1;
        while (true) {
            Car *cur = first;
            for (int i = 0; i < k; ++i) {
                cur = cur->next;
                ++countOp;
                cur->light = false;
            }
            for (int i = 0; i < k; ++i) {
                cur = cur->prev;
                ++countOp;
            }
            if (!first->light) {
                break;
            }
            ++k;
        }
        first->light = true;
        return k;
    }
}

int Train::getOpCount() {
    return countOp;
}
