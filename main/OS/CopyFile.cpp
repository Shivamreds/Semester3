#include <iostream>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
using namespace std;


int main(int argc , char ** argv){
    char arr[200000];
    int n;
    int f1 = open(argv[1], O_RDONLY);
    int f2 = open(argv[2], O_WRONLY | O_CREAT);

    if (f1 < 0)
        cout<<"\nSource File cannot be opened.\n";

    if (f2 < 0)
        cout<<"\nTarget File cannot be opened/created.\n";

    while ((n = read(f1, arr, 100)) > 0)
        write(f2, arr, n);

    write(f2, "\0", 1);

    if (n < 0)
        cout<<"\nFile could not read the content.\n";

    close(f1);
    close(f2);

    return 0;
}

//ANOTHER METHOD


/*OUTPUT
avi@avi-Vostro-3490:~/Documents/Sem3/OS$ g++ 5CopyFile.cpp -o 5CopyFile
avi@avi-Vostro-3490:~/Documents/Sem3/OS$ ./5CopyFile a.txt b.txt
*/


// int main(int argc , char ** argv){
//     string copyFrom= argv[1];   
//     string copyTo=argv[2];

//     char arr[200]=" ";

//     strcat(arr,"cd ~/Desktop  && ");
//     strcat(arr, "cp ");
//     strcat(arr,copyFrom.c_str());
//     strcat(arr," ");
//     strcat(arr,copyTo.c_str());
    
//     strcat(arr,";echo File1 && cat ");
//     strcat(arr,copyFrom.c_str());
//     strcat(arr," && echo ------------- && echo File2 && cat ");
//     strcat( arr,copyTo.c_str());
//     system(arr);
// }

/* OUTPUT
avi@avi-Vostro-3490:~/Documents/Sem3/OS$ g++ 5CopyFile.cpp -o 5CopyFile
avi@avi-Vostro-3490:~/Documents/Sem3/OS$ ./5CopyFile 1.txt 2.txt
File1
hello
gia
Hello Boss
Hello Boss
-------------
File2
hello
gia
Hello Boss
Hello Boss
*/
