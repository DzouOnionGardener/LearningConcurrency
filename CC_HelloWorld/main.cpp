#include <iostream>
#include <thread>
using namespace std;
void helloWorld(){
    cout << "hello world \n";
}
void Greetings(){
    cout << "salutations\n";
}
int main() {
    thread t(helloWorld);
    thread t1(Greetings);
    t1.join();
    t.join();
    return 0;
}