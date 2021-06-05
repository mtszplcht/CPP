#include <iostream>
#include <string>
#include "sort.h"
using namespace std;


void SortExample::quick_sort(int* tab, int left, int right){
    int pivot = tab[(left+right)/2];
    int i = left;
    int j =right;
    int temp;
    do{
        while(tab[i]<pivot) i++;
        while(tab[j]>pivot) j--;
        if(i<=j){
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
            j--;
        }
    }while(i<=j);

    if(i<right) quick_sort(tab, i, right);
    if(j>left) quick_sort(tab, left, j);
}



int SortExample::binary_search(int* tab, int left, int right, int lookUpValue){

    int mid = (left+right)/2;
    if(tab[mid] == lookUpValue){
        return mid;
    }else if(lookUpValue < tab[mid]){
        return binary_search(tab, left, mid-1, lookUpValue);
    }else if(lookUpValue > tab[mid]){
        return binary_search(tab, mid+1, right, lookUpValue);
    }else{
        return -1;
    }
}

string SortExample::print(int* tab, int length){
    string str = "";
    for(int i=0; i<length; i++){
        str += to_string(tab[i]);
    }
    return str;
}