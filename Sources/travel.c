#include "travel.h"
#include <string.h>


//사용자에게 보여주는 함수
void showTravel(const struct Travel* travel) {
    printf("여행지 \n");
    printf("이름: %s\n", travel->name);
    printf("위치: %s\n", travel->location);
    printf("주요명소: %s\n", travel->attraction);
    printf("음식: %s\n", travel->food);
    printf("기후: %s\n", travel->climate);
    printf("취향: ");
    for (int i = 0; i < 3; ++i) {
        printf("%s", travel->type[i]);
        if (i < 3 - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

//검색할때 맞는지 체크하기
int checkMatch(const char(*userPreferences)[50], const struct Travel* travel) {
    int matchCount = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (strcmp(travel->type[i], userPreferences[j]) == 0) {
                matchCount++;
                break;   
            }
        }
    }

    return (matchCount == 3);
}


//여행지 찾기 부분 함수
void searchTravel(const char* searchQuery, struct Travel* travelList, int listSize, int matchingIndices[], int* matchingCount) {
    *matchingCount = 0;
    for (int i = 0; i < listSize; ++i) {
        if (strstr(travelList[i].name, searchQuery) != NULL ||
            strstr(travelList[i].location, searchQuery) != NULL ||
            checkMatch(&searchQuery, &travelList[i]) > 0) {
            matchingIndices[*matchingCount] = i;
            (*matchingCount)++;
        }
    }
}

//평균 평점 계산하는 함수
double calculateAverageRating(const struct Travel* travel) {
    if (travel->numReviews == 0) {
        return 0.0;
    }
    return (double)travel->rating / travel->numReviews;
}


//평균평점 정렬하는 함수
void sortAverageRating(struct Travel* travelList, int listSize) {
    for (int i = 0; i < listSize - 1; ++i) {
        for (int j = i + 1; j < listSize; ++j) {
            double avgRatingI = calculateAverageRating(&travelList[i]);
            double avgRatingJ = calculateAverageRating(&travelList[j]);

            if (avgRatingI < avgRatingJ) {
                struct Travel temp = travelList[i];
                travelList[i] = travelList[j];
                travelList[j] = temp;
            }
        }
    }
}

//여행지평점 정렬함수
void sortTravelRating(struct Travel* travelList, int listSize) {
    for (int i = 0; i < listSize - 1; ++i) {
        for (int j = i + 1; j < listSize; ++j) {
            double avgRatingI = calculateAverageRating(&travelList[i]);
            double avgRatingJ = calculateAverageRating(&travelList[j]);

            if (avgRatingI < avgRatingJ) {
                struct Travel temp = travelList[i];
                travelList[i] = travelList[j];
                travelList[j] = temp;
            }
        }
    }
}

//주 실행 함수 
void performSearch(struct Travel* travel, int travelCount) {
    printf("검색어를 입력하세요(도시나 나라 대륙 이름을 입력하시오): ");
    char searchQuery[50];
    scanf_s("%s", searchQuery, sizeof(searchQuery));

    int matchingIndices[5] = { 0 };
    int matchingCount = 0;
    searchTravel(searchQuery, travel, travelCount, matchingIndices, &matchingCount);


    if (matchingCount > 0) {
        int matchingIndeices[5] = { 0 };
        int searchResultIndices[5] = { 0 };
        int searchResultCount = 0;
        for (int i = 0; i < matchingCount; ++i) {
            if (strstr(travel[matchingIndices[i]].name, searchQuery) != NULL ||
                strstr(travel[matchingIndices[i]].location, searchQuery) != NULL ||
                checkMatch(&searchQuery, &travel[matchingIndices[i]]) > 0) {
                searchResultIndices[searchResultCount] = matchingIndices[i];
                searchResultCount++;
            }
        }

        sortAverageRating(travel, searchResultCount);

        printf("\n평균 평점 기준으로 정렬된 여행지입니다:\n");
        for (int i = 0; i < searchResultCount; ++i) {
            printf("%d. ", i + 1);
            showTravel(&travel[searchResultIndices[i]]);
        }
        // 선택 메뉴
        int choice;
        printf("\n어떤 작업을 수행하시겠습니까?\n");
        printf("1. 여행지 선택\n");
        printf("2. 평점 및 코멘트 입력\n");
        printf("3. 다시 검색\n");
        printf("4. 종료\n");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            selectTravel(travel, travelCount, matchingIndices, matchingCount);
            break;
        case 2:
            inputRatingAndComment(travel, travelCount, matchingIndices, matchingCount);
            break;
        case 3:
            performSearch(travel, travelCount);  
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 선택입니다.\n");
            break;
        }
    }
    else {
        printf("해당하는 여행지가 없습니다.\n");
    }
}

//여행지 선택후 연결해줄지 말지 출력하는 함수
void selectTravel(struct Travel* travel, int travelCount, int matchingIndices[], int matchingCount) {
    int choice;
    printf("\n어떤 여행지를 선택하시겠습니까? (번호로 선택하시오): ");
    if (scanf_s("%d", &choice) != 1 || (choice < 1 || choice > matchingCount)) {
        printf("잘못된 선택입니다.\n");
        return;
    }

    printf("선택하신 여행지:\n");
    showTravel(&travel[matchingIndices[choice - 1]]);
    printf("\n선택하신 여행지에서 숙소나 일정을 알아봐 드릴까요?\n");
    printf("1. 네 연결해주세요\n");
    printf("2. 아니요 연결해주지 마세요\n");

    int planChoice;
    if (scanf_s("%d", &planChoice) != 1) {
        printf("잘못된 선택입니다.\n");
        return;
    }

    if (planChoice == 1) {
        printf("사이트와 연결하는 중입니다...\n");
    }
    else if (planChoice == 2) {
        printf("다른 여행지를 탐색해 보세요\n");
    }
}


//평균과 코멘트 입력하는 함수
void inputRatingAndComment(struct Travel* travel, int travelCount, int matchingIndices[], int matchingCount) {
    int choice;
    printf("\n평점과 코멘트를 입력할 여행지를 선택하세요 (번호로 선택하시오): ");
    if (scanf_s("%d", &choice) != 1 || (choice < 1 || choice > matchingCount)) {
        printf("잘못된 선택입니다.\n");
        return;
    }

    printf("평점을 입력하세요 (0~5): ");
    int newRating;
    if (scanf_s("%d", &newRating) != 1 || (newRating < 0 || newRating > 5)) {
        printf("잘못된 입력입니다.\n");
        return;
    }

    int totalRatings = travel[matchingIndices[choice - 1]].rating * travel[matchingIndices[choice - 1]].numReviews;
    int numReviews = travel[matchingIndices[choice - 1]].numReviews;

    totalRatings += newRating;
    numReviews++;
    double averageRating = (double)totalRatings / numReviews;

    travel[matchingIndices[choice - 1]].numReviews = numReviews;
    travel[matchingIndices[choice - 1]].rating = averageRating;

    printf("코멘트를 입력하세요: ");
    if (scanf_s(" %[^\n]s", travel[matchingIndices[choice - 1]].comment, sizeof(travel[matchingIndices[choice - 1]].comment)) != 1) {
        printf("잘못된 입력입니다.\n");
        return;
    }

    printf("입력이 완료되었습니다.\n");
}

