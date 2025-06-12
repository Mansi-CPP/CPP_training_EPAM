#include<iostream>
#include<mutex>
#include<vector>
#include<string>
using namespace std;

//observer interface
class subscriber {
public:
    virtual void update(string video) = 0;
    virtual ~subscriber()=default;

};
//concrete observer
class email_sub: public subscriber {
    string email;
public:
    email_sub(string name):email(name){}
    void update(string video) override {
        cout << "sent email" << this->email << "about" << video << endl;
    }
};
class sms_sub : public subscriber {
    string sms;
public:
    sms_sub(string name) :sms(name) {}
    void update(string video) override {
        cout << "sent sms" << this->sms<< "about" << video << endl;
    }
};
class app_sub : public subscriber {
    string n;
public:
    app_sub(string name) :n(name) {}
    void update(string video) override {
        cout << "sent app" << this->n<< "about" << video << endl;
    }
};
//subject interface
class channel {
public:
   virtual void addsubscriber(subscriber* name)=0;
   virtual void uploadvideo(string vid)=0;
   virtual void notifysubscriber()=0;
   virtual ~channel() = default;
};

class mychannel :public channel {
private:
    vector<subscriber*>subscribers;
    string video;
public:
    void addsubscriber(subscriber* name) override {
        subscribers.push_back(name);
    }
    void uploadvideo(string vid) override {
        video = vid;
        notifysubscriber();
    }
    void notifysubscriber() override {
        for (auto sub : subscribers) {
            sub->update(video);
        }
    }
};

int main() {
    email_sub user1("Alice");
    sms_sub user2("Mansi");
    app_sub user3("Bob");
    
    mychannel CPP_basics;
    CPP_basics.addsubscriber(&user1);
    CPP_basics.addsubscriber(&user2);
    CPP_basics.addsubscriber(&user3);
    CPP_basics.uploadvideo("observer_pattern");

    return 0;

    

}
