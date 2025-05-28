#include "gui/panels/TrackView.h"


TrackView::TrackView(QWidget *parent)
    : QWidget(parent)
{
    setObjectName("trackViewPanel");
    setContentsMargins(0, 0, 0, 0);

    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(4);

    // Adiciona faixas simples diretamente
    for (int i = 0; i < 3; ++i) {
        EmptyTrack *track = new EmptyTrack(this);
        track->setTrackId(QString("Track_%1").arg(i + 1)); // se estiver implementado
        mainLayout->addWidget(track);
    }

    setLayout(mainLayout);
}

