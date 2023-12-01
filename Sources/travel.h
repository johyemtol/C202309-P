#pragma once
#include<stdio.h>

struct Travel {
	char name[50];
	char location[50];
	char attraction[100];
	char food[100];
	char climate[50];
	char type[3][50];
	char comment[200];
	int rating;
};

void showTravel(const struct Travel* travel);
int checkMatch(const char(*userPreferences)[50], const struct Travel* travel);
void searchTravel(const char* searchQuery, struct Travel* travelList, int listSize, int matchingIndices[], int* matchingCount);