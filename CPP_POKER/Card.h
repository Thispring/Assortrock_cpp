// Card의 역할은 숫자를 받아와서 어떤 포커카드인지 정보를 넘겨주고
// Player가 뽑은 5개의 포커카드를 통해 어떤 족보인지 정보를 넘겨주는 역할

// 카드 정보에 대한 헤더
// 어떤 카드인지는 숫자를 통해 구분하고
// 출력은 유니코드를 사용 (♠, ♥, ♦, ♣)
#pragma once
#define NUMBER_LIMIT 13
#define SHAPE_LIMIT 4

#define CLUB 1
#define DIA 2
#define HEART 3
#define SPADE 4


// TODO: 전처리기로 카드 숫자와 문양을 정의

class Card {
protected:
	// 카드 문양 출력용 데이터
	// ♦ 문자 비정상 출력 문제 있음
	// -> 컴퓨터 유니코드 설정
	const char* ShapeNames[4] = {
		"♣", "♦", "♥", "♠"
	};
	// 카드 이름 출력용 데이터
	const char* NumberNames[13] = {
		"    1", "    2", "    3", "    4", "    5", "    6", "    7", "    8", "    9", "   10",
		" JACK",
		"QUEEN",
		" KING"
	};

public:
	// Dealer에서 무작위 숫자를 받아, 카드를 설정하는 함수
	// set함수를 통해 얻어온 정보를 출력하는 함수
	void getCardNumber(int num);
	void getCardShape(int shape);

	// Player 손패의 값을 확인하여, 어떤 카드인지 판별하여, 출력하는 함수
	//void ShowCardInfo(int hands[]);

	// ShowCardInfo를 전체 패를 보여주는 버전과 인덱스를 받아 해당 카드한개의 정보를 보여주는 버전으로 나누어 구현

	void ShowHands(int hands[]);
	void ShowCardInfo(int arrayNum, int selectHands[]);
};