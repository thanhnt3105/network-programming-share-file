#include "fileinfodialog.h"

FileInfoDialog::FileInfoDialog(QJsonArray fileArray, QWidget *parent)
    : QDialog(parent)
{
    // Khởi tạo QTableWidget
    tableWidget = new QTableWidget(fileArray.size(), 2, this);
    tableWidget->setHorizontalHeaderLabels({"File Name", "File Path"});

    for (int i = 0; i < fileArray.size(); ++i)
    {
        QJsonObject fileDataObject = fileArray.at(i).toObject();
        QString fileName = fileDataObject.value("file_name").toString();
        QString filePath = fileDataObject.value("file_path").toString();

        QTableWidgetItem *fileNameItem = new QTableWidgetItem(fileName);
        QTableWidgetItem *filePathItem = new QTableWidgetItem(filePath);

        tableWidget->setItem(i, 0, fileNameItem);
        tableWidget->setItem(i, 1, filePathItem);
    }

    // Hiển thị cửa sổ QDialog
    setWindowTitle("File Information");
    resize(400, 300);
    tableWidget->resize(400, 300);
}
