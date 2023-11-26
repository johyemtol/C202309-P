#include "travel.h"

int main() {
	struct Travel travel[5] = {
        {"서울a","아시아 한국","경복궁, ","비빔밥, 김치","사계절",{"휴식","자연","음식"}},
        {"bs울","아시아 한국","경복궁, ","비빔밥, 김치","사계절",{"관광","도시","문화"}},
        {"ce울","아시아 한국","경복궁, ","비빔밥, 김치","사계절",{"휴식","음식","자연"}},
        {"df울","아시아 한국","경복궁, ","비빔밥, 김치","사계절",{"관광","문화","날씨"}},
        {"ea울","아시아 한국","경복궁, ","비빔밥, 김치","사계절",{"휴식","건물","휴식"}},

	};


    printf("취향을 입력하세요?(휴식, 관광): ");
    char userPreferences[50];
    scanf_s("%s", userPreferences, sizeof(userPreferences));

    int recommendCount = 0;
    int matchingIndices[5] = { 0 }; // 배열 크기는 여행지의 수와 같게 설정

    for (int i = 0; i < 5; ++i) {
        int matchCount = checkMatch(&userPreferences, &travel[i]);
        if (matchCount >= 1) {
            matchingIndices[recommendCount] = i;
            recommendCount++;
        }
    }

    if (recommendCount > 0) {
        printf("추천하는 여행지입니다:\n");
        for (int i = 0; i < recommendCount; ++i) {
            printf("%d. ", i + 1);
            showTravel(&travel[matchingIndices[i]]);
        }

        printf("어떤 여행지를 선택하시겠습니까? (번호로 선택하시오): ");
        int choice;
        scanf_s("%d", &choice);

        if (choice >= 1 && choice <= recommendCount) {
            printf("선택하신 여행지:\n");
            showTravel(&travel[matchingIndices[choice - 1]]);
            // 이어서 관광지와 추천 말하기
        }
        else {
            printf("잘못된 선택입니다.");
        }
    }
    else {
        printf("해당하는 여행지가 없습니다.");
    }

    return 0;
}