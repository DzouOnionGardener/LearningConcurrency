#include <iostream>
#include <thread>
using namespace std;

class background_task{
public:
    void operator() () {
        add_numbers();
        printMessage();
    }
    void add_numbers(){
        int sum = 0;
        for(int i = 0; i < 10; i++){
            sum += i;
        }
        cout << "sum : " << sum << endl;
    }
    void printMessage(){
        cout << "hello world\n";
    }
};

struct func{
    int& i;
    func(int& i): i(i){};
    void operator() () {
        unsigned k;
        for(unsigned j = 0; j < 1000; ++j){
            k = sum(i);
        }
        cout << k << endl;
    }
    unsigned sum(unsigned n){
        unsigned sum;
        sum += n;

        return sum;
    }
};

void oops(){
    int state = 1;
    func my_func(state);
    thread my_thread(my_func);
    //my_thread.detach(); //oops function ends w/o waiting for thread to finish
    //my_thread.join();
    if(my_thread.joinable()){
        my_thread.join();
    }
    if (!my_thread.joinable()){
        my_thread.detach();
    }
}
int main() {
    //method 1
    background_task f;
    thread t(f); //object is copied to the thread
    t.join();

    // method 2
    thread t1((background_task()));
    t1.join();
    //method 3
    thread t2{background_task()};
    t2.join();
    //methods 2 and 3 both create a variable for each declaration

    oops();

    return 0;
}
/*
 * "Every c++ program has at least 1 thread, which is started by the c++ runtime:
 * the thread running main(). Your program can then launch additional threads that have another function
 * as the entry point. These threads then run concurrently with each other and which the initial thread.
 * Just as the program exits when the program returns from main(), when the specified entry point function
 * returns, the thread exits. As you'll see, if you have std::thread object fir a thread, you can wait for
 * it to finish but first you have to start it."
 */