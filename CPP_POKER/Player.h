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
	// Dealer로 부터 랜덤한 값을 받아 카드를 얻는 함수
	void GetCard(int hands[]);
	// Player의 손패를 출력하는 함수 (배열 데이터의 정수 값 출력)
	void ShowHands(int hands[]);
	// Player가 손패에서 카드를 고르는 함수, 주소값을 반환
	// 방향키를 입력받아 컨트롤
	// 게임에서의 키를 눌러 다른 화면을 출력하게 하려면
	// 무한반복안에 출력과 조건을 걸어두고, 특정 조건을 만나면
	// 출력의 내용을 변경하는 방식으로 동작함
	int& PickCardFromHand(int hands[]);
};