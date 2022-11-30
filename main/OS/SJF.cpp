#include <iostream>
using namespace std;

//Global Arrays
int burstTimeArr[20]={};
int sz={}; // sz of Array


// "NON PREMPTIVE SHORTEST" JOB FIRST ALGORITHM
// By Avishkaar Pawar 


//Enter data in this array for debugging
class process{
    public:

    string jobName;
    int burstTime;
    static int jobCount;

    void setBurst(){
        cout<<"Enter Burst time : ";
        cin >> burstTime;
        jobCount++;
    }
    int getBurst(){
        return burstTime;
    }
    
    
};
int process::jobCount=0;
process plst[100]; // Array to store processes

void data(){
    burstTimeArr[0]=10;
    burstTimeArr[1]=12;
    burstTimeArr[2]=7;
    burstTimeArr[3]=9;
    cout<<"Debug Data taken"<<endl;
}

void mySort(){
   
    for(int a=0;a<sz;a++){
        for (int b=0;b<sz-a-1;b++){
            if (burstTimeArr[b]>burstTimeArr[b+1]){
                swap(burstTimeArr[a],burstTimeArr[a+1]);
            }
            cout<<burstTimeArr[b];
            
        }
    }
    
}


int main(){
    cout<<"Enter number of process : "<<endl;
    int sz;
    cin>> sz; 
    
    data();
    int done=0;
    while (done<sz)
    {
        process p;
        p.setBurst();
        plst[done]=p;
        burstTimeArr[done]= plst[done].getBurst();
        done++;
    }
    mySort();
    done=0;
    while (done<sz){
        cout<< burstTimeArr[done++]<<endl; 
    }
}
