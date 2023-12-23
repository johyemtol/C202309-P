#include "travel.h"
#include <string.h>


//����ڿ��� �����ִ� �Լ�
void showTravel(const struct Travel* travel) {
    printf("������ \n");
    printf("�̸�: %s\n", travel->name);
    printf("��ġ: %s\n", travel->location);
    printf("�ֿ���: %s\n", travel->attraction);
    printf("����: %s\n", travel->food);
    printf("����: %s\n", travel->climate);
    printf("����: ");
    for (int i = 0; i < 3; ++i) {
        printf("%s", travel->type[i]);
        if (i < 3 - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

//�˻��Ҷ� �´��� üũ�ϱ�
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


//������ ã�� �κ� �Լ�
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

//��� ���� ����ϴ� �Լ�
double calculateAverageRating(const struct Travel* travel) {
    if (travel->numReviews == 0) {
        return 0.0;
    }
    return (double)travel->rating / travel->numReviews;
}


//������� �����ϴ� �Լ�
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

//���������� �����Լ�
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

//�� ���� �Լ� 
void performSearch(struct Travel* travel, int travelCount) {
    printf("�˻�� �Է��ϼ���(���ó� ���� ��� �̸��� �Է��Ͻÿ�): ");
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

        printf("\n��� ���� �������� ���ĵ� �������Դϴ�:\n");
        for (int i = 0; i < searchResultCount; ++i) {
            printf("%d. ", i + 1);
            showTravel(&travel[searchResultIndices[i]]);
        }
        // ���� �޴�
        int choice;
        printf("\n� �۾��� �����Ͻðڽ��ϱ�?\n");
        printf("1. ������ ����\n");
        printf("2. ���� �� �ڸ�Ʈ �Է�\n");
        printf("3. �ٽ� �˻�\n");
        printf("4. ����\n");
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
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �����Դϴ�.\n");
            break;
        }
    }
    else {
        printf("�ش��ϴ� �������� �����ϴ�.\n");
    }
}

//������ ������ ���������� ���� ����ϴ� �Լ�
void selectTravel(struct Travel* travel, int travelCount, int matchingIndices[], int matchingCount) {
    int choice;
    printf("\n� �������� �����Ͻðڽ��ϱ�? (��ȣ�� �����Ͻÿ�): ");
    if (scanf_s("%d", &choice) != 1 || (choice < 1 || choice > matchingCount)) {
        printf("�߸��� �����Դϴ�.\n");
        return;
    }

    printf("�����Ͻ� ������:\n");
    showTravel(&travel[matchingIndices[choice - 1]]);
    printf("\n�����Ͻ� ���������� ���ҳ� ������ �˾ƺ� �帱���?\n");
    printf("1. �� �������ּ���\n");
    printf("2. �ƴϿ� ���������� ������\n");

    int planChoice;
    if (scanf_s("%d", &planChoice) != 1) {
        printf("�߸��� �����Դϴ�.\n");
        return;
    }

    if (planChoice == 1) {
        printf("����Ʈ�� �����ϴ� ���Դϴ�...\n");
    }
    else if (planChoice == 2) {
        printf("�ٸ� �������� Ž���� ������\n");
    }
}


//��հ� �ڸ�Ʈ �Է��ϴ� �Լ�
void inputRatingAndComment(struct Travel* travel, int travelCount, int matchingIndices[], int matchingCount) {
    int choice;
    printf("\n������ �ڸ�Ʈ�� �Է��� �������� �����ϼ��� (��ȣ�� �����Ͻÿ�): ");
    if (scanf_s("%d", &choice) != 1 || (choice < 1 || choice > matchingCount)) {
        printf("�߸��� �����Դϴ�.\n");
        return;
    }

    printf("������ �Է��ϼ��� (0~5): ");
    int newRating;
    if (scanf_s("%d", &newRating) != 1 || (newRating < 0 || newRating > 5)) {
        printf("�߸��� �Է��Դϴ�.\n");
        return;
    }

    int totalRatings = travel[matchingIndices[choice - 1]].rating * travel[matchingIndices[choice - 1]].numReviews;
    int numReviews = travel[matchingIndices[choice - 1]].numReviews;

    totalRatings += newRating;
    numReviews++;
    double averageRating = (double)totalRatings / numReviews;

    travel[matchingIndices[choice - 1]].numReviews = numReviews;
    travel[matchingIndices[choice - 1]].rating = averageRating;

    printf("�ڸ�Ʈ�� �Է��ϼ���: ");
    if (scanf_s(" %[^\n]s", travel[matchingIndices[choice - 1]].comment, sizeof(travel[matchingIndices[choice - 1]].comment)) != 1) {
        printf("�߸��� �Է��Դϴ�.\n");
        return;
    }

    printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
}

