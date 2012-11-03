#include "WlanConnectionIndicator.h"

#include <QtNetwork/QNetworkConfiguration>
#include <QtNetwork/QNetworkConfigurationManager>

WlanConnectionIndicator::WlanConnectionIndicator(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
    , hasConnection_(false)
{
    cfgManager_ = new QNetworkConfigurationManager(this);
    connect(cfgManager_, SIGNAL(configurationAdded(QNetworkConfiguration const&)),
            this, SLOT(onConfigurationAdded(QNetworkConfiguration const&)) );
    connect(cfgManager_, SIGNAL(configurationChanged(QNetworkConfiguration const&)),
            this, SLOT(onConfigurationChanged(QNetworkConfiguration const&)) );
    connect(cfgManager_, SIGNAL(configurationRemoved(QNetworkConfiguration const&)),
            this, SLOT(onConfigurationRemoved(QNetworkConfiguration const&)) );


    auto cfgs = cfgManager_->allConfigurations(QNetworkConfiguration::Active);
    if (cfgs.empty())
    {
        qDebug() << "No active configurations";
    }
    else
    {

        for (auto it = cfgs.begin(); it != cfgs.end(); ++it)
        {
            QNetworkConfiguration& cfg = *it;
            qDebug() << "Bearer: " << cfg.bearerTypeName() << cfg.bearerType();
            qDebug() << "Name: " << cfg.name();
            if (cfg.bearerType() == QNetworkConfiguration::BearerWLAN
                    && cfg.state() == QNetworkConfiguration::Active)
            {
                qDebug() << "=== Got a connection!";
                hasConnection_ = true;
            }
            qDebug() << "==";
        }
    }
}

void WlanConnectionIndicator::onConfigurationAdded(QNetworkConfiguration const& cfg)
{
    if (!hasConnection())
    {
        if (cfg.bearerType() == QNetworkConfiguration::BearerWLAN
                && cfg.state() == QNetworkConfiguration::Active)
        {
            hasConnection_ = true;
            emit connectionStateChanged(hasConnection_);
        }
    }
}

void WlanConnectionIndicator::onConfigurationChanged(QNetworkConfiguration const& cfg)
{
    qDebug() << "conf changed: " << cfg.name()
             << "Bearer: " << cfg.bearerTypeName()
             << "state: " << cfg.state();
    if (cfg.bearerType() == QNetworkConfiguration::BearerWLAN)
    {
        hasConnection_ = cfg.state() == QNetworkConfiguration::Active;
        emit connectionStateChanged(hasConnection_);
    }
}

void WlanConnectionIndicator::onConfigurationRemoved(QNetworkConfiguration const& cfg)
{
    if (hasConnection())
    {
        if (cfg.bearerType() == QNetworkConfiguration::BearerWLAN)
        {
            hasConnection_ = false;
            emit connectionStateChanged(hasConnection_);
        }
    }
}
