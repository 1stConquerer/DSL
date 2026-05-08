#include <iostream>
#include <algorithm>
using namespace std;

void print(int a[], int n) {
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

// 🔹 Bubble Sort
void bubble(int a[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
}

// 🔹 Selection Sort
void selection(int a[], int n) {
    for(int i=0;i<n-1;i++) {
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        swap(a[i],a[min]);
    }
}

// 🔹 Insertion Sort
void insertion(int a[], int n) {
    for(int i=1;i<n;i++) {
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

// 🔹 Merge Sort
void merge(int a[], int l, int m, int r) {
    int i=l,j=m+1,k=0;
    int t[100];

    while(i<=m && j<=r)
        t[k++]=(a[i]<a[j])?a[i++]:a[j++];

    while(i<=m) t[k++]=a[i++];
    while(j<=r) t[k++]=a[j++];

    for(i=l,k=0;i<=r;i++,k++)
        a[i]=t[k];
}

void mergeSort(int a[], int l, int r) {
    if(l<r) {
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

// 🔹 Quick Sort
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for(int j=low;j<high;j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

// 🔹 MAIN MENU
int main() {
    int n,ch;
    cout<<"Enter number of elements: ";
    cin>>n;

    int a[100];
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++) cin>>a[i];

    do {
        cout<<"\nMENU\n";
        cout<<"1 Bubble Sort\n";
        cout<<"2 Selection Sort\n";
        cout<<"3 Insertion Sort\n";
        cout<<"4 Merge Sort\n";
        cout<<"5 Quick Sort\n";
        cout<<"0 Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch) {
            case 1: bubble(a,n); break;
            case 2: selection(a,n); break;
            case 3: insertion(a,n); break;
            case 4: mergeSort(a,0,n-1); break;
            case 5: quickSort(a,0,n-1); break;
        }

        if(ch!=0) {
            cout<<"\nSorted Array: ";
            print(a,n);
        }

    } while(ch!=0);

    return 0;
}
