#include "filecontroller.h"

File *FileController::getFile() const
{
    return file;
}

void FileController::setFile(File *newFile)
{
    file = newFile;
}

QList<File *> FileController::getFileList() const
{
    return fileList;
}

void FileController::setFileList(const QList<File *> &newFileList)
{
    fileList = newFileList;
}

FileController::FileController(QObject *parent)
    : QObject{parent}
{
    this->fileQuery = new FileQuery();
}

QString FileController::getAllFiles()
{
    this->fileQuery->getAllFiles();
    return "get files successfully";
}

QString FileController::searchFileByName(QString fileName)
{
    QList<File*> fileList = this->fileQuery->getAllFileByName(fileName);

    if (fileList.isEmpty()) {
        qDebug() << "file not found";
        return "file not found";
    } else {
        this->setFileList(fileList);
        for (File* file : fileList) {
            qDebug() << "File ID: " << file->getId();
            qDebug() << "File Name: " << file->getFileName();
            qDebug() << "File Path: " << file->getFilePath();
            qDebug() << "User ID: " << file->getUser()->getId();
            qDebug() << "Username: " << file->getUser()->getUsername();
            qDebug() << "-----------------------";
        }
        return "file found";
    }
}

QString FileController::uploadFile(QString fileName, QString filePath, quint64 userId)
{
    this->fileQuery->saveFileByUserId(userId,fileName,filePath);
    return "save file successfully";
}



