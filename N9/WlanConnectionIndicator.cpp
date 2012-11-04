#include "WlanConnectionIndicator.h"

#include <QtNetwork/QNetworkConfiguration>
#include <QtNetwork/QNetworkConfigurationManager>

WlanConnectionIndicator::WlanConnectionIndicator(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
    , hasConnection_(false)
{
    cfgManager_ = new QNetworkConfigurationManager(this);
    connect(cfgManager_, SIGNAL(configurationAdded(QNetworkConfiguration const&)),
            this, SLOT(onConfigurationChanged(QNetworkConfiguration const&)) );
    connect(cfgManager_, SIGNAL(configurationChanged(QNetworkConfiguration const&)),
            this, SLOT(onConfigurationChanged(QNetworkConfiguration const&)) );
    connect(cfgManager_, SIGNAL(configurationRemoved(QNetworkConfiguration const&)),
            this, SLOT(onConfigurationChanged(QNetworkConfiguration const&)) );


    auto cfgs = cfgManager_->allConfigurations(QNetworkConfiguration::Active);
    if (cfgs.empty())
    {
        qDebug() << "No active configurations";
    }
    else
    {
        foreach (auto& cfg, cfgs)
        {
            onConfigurationChanged(cfg);
        }
    }
}

void WlanConnectionIndicator::onConfigurationChanged(QNetworkConfiguration const& cfg)
{
    if (cfg.bearerType() == QNetworkConfiguration::BearerWLAN)
    {
        bool const hadConnection = hasConnection_;
        hasConnection_ = cfg.state() == QNetworkConfiguration::Active;
        if (hadConnection != hasConnection_)
        {
            emit connectionStateChanged(hasConnection_);
        }
    }
}
