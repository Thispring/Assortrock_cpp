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
