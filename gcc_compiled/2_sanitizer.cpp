#include <iostream>
#include <vector>

using namespace std;

const string& makeString() {
    vector<string> v { "c++", "python" };
    return v[0];
}

int main() {
    //sanitizer helps to 
    //1 identify wrong memory access
    //2 accessing freed memory
    //3 identify memory leaks

    const string& ref = makeString();
    cout << ref << endl;

    return 0;
}

