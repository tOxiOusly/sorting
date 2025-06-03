#include "sorts.h"

#include <iostream>

using namespace std;

sorts::sorts(vector<int>& vc)
{
	this->vc = vc;
}

void sorts::BubbleSort()
{
	for (int i = 0; i < vc.size(); ++i)
	{
		for (int j = 0; j < vc.size() - i - 1; ++j)
		{
			if (vc[j + 1] < vc[j])
			{
				swap(vc[j], vc[j + 1]);
			}
		}
	}
	cout << "Bubble Sort\n" << "Time complexity: worst - O(n^2)\tavg - O(n^2)\tbest - O(n)" << endl;
}

void sorts::ShakerSort()
{
	int left = 0;
	int right = vc.size() - 1;
	while (left <= right)
	{
		for (int i = right; i > left; --i)
		{
			if (vc[i - 1] > vc[i])
			{
				swap(vc[i - 1], vc[i]);
			}
		}
		++left;
		for (int i = left; i < right; ++i)
		{
			if (vc[i] > vc[i + 1])
			{
				swap(vc[i], vc[i + 1]);
			}
		}
		--right;
	}
	cout << "Shaker Sort\n" << "Time complexity: worst - O(n^2)\tavg - O(n^2)\tbest - O(n)" << endl;
}

void sorts::CombSort()
{
	const double factor = 1.247;
	double step = vc.size() - 1;
	while (step >= 1)
	{
		for (int i = 0; i + step < vc.size(); ++i)
		{
			if (vc[i] < vc[i + step])
			{
				swap(vc[i], vc[i + step]);
			}
		}
		step /= factor;
	}

	for (int i = 0; i < vc.size() - 1; ++i)
	{
		for (int j = 0; j < vc.size() - i - 1; ++j)
		{
			if (vc[j] > vc[j + 1])
			{
				swap(vc[j], vc[j + 1]);
			}
		}
	}
	cout << "Comb Sort\n" << "Time complexity: worst - O(n^2)\tavg - Omega(n^2/2^p)\tbest - O(n log n)" << endl;
}

void sorts::InsertSort()
{
	for (int i = 1; i < vc.size(); ++i)
	{
		int x = vc[i];
		int j = i;
		while (j > 0 && vc[j - 1] > x)
		{
			vc[j] = vc[j - 1];
			--j;
		}
		vc[j] = x;
	}
	cout << "Insertion Sort\n" << "Time complexity: worst - O(n^2)\t\tavg - O(n^2)\t\tbest - O(n) compairing O(1) swap" << endl;
}

void sorts::QuickSort()
{
	this->QuickSortBody(vc, 0, this->vc.size() - 1);
	cout << "Quick Sort\n" << "Time complexity: worst - O(n^2)\t\tavg - O(n log n)\t\tbest - O(n)" << endl;
}

int sorts::Partition(vector<int>& vc, int l, int r)
{
	int x = vc[r];
	int less = l;
	
	for (int i = l; i < r; ++i)
	{
		if (vc[i] <= x)
		{
			swap(vc[i], vc[less]);
			++less;
		}
	}

	swap(vc[less], vc[r]);
	
	return less;
}

void sorts::QuickSortBody(vector<int>& vc, int l, int r)
{
	if (l < r)
	{
		int q = Partition(vc, l, r);
		QuickSortBody(vc, l, q - 1);
		QuickSortBody(vc, q + 1, r);
	}
}

void sorts::MergeSortBody(vector<int>& vc, vector<int>& buffer, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		MergeSortBody(vc, buffer, l, m);
		MergeSortBody(vc, buffer, m + 1, r);

		int b = l;
		for (int i = l, j = m + 1; i <= m || j <= r; )
		{
			if (j > r || (i <= m && vc[i] < vc[j]))
			{
				buffer[b] = vc[i];
				++i;
			}
			else
			{
				buffer[b] = vc[j];
				++j;
			}
			++b;
		}
		for (int i = l; i <= r; ++i)
		{
			vc[i] = buffer[i];
		}
	}
}

void sorts::MergeSort()
{
	this->buffer.resize(vc.size());
	this->MergeSortBody(vc, buffer, 0, vc.size() - 1);
	cout << "Quick Sort\n" << "Time complexity: worst - O(n log n)\t\tavg - O(n log n)\t\tbest - O(n log n)" << endl;
}

void sorts::SelectionSort()
{
	for (int i = 0; i < vc.size(); ++i)
	{
		int j = min_el(i, vc.size());
		swap(vc[i], vc[j]);
	}
	cout << "Selection Sort\n" << "Time complexity: worst - O(n^2)\t\tavg - O(n^2)\t\tbest - O(n^2)" << endl;
}

int sorts::min_el(int l, int r)
{
	int min = vc[l];
	int ind = l;
	for (int i = l + 1; i < r; ++i)
	{
		if (vc[i] < min)
		{
			min = vc[i];
			ind = i;
		}
	}
	return ind;
}

ostream& operator<<(ostream& os, sorts& vc)
{
	for (auto& el : vc.vc)
	{
		os << el << " ";
	}
	return os;
}
