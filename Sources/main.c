#include "travel.h"
#include <stdio.h>

int main() {
    struct Travel travel[5] = {
        {"����","�ƽþ� �ѱ�","�溹��, ����Ÿ��","�����, ��ġ","�����",{"����","����","����"}, "�ſ� �Ƹ��ٿ�", 3},
        {"�ĸ�","���� ������","����ž, ��긣 �ڹ��� ","���� �θ��⴨, ������","��ȭ��",{"����","����","��ȭ"}, "������ ����", 4},
        {"����","���� ����","Ÿ�� �긮��, ��ŷ�� ���� ","�ǽ� �� Ĩ��, �ױ۸��� �귢�۽�Ʈ","����������� ���������� ���ì��� �ٳ����",{"�޽�","����","�ڿ�"}, "", 3},
        {"ĵ����","����Ʈ���ϸ��� ȣ��","���������� ","Ļ��� ���, ��Ʈ����","��ȭ��",{"����","��ȭ","����"}, "", 0},
        {"������ d.c","�Ƹ޸�ī �̱�","���� ����, ��ǰ�","������ũ, ����","�����",{"����","�ǹ�","����"}, "ȭ����", 4},
    };
    printf("�˻�� �Է��ϼ���: ");
    char searchQuery[50];
    scanf_s("%s", searchQuery, sizeof(searchQuery));

    int matchingIndices[5] = { 0 };
    int matchingCount = 0;

    searchTravel(searchQuery, travel, 5, matchingIndices, &matchingCount);

    if (matchingCount > 0) {
        printf("�˻� ����� ���� �������Դϴ�:\n");
        for (int i = 0; i < matchingCount; ++i) {
            printf("%d. ", i + 1);
            showTravel(&travel[matchingIndices[i]]);
        }

        int choice;
        int menuChoice = 0;
        do {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            printf("�޴��� �����ϼ���:\n");
            printf("1. ������ ����\n");
            printf("2. ������ ���� �� �ڸ�Ʈ �Է�\n");

            if (scanf_s("%d", &menuChoice) != 1) {
                menuChoice = -1;
                printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
                continue;
            }

            switch (menuChoice) {
            case 1:
                printf("\n� �������� �����Ͻðڽ��ϱ�? (��ȣ�� �����Ͻÿ�): ");
                if (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
                    printf("�߸��� �����Դϴ�.\n");
                    continue;
                }

                if (choice >= 1 && choice <= matchingCount) {
                    printf("�����Ͻ� ������:\n");
                    showTravel(&travel[matchingIndices[choice - 1]]);
                    printf("\n�����Ͻ� ���������� ���ҳ� ������ �˾ƺ� �帱���?\n");
                    printf("1. �� �������ּ���\n");
                    printf("2. �ƴϿ� ���������� ������\n");
                    int planChoice;
                    if (scanf_s("%d", &planChoice) != 1) {
                        printf("�߸��� �����Դϴ�.\n");
                        continue;
                    }
                    if (planChoice == 1) {
                        printf("����Ʈ�� �����ϴ� ���Դϴ�...\n");
                    }
                    else if (planChoice == 2) {
                        printf("�ٸ� �������� Ž���� ������\n");
                    }
                }
                else {
                    printf("�߸��� �����Դϴ�.\n");
                }
                break;
             

            case 2:
                printf("\n������ �ڸ�Ʈ�� �Է��� �������� �����ϼ��� (��ȣ�� �����Ͻÿ�): ");
                if (scanf_s("%d", &choice) != 1) {
                    printf("�߸��� �����Դϴ�.\n");
                    continue;
                }

                if (choice >= 1 && choice <= matchingCount) {
                    printf("������ �Է��ϼ��� (0~5): ");
                    int newRating;
                    if (scanf_s("%d", &newRating) != 1) {
                        printf("�߸��� �Է��Դϴ�.\n");
                        continue;
                    }

                    int totalRatings = travel[matchingIndices[choice - 1]].rating * travel[matchingIndices[choice - 1]].numReviews;
                    totalRatings += newRating;
                    travel[matchingIndices[choice - 1]].numReviews++;
                    travel[matchingIndices[choice - 1]].rating = totalRatings / travel[matchingIndices[choice - 1]].numReviews;

                    printf("��� ����: %d\n", travel[matchingIndices[choice - 1]].rating);

                    printf("�ڸ�Ʈ�� �Է��ϼ���: ");
                    if (scanf_s(" %[^\n]s", travel[matchingIndices[choice - 1]].comment, sizeof(travel[matchingIndices[choice - 1]].comment)) != 1) {
                        printf("�߸��� �Է��Դϴ�.\n");
                        continue;
                    }

                    printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
                }
                else {
                    printf("�߸��� �����Դϴ�.\n");
                }
                break;

            default:
                printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
                break;
            }
        } while (menuChoice < 1 || menuChoice > 2);
    }
    else {
        printf("�ش��ϴ� �������� �����ϴ�.\n");
    }

    return 0;
}
