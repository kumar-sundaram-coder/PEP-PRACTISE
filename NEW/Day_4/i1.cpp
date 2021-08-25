Question 1. 

An Sorted Array is rotated at some point find out point where it rotated.

[1 2 3 4 5 6 7]   ->[3,4,5,6,7 1 2]

[1 2 3 4]  -> [3,4,1,2]

[1 2 3 4]
low=0 
high=0
mid= 0
arr[0]=1

3 

fi
O(n)


int findMinimum(int arr[],int low, int high){
while(low<high){

int mid=low+(high-low)/2;

if(arr[mid]==arr[high]){
	high--;
}
else if(arr[mid]>arr[high]){
	low=mid+1;
}
else{
	high=mid;
}
}
return arr[high];
}
O(logN)

A				B
A-> 100 -> B

valid(A, B)
Authentication(A)
Balance(A)
Debit(A,100)
Credit(B,100)



ACID -->

Debit  -->> 
Credit



Linked List
Binary Tree
Binary Searcg tree







