#ifndef MULTIRACK_H
#define MULTIRACK_H

#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include "gui/mixer/MixerView.h"

class MultiRack : public QWidget
{
    Q_OBJECT

public:
    explicit MultiRack(QWidget *parent = nullptr);

    void setTracks(const QList<TrackModel *> &tracks);

    void showMixer();
    void showEffects();
    bool isShowingMixer() const;
    bool isShowingEffects() const;

    void addTrackChannel(TrackModel * track);

private:
    QWidget *blankPanel;
    MixerView *mixerPanel;
    QWidget *effectsPanel;
    QStackedWidget *rackStack;
};

#endif // MULTIRACK_H

