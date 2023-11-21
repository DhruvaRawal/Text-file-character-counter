#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstring>
#define MAX_FILE_NAME 100

using namespace std;

int main()
{
    int count = 0;

    char filename[MAX_FILE_NAME +1];
    fill_n(filename, MAX_FILE_NAME, 0);
    char c;

 printf("Enter file name: ");
  (void) fgets(filename, MAX_FILE_NAME, stdin);
    filename[strcspn(filename, "\n")] = 0;

    ifstream in(filename);
    in.unsetf(ifstream::skipws);

if (in.fail()) {
        cerr << strerror(errno) << endl;
        return 0;
    }

while (!in.eof()) {
        if (in.peek() == '$') {
            break;
        }
        in >> c;
        ++count;
    }

  cout<<"The file " << filename << " has " << count << " characters\n";
  
    return 0;
}