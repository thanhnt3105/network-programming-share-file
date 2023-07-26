#include <session/session.h>


Session* Session::instance = nullptr;
Session::Session(){

}

quint16 Session::getUserId() const
{
    return userId;
}

void Session::setUserId(quint16 newUserId)
{
    userId = newUserId;
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
