#include<iostream>
using namespace std;
class MaxHeap
{
	int *arr;
	int capacity;
	int size;
	
	public:
		MaxHeap()
		{
			
		}
		MaxHeap(int capacity)
		{
			arr = new int[capacity];
			this->capacity = 0;
			this->size = 0;
		}
		
		int getSize()
		{
			return size;
		}
		
		int getParent(int child)
		{
			if(child%2 == 0)
			{
				return (child/2)-1;
			}
			else return (child/2);
		}
		
		int getLeft(int parent)
		{
			return (2*parent+1);
		}
		
		int getRight(int parent)
		{
			return (2*parent+2);
		}
		
		int getMax()
		{
			return arr[0];
		}
		
		bool isLeaf(int i)
		{
			if(i>=size)
			{
				return true;
			}
			else return false;
		}
		
		void Display(int a[],int size)
		{
			for(int i=0;i<size;i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
		
		void ShiftUp(int i)
		{
			if(i==0)
			{
				return;
			}
			
			int p_index = getParent(i);
			if(arr[p_index]<arr[i])
			{
				swap(arr[p_index],arr[i]);
				ShiftUp(p_index);
			}
		}
		
		void ShiftDown(int i)
		{
			int l = getLeft(i);
			int r = getRight(i);
			
			if(isLeaf(i))
			{
				return;
			}
			
			int maxIndex = i;
			if(arr[l]>arr[i])
			{
				maxIndex = l;
			}
			
			if(!isLeaf(r) && (arr[r]>arr[maxIndex]))
			{
				maxIndex = r;
			}
			
			if(maxIndex!=i)
			{
				swap(arr[i],arr[maxIndex]);
				ShiftDown(maxIndex);
			}
		}
		
		void Insert(int k)
		{
			arr[size] = k;
			ShiftUp(size);
			size++;
			for(int i=0;i<size;i++)
			{
				cout << arr[i] << " ";
			}
			cout<< endl;
		}
	
		
		
};
