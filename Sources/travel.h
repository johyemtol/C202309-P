#pragma once
#include<stdio.h>

struct Travel {
	char name[50];
	char location[50];
	char attraction[100];
	char food[100];
	char climate[50];
	char type[50];
};

void showTravel(const struct Travel* travel);