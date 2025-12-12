#pragma once

// 헤더파일의 역할

#define HAND_LIMIT 9
#define SELECT_CARD_LIMIT 5

#include "Dealer.h"
#include "Card.h"
#include <iostream>

class Player {
protected:
	int status;
public:
	int hands[HAND_LIMIT] = {};
	int selectHands[SELECT_CARD_LIMIT] = {};
	int arrayNumber = 0;
	
	// Dealer로 부터 랜덤한 값을 받아 카드를 얻는 함수
	void GetCard(int hands[]);

	// Player의 손패를 출력하는 함수 (배열 데이터의 정수 값 출력)
	void ShowHands(int hands[]);
	
	// Player가 키보드로 카드를 선택하는 함수
	// int 타입으로 hands의 인덱스에 접근
	int SelectCard(int index, int action);

	// Player가 손패에서 카드를 고르는 함수
	// WASD를 입력받아 컨트롤
	// 배열을 매개변수로 받아, 배열 끼리 값을 옮김
	void PickCardFromHand(int index, int hands[], int selectHands[]);
	//*** 게임에서의 키를 눌러 다른 화면을 출력하게 하려면
	//*** 무한반복안에 출력과 조건을 걸어두고, 특정 조건을 만나면
	//*** 출력의 내용을 변경하는 방식으로 동작함
};