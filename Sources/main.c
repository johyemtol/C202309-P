#include<stdio.h>

int main() {
	printf("어떤 여행지를 추천해줄까요?(번호로 선택하시오)");
	//번호 메겨진 여행지들 나열
	int choice;
	scanf_s("%d", &choice);
	if (choice >= 1) {
		printf("당신이 선택한 여행지는 ~~입니다.");
		//이어서 관광지와 추천 말하기
	}
	else {
		printf("잘못된 선택입니다.");
	}
}