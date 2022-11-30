#include <iostream>
using namespace std;

int main(){
    
    system("echo Total Memory : && cat /proc/meminfo | awk ' {if(NR==1) a=$2} END {print a} ' ");

    system("echo Available Memory : && cat /proc/meminfo | awk ' {if (NR==3) b=$2} END {print b} ' ");
    
    system("echo Used Memory : && cat /proc/meminfo | awk ' {if(NR==1) a=$2;if (NR==3) b=$2} END {print a-b} ' ");
    
}

/*
Total Memory :
7993888
Available Memory :
4095852
Used Memory :
3898036
*/
