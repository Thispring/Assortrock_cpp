#include "Card.h"
#include "Dealer.h"

#include <iostream>
#include <ctime>

int Dealer::RandomNumber() {
	return rand()% NUMBER_LIMIT + 1;
}

int Dealer::RandomShape() {
	return rand()% SHAPE_LIMIT + 1;
}
