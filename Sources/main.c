#include "travel.h"
#include <stdio.h>

int main() {
    struct Travel travel[5] = {
        {"서울","아시아 한국","경복궁, 서울타워","비빔밥, 김치","사계절",{"도시","역사","음식"}, "매우 아름다움", 3},
        {"파리","유럽 프랑스","에펠탑, 루브르 박물관 ","뵈프 부르기뇽, 달팽이","온화함",{"관광","도시","문화"}, "예술의 도시", 4},
        {"런던","유럽 영국","타워 브리지, 버킹엄 궁전 ","피시 앤 칩스, 잉글리쉬 브랙퍼스트","사계절이지만 변덕스러움 우산챙기고 다녀야함",{"휴식","관광","자연"}, "", 3},
        {"캔버라","오스트레일리아 호주","국립도서관 ","캥고루 고기, 미트파이","온화함",{"관광","문화","날씨"}, "", 0},
        {"워싱턴 d.c","아메리카 미국","링컨 기념관, 백악관","스테이크, 버거","사계절",{"관광","건물","도시"}, "화려함", 4},
    };
    printf("검색어를 입력하세요: ");
    char searchQuery[50];
    scanf_s("%s", searchQuery, sizeof(searchQuery));

    int matchingIndices[5] = { 0 };
    int matchingCount = 0;

    searchTravel(searchQuery, travel, 5, matchingIndices, &matchingCount);

    if (matchingCount > 0) {
        printf("검색 결과로 나온 여행지입니다:\n");
        for (int i = 0; i < matchingCount; ++i) {
            printf("%d. ", i + 1);
            showTravel(&travel[matchingIndices[i]]);
        }

        int choice;
        int menuChoice = 0;
        do {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            printf("메뉴를 선택하세요:\n");
            printf("1. 여행지 선택\n");
            printf("2. 여행지 평점 및 코멘트 입력\n");

            if (scanf_s("%d", &menuChoice) != 1) {
                menuChoice = -1;
                printf("잘못된 선택입니다. 다시 선택해주세요.\n");
                continue;
            }

            switch (menuChoice) {
            case 1:
                printf("\n어떤 여행지를 선택하시겠습니까? (번호로 선택하시오): ");
                if (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
                    printf("잘못된 선택입니다.\n");
                    continue;
                }

                if (choice >= 1 && choice <= matchingCount) {
                    printf("선택하신 여행지:\n");
                    showTravel(&travel[matchingIndices[choice - 1]]);
                    printf("\n선택하신 여행지에서 숙소나 일정을 알아봐 드릴까요?\n");
                    printf("1. 네 연결해주세요\n");
                    printf("2. 아니요 연결해주지 마세요\n");
                    int planChoice;
                    if (scanf_s("%d", &planChoice) != 1) {
                        printf("잘못된 선택입니다.\n");
                        continue;
                    }
                    if (planChoice == 1) {
                        printf("사이트와 연결하는 중입니다...\n");
                    }
                    else if (planChoice == 2) {
                        printf("다른 여행지를 탐색해 보세요\n");
                    }
                }
                else {
                    printf("잘못된 선택입니다.\n");
                }
                break;
             

            case 2:
                printf("\n평점과 코멘트를 입력할 여행지를 선택하세요 (번호로 선택하시오): ");
                if (scanf_s("%d", &choice) != 1) {
                    printf("잘못된 선택입니다.\n");
                    continue;
                }

                if (choice >= 1 && choice <= matchingCount) {
                    printf("평점을 입력하세요 (0~5): ");
                    int newRating;
                    if (scanf_s("%d", &newRating) != 1) {
                        printf("잘못된 입력입니다.\n");
                        continue;
                    }

                    int totalRatings = travel[matchingIndices[choice - 1]].rating * travel[matchingIndices[choice - 1]].numReviews;
                    totalRatings += newRating;
                    travel[matchingIndices[choice - 1]].numReviews++;
                    travel[matchingIndices[choice - 1]].rating = totalRatings / travel[matchingIndices[choice - 1]].numReviews;

                    printf("평균 평점: %d\n", travel[matchingIndices[choice - 1]].rating);

                    printf("코멘트를 입력하세요: ");
                    if (scanf_s(" %[^\n]s", travel[matchingIndices[choice - 1]].comment, sizeof(travel[matchingIndices[choice - 1]].comment)) != 1) {
                        printf("잘못된 입력입니다.\n");
                        continue;
                    }

                    printf("입력이 완료되었습니다.\n");
                }
                else {
                    printf("잘못된 선택입니다.\n");
                }
                break;

            default:
                printf("잘못된 선택입니다. 다시 선택해주세요.\n");
                break;
            }
        } while (menuChoice < 1 || menuChoice > 2);
    }
    else {
        printf("해당하는 여행지가 없습니다.\n");
    }

    return 0;
}
