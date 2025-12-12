#include "Card.h"
#include "Player.h"

#include <iostream>

void Card::getCardNumber(int getCardNum) {
	std::cout << "getNumber is: " << getCardNum << std::endl;
	std::cout << "CardNumber is: " << NumberNames[getCardNum - 1] << std::endl;
}

void Card::getCardShape(int getShapeNum) {
	std::cout << "getShapeNumber is: " << getShapeNum << std::endl;
	std::cout << "CardNumber is: " << ShapeNames[getShapeNum - 1] << std::endl;
}

void Card::ShowHands(int hands[]) {
	// 카드는 shape값과 number값의 곱으로 이루어져 있어
	// 범위를 설정해 shape를 찾고, 어떤 숫자의 카드인지 출력
	// 출력은 Card.h에 선언한 문자 배열 사용

	for (int i = 0; i < HAND_LIMIT; i++)
	{
		// ShapeNames은 0부터 3까지 4개
		// NumberNames은 0부터 13까지 13개
		int cardType = hands[i];
		if (1 <= cardType && 13 >= cardType)
			std::cout << "hands[" << i << "] Card [" << ShapeNames[CLUB-1] << " " << NumberNames[cardType-1] << "]" << std::endl;
		else if (2 <= cardType && 26 >= cardType)
			std::cout << "hands[" << i << "] Card [" << ShapeNames[DIA-1] << " " << NumberNames[(cardType/DIA)-1] << "]" << std::endl;
		else if (3 <= cardType && 39 >= cardType)
			std::cout << "hands[" << i << "] Card [" << ShapeNames[HEART-1] << " " << NumberNames[(cardType/HEART)-1] << "]" << std::endl;
		else if (4 <= cardType && 52 >= cardType)
			std::cout << "hands[" << i << "] Card [" << ShapeNames[SPADE-1] << " " << NumberNames[(cardType/SPADE)-1] << "]" << std::endl;
		else
			std::cout << "Unknown Type" << std::endl;
	}
}

void Card::ShowCardInfo(int arrayNum, int selectHands[]) {
	// 카드는 shape값과 number값의 곱으로 이루어져 있어
	// 범위를 설정해 shape를 찾고, 어떤 숫자의 카드인지 출력
	// 출력은 Card.h에 선언한 문자 배열 사용

	// ShapeNames은 0부터 3까지 4개
	// NumberNames은 0부터 13까지 13개
	
	// 만약 arrayNum이 0이 아닌 값이 온다면
	int index = 0;

	if (arrayNum != 0)
		index = arrayNum - 1;
	else
		index = 0;

	int cardType = selectHands[index];

	if (1 <= cardType && 13 >= cardType)
		std::cout << "selectHands[" << index << "] Card [" << ShapeNames[CLUB - 1] << " " << NumberNames[cardType - 1] << "]" << std::endl;
	else if (2 <= cardType && 26 >= cardType)
		std::cout << "selectHands[" << index << "] Card [" << ShapeNames[DIA - 1] << " " << NumberNames[(cardType / DIA) - 1] << "]" << std::endl;
	else if (3 <= cardType && 39 >= cardType)
		std::cout << "selectHands[" << index << "] Card [" << ShapeNames[HEART - 1] << " " << NumberNames[(cardType / HEART) - 1] << "]" << std::endl;
	else if (4 <= cardType && 52 >= cardType)
		std::cout << "selectHands[" << index << "] Card [" << ShapeNames[SPADE - 1] << " " << NumberNames[(cardType / SPADE) - 1] << "]" << std::endl;
	else
		std::cout << "Unknown Type" << std::endl;	
}