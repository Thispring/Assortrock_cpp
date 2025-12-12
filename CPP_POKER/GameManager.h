#pragma once

// 전체 게임의 관리를 담당합니다.
// 관리할 부분을 클래스로 만들어서 사용합니다.

// 클래스를 어떻게 나누는게 좋을지 생각해보기
// 헤더파일 단위로 
// ex) GameManager에 역할이 다른 클래스 5개가 필요한 경우 .h도 5개 생성
// 하나의 클래스 안에 생성
// ex) GameManager에 역할이 다른 클래스 5개가 필요한 경우 GameManager에 5개의 클래스 생성

// 개별 파일로 클래스를 분리하는게 좋다고함
class GameManager {
	PrintManager print;
};

class PrintManager {
	// 터미널에 출력을 담당하는 클래스
	// main에서 while(1)문에 함수를 배치하여
	// 매 프레임 프린트하게 구현
public:
	void PrintBorad();
};

