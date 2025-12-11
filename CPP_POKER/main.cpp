// CPP 포커 게임

#include "Player.h"
#include "Dealer.h"
#include "Card.h"

#include <iostream>

// windows API에서 터미널에 있는 문자를 읽어오는 기능
// windows.h 에서 ReadConsoleOutput함수를 사용
#include <windows.h>
void getch(void)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// 읽어온 데이터를 저장할 버퍼
	CHAR_INFO buffer[10];
	// 읽어올 영역의 크기
	COORD bufferSize = { 10, 1 };
	// 읽기 시작할 좌표 (가장 왼쪽 위)
	COORD bufferCoord = { 0, 0 };
	// 읽을 사각형 영역
	SMALL_RECT readRegion = { 0, 0, 9, 0 };

	ReadConsoleOutput(hConsole, buffer, bufferSize, bufferCoord, &readRegion);

	// 읽어온 내용을 출력합니다.
	std::wcout << buffer[0].Char.UnicodeChar;

	if (buffer[0].Char.UnicodeChar == 'h')
	{
		std::cout << "Hello World" << std::endl;
	}
}

int main()
{
	// dealer.Random 함수들에 srand(time(NULL)); 실행 시
	// 컴퓨터의 빠른 연산속도에 따라 함수들이 호출되어, time 시드값 간의 차이가
	// 유의미하게 나지 않아, 이를 컴퓨터가 인식하지 못해 같은 값이 출력되는 문제발생
	// -> 해결을 위해 main함수에서 srand를 한번만 호출
	srand(time(NULL));

	Player player;
	Dealer dealer;
	Card card;

	player.GetCard(player.hands);
	player.ShowHands(player.hands);

	card.ShowCardInfo(player.hands);

	while (1)
	{
		getch();
	}

	return 0;
}



//BOOL ReadConsoleOutputCharacter(
//	[in]  HANDLE  hConsoleOutput,      // 콘솔 화면 버퍼 핸들
//	[out] LPTSTR  lpCharacter,         // 읽어온 문자를 저장할 버퍼
//	[in]  DWORD   nLength,             // 읽어올 문자의 개수
//	[in]  COORD   dwReadCoord,         // 읽기 시작할 좌표 (X, Y)
//	[out] LPDWORD lpNumberOfCharsRead  // 실제로 읽어온 문자의 개수를 저장할 변수의 포인터
//);