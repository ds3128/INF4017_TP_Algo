#include <iostream>
#include "fonctions.h"

#define MAX_BLANC 255
#define MIN_BLANC 128

Pixel::Pixel(int valPixel) {
    this->valPixel = valPixel;
}

Pixel::Pixel(int x, int y, int valPixel, int pgcb) {
    this->x = x;
    this->y = y;
    this->valPixel = valPixel;
    this->pgcb = pgcb;
}

void Pixel::setX(int x) {
    this->x = x;
}

int Pixel::getX() {
    return this->x;
}

void Pixel::setY(int y) {
    this->y = y;
}

int Pixel::getY() {
    return this->y;
}

void Pixel::setValPixel(int valPixel) {
    this->valPixel = valPixel;
}

int Pixel::getValPixel() {
    return this->valPixel;
}

void Pixel::setPGCB(int pgcb) {
    this->pgcb = pgcb;
}

int Pixel::getPGCB() {
    return this->pgcb;
}

int Pixel::couleur() {
    if(valPixel <= 255 && valPixel >= 70){
        valPixel = 255;
        return 0;
    }
    else{
        valPixel = 0;
        return 1;
    }

}
