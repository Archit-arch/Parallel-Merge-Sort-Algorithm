#include "mergeSort.hpp"
#include <cstdlib>  // For exit()
#include<iostream>

MergeSort::MergeSort(std::vector<int> *nums){
    this->nums = nums;
}

MergeSort::~MergeSort(){}  
void MergeSort::recursiveSort(int left, int right){
    // Correct the base case
    if(left >= right){
        return;
    }

    int mid = left + (right - left) / 2;

    recursiveSort(left, mid);
    recursiveSort(mid + 1, right);

    std::vector<int> result;

    int i = left;
    int j = mid + 1;

    // Merge the two halves
    while(i <= mid && j <= right){
        if((*nums)[i] <= (*nums)[j]){
            result.push_back((*nums)[i]);
            i++;
        } else {
            result.push_back((*nums)[j]);
            j++;
        }
    }

    // Copy any remaining elements from the left half
    while(i <= mid){
        result.push_back((*nums)[i]);
        i++;
    }

    // Copy any remaining elements from the right half
    while(j <= right){
        result.push_back((*nums)[j]);
        j++;
    }

    // Copy the merged result back to the original vector
    for(int k = 0; k < result.size(); k++){
        (*nums)[left + k] = result[k];
    }

    return;
}

void MergeSort::sort(){
    // Handle empty array case
    if(nums->empty()){
        exit(1);  // Better to return or handle it without terminating the program abruptly
    }
    recursiveSort(0, nums->size() - 1);  // Correct the range

    for(int i=0;i<(*nums).size();i++){
        std::cout<<(*nums)[i]<<std::endl;
    }

}
