#include <iostream>
#include <string.h>
using namespace std;

int main(int argc , char * argv[]){
  
    char arr[200]=" ";

    strcat(arr," ls -l ");
    strcat(arr, argv[1]);
    strcat(arr,"| awk ' {print$1,$8} '");
    system(arr);
    return 0;
}


/* OUTPUT
avi@avi-Vostro-3490:~/Documents/Sem3/OS$ ./4FileInfo a.txt
-rw-rw-r-- 00:14
*/
