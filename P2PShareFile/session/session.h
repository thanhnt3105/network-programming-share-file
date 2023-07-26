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
    quint16 userId;

public:
    static Session* getInstance();
    QString getUsername() const;
    void setUsername(const QString &newUsername);
    quint16 getUserId() const;
    void setUserId(quint16 newUserId);
};
#endif // SESSION_H
