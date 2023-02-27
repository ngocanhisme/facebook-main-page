#include <iostream>

using namespace std;

void input(int A[], int &n) {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
}

void Swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

void output(int A[], int n) {
    for(int i=0; i<n; i++) {
        cout << A[i] << "  ";
    }
}

void sort1(int A[], int n) {
    for(int i=0; i<n-1; i++) {
        if(A[i+1] < A[i]) {
            Swap(A[i+1],A[i]);
            i = -1;
        }
    }
}

void selection_sort1(int A[], int n) {
    for(int i=0; i<n; i++) {
        int min_index = i;
        for(int j=i+1; j<n; j++) {
            if(A[j] < A[min_index]) {
                min_index = j;
            }
        }
        if(min_index != i) Swap(A[i], A[min_index]);
    }
}

void selection_sort2(int A[], int n) {

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(A[j] < A[i]) {
                Swap(A[i], A[j]);
            }
        }
    }
}

void insertion_sort(int A[], int n) {
    for(int i=0; i<n-1; i++) {
        if(A[i+1] < A[i]) {
            Swap(A[i+1], A[i]);
            if(i>0) i=i-2;
        }
    }
}

void bubble_sort(int A[], int n) {
    while(true) {
        int c=0;
        for(int i=0; i<n-1; i++) {
            if(A[i+1] < A[i]) {
                Swap(A[i+1],A[i]);
                c++;
            }
        }
        if(c == 0) break;
    }
}

int Partition(int A[], int Start, int End) {
//Find the pivot index
    int pivot = A[Start];
    int c=0;
    for(int i=Start+1; i<=End; i++) {
        if(A[i] <= pivot) c++;
    }
    int p = Start + c; //Pivot index
    Swap(A[Start], A[p]); //Sort pivot to its right position

// Sort greater elements than pivot to the left of it and less ones to the right
    int i = Start;
    int j = End;
    while(i<p && j>p) {  //Condition to check the element before and after pivot
        // Loop until finding the wrong ordered elements to swap
        while(A[i] <= pivot) {
            i++;
        }
        while(A[j] > pivot) {
            j--;
        }
        //Swap wrong ordered elements
        if(i<p && j>p) Swap(A[i++], A[j--]); //Swap elements before and after pivot
    }
    return p;
}

void quick_sort(int A[], int Start, int End) {
    if(Start < End) { /*This means if Start==End or Start>=End, stop sorting. If it's not, continue (=return;)
                               Because Start == End <=> there is just one element
                                AND     Start < End <=> quick_sort(A,Start,-1) or quick_sort(A,End+1,End
                                                            UNVALID function --> not work = not sort*/
        // Find the index for Pivot
        int p = Partition(A, Start, End);
        // Sort left parts
        quick_sort(A, Start, p-1);
        // Sort right parts
        quick_sort(A, p+1, End);
    }
}

int binarySearch1(int A[], int first, int last, int x) {
    //Recursion
    if(last >= first) {
       int index = first + (last-first)/2;
       if(A[index] == x) return index;
       if(A[index] > x) binarySearch1(A,first,index-1,x);
       else binarySearch1(A,index+1,last,x);
    } else return -1;
}

int binarySearch2(int A[], int first, int last, int x) {
    //Loop
    while(last >= first) {
        int index = first + (last-first)/2;
        if(A[index] == x) return index;
        if(A[index] > x) last = index-1;
        else first = index+1;
    }
}

int main()
{
    int A[20]={20,1,19,2,18,3,17,4,16,5,15,6,14,13,7,12,8,11,9,10};
    cout << "Unsorted array: " << endl;
    output(A,20);

    //selection_sort1(A,20);
    //selection_sort2(A,10);
    //sort1(A,10);
    //insertion_sort(A,10);
    //bubble_sort(A,10);
    quick_sort(A,0,19);
    cout << endl << "Sorted array: " << endl;
    output(A,20);
// Searching algorithm
    cout << endl << "What value do you want to find? ";
    int x;
    cin >> x;
    int index = binarySearch1(A,0,19,x);
    cout << endl << "It's index is: " << index;

    cout << endl << "Another? ";
    cin >> x;
    int indexxx = binarySearch2(A,0,19,x);
    cout << endl << "It's index is: " << indexxx;
    return 0;
}
