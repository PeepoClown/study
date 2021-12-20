#include "datadownloader.h"

DataDownloader::DataDownloader(const QUrl &url, QObject *parent)
    : QObject(parent)
    , url(url)
    , manager(new QNetworkAccessManager())
    , data(new QByteArray(""))
{
    connect(manager, &QNetworkAccessManager::finished,
            this, &DataDownloader::onReady);
}

DataDownloader::~DataDownloader()
{
    delete manager;
    delete data;
}

void DataDownloader::initRequest() const
{
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void DataDownloader::onReady(QNetworkReply *reply)
{
    if (reply->error())
        emit downloadFailed();
    else
    {
        data = new QByteArray(reply->readAll());
        emit downloadFinished();
    }
}

QByteArray DataDownloader::getData() const
{
    return *data;
}
