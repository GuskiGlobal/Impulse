#include "gui/tracks/TrackWidget.h"

TrackWidget::TrackWidget(TrackModel *model, QWidget *parent)
    : QWidget(parent), trackModel(model)
{
    layout = new QHBoxLayout(this);
    control = new TrackControl(this);
    lane = new TrackLane(model, this);

    layout->addWidget(lane,1);
    layout->addWidget(control);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}
