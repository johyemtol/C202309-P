#include "travel.h"

void showTravel(const struct Travel* travel) {
	printf("������: \n");
	printf("�̸�: %s\n", travel->name);
	printf("��ġ: %s\n", travel->location);
	printf("�ֿ���: %s\n", travel->attraction);
	printf("����: %s\n", travel->food);
	printf("����: %s\n", travel->climate);
}