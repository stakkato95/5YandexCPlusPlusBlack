//#define _GLIBCXX_DEBUG
//#define _GLIBCXX_DEBUG_PEDANTIC

#include <iostream>
#include <vector>

using namespace std;

int main() {
    //goal - find logical 'out of range' errors, which appear only at runtime
    vector<int> v { 8 };
    v.reserve(2);

    //vector owns the memory at index 1 (but there is currently no value there)
    //application does not crash
    size_t i = 1;
    cout << v[i] << endl;
    
    //enable 'out of range' check at the preprocessing stage with macro definitions
    //(aka debug defines)
    //Solution 1:
    //g++ 1_debugging_macro.cpp -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
    //Solution 2:
    //uncomment two defines at the beginning of the file

    //!!!IMPORTANT!!!
    //Debug defines work only with c++ standard library
    //if you develop your won library - use sanithizer
    return 0;
}

