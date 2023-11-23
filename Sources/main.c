#include "travel.h"

int main() {
	struct Travel travel[5] = {
		{"서울a","아시아 한국","경복궁, ","비빔밥, 김치","사계절","휴식"},
		{"bs울","아시아 한국","경복궁, ","비빔밥, 김치","사계절","관광"},
		{"ce울","아시아 한국","경복궁, ","비빔밥, 김치","사계절","휴식"},
		{"df울","아시아 한국","경복궁, ","비빔밥, 김치","사계절","관광"},
		{"ea울","아시아 한국","경복궁, ","비빔밥, 김치","사계절","휴식"},

	};

	printf("취향을 입력하세요?(휴식, 관광): ");
	char userType[50];
	scanf_s("%s", userType, sizeof(userType));

	int recommendCount = 0;
	for (int i = 0; i < 5; ++i) {
		if (strcmp(travel[i].type, userType) == 0) {
			recommendCount++;
		}
	}

    if (recommendCount > 0) {
        printf("추천하는 여행지입니다:\n");
        for (int i = 0; i < 5; ++i) {
            if (strcmp(travel[i].type, userType) == 0) {
                printf("%d. ", i + 1);
                showTravel(&travel[i]);
            }
        }

        printf("어떤 여행지를 선택하시겠습니까? (번호로 선택하시오): ");
        int choice;
        scanf_s("%d", &choice);

        if (choice >= 1 && choice <= recommendCount) {
            printf("선택하신 여행지:\n");
            showTravel(&travel[choice - 1]);
            // 이어서 관광지와 추천 말하기
        }
        else {
            printf("잘못된 선택입니다.");
        }
    }
    else {
        printf("해당하는 여행지가 없습니다.");
    }

	
}