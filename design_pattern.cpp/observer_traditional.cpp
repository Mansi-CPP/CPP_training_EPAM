#include<iostream>
#include<mutex>
#include<vector>
#include<string>
using namespace std;

class subscriber;
class channel {
    vector<subscriber*>subscribers;
    string video;
public:
    void addsubscriber(subscriber* name) {
        subscribers.push_back(name);
    }
    void uploadvideo(string vid){
        video = vid;
        notifysubscriber();
    }
    void notifysubscriber();
    const string& getvideo() const{
        return video;
    }
};
class subscriber {
    string name;
public:
    subscriber(string name) {
        this->name = name;
    }
    void subscribe(channel& ch) {
        ch.addsubscriber(this);
    }
    void watchvideo(channel& ch) {
        cout << "watching" << ch.getvideo() << endl;
    }
    const string& getname() const {
        return name;
    }
};
//manually informing each subscriber so if there are 100 then this is a problem
void channel::notifysubscriber() {
    for (auto sub : subscribers) {
        cout << "inform" << sub->getname() << "about new video" << this->getvideo()<<endl;
    }
    //if we need to add new method like send email etc then we need to modify this notify subscriber
    //we need to modift this again and again so becomes inscalable
     // sendEmail(sub);
     // sendSMS(sub);
     // sendPushNotification(sub);
}
//If tomorrow you want to notify via an AppNotifier or DiscordNotifier,
//you must open and modify channel::notifysubscriber() to add this new logic.
//
//That violates OCP, because you're constantly modifying old code rather than 
//just adding new classes or logic elsewhere.
//singl
int main() {
    subscriber user1("Alice");
    subscriber user2("bob");

    channel mychannel;
    user1.subscribe(mychannel);
    user2.subscribe(mychannel);

    mychannel.uploadvideo("C++ basics");
    mychannel.uploadvideo("observer patter");

    return 0;

    

}
