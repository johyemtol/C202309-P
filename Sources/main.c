#include<stdio.h>

int main() {
	printf("� �������� ��õ���ٱ��?(��ȣ�� �����Ͻÿ�)");
	//��ȣ �ް��� �������� ����
	int choice;
	scanf_s("%d", &choice);
	if (choice >= 1) {
		printf("����� ������ �������� ~~�Դϴ�.");
		//�̾ �������� ��õ ���ϱ�
	}
	else {
		printf("�߸��� �����Դϴ�.");
	}
}