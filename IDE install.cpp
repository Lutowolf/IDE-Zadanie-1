#include <fstream>
#include <iostream>

using namespace std;

void ToTheRight(int* arr2, int size2) {
    for (int j = 0; j < size2; j++) {
        int tmp = arr2[j];
        arr2[j] = arr2[size2-1];
        arr2[size2-1] = tmp;
    }
}

void ToTheLeft(int* arr1, int size1) {
    for (int j = 0; j < size1-1; j++) {
        int tmp = arr1[j+1];
        arr1[j+1] = arr1[j];
        arr1[j] = tmp;
    }
}

int main()
{
    int size1;
    ifstream textin("auf.txt");
    textin >> size1;
    int* arr1 = new int[size1] {};
    for (int i = 0; i < size1; i++) {
        textin >> arr1[i];
    }
    ToTheLeft(arr1, size1);
    int size2;
    textin >> size2;
    int* arr2 = new int[size2] {};
    for (int i = 0; i < size2; i++) {
       textin >> arr2[i];
    }
    ToTheRight(arr2, size2);
    ofstream textout("out.txt");
    textout << size2 << endl;
    for (int i = 0; i < size2; i++) {
        textout << arr2[i] << " ";
    }
    textout << endl << size1 << endl;
    for (int i = 0; i < size1; i++) {
        textout << arr1[i] << " ";
    }
    textin.close();
    textout.close();
    delete[] arr1;
    delete[] arr2;
}