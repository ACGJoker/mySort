#pragma once
#include<iostream>
using namespace std;
template<class T>
void InsertSort(T val[], int n)//插入
{
	int i, cur;
	for (i = 1; i < n; i++)
	{
		int temp = val[i];
		cur = i - 1;
		while (cur >= 0 && val[cur] > temp)
		{
			val[cur + 1] = val[cur];
			cur--;
		}
		val[cur + 1] = temp;
	}
}

template<class T>
void BISort(T val[], int n)//折半插入
{
	int left, mid, right, p;
	for (p = 1; p < n; p++)
	{
		T temp = val[p];
		left = 0;
		right = p - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (val[mid] > temp)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (int i = p - 1; i >= left; i--)
			val[i + 1] = val[i];
		val[left] = temp;
	}
}

template<class T>
void ShellSort(T val[], int n)//希尔
{
	int d = n / 2;
	while (d >= 1)
	{
		for (int k = 0; k < d; k++)
		{
			for (int i = k + d; i < n; i += d)
			{
				T temp = val[i];
				int j = i - d;
				while (j >= k && val[j] > temp)
				{
					val[j + d] = val[j];
					j = j - d;
				}
				val[j + d] = temp;
			}
		}
		d = d / 2;
	}
}


//交换
template<class T>
void BubbleSort(T val[], int n)//冒泡
{
	int flag;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (val[j] > val[j + 1])
			{
				swap(val[j], val[j + 1]);
				flag = true;
			}
		}
		if (!flag)
		{
			return;
		}
	}
}
template<class T>
int Part(T val[], int start, int end);
template<class T>
void QSort(T val[], int left, int right)//快速
{
	if (left < right)
	{
		int p = Part(val, left, right);
		QSort(val, left, p - 1);
		QSort(val, p + 1, right);
	}
}
template<class T>
int Part(T val[], int start, int end)//快速
{
	T pos = val[start];
	int left = start;
	int right = end;
	while (left <= right)
	{
		while (left <= right && val[right] > pos)
			right--;
		while (left <= right && val[left] <= pos)
			left++;
		if (left < right)
		{
			swap(val[right], val[left]);
			left++; right--;
		}
	}
	swap(val[start], val[right]);
	return right;
}

//选择
template<class T>
void SelectSort(T val[], int n)//简单选择
{
	int pos;
	for (int i = 1; i < n; i++)
	{
		pos = i - 1;
		for (int j = i; j < n; j++)
		{	
			if (val[j] < val[pos])
			{
				pos = j;
			}
		}
		if (pos != i - 1)
			swap(val[pos], val[i - 1]);
	}
}
template<class T>
void Merge(T val[], int start, int mid, int end);
//归并
template<class T>
void MergeSort(T val[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(val, start, mid);
		MergeSort(val, mid+1, end);
		Merge(val, start, mid, end);


	}
}
template<class T>
void Merge(T val[], int start, int mid, int end)
{
	int len1 = mid - start + 1;
	int len2 = end - mid;
	T* left = new T[len1];
	T* right = new T[len2];

	for (int i = 0; i < len1; i++)
	{
		left[i] = val[i + start];
	}
	for (int i = 0; i < len2; i++)
	{
		right[i] = val[i + mid + 1];
	}
	int i=0, j=0, k;
	for (k = start; k < end; k++)
	{
		if (i == len1 || j == len2)
			break;
		if (left[i] <= right[j])
			val[k] = left[i++];
		else
			val[k] = right[j++];
	}
	while (i < len1)
		val[k++] = left[i++];
	while (j < len2)
		val[k++] = right[j++];
	delete[]left;
	delete[]right;

}


void Arrange(int A[], int n)
// n个整数存于数组A中，本算法将数组中所有正数排在所有负数的前面
{
	int i = 0, j = n - 1, x;
	while (i < j)
	{
		while (i < j && A[i]>0)
			i++;
		while (i < j && A[j] < 0)
			j--;
		if (i < j)
		{
			x = A[i];
			A[i++] = A[j];
			A[j--] = x;
			//变换A[i]与A[j]
		}
	}
}
