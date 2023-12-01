#include "travel.h"

int main() {
    //무작위로 구성, 나중에 여행지 추가하는 코드도 추가할 고민중
    struct Travel travel[5] = {
        {"서울a","아시아 한국","경복궁, ","비빔밥, 김치","사계절",{"휴식","자연","음식"}, "", 0},
        {"bs울","아시아 한국","경복궁, ","비빔밥, 김치","사계절",{"관광","도시","문화"}, "", 0},
        {"ce울","아시아 한국","경복궁, ","비빔밥, 김치","사계절",{"휴식","음식","자연"}, "", 0},
        {"df울","아시아 한국","경복궁, ","비빔밥, 김치","사계절",{"관광","문화","날씨"}, "", 0},
        {"ea울","아시아 한국","경복궁, ","비빔밥, 김치","사계절",{"휴식","건물","휴식"}, "", 0},
    };

    printf("검색어를 입력하세요:(나라, 이름, 대륙) ");
    char searchQuery[50];
    scanf_s("%s", searchQuery, sizeof(searchQuery));

    int matchingIndices[5] = { 0 };
    int matchingCount = 0;

    searchTravel(searchQuery, travel, 5, matchingIndices, &matchingCount);

    //검색하였을때 검색 결과에 알맞은 여행지가 있더라면
    if (matchingCount > 0) {
        printf("검색 결과로 나온 여행지입니다:\n");
        for (int i = 0; i < matchingCount; ++i) {
            printf("%d. ", i + 1);
            showTravel(&travel[matchingIndices[i]]);
        }

        //선택된 여행지 중 여행지 선택 혹은 평점 코멘트 입력할 수 있게 설정
        printf("메뉴를 선택하세요:\n");
        printf("1. 여행지 선택\n");
        printf("2. 여행지 평점 및 코멘트 입력\n");

        int menuChoice;
        scanf_s("%d", &menuChoice);

        //여행지 선택
        if (menuChoice == 1) {
            printf("어떤 여행지를 선택하시겠습니까? (번호로 선택하시오): ");
            int choice;
            scanf_s("%d", &choice);

            if (choice >= 1 && choice <= matchingCount) {
                printf("선택하신 여행지:\n");
                showTravel(&travel[matchingIndices[choice - 1]]);
                // 이어서 관광지와 추천 말하기
            }
            else {
                printf("잘못된 선택입니다.");
            }
        }
        //여행지 평점 및 코멘트 입력
        else if (menuChoice == 2) {
            printf("평점과 코멘트를 입력할 여행지를 선택하세요 (번호로 선택하시오): ");
            int choice;
            scanf_s("%d", &choice);

            //평점과 코멘트 입력하는 코드
            if (choice >= 1 && choice <= matchingCount) {
                printf("평점을 입력하세요 (0~5): ");
                scanf_s("%d", &travel[matchingIndices[choice - 1]].rating);

                printf("코멘트를 입력하세요: ");
                scanf_s(" %[^\n]s", travel[matchingIndices[choice - 1]].comment, sizeof(travel[matchingIndices[choice - 1]].comment));

                printf("입력이 완료되었습니다.\n");
            }
            else {
                printf("잘못된 선택입니다.");
            }
        }
        else {
            printf("잘못된 선택입니다.");
        }
    }
    //검색했을때 알맞은 검색어가 없을때
    else {
        printf("해당하는 여행지가 없습니다.");
    }

    return 0;
}
