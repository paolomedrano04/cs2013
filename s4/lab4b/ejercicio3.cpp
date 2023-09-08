 #include <iostream>

using namespace std;

template<typename...Ts>
float suma_alternada(Ts... args){
    return (args-...);
}


int main(){
    cout << suma_alternada(1) << endl;
    // 1
    cout << suma_alternada(3,4) << endl;
    // 3-4= -1
    cout << suma_alternada(1,2,3,4,5) << endl;
    // 1-2+3-4+5=3
    cout << suma_alternada(4,4,5,6) << endl;
    // 4op(4op(5op6))
    return 0;
}
