#include "travel.h"

int main() {
    struct Travel travel[5] = {
        {"����","�ƽþ� �ѱ�","�溹��, ����Ÿ��","�����, ��ġ","�����",{"����","����","����"}, "�ſ� �Ƹ��ٿ�", 3},
        {"�ĸ�","���� ������","����ž, ��긣 �ڹ��� ","���� �θ��⴨, ������","��ȭ��",{"����","����","��ȭ"}, "������ ����", 4},
        {"����","���� ����","Ÿ�� �긮��, ��ŷ�� ���� ","�ǽ� �� Ĩ��, �ױ۸��� �귢�۽�Ʈ","����������� ���������� ���ì��� �ٳ����",{"�޽�","����","�ڿ�"}, "", 3},
        {"ĵ����","����Ʈ���ϸ��� ȣ��","���������� ","Ļ��� ���, ��Ʈ����","��ȭ��",{"����","��ȭ","����"}, "", 0},
        {"������ d.c","�Ƹ޸�ī �̱�","���� ����, ��ǰ�","������ũ, ����","�����",{"����","�ǹ�","����"}, "ȭ����", 4},
        //������ 5���ۿ� ������ �� �߰��� ����
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

        printf("�޴��� �����ϼ���:\n");
        printf("1. ������ ����\n");
        printf("2. ������ ���� �� �ڸ�Ʈ �Է�\n");

        int menuChoice;
        scanf_s("%d", &menuChoice);

        if (menuChoice == 1) {
            printf("� �������� �����Ͻðڽ��ϱ�? (��ȣ�� �����Ͻÿ�): ");
            int choice;
            scanf_s("%d", &choice);

            if (choice >= 1 && choice <= matchingCount) {
                printf("�����Ͻ� ������:\n");
                showTravel(&travel[matchingIndices[choice - 1]]);
                printf("\n�����Ͻ� ���������� ���ҳ� ������ �˾ƺ� �帱���?\n");
                printf("1. �� �������ּ���\n");
                printf("2. �ƴϿ� ���������� ������\n");
                int planChoice;
                scanf_s("%d", &planChoice);
                if (planChoice == 1) {
                    printf("����Ʈ�� �����ϴ� ���Դϴ�...\n");

                    //���߿� ������Ʈ�� �����Ͽ� ���ҳ� ���� ������ �ְ� ��
                }
                else if (planChoice == 2) {
                    printf("�ٸ� �������� Ž���� ������\n");
                }

            }
            else {
                printf("�߸��� �����Դϴ�.");
            }
        }
        else if (menuChoice == 2) {
            printf("������ �ڸ�Ʈ�� �Է��� �������� �����ϼ��� (��ȣ�� �����Ͻÿ�): ");
            int choice;
            scanf_s("%d", &choice);

            if (choice >= 1 && choice <= matchingCount) {
                printf("������ �Է��ϼ��� (0~5): ");
                int newRating;
                scanf_s("%d", &newRating);

                // Calculate the new average rating
                int totalRatings = travel[matchingIndices[choice - 1]].rating * travel[matchingIndices[choice - 1]].numReviews;
                totalRatings += newRating;
                travel[matchingIndices[choice - 1]].numReviews++;
                travel[matchingIndices[choice - 1]].rating = totalRatings / travel[matchingIndices[choice - 1]].numReviews;

                printf("��� ����: %d\n", travel[matchingIndices[choice - 1]].rating);

                printf("�ڸ�Ʈ�� �Է��ϼ���: ");
                scanf_s(" %[^\n]s", travel[matchingIndices[choice - 1]].comment, sizeof(travel[matchingIndices[choice - 1]].comment));

                printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
            }
            else {
                printf("�߸��� �����Դϴ�.");
            }
        }
        else {
            printf("�߸��� �����Դϴ�.");
        }
    }
    else {
        printf("�ش��ϴ� �������� �����ϴ�.");
    }

    return 0;
}