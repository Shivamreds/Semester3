#include <iostream>

using namespace std;

int main()
{
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];
    cout << "\n\t\t\tMemory Management Scheme - Best Fit";
    cout << "\nEnter the number of blocks:";
    cin >> nb;
    cout << "Enter the number of processes:";
    cin >> np;

    cout << "\nEnter the size of the blocks:-\n";
    for (i = 1; i <= nb; i++)
    {
        cout << "Block no." << i << ":";
        cin >> b[i];
    }

    cout << "\nEnter the size of the processes :-\n";
    for (i = 1; i <= np; i++)
    {
        cout << "Process no. " << i << ":";
        cin >> p[i];
    }

    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (barray[j] != 1)
            {
                temp = b[j] - p[i];
                if (temp >= 0)
                    if (lowest > temp)
                    {
                        parray[i] = j;
                        lowest = temp;
                    }
            }
        }

        fragment[i] = lowest;
        barray[parray[i]] = 1;
        lowest = 10000;
    }

    cout << "\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment";
    for (i = 1; i <= np && parray[i] != 0; i++)
        cout << "\n"<< i << "\t\t" << p[i] << "\t\t" << parray[i] << "\t\t" << b[parray[i]] << "\t\t" << fragment[i];

    return 0;
}

/* OUTPUT
PS D:\ANDC\Sem3\OS> cd "d:\ANDC\Sem3\OS\" ; if ($?) { g++ BestFit.cpp -o BestFit } ; if ($?) { .\BestFit }
                        Memory Management Scheme - Best Fit
Enter the number of blocks:6
Enter the number of processes:4  
Enter the size of the blocks:-
Block no.1:300
Block no.2:500
Block no.3:600
Block no.4:230
Block no.5:102
Block no.6:20
Enter the size of the processes :-
Process no. 1:432
Process no. 2:204
Process no. 3:192
Process no. 4:11
Process_no      Process_size    Block_no        Block_size      Fragment
1               432             2               500             68
2               204             4               230             26
3               192             1               300             108
4               11              6               20              9
*/
