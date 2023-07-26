#include <session/session.h>


Session* Session::instance = nullptr;
Session::Session(){

}

QString Session::getUsername() const
{
    return username;
}

void Session::setUsername(const QString &newUsername)
{
    username = newUsername;
}

Session* Session::getInstance(){
    if(instance == nullptr){
        instance = new Session();
    }
    return instance;
}
