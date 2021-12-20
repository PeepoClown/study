#include "wifinetwork.h"

WifiNetwork::WifiNetwork(const QString &wifiName, const QString &parkName,
                         const QString &location, const QString &coordinates)
    : wifiName(wifiName)
    , parkName(parkName)
    , location(location)
    , coordinates(coordinates)
{

}

WifiNetwork::WifiNetwork(const WifiNetwork &network)
{
    this->wifiName = network.wifiName;
    this->parkName = network.parkName;
    this->location = network.location;
    this->coordinates = network.coordinates;
}

QString WifiNetwork::getWifiName() const
{
    return wifiName;
}

QString WifiNetwork::getParkName() const
{
    return parkName;
}

QString WifiNetwork::getLocation() const
{
    return location;
}

QString WifiNetwork::getCoordinates() const
{
    return coordinates;
}
