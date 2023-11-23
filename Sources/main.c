#include "travel.h"

int main() {
	struct Travel travel[5] = {
		{"����a","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����","�޽�"},
		{"bs��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����","����"},
		{"ce��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����","�޽�"},
		{"df��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����","����"},
		{"ea��","�ƽþ� �ѱ�","�溹��, ","�����, ��ġ","�����","�޽�"},

	};

	printf("������ �Է��ϼ���?(�޽�, ����): ");
	char userType[50];
	scanf_s("%s", userType, sizeof(userType));

	int recommendCount = 0;
	for (int i = 0; i < 5; ++i) {
		if (strcmp(travel[i].type, userType) == 0) {
			recommendCount++;
		}
	}

    if (recommendCount > 0) {
        printf("��õ�ϴ� �������Դϴ�:\n");
        for (int i = 0; i < 5; ++i) {
            if (strcmp(travel[i].type, userType) == 0) {
                printf("%d. ", i + 1);
                showTravel(&travel[i]);
            }
        }

        printf("� �������� �����Ͻðڽ��ϱ�? (��ȣ�� �����Ͻÿ�): ");
        int choice;
        scanf_s("%d", &choice);

        if (choice >= 1 && choice <= recommendCount) {
            printf("�����Ͻ� ������:\n");
            showTravel(&travel[choice - 1]);
            // �̾ �������� ��õ ���ϱ�
        }
        else {
            printf("�߸��� �����Դϴ�.");
        }
    }
    else {
        printf("�ش��ϴ� �������� �����ϴ�.");
    }

	
}