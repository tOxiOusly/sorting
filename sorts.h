#pragma once

#include <vector>
#include <fstream>

using namespace std;

class sorts
{
public:
	sorts(vector<int>& vc);
	friend ostream& operator<<(ostream& os, sorts& vc);
	void BubbleSort();
	void ShakerSort();
	void SelectionSort();
	void CombSort();
	void InsertSort();
	void QuickSort();
	void MergeSort();
private:
	vector<int> vc;
	vector<int> buffer;
	int Partition(vector<int>& vc, int l, int r);
	int min_el(int l, int r);
	void QuickSortBody(vector<int>& vc, int l, int r);
	void MergeSortBody(vector<int>& vc, vector<int>& buffer, int l, int r);
};

