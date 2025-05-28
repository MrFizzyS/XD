#include<iostream>
#include<string>
using namespace std;

class notification
{
    protected:
    string message;
    string text;

    public:
    notification(string msg, string txt) : message(msg), text(txt) {}
    virtual void show() const = 0;  
};

class importantnotif : public notification 
{
    string importance;
    void(*extraction)();
    public:
    importantnotif(string msg, string txt, string imp) : notification(msg, txt), importance(imp) {}

    void setextraction(void(*action)()) 
    {
        extraction = action;
    }


    void show() const override {
        cout<<"Важливе повідомлення: "<<message<<endl;
        cout<<"Повідомлення: "<<message<<endl;
        cout<<"текст: "<<text<<endl;
        if(importance == "high" && extraction) {
            extraction();
        }
    }
};

int main(){
    importantnotif notification("Увага","це важливе повідомлення","high");

    notification.setextraction([]() {
        cout<<"Потрібне підтвердження."<<endl;
    });
    notification.show();
    return 0;
}