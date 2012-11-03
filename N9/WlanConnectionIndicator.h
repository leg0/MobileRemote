#pragma once
#include <QDeclarativeItem>

class QNetworkConfiguration;
class QNetworkConfigurationManager;

class WlanConnectionIndicator : public QDeclarativeItem
{
    Q_OBJECT
public:
    explicit WlanConnectionIndicator(QDeclarativeItem *parent = 0);
    
    Q_PROPERTY(bool hasConnection READ hasConnection NOTIFY connectionStateChanged)

    bool hasConnection() const
    {
        return hasConnection_;
    }

signals:
    
    void connectionStateChanged(bool isConnected);

private slots:

    void onConfigurationAdded(QNetworkConfiguration const& cfg);
    void onConfigurationChanged(QNetworkConfiguration const& cfg);
    void onConfigurationRemoved(QNetworkConfiguration const& cfg);

private:

    QNetworkConfigurationManager* cfgManager_;
    bool hasConnection_;
};
