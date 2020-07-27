#include <math.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

static int inversions = 0;

template<typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int n)
{
	auto first = v.cbegin() + m;
	auto last = v.cbegin() + n + 1;

	std::vector<T> vec(first, last);
	return vec;
}

std::vector<int> merge(std::vector<int> left,std::vector<int> right){
    
    // necessary when an array containing only one element is divided
    if(right.size()==0)return left;

    int length = left.size() + right.size();  
    int i=0, j=0, k=0;
    std::vector<int> merged;

    // merge the left and right arrays into a sorted array
    while(k<length){
        // if we reach the end of left, then just return right
        if(i==left.size()){
            for(int a=j;a<right.size();a++)
                merged.push_back(right[a]);
            break;
        }
        // if we reach the end of right, then just return left
        if(j==right.size()){
            for(int b=i;b<left.size();b++){
                merged.push_back(left[b]);
                inversions++;
            }
            break;
        }
        // walk through the sorted left and right arrays, travelling from 
        // smallest to largest elements, and pushing to the sorted array as we go
        if(left[i]<right[j]){
            merged.push_back(left[i]);
            i++;
        }else{
            merged.push_back(right[j]);
            // counting the number of inversions in our array
            inversions++;
            j++;
        }
        k++;
    }
    
    return merged;
    
}

std::vector<int> sort(std::vector<int> vec){
    
    int length = vec.size();
    // divide...
    std::vector<int> left = slice(vec,0,length/2-1);
    std::vector<int> right = slice(vec,length/2,length-1);
    
    // base case where left and right contain max one element each
    if(length<3){
        std::vector<int> sorted = merge(left,right);
        return sorted;
    }
    
    // ... and conquer
    std::vector<int> l_sorted = sort(left);
    std::vector<int> r_sorted = sort(right);
    std::vector<int> sorted = merge(l_sorted,r_sorted);
    
    return sorted;
    
}

int main(){
   
    std::vector<int> vec = {1,7,7,3,1,4,2,0,3,6,5,7,8,32,5,4,6,6};
    //std::vector<int> vec = {1,3,5,2,4,6};
    
    std::vector<int> v_sorted = sort(vec);
    
    std::cout << "unsorted array: ";
    for(auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    
    std::cout << "sorted array: ";
    for(auto i : v_sorted)
        std::cout << i << " ";
    std::cout << std::endl;
    
    std::cout << "array had " << inversions << " inversions" << endl;
    
    return 0;
    
}