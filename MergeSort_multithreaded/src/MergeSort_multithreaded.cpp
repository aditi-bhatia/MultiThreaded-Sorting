#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;

const int VECTOR_SIZE = 100;

void merge(vector<int>& vec, int start, int mid, int end) {
	vector<int> firstHalf(vec.begin() + start, vec.begin() + mid + 1);
	vector<int> secondHalf(vec.begin() + mid + 1, vec.begin() + end + 1);

	int a = 0;
	int b = 0;
	int index = start;
	while (a < firstHalf.size() && b < secondHalf.size()) { //merges
		if (firstHalf[a] < secondHalf[b])
			vec[index++] = firstHalf[a++];
		else
			vec[index++] = secondHalf[b++];
	}

	// merge the left-over elements
	while (a < firstHalf.size())
		vec[index++] = firstHalf[a++];
	while (b < secondHalf.size())
		vec[index++] = secondHalf[b++];
}

void merge_sort(vector<int>& vec, int start, int end) {
	if (start >= end)
		return;

	int mid = start + (end - start) / 2;

// multi-thread version
	thread first(merge_sort, std::ref(vec), start, mid);
	thread second(merge_sort, std::ref(vec), mid + 1, end);
	first.join();
	second.join();

	/*
	 merge_sort(vec, start, mid);  //for single-threaded
	 merge_sort(vec, mid + 1, end);
	 */

	merge(vec, start, mid, end);
}
void random_number_generator(vector<int>& a) {
	srand(time(NULL));
	for (int i = 0; i < a.size(); ++i) {
		a[i] = rand();
	}
}

int main() {
	int start = clock();
	//int a[] = {90, 2, 67, 9, 22, 1, 77, 45, 23, 45,66, 34, 12, 4, 6};
	//vector<int> vec(a, a + 15);

	vector<int> vec;
	vec.resize(VECTOR_SIZE - 1);    //vector initialization
	random_number_generator(vec);
	merge_sort(vec, 0, VECTOR_SIZE - 1);
	//for (int i = 0; i < 15; i ++)
	//  cout << vec[i] << endl;
	int stop = clock(); // record stop time in clocks.
	cout << "Running time: " << ((stop - start) / double(CLOCKS_PER_SEC)) * 1000
			<< " ms" << endl;
	return 0;
}
