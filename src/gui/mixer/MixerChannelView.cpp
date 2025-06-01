#include "gui/mixer/MixerChannelView.h"

MixerChannelView::MixerChannelView(TrackModel *model, QWidget *parent)
    : QWidget(parent), trackModel(model)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    nameLabel = new QLabel(trackModel->name(), this);
    nameLabel->setAlignment(Qt::AlignCenter);

    volumeSlider = new QSlider(Qt::Vertical, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(trackModel->volume());

    layout->addWidget(nameLabel);
    layout->addWidget(volumeSlider);
    setLayout(layout);

    connect(volumeSlider, &QSlider::valueChanged,
            trackModel, &TrackModel::setVolume);

    connect(trackModel, &TrackModel::volumeChanged,
            this, &MixerChannelView::updateFromModel);
}

void MixerChannelView::updateFromModel(int value)
{
    volumeSlider->blockSignals(true);
    volumeSlider->setValue(value);
    volumeSlider->blockSignals(false);
}
