#include <QDialog>
#include <QTableWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QTableWidgetItem>
#include <QHeaderView>

class FileInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileInfoDialog(QJsonArray fileArray, QWidget *parent = nullptr);

private:
    QTableWidget *tableWidget;
};
