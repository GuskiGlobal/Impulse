#include "gui/mixer/ChannelWidget.h"

ChannelWidget::ChannelWidget(QString trackName, QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    nameLabel = new QLabel(trackName, this);
    nameLabel->setAlignment(Qt::AlignCenter);

    volumeSlider = new QSlider(Qt::Vertical, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(80);
    volumeSlider->setMinimumHeight(150);
    volumeSlider->setMaximumHeight(150);
    volumeLayout = new QVBoxLayout();
    volumeLayout->addWidget(volumeSlider);
    volumeLayout->setAlignment(Qt::AlignCenter);
    volumeLayout->setContentsMargins(0, 0, 0, 0);

    channelControl = new ChannelControl(this);
    channelEffects = new ChannelEffects(this);

    layout->addWidget(nameLabel);
    layout->addWidget(channelEffects);
    layout->addWidget(channelControl);
    layout->addLayout(volumeLayout);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(4, 4, 4, 4);
    layout->setSpacing(4);
    setMinimumWidth(80);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    channelControl->setMinimumHeight(80);
    channelControl->setMaximumHeight(80);
    channelEffects->setMinimumHeight(60);
    setMaximumWidth(80);
    setLayout(layout);
}
