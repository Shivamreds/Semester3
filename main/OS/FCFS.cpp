#include <iostream>
using namespace std;


int waitArr[100],turnAroundArr[100];
float avgTime(int waitArr[],int jobCount){
    float sum=0;
    for (int a=0;a<jobCount;a++){
        sum+=waitArr[a];
    }
    return sum/jobCount;
}

void print(int  burstTime[],int jobCount ){
    for (int a=0;a<jobCount; a++){
        for (int b=0;b<burstTime[a];b++){
            cout<<"|"<<flush;
        }
        cout<<" "<<flush;
    }
    cout<<endl;
    for (int c=0;c<jobCount;c++){
        int pos=(burstTime[c])/2;
        for (int d=0;d<pos;d++){
            cout<<" "<<flush;
        }
        cout<<c+1<<" "<<flush;
        for (int d=0;d<pos;d++){
            cout<<" "<<flush;
        }
    }
    cout<<endl;
}


void waitingTime(int burstTime[],int jobCount){
    waitArr[0]=0;
    for (int a=1;a<jobCount;a++){
            int time=0;
            
        for (int b=0;b<a;b++){
            time+=burstTime[b];
        }
        waitArr[a]=time;
    }
    
}
void turnAroundTime(int burstTime[],int jobCount){
    for (int a=0;a<jobCount;a++){
        turnAroundArr[a]=waitArr[a]+burstTime[a];
    }
}
void table(int burstTime[], int jobCount){
    cout<<"Process Duration Wait_Time Turn_Around_Time"<<endl;
    for(int a=0;a<jobCount;a++){
        cout<<"    "<<a+1<<"        "<<burstTime[a]<<"       "<<waitArr[a]<<"     " <<turnAroundArr[a]<<endl;
    }
}
void init(int burstTime[],int jobCount){
    waitingTime(burstTime,jobCount);
    turnAroundTime(burstTime,jobCount);
}
int main(){
    int jobCount;
    cout<<"Enter number of Jobs : ";
    cin>>jobCount;
    int  burstTime[jobCount];
  
    for (int a=0;a<jobCount;a++){
        cout<<"Enter burst time for Process "<<a+1<<" : "<<endl;
        cin>>burstTime[a];
    }
    init(burstTime,jobCount);

    cout<<"\nAverage Waiting Time : "<<avgTime(waitArr,jobCount)<<endl;
    cout<<"Average TurnAroundTime : "<<avgTime(turnAroundArr,jobCount)<<endl;
    print(burstTime,jobCount);
    table(burstTime,jobCount);


}


/*
Enter number of Jobs : 4
Enter burst time for Process 1 : 
3
Enter burst time for Process 2 : 
6
Enter burst time for Process 3 : 
9
Enter burst time for Process 4 : 
1
Average Waiting Time : 7.5
Average TurnAroundTime : 12.25
Process Duration Wait_Time Turn_Around_Time
    1        3       0     3
    2        6       3     9
    3        9       9     18
    4        1       18    19
*/
