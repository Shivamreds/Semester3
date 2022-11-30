#include <iostream>
using namespace std;
int main(){
    int time[10]={};
    int p_count=0;
    int tick=0;
    int t_quantum=0;
    cout<<"Enter no of Processes : ";
    cin>>p_count;
    cout<<"Enter Time Quantum : ";
    cin>>t_quantum;
    for(int i = 0; i < p_count; i++)
    {
        cout<<"Enter time for Process "<<i<<endl;
        cin>>time[i];
        tick+=time[i];
    }
    int temp=0;
    int p_curr=0;
    while(temp<tick){
        int b=0;

        for (b;(b<t_quantum) && (time[p_curr]!=0);b++){
            (time[p_curr])--;
            cout<<"|";
            temp++;
        }
        if (time[p_curr]>0){
        cout<<"P"<<(p_curr%p_count)<<endl;
        }
        p_curr++;
        p_curr=p_curr%p_count;
    }
    
    
}
