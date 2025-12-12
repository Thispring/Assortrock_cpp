// CPP 포커 게임

#include "Player.h"
#include "Dealer.h"
#include "Card.h"

#include <iostream>
#include <vector>

// windows API에서 입력버퍼 있는 문자를 읽어오는 기능
// windows.h에 있는 함수 이용하여 getstdin에 구현
// -> 작동방식 확인 필요
#include <windows.h>

int getstdin()
{
	// Unicode WASD
	// W (U+0057)
	// A (U+0041)
	// S (U+0053)
	// D (U+0044)
	// 소문자는 대문자+32

	// Unicode는 16진수로 이루어져있고, 정수로 반환 시
	// 16 -> 10진수 반환 과정이 있음을 유의

	// 입력이 없었을 때 %을 반환하는 상황
	// cmd.exe의 "echo %errorlevel%"
	// cmd.exe에는 errorlevel 이라는 특별환경변수가 존재
	
	// 1. 표준 입력 핸들 가져오기
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	if (hInput == INVALID_HANDLE_VALUE) {
		std::cerr << "표준 입력 핸들을 가져올 수 없습니다. 오류 코드: " << GetLastError() << std::endl;
		return 1;
	}

	// 2. 콘솔 입력 모드 설정 (선택 사항, 기본 모드로도 동작)
	//    라인 입력, 에코 입력 비활성화 등을 하려면 SetConsoleMode 사용
	DWORD originalMode;
	GetConsoleMode(hInput, &originalMode);
	// 예: SetConsoleMode(hInput, originalMode & ~ENABLE_LINE_INPUT & ~ENABLE_ECHO_INPUT);

	//std::cout << "CMD에 아무 내용이나 입력해보세요. 프로그램이 10초 후에 버퍼를 읽습니다." << std::endl;
	//std::cout << "(Enter를 누르지 않아도 됩니다.)" << std::endl;

	// 사용자가 입력할 시간을 줌
	Sleep(10);

	// 3. 입력 버퍼에 쌓인 이벤트 개수 확인

	// DWORD는 long 정수타입 변수, 이벤트 개수 확인
	DWORD numEvents = 0;
	if (!GetNumberOfConsoleInputEvents(hInput, &numEvents)) {
		std::cerr << "입력 이벤트 개수를 가져올 수 없습니다. 오류 코드: " << GetLastError() << std::endl;
		return 1;
	}

	/*if (numEvents == 0) {
		std::cout << "\n입력 버퍼가 비어있습니다." << std::endl;
		return 0;
	}*/

	//std::cout << "\n--- 입력 버퍼 내용 읽기 시작 ---" << std::endl;
	//std::cout << "버퍼에 " << numEvents << "개의 이벤트가 있습니다." << std::endl;

	// 4. 입력 이벤트를 저장할 버퍼 생성 및 읽기
	std::vector<INPUT_RECORD> buffer(numEvents);
	DWORD numEventsRead = 0;
	if (!ReadConsoleInput(hInput, buffer.data(), numEvents, &numEventsRead)) {
		std::cerr << "콘솔 입력을 읽을 수 없습니다. 오류 코드: " << GetLastError() << std::endl;
		return 1;
	}

	std::string result = "";
	// 5. 읽어온 이벤트를 순회하며 키보드 입력 추출
	for (DWORD i = 0; i < numEventsRead; ++i) {
		// 이벤트 타입이 KEY_EVENT인 경우
		if (buffer[i].EventType == KEY_EVENT) {
			KEY_EVENT_RECORD& keyEvent = buffer[i].Event.KeyEvent;

			// 키가 '눌렸을' 때만 처리 (뗐을 때는 무시)
			if (keyEvent.bKeyDown) {
				char ch = keyEvent.uChar.AsciiChar;
				return ch;

				// 출력 가능한 문자인 경우에만 결과 문자열에 추가
				if (isprint(static_cast<unsigned char>(ch))) {
					result += ch;
				}
			}
		}
	}
}

// 25/12/12: 메모리 누수 발생 확인 필요
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
	card.ShowHands(player.hands);

	while (1)
	{
		char input = 0;

		// 입력버퍼에서 문자를 읽어오는 함수
		input = getstdin();
		// 반환한 문자 내용을 기반으로 특정 동작을 수행하도록 조건문을 작성합니다.

		static int index = 0;

		switch (input)
		{
		// input에서 받아온 문자의 숫자를 case로 사용합니다.
		// 방향키 입력 숫자를 확인하기
		// or WASD 사용

		// case 87 && 119: 와 같이 표현하면
		// 컴파일러는 && 논리연산을 실행 -> 양쪽의 값이 모두 참이면 참 반환
		// 숫자를 논리값으로 해석하여, 0이아닌 모든 숫자는 참으로 계산
		// 고로 switch에서 2개이상의 숫자에 같은 조건을 넣고싶으면, 중첩하여 표현하기


		// W, w
		// W키는 현재 index 값에 맞는 카드를 hands에서 가져와 selectHands에 순차적으로 배치
		// 선입후출 방식으로 카드를 선택하고 제외 시키기
		case 87:
		case 119:
			std::cout << "Input: W" << std::endl;
			player.PickCardFromHand(index, player.hands, player.selectHands);
			card.ShowCardInfo(player.arrayNumber, player.selectHands);
			break;
		// A, a
		// A키는 인덱스를 -1연산으로 인덱스 번호를 변경
		case 65:
		case 97:
			std::cout << "Input: A" << std::endl;
			index += player.SelectCard(index, -1);
			std::cout << "Current index: " << index << std::endl;
			break;
		// S, s
		// S키는 선택모드를 변경
		// ex) 호출이 없었다면 hands에서 카드를 W로 선택할 수 있게하고, 호출이 있었다면 hands가 아닌 selectHands에서 카드를 W로 다시 가져오는 기능
		case 83:
		case 115:
			std::cout << "Input: S" << std::endl;
			break;
		// D, d
		// D키는 인덱스를 +1연산으로 인덱스 번호를 변경
		case 68:
		case 100:
			std::cout << "Input: D" << std::endl;
			index += player.SelectCard(index, 1);
			std::cout << "index: " << index << std::endl;
			break;

		default:
			break;
		}
	}

	return 0;
}
