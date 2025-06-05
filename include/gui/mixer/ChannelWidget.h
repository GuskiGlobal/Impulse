#ifndef CHANNELWIDGET_H
#define CHANNELWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>

#include "gui/mixer/ChannelControl.h"
#include "gui/mixer/ChannelEffects.h"
#include "core/tracks/TrackModel.h"
#include "core/mixer/ChannelModel.h"

class ChannelWidget : public QWidget {
    
    Q_OBJECT

public:
    explicit ChannelWidget(QString trackName, QWidget *parent = nullptr);
    explicit ChannelWidget(ChannelModel *channelModel, QWidget *parent = nullptr);
    void addTrackWidget(QWidget *widget);

    int trackId() const { return model && model->track() ? model->track()->id() : -1; }
    TrackModel* track() const { return model ? model->track() : nullptr; }

    int volume() const { return model ? model->volume() : 0; }
    void setVolume(int value) { if (model) model->setVolume(value); }

    QString name() const { return model ? model->name() : QString(); }
    void setName(const QString &name) { if (model) model->setName(name); }


signals:
    void addTrackRequested();

private:
    QVBoxLayout *channelLayout;
    QLabel *nameLabel;
    QVBoxLayout *volumeLayout;
    QSlider *volumeSlider;
    ChannelControl *channelControl;
    ChannelEffects *channelEffects;
    ChannelModel *model = nullptr;
};

#endif // CHANNELWIDGET_H
