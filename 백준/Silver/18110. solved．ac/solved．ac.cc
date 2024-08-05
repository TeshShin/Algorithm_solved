#include<iostream>
#include <algorithm>

using namespace std;

int opin[300001];

int roundNum(double num);
int percent30(double length);
void quickSort(int opin[], int start, int end);

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
	sort(opin, opin + length);
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

void quickSort(int opin[], int start, int end) {
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