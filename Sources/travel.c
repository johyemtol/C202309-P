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
	printf("�ڸ�Ʈ: %s\n", travel->comment);
	printf("����: %d\n", travel->rating);
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

//�̸� �Ǵ� ������ �Է� �Ǿ��������� �������� ����ϱ� ���� �Լ�
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

