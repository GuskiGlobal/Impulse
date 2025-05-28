#include "gui/tracks/EmptyTrack.h"


EmptyTrack::EmptyTrack(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *trackLayout = new QHBoxLayout(this);

    dragBar = new QLabel(this);
    dragBar->setFixedWidth(20);
    dragBar->setText("≡");
    dragBar->setAlignment(Qt::AlignCenter);
    dragBar->setObjectName("trackDragBar");
    
    trackLabel = new QLabel("Faixa Vazia", this);
    trackLabel->setObjectName("trackTimelineArea"); //Mudar nome 
    trackControl = new TrackControl(this);
    trackControl->setObjectName("trackControlPanel");
    
    trackLayout->addWidget(trackLabel);    // Timeline
    trackLayout->addWidget(trackControl);  // Painel
    trackLayout->addWidget(dragBar);       // Ícone de drag

    trackLayout->setStretch(0, 4); // dragBar (fixa)
    trackLayout->setStretch(1, 0); // timeline
    trackLayout->setStretch(2, 0); // control (já tem largura fixa)
    setLayout(trackLayout);
}

void EmptyTrack::setTrackId(const QString &id)
{
    trackId = id;
}

QString EmptyTrack::getTrackId() const
{
    return trackId;
}


