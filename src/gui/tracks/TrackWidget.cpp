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
    //setMinimumHeight(100);
    setFixedHeight(100);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    control->setMinimumHeight(100);
    control->setMaximumHeight(100);
    //lane->setMinimumHeight(80);
    //lane->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
}
