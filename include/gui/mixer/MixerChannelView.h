#ifndef MIXERCHANNELVIEW_H
#define MIXERCHANNELVIEW_H

#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>

#include "core/tracks/TrackModel.h"

class MixerChannelView : public QWidget {
    Q_OBJECT

public:
    explicit MixerChannelView(TrackModel *model, QWidget *parent = nullptr);

private slots:
    void updateFromModel(int value);

private:
    TrackModel *trackModel;
    QSlider *volumeSlider;
    QLabel *nameLabel;
};

#endif // MIXERCHANNELVIEW_H
