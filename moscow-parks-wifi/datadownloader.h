#ifndef DATADOWNLOADER_H
#define DATADOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class DataDownloader : public QObject
{
    Q_OBJECT
public:
    explicit DataDownloader(const QUrl &url, QObject *parent = nullptr);
    virtual ~DataDownloader();
    void initRequest() const;
    QByteArray getData() const;

signals:
    void downloadFinished();
    void downloadFailed();

public slots:
    void onReady(QNetworkReply *reply);

private:
    QUrl url;
    QNetworkAccessManager *manager;
    QByteArray *data;
};

#endif // DATADOWNLOADER_H
