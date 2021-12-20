#ifndef WIFINETWORK_H
#define WIFINETWORK_H

#include <QObject>

class WifiNetwork : public QObject
{
    Q_OBJECT
public:
    explicit WifiNetwork(const QString &wifiName, const QString &parkName,
                         const QString &location, const QString &coordinates);
    WifiNetwork(const WifiNetwork &network);
    QString getWifiName() const;
    QString getParkName() const;
    QString getLocation() const;
    QString getCoordinates() const;

private:
    QString wifiName,
            parkName,
            location,
            coordinates;
};

#endif // WIFINETWORK_H
