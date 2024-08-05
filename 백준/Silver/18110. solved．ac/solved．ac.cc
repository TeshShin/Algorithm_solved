#include<iostream>
#include <algorithm>
#include<cstdlib>
#include<ctime>

using namespace std;
/* 이 문제는 피벗을 랜덤으로 고르는 것이 핵심인가?? <- 이것도 아님!! 그럼 뭐가 문제지 */
/* ==> 최악의 시간 복잡도도 nlogn을 보장하는 정렬 알고리즘을 사용해야한다!*/
int opin[300001];
int sorted[300001]; // 추가적인 공간이 필요

int roundNum(double num);
int percent30(double length);
//void quickSort(int opin[], int start, int end);
//void swap(int* a, int* b);
void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);
int main() {

	int length;
	cin >> length;
	if (length == 0) {
		cout << 0;
		return 0;
	}
		
	for (int i = 0; i < length; i++) {
		cin >> opin[i];
	}
	//quickSort(opin, 0, length - 1);
	//sort(opin, opin + length); // 내장 함수는 정답임
	merge_sort(opin, 0, length - 1);
	//for (int i = 0; i < length; i++) { // 빠른 정렬 체크
	//	cout << opin[i] << " ";
	//}


	int except = percent30(length);
	double level = 0;

	for (int i = except; i < length - except; i++) {
		level += opin[i];
	}
	level = level / (length - 2 * except);

	cout << roundNum(level);


	return 0;
}



int roundNum(double num) {
	if (num - int(num) >= 0.5) {
		return int(num) + 1;
	}
	else {
		return int(num);
	}
}

int percent30(double length) {
	length = length * (15 / float(100));
	return roundNum(length);
}
/*
void quickSort(int opin[], int start, int end) {	// 시간 초과
	if (start >= end) return;
	int pivot = start;
	int i = start + 1;
	int j = end;
	while (i <= j) {
		while (opin[i] <= opin[pivot]) i++;
		while (opin[j] >= opin[pivot] && j > start) j--;
		if (i > j) {
			int temp = opin[j];
			opin[j] = opin[pivot];
			opin[pivot] = temp;
		}
		else {
			int temp = opin[j];
			opin[j] = opin[i];
			opin[i] = temp;
		}
	}
	quickSort(opin, start, j - 1);
	quickSort(opin, j + 1, end);
}
*/

/*
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void quickSort(int opin[], int start, int end) { // 시간초과
	if (start >= end) return;
	srand((unsigned int)time(NULL));
	int pivot = rand() % (end + 1 - start) + start;
	int pivotValue = opin[pivot];

	swap(&opin[pivot], &opin[end]);

	int store_index = start;

	// store_index를 기준으로
	// 왼쪽에 pivot_value보다 작은 값들 위치시킴
	for (int i = start; i < end; i++) {
		if (opin[i] < pivotValue) {
			swap(&opin[i], &opin[store_index]);
			store_index++;
		}
	}
	swap(&opin[store_index], &opin[end]);

	quickSort(opin, start, store_index - 1);
	quickSort(opin, store_index + 1, end);
}
*/

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// 남아 있는 값들을 일괄 복사
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	// 남아 있는 값들을 일괄 복사
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}

// 합병 정렬
void merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
		merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
		merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
		merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
	}
}

