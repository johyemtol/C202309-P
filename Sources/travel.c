#include "travel.h"

void showTravel(const struct Travel* travel) {
	printf("여행지: \n");
	printf("이름: %s\n", travel->name);
	printf("위치: %s\n", travel->location);
	printf("주요명소: %s\n", travel->attraction);
	printf("음식: %s\n", travel->food);
	printf("기후: %s\n", travel->climate);
}