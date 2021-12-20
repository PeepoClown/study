#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "datadownloader.h"
#include "wifinetwork.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fillTable();
    void fillMap();
    void addScriptToFile(const QString &script) const;

public slots:
    void onDownloadFinished();
    void onDownloadFailed();
    void getData();
    void clearTable();

private:
    Ui::MainWindow *ui;
    DataDownloader *downloader;
    QVector<WifiNetwork> networks;
};
#endif // MAINWINDOW_H
