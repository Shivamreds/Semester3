#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

int main() {
    pid_t processID, p;
    char choice;
    cout<<"------------------------\n";
    cout<<"---------MENU-----------\n";
    cout<<"a.Same Program, Same Code\n";
    cout<<"b.Same Program, Different Code\n";
    cout<<"c.Before Terminating, the Parent waits for the child to finish its task\n";
    cout<<"------------------------\n\n";
    cout<<"Enter your choice ???"<<endl;
    cin>>choice;
    switch(choice){
    case 'a':
    
    cout<<"------------------------\n";
    cout<<"Same Program, Same Code\n";
    cout<<"------------------------\n";

    p = fork();
    processID = getpid();

    printf("Output of fork: %d\n", p);
    printf("Process ID: %d\n", processID);
    break;
    
    case 'b':
    p = fork();

    if (p < 0) {
        // error occurred
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (p == 0) {
        // child process
    cout<<"------------------------\n";

    cout<<"Same Program, Different Code\n";
    cout<<"This Process counts numbers in the first 10 natural numbers "<<endl;
    int count=0;
    for(int i=1;i<10;i++){
    count++;
    
    cout<<" "<<count<<" "<<endl;
    }

    cout<<"------------------------\n\n";
  
        
    }
    break;
    case 'c':
    p = fork();
    if (p < 0) {
        // error occurred
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (p == 0) {
        // child process
       cout<<"Child Process"<<endl;
        execlp("/bin/ls","ls",NULL);
    }
  
    else {
        // parent process
        // parent will wait for the child to complete
        wait(NULL);
        cout<<"----------------------------------------------------------------------\n";
        cout<<"Before Terminating, the Parent waits for the child to finish its task\n";
        cout<<"----------------------------------------------------------------------\n";
        cout<<"Child Complete";
    }
    break;
    default:
    cout<<"Default Choice "<<endl;
    break;
    }

    return 0;
}
