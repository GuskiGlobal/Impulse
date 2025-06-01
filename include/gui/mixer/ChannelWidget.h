#ifndef CHANNELWIDGET_H
#define CHANNELWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>

#include "gui/mixer/ChannelControl.h"
#include "gui/mixer/ChannelEffects.h"

class ChannelWidget : public QWidget {
    
    Q_OBJECT

public:
    explicit ChannelWidget(QString trackName, QWidget *parent = nullptr);
    void addTrackWidget(QWidget *widget);

signals:
    void addTrackRequested();

private:
    QVBoxLayout *channelLayout;
    QLabel *nameLabel;
    QVBoxLayout *volumeLayout;
    QSlider *volumeSlider;
    ChannelControl *channelControl;
    ChannelEffects *channelEffects;
};

#endif // CHANNELWIDGET_H
