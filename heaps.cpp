#include <iostream>
#include <vector>
using namespace std;

class maxHeap{
    vector<int> vec;


    void heapify(int idx){
        int size=vec.size();
        if((2*idx+1)>=size) return;
        if((2*idx+2)>=size){
            if(vec[idx]<vec[2*idx+1]){
                int dum=vec[idx];
                vec[idx]=vec[2*idx+1];
                vec[2*idx+1]=dum;
                return;
            }
        }
        int greater_child;
        if(vec[2*idx+1]>vec[2*idx+2]){
            greater_child=2*idx+1;
        }
        else{
            greater_child=2*idx+2;
        }
        if(vec[idx]<vec[greater_child]){
            int dum=vec[idx];
            vec[idx]=vec[greater_child];
            vec[greater_child]=dum;
            heapify(greater_child);
        }
        return;
    }

    void sift_up(int idx){
        while(idx>0){
            if(vec[idx]>vec[(idx-1)/2]){
                int dum=vec[idx];
                vec[idx]=vec[(idx-1)/2];
                vec[(idx-1)/2]=dum;
            }
            else{
                return;
            }
            idx=(idx-1)/2;
        }
        return;
    }

    void insert(int num){
        vec.push_back(num);
        sift_up(vec.size()-1);
    }

};