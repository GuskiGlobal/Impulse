#include "gui/panels/TrackView.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>

#include "gui/tracks/TrackWidget.h"
#include "core/tracks/TrackModel.h"

TrackView::TrackView(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    trackContainer = new QWidget(scrollArea);
    trackLayout = new QVBoxLayout(trackContainer);
    trackLayout->setContentsMargins(0, 0, 0, 0);
    trackContainer->setLayout(trackLayout);
    scrollArea->setWidget(trackContainer);

    mainLayout->addWidget(scrollArea);

    QPushButton *addTrackButton = new QPushButton("+ Adicionar Faixa", this);
    connect(addTrackButton, &QPushButton::clicked, this, &TrackView::addTrackRequested);
    mainLayout->addWidget(addTrackButton);

    setLayout(mainLayout);

    trackLayout->addStretch();
}

void TrackView::addTrackWidget(QWidget *widget)
{
    if (trackLayout) {
        int index = trackLayout->count() - 1;
        trackLayout->insertWidget(index, widget);
    }
}

