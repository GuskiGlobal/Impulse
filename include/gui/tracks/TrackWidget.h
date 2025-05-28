#ifndef TRACKWIDGET_H
#define TRACKWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

#include "gui/tracks/TrackControl.h"
#include "gui/tracks/TrackLane.h"
#include "core/tracks/TrackModel.h"

class TrackWidget : public QWidget {
    Q_OBJECT

public:
    explicit TrackWidget(TrackModel *model, QWidget *parent = nullptr);

private:
    QHBoxLayout *layout;
    TrackControl *control;
    TrackLane *lane;
    TrackModel *trackModel;
};

#endif // TRACKWIDGET_H
