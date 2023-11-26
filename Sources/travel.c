#include "travel.h"

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