#include<iostream>
#include<mutex>
using namespace std;
//
//class singleton {
//private:
//    static singleton* instance;
//    singleton() {
//        cout << "singelton const" << endl;
//    }
//    //delete assignment operator and copy const
//    singleton(const singleton&) = delete;
//    singleton operator=(const singleton) = delete;
//public:
//    //to get the single instance
//    // static so that we can access it without creating an object of this class 
//    //which is the sole purpose so that we do have a single instance.Static will b
//    static singleton* get_instance(){
//        //create instance only if not exist
//
//        if (!instance) {
//            instance = new singleton();
//        }
//        return instance;
//    }
//    void showMessage() {
//        std::cout << "Hello from Singleton!\n";
//    }
//
//};
//singleton* singleton::instance = nullptr;
//thread safe
//if three thread A,B,C access at same time and A enters first it locks the other untill they execute

//class singleton {
//private:
//    static singleton* instance;
//    static mutex m;
//    singleton() {
//        cout << "singelton const" << endl;
//    }
//    //delete assignment operator and copy const
//    singleton(const singleton&) = delete;
//    singleton operator=(const singleton) = delete;
//public:
//   
//    static singleton* get_instance() {
//        //create instance only if not exist
//        //lock until this thread releases
//        // this is ineefficient as unnecessarily thread wait for entire duration
//        //the can directly got to  return instance; and get instance at same time
//        /*lock_guard<mutex> lock(m);
//        if (!instance) {
//            instance = new singleton();
//        }
//        return instance;*/
//        //so instead use double check
//        // we do not lock here lock_guard<mutex> lock(m);
//        if (!instance) {
//            lock_guard<mutex> lock(m);
//            if (!instance) {       //double check to ensure that if suppose three thread A b c are there
//                                   // a already created instance now when b is released by mtex
//                                   // if this second check not present it will create another instance
//                                    //irrespective of the fact that instance is already created
//                instance = new singleton();
//            }
//        }
//        return instance;
//    }
//    void showMessage() {
//        std::cout << "Hello from Singleton!\n";
//    }
//
//};
//singleton* singleton::instance = nullptr;
//mutex singleton::m;
// this is complex

class singleton {
private:
    //static singleton* instance; we do not create a variable here
    singleton() {
        cout << "singelton const" << endl;
    }
    //delete assignment operator and copy const
    singleton(const singleton&) = delete;
    singleton operator=(const singleton) = delete;
public:
    // this belongs to the class not object so 
   /* That means the compiler will automatically ensure that only one thread initializes the variable,
        even if multiple threads call the function at the same time.*/
    static singleton* get_instance(){
        static singleton* instance;
        return instance;
    }
    void showMessage() {
        std::cout << "Hello from Singleton!\n";
    }

};
void accessSingleton() {
    singleton& s = *singleton::get_instance();
    s.showMessage();
}
int main() {
  // Singleton& s1 = Singleton::getInstance();
  //   s1.showMessage();

  //   Singleton& s2 = Singleton::getInstance();
  //   std::cout << "Same instance? " << (&s1 == &s2) << std::endl;
    std::thread t1(accessSingleton);
    std::thread t2(accessSingleton);
    std::thread t3(accessSingleton);

    t1.join();
    t2.join();
    t3.join();

    return 0;

    

}
