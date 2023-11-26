#include "travel.h"

int main() {
	struct Travel travel[5] = {
        {"����a","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����",{"�޽�","�ڿ�","����"}},
        {"bs��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����",{"����","����","��ȭ"}},
        {"ce��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����",{"�޽�","����","�ڿ�"}},
        {"df��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����",{"����","��ȭ","����"}},
        {"ea��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����",{"�޽�","�ǹ�","�޽�"}},

	};


    printf("������ �Է��ϼ���?(�޽�, ����): ");
    char userPreferences[50];
    scanf_s("%s", userPreferences, sizeof(userPreferences));

    int recommendCount = 0;
    int matchingIndices[5] = { 0 }; // �迭 ũ��� �������� ���� ���� ����

    for (int i = 0; i < 5; ++i) {
        int matchCount = checkMatch(&userPreferences, &travel[i]);
        if (matchCount >= 1) {
            matchingIndices[recommendCount] = i;
            recommendCount++;
        }
    }

    if (recommendCount > 0) {
        printf("��õ�ϴ� �������Դϴ�:\n");
        for (int i = 0; i < recommendCount; ++i) {
            printf("%d. ", i + 1);
            showTravel(&travel[matchingIndices[i]]);
        }

        printf("� �������� �����Ͻðڽ��ϱ�? (��ȣ�� �����Ͻÿ�): ");
        int choice;
        scanf_s("%d", &choice);

        if (choice >= 1 && choice <= recommendCount) {
            printf("�����Ͻ� ������:\n");
            showTravel(&travel[matchingIndices[choice - 1]]);
            // �̾ �������� ��õ ���ϱ�
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