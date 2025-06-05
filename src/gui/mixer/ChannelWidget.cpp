#include "gui/mixer/ChannelWidget.h"

ChannelWidget::ChannelWidget(ChannelModel *channelModel, QWidget *parent)
    : QWidget(parent), model(channelModel)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Nome
    nameLabel = new QLabel(channelModel->name(), this);
    nameLabel->setAlignment(Qt::AlignCenter);

    //connect(channelModel, &ChannelModel::nameChanged, nameLabel, &QLabel::setText);

    // Volume
    volumeSlider = new QSlider(Qt::Vertical, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(channelModel->volume());

    connect(volumeSlider, &QSlider::valueChanged, model, &ChannelModel::setVolume);
    connect(model, &ChannelModel::volumeChanged, volumeSlider, &QSlider::setValue);

    // Layouts
    volumeLayout = new QVBoxLayout();
    volumeLayout->addWidget(volumeSlider);
    volumeLayout->setAlignment(Qt::AlignCenter);
    volumeLayout->setContentsMargins(0, 0, 0, 0);

    // Controles e efeitos
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
    setMaximumWidth(80);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    channelControl->setMinimumHeight(80);
    channelControl->setMaximumHeight(80);
    channelEffects->setMinimumHeight(60);

    setLayout(layout);
}
