#include <iostream>
using namespace std;


// cat /proc/sys/kernel/osrelease

int main(){
    cout<<"Kernel Version : "<<flush;
    system("cat /proc/sys/kernel/osrelease");
    system("cat /proc/cpuinfo | awk 'NR==4 {print}' ");
    cout<<"CPU type : "<<flush;
    system("cat /proc/cpuinfo | awk 'NR==5 {print $4 $5 $6 $8 $9 }' ");
    
}


/*  OUTPUT
Kernel Version : 5.4.0-125-generic
model           : 142
CPU type : Intel(R)Core(TM)i3-10110U@2.10GHz
*/
