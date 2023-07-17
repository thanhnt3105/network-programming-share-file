#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <entity/user.h>

class File : public QObject
{
    Q_OBJECT

private:
    quint64 id;
    QString fileName;
    QString filePath;
    User* user;


public:
    explicit File(QObject *parent = nullptr);
    quint64 getId() const;
    void setId(quint64 newId);

    QString getFileName() const;
    void setFileName(const QString &newFileName);

    QString getFilePath() const;
    void setFilePath(const QString &newFilePath);

    User *getUser() const;
    void setUser(User *newUser);

signals:

};

#endif // FILE_H
