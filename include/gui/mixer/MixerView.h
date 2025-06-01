#ifndef MIXERVIEW_H
#define MIXERVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>
#include <QPushButton>
#include <QScrollArea>

#include "core/tracks/TrackModel.h"
#include "core/SessionController.h"
#include "gui/mixer/ChannelWidget.h"

class SessionController;
class TrackModel;
class ChannelWidget;

class MixerView : public QWidget {
    Q_OBJECT

public:
    explicit MixerView(QWidget *parent = nullptr);
    void bindToSession(SessionController *session);

signals:
    void requestNewTrack();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *layout;
    QScrollArea *scrollArea;
    QWidget *containerWidget;
    QList<ChannelWidget *> channelWidgets;
    QPushButton *addChannelButton;
    SessionController *session;

    void createAddButton();
    void addChannel(TrackModel *track);
};

#endif // MIXERVIEW_H
