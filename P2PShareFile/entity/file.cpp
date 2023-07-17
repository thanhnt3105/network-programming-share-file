#include "file.h"

quint64 File::getId() const
{
    return id;
}

void File::setId(quint64 newId)
{
    id = newId;
}

QString File::getFileName() const
{
    return fileName;
}

void File::setFileName(const QString &newFileName)
{
    fileName = newFileName;
}

QString File::getFilePath() const
{
    return filePath;
}

void File::setFilePath(const QString &newFilePath)
{
    filePath = newFilePath;
}

User *File::getUser() const
{
    return user;
}

void File::setUser(User *newUser)
{
    user = newUser;
}

File::File(QObject *parent)
    : QObject(parent)
{

}
