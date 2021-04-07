#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

int family[101][101], visited[101];
int number_of_people, number_of_input;
int person_a, person_b;
int length_of_relation;

void init() {
	for (int i = 0; i < 101; i++)
		memset(family[i], 0, sizeof(int) * 101);
	memset(visited, 0, sizeof(int) * 101);
	length_of_relation = -1;
}

void dfs(int current, int target, int length) {
	visited[current] = 1;

	for (int i = 1; i <= family[current][0]; i++) {
		int next_person = family[current][i];

		if (next_person == target) {
			length_of_relation = length + 1;
			visited[target] = 1;
			break;
		}
		else if (visited[next_person] == 0 && visited[target] == 0)
			dfs(next_person, target, length + 1);
	}
}

int main() {

	init();

	scanf("%d", &number_of_people);
	scanf("%d %d", &person_a, &person_b);
	scanf("%d", &number_of_input);

	for (int i = 0; i < number_of_input; i++) {
		int tmp_a, tmp_b;
		scanf("%d %d", &tmp_a, &tmp_b);
		family[tmp_a][0]++;
		family[tmp_b][0]++;

		family[tmp_a][family[tmp_a][0]] = tmp_b;
		family[tmp_b][family[tmp_b][0]] = tmp_a;
	}

	dfs(person_a, person_b, 0);

	printf("%d\n", length_of_relation);

	return 0;
}