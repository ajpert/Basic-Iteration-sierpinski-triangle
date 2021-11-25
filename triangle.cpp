#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char*argv[]) {
    
    string file_name;
    cout << "give file name to output to(warning will delete and make new file, input nothing for no file): ";
    getline(cin,file_name);
    ofstream f;
    remove(file_name.c_str());
    f.open(file_name.c_str());

    int arr_size = pow(2,atoi(argv[1]) + 1);
    char arr1[arr_size];
    char arr2[arr_size];
    for(int i = 0; i < arr_size; i++) {
        arr1[i] = ' ';
        arr2[i] = ' ';
    }
    arr1[arr_size/2] = 'A';
    for(int i = 0; i < pow(2,atoi(argv[1])); i++) {
        for(int i = 0; i < arr_size; i++) {
            cout << arr1[i];
            f << arr1[i];
        }
        cout << endl;
        f << endl;
        for(int i = 0; i < arr_size; i++) {
            arr2[i] = arr1[i];
        }
        for(int i = 0; i < arr_size - 1; i++) {
            if(arr2[i] == 'A') {
                if(arr2[i + 2] != 'A' && arr2[i - 2] != 'A') {
                    arr1[i] = ' ';
                    arr1[i-1] = 'A';
                    arr1[i+1] = 'A';
                    i += 2;
                }
                else if(arr2[i + 2] == 'A' && arr2[i - 2] == 'A') {
                    arr1[i] = ' ';
                }
                else if(arr2[i + 2] == 'A') {
                    arr1[i-1] = 'A';
                    arr1[i] = ' ';
                }
                else if(arr2[i-2] == 'A') {
                    arr1[i+1] = 'A';
                    arr1[i] = ' ';
                    i++;
                }
            }
        }
    }
}
