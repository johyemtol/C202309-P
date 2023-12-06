#include "travel.h"
#include <string.h>

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
    return matchCount;
}

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