// 소스 파일의 역할

#include "Player.h"
#include "Dealer.h"

#include <iostream>

Player player;
Dealer dealer;


void Player::GetCard(int hands[]) {
	// TODO: 중복되는 카드를 제외하고 받는 기능 구현
	/*for (int i = 0; i < HAND_LIMIT; i++)
	{
		hands[i] = dealer.RandomNumber() * dealer.RandomShape();
	}*/

	bool isDup = false;
	int count = 0;
	while (count != HAND_LIMIT)
	{
		//int tempHands[HAND_LIMIT] = { };
		for (int i = 0; i < HAND_LIMIT; i++)
		{
			hands[i] = dealer.RandomNumber() * dealer.RandomShape();
			//tempHands[i] = hands[i];
			
			// i가 0이 아닌 두번째 부터검사
			if (i != 0)
			{
				for (int j = 0; j < HAND_LIMIT; j++)
				{
					// i와 j의 숫자가 같을때와 값이 0일때는 제외
					if ( i != j && hands[i] != 0 && hands[i] == hands[j])
					{
						isDup = true;
						break;
					}
				}
			}

			// 만약 중복으로 인해 isDup가 true라면 다시 뽑기
			if (isDup)
			{
				isDup = false;
				i--;
				continue;
			}

			count++;
		}
	}
}

void Player::ShowHands(int hands[]) {
	for (int i = 0; i < HAND_LIMIT; i++)
		std::cout << "hands[" << i << "]: " << hands[i] << std::endl;
}

// W, A 키 입력을 받았을 때, 조건에 맞게 인덱스 값을 변경하고 인덱스를 반환하는 함수
int Player::SelectCard(int index, int action) {
	// hnads[HAND_LIMIT] 범위 내에서만 움직여야함
	// 0~8

	// index 매개변수를 추가하고, 만약 index-action의 결과가 음수라면
	// 8로 초기화
	bool isNegative = false;

	if (action == -1)
		isNegative = true;
	else
		isNegative = false;

	// index가 0일때 -1를 만났을 때, 
	// index가 8일때 +1을 만났을 때 예외처리
	switch (index)
	{
	case 0: 
		if (isNegative)		// 현재 index값이 0인데 -1이 들어온 경우
			return 8;		// 8을 반환하여 -=연산으로 index를 0으로 만들기
		else
			return action;
		break;
	case 8:
		if (!isNegative)	// 현재 index값이 8인데 +1이 들어온 경우
			return -8;		// -8을 반환하여 +=연산으로 index를 0으로 만들기
		else
			return action;
		break;
	case 9:
		if (index >= 9)
		{
			std::cout << "Out of Range" << std::endl;
			exit(1);
		}
		break;
	default:
			return action;
		break;
	}
}

void Player::PickCardFromHand(int index, int hands[], int selectHands[]) {
	// 현재 index번호를 받아 현재 뽑은 카드가 hands[index]에 있는 값을
	// selectHands의 첫번째 자리부터 정렬
	// 선택한 hands[index]값을 0으로 변경
	// selectHands[] 범위: 0 ~ 4
	// arrayNumber는 공유되게 설정

	// 이미 선택된 hands[index]일 때
	if (hands[index] == 0)
	{
		std::cout << "Already selected card from hands!" << std::endl;
		return;
	}


	// selectHands 인덱스 범위를 벗어났을 때
	if (arrayNumber == SELECT_CARD_LIMIT)
	{
		arrayNumber = 0;
		std::cout << "Is SELECT CARD LIMIT!" << std::endl;
		return;
	}

	selectHands[arrayNumber] = hands[index];
	hands[index] = 0;
	arrayNumber++;
}