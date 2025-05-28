#include "gui/tracks/TrackLane.h"

#include <QPainter>

TrackLane::TrackLane(TrackModel *model, QWidget *parent)
    : QWidget(parent), trackModel(model)
{
    setMinimumHeight(60);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void TrackLane::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(rect(), QColor("#EEEEEE"));
}
