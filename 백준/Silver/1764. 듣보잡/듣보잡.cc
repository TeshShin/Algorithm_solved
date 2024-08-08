#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable : 4996)
int N, M;
char namelist1[500001][21];
char cantseeName[21];
char sorted[500001][21];


char reallist[500001][21];
int length = 0;


void merge(char list[][21], int left, int mid, int right);
void merge_sort(char list[][21], int left, int right);

int findchar(char namelist[][21], char name[], int first, int last);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> namelist1[i];
	}
	merge_sort(namelist1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		cin >> cantseeName;
		if (findchar(namelist1, cantseeName, 0, N - 1)) {
			strcpy(reallist[length], cantseeName);
			length++;
		}
	}

	merge_sort(reallist, 0, length - 1);
	cout << length << '\n';
	for (int i = 0; i < length; i++) {
		cout << reallist[i] << '\n';
	}

	return 0;
}


void merge(char list[][21], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right) {
		if (strcmp(list[i] , list[j]) <= 0)
			strcpy(sorted[k++], list[i++]);
		else
			strcpy(sorted[k++], list[j++]);
	}

	// 남아 있는 값들을 일괄 복사
	if (i > mid) {
		for (l = j; l <= right; l++)
			strcpy(sorted[k++], list[l]);
	}
	// 남아 있는 값들을 일괄 복사
	else {
		for (l = i; l <= mid; l++)
			strcpy(sorted[k++], list[l]);
	}

	// 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++) {
		strcpy(list[l], sorted[l]);
	}
}

// 합병 정렬
void merge_sort(char list[][21], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
		merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
		merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
		merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
	}
}

int findchar(char namelist[][21], char name[], int first, int last) {
	int mid = (first + last) / 2;
	if (first > last) {
		return 0;
	}
	else {
		if (strcmp(namelist[mid], name) == 0) {
			return 1;
		}
		else if (strcmp(namelist[mid], name) < 0) {
			return findchar(namelist, name, mid + 1, last);
		}
		else if (strcmp(namelist[mid], name) > 0) {
			return findchar(namelist, name, first, mid - 1);
		}
	}
	return 0;
}