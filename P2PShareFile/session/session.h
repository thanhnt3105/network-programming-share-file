#ifndef SESSION_H
#define SESSION_H

#include <string>
#include<QVector>

class Session
{
private:
    static Session* instance;
    Session();
    QString username;

public:
    static Session* getInstance();
    QString getUsername() const;
    void setUsername(const QString &newUsername);
};
#endif // SESSION_H
