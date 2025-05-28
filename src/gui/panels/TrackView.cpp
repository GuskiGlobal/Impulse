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

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    trackContainer = new QWidget(scrollArea);
    trackLayout = new QVBoxLayout(trackContainer);
    trackContainer->setLayout(trackLayout);
    scrollArea->setWidget(trackContainer);

    mainLayout->addWidget(scrollArea);

    QPushButton *addTrackButton = new QPushButton("+ Adicionar Faixa", this);
    connect(addTrackButton, &QPushButton::clicked, this, &TrackView::addTrack);
    mainLayout->addWidget(addTrackButton);

    setLayout(mainLayout);

    // Adiciona faixas iniciais
    for (int i = 0; i < 3; ++i) {
        addTrack();
    }
}

void TrackView::addTrack()
{
    auto *trackModel = new TrackModel(this);
    trackModel->name = QString("Track %1").arg(trackLayout->count() + 1);

    auto *trackWidget = new TrackWidget(trackModel, this);
    trackLayout->addWidget(trackWidget);
}

