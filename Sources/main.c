#include "travel.h"

int main() {
    //�������� ����, ���߿� ������ �߰��ϴ� �ڵ嵵 �߰��� �����
    struct Travel travel[5] = {
        {"����a","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����",{"�޽�","�ڿ�","����"}, "", 0},
        {"bs��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����",{"����","����","��ȭ"}, "", 0},
        {"ce��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����",{"�޽�","����","�ڿ�"}, "", 0},
        {"df��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����",{"����","��ȭ","����"}, "", 0},
        {"ea��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����",{"�޽�","�ǹ�","�޽�"}, "", 0},
    };

    printf("�˻�� �Է��ϼ���:(����, �̸�, ���) ");
    char searchQuery[50];
    scanf_s("%s", searchQuery, sizeof(searchQuery));

    int matchingIndices[5] = { 0 };
    int matchingCount = 0;

    searchTravel(searchQuery, travel, 5, matchingIndices, &matchingCount);

    //�˻��Ͽ����� �˻� ����� �˸��� �������� �ִ����
    if (matchingCount > 0) {
        printf("�˻� ����� ���� �������Դϴ�:\n");
        for (int i = 0; i < matchingCount; ++i) {
            printf("%d. ", i + 1);
            showTravel(&travel[matchingIndices[i]]);
        }

        //���õ� ������ �� ������ ���� Ȥ�� ���� �ڸ�Ʈ �Է��� �� �ְ� ����
        printf("�޴��� �����ϼ���:\n");
        printf("1. ������ ����\n");
        printf("2. ������ ���� �� �ڸ�Ʈ �Է�\n");

        int menuChoice;
        scanf_s("%d", &menuChoice);

        //������ ����
        if (menuChoice == 1) {
            printf("� �������� �����Ͻðڽ��ϱ�? (��ȣ�� �����Ͻÿ�): ");
            int choice;
            scanf_s("%d", &choice);

            if (choice >= 1 && choice <= matchingCount) {
                printf("�����Ͻ� ������:\n");
                showTravel(&travel[matchingIndices[choice - 1]]);
                // �̾ �������� ��õ ���ϱ�
            }
            else {
                printf("�߸��� �����Դϴ�.");
            }
        }
        //������ ���� �� �ڸ�Ʈ �Է�
        else if (menuChoice == 2) {
            printf("������ �ڸ�Ʈ�� �Է��� �������� �����ϼ��� (��ȣ�� �����Ͻÿ�): ");
            int choice;
            scanf_s("%d", &choice);

            //������ �ڸ�Ʈ �Է��ϴ� �ڵ�
            if (choice >= 1 && choice <= matchingCount) {
                printf("������ �Է��ϼ��� (0~5): ");
                scanf_s("%d", &travel[matchingIndices[choice - 1]].rating);

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
    //�˻������� �˸��� �˻�� ������
    else {
        printf("�ش��ϴ� �������� �����ϴ�.");
    }

    return 0;
}
