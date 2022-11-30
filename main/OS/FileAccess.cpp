#include <iostream>
#include <sys/stat.h>
using namespace std;



int main(int argc,char * argv[]){
   struct stat s1;
   if (stat(argv[1],&s1)==0){
      
      cout<<"User id : "<<s1.st_uid<<endl;
      cout<<"File Mode : "<<s1.st_mode<<endl;
      cout<<"Size of File in bytes : "<<s1.st_size<<endl;
      cout<<"Access Time : "<<(s1.st_atime)<<endl;
      cout<<"Block size for I/O : "<<s1.st_blksize<<endl;
    
   }
   else{
     cout<<"Error";
   }
    
}


/*OUTPUT
avi@avi-Vostro-3490:~/Documents/Sem3/OS$ g++ fileAccess.cpp -o fileAccess
avi@avi-Vostro-3490:~/Documents/Sem3/OS$ ./fileAccess a.txt
User id : 1000
File Mode : 33204
Size of File in bytes : 20
Access Time : 1663003278
Block size for I/O : 4096
*/
