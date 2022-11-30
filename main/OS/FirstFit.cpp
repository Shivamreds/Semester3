#include <iostream>
using namespace std;
 
int main()
{
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
 
    for(i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }
    
    cout<<"Enter no. of blocks: ";
    cin>>bno;
    
    cout<<"\nEnter size of each block: ";
    for(i = 0; i < bno; i++)
        cin>>bsize[i];
 
    cout<<"\nEnter no. of processes: ";
    cin>>pno;
    
    cout<<"\nEnter size of each process: ";
    for(i = 0; i < pno; i++)
        cin>>psize[i];
    for(i = 0; i < pno; i++)         //allocation as per first fit
        for(j = 0; j < bno; j++)
            if(flags[j] == 0 && bsize[j] >= psize[i])
            {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }
    
    //display allocation details
    cout<<"\nBlock no.\tsize\t\tprocess no.\t\tsize";
    for(i = 0; i < bno; i++)
    {
        cout<<"\n"<< i+1<<"\t\t"<<bsize[i]<<"\t\t";
        if(flags[i] == 1)
            cout<<allocation[i]+1<<"\t\t\t"<<psize[allocation[i]];
        else
            cout<<"Not allocated";
    }
    
    return 0;
}



/* OUTPUT
PS D:\ANDC\Sem3\OS> g++ .\FirstFit.cpp  
PS D:\ANDC\Sem3\OS> g++ .\FirstFit.cpp -o FirstFit
PS D:\ANDC\Sem3\OS> .\FirstFit.exe
Enter no. of blocks: 5
Enter size of each block: 100
200
400
500
50
Enter no. of processes: 3
Enter size of each process: 134
232
51
Block no.       size            process no.             size
1               100             3                       51
2               200             1                       134
3               400             2                       232
4               500             Not allocated
5               50              Not allocated
*/
