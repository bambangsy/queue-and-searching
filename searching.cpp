#include <iostream>
using namespace std;

int linearSearch(int arr[],int value,int size){
	for(int i = 0;i<size;i++){
		if (arr[i] == value){
			return i;
			
		}
	}
	return -1;
}
	
int binarySearch(int arr[], int value,int size){
	int start = 0;
	int end = size-1;
	
	while (start<=end){
		int mid = ((end-start)/2) + start;
		
		if(arr[mid]==value){
			return mid;
		}
		else if(arr[mid]<value){
			start = mid + 1;
		}
		else{
			end = mid-1;
		}
	}
	
	return -1;
}	
	
	

int main(){
	const int size = 100000;
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
	cout<< linearSearch(arr,90000,size);
	
	
}
