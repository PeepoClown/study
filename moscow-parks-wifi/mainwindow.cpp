#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , downloader(new DataDownloader(QUrl("https://data.gov.ru/opendata/7710878000-wifi/data-20191015T0100.json?encoding=UTF-8")))
{
    ui->setupUi(this);
    ui->map->load(QUrl("file:" + QDir::currentPath() + "/index.html"));

    connect(downloader, &DataDownloader::downloadFinished,
            this, &MainWindow::onDownloadFinished);
    connect(downloader, &DataDownloader::downloadFailed,
            this, &MainWindow::onDownloadFailed);
    connect(ui->searchButton, &QPushButton::clicked,
            this, &MainWindow::getData);
    connect(ui->clearButton, &QPushButton::clicked,
            this, &MainWindow::clearTable);
}

MainWindow::~MainWindow()
{
    QFile file(QDir::currentPath() + "/_index.html");
    file.remove();

    delete ui;
    delete downloader;
}

void MainWindow::getData()
{
    downloader->initRequest();
}

void MainWindow::onDownloadFinished()
{
    QString selector = ui->selector->text().toLower();
    networks.clear();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(downloader->getData());
    QJsonArray jsonArray = jsonDocument.array();
    for (const auto &elem : jsonArray)
    {
        if (elem.toObject().value("ParkName").toString().toLower().contains(selector))
            networks.push_back(WifiNetwork(
                              elem.toObject().value("Name").toString(),
                              elem.toObject().value("ParkName").toString(),
                              elem.toObject().value("AdmArea").toString()
                              +
                              elem.toObject().value("District").toString(),
                              elem.toObject().value("Latitude_WGS84").toString()
                              + "," +
                              elem.toObject().value("Longitude_WGS84").toString()
                              ));
    }

    QMessageBox msgBox(QMessageBox::Icon::Information, "Download", "Download finished.");
    msgBox.exec();

    fillTable();

    fillMap();
}

void MainWindow::onDownloadFailed()
{
    QMessageBox msgBox(QMessageBox::Icon::Critical, "Download", "Download failed.");
    msgBox.exec();
}

void MainWindow::fillTable()
{
    ui->table->clear();
    ui->table->setRowCount(networks.size());
    ui->table->setColumnCount(4);
    ui->table->setHorizontalHeaderLabels(QStringList() << "Wi-fi name" << "Park name"
                                         << "Location" << "Coordinates");

    int currentRow = 0;
    for (const auto &elem : networks)
    {
        int currentColumn = 0;
        while (currentColumn < 4)
        {
            QTableWidgetItem *tableItem = new QTableWidgetItem("");
            switch (currentColumn)
            {
                case 0 :
                {
                    tableItem->setText(elem.getWifiName());
                    ui->table->setItem(currentRow, currentColumn, tableItem);
                    break;
                }
                case 1 :
                {
                    tableItem->setText(elem.getParkName());
                    ui->table->setItem(currentRow, currentColumn, tableItem);
                    break;
                }
                case 2 :
                {
                    tableItem->setText(elem.getLocation());
                    ui->table->setItem(currentRow, currentColumn, tableItem);
                    break;
                }
                case 3 :
                {
                    tableItem->setText(elem.getCoordinates());
                    ui->table->setItem(currentRow, currentColumn, tableItem);
                    break;
                }
            }
            currentColumn++;
        }
        currentRow++;
    }
}

void MainWindow::clearTable()
{
    ui->selector->clear();
    ui->table->clear();
    ui->table->setRowCount(0);
    ui->map->load(QUrl("file:" + QDir::currentPath() + "/index.html"));
}

void MainWindow::fillMap()
{
    QStringList script;
    int counter = 0;
    script << "var markers = [];";
    for (const auto &elem : networks)
    {
        script << "markers[" + QString::number(counter) + "] = new google.maps.Marker({"
               << "\tposition: new google.maps.LatLng(" + elem.getCoordinates() + "),"
               << "\tmap: map"
               << "});"
               << "markers[" + QString::number(counter) + "].addListener('click', function() {"
               << "\tmap.setZoom(15);"
               << "\tmap.setCenter(markers[" + QString::number(counter) + "].getPosition());"
               << "\tdocument.getElementById('wifiName').innerHTML = '" + elem.getWifiName() + "';"
               << "\tdocument.getElementById('parkName').innerHTML = '" + elem.getParkName() + "';"
               << "\tdocument.getElementById('location').innerHTML = '" + elem.getLocation() + "';"
               << "\tdocument.getElementById('coordinates').innerHTML = '" + elem.getCoordinates() + "';"
               << "});";
        counter++;
    }
    addScriptToFile(script.join("\n"));
    ui->map->setUrl(QUrl("file:" + QDir::currentPath() + "/_index.html"));
}

void MainWindow::addScriptToFile(const QString &script) const
{
    QFile file(QDir::currentPath() + "/index.html");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    QString htmlData = in.readAll();
    file.close();

    htmlData = htmlData.mid(0, htmlData.lastIndexOf('}'));
    htmlData += script;
    htmlData += "\n}\n</script>\n</body>\n</html>\n";

    QFile _file(QDir::currentPath() + "/_index.html");
    if (!_file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&_file);
    out << htmlData;
    _file.close();
}
