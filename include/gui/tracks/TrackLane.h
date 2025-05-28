#ifndef TRACKLANE_H
#define TRACKLANE_H

#include <QWidget>
#include <QList>

#include "core/tracks/TrackModel.h"
#include "gui/tracks/ClipWidget.h"

class TrackLane : public QWidget {
    Q_OBJECT

public:
    explicit TrackLane(TrackModel *model, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    TrackModel *trackModel;
    QList<ClipWidget*> clipWidgets;
};

#endif // TRACKLANE_H
