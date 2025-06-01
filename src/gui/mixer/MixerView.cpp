#include "gui/mixer/MixerView.h"


MixerView::MixerView(QWidget *parent)
    : QWidget(parent), session(nullptr)
{
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    containerWidget = new QWidget(scrollArea);
    layout = new QHBoxLayout(containerWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(4);
    layout->addStretch();

    containerWidget->setLayout(layout);
    scrollArea->setWidget(containerWidget);
    mainLayout->addWidget(scrollArea);

    //createAddButton();

    setLayout(mainLayout);

    
}

void MixerView::createAddButton()
{
    addChannelButton = new QPushButton("+", this);
    addChannelButton->setFixedSize(30, 100);
    connect(addChannelButton, &QPushButton::clicked, this, [=]() {
        emit requestNewTrack(); // SessionController escuta e cria nova faixa
    });
    layout->addWidget(addChannelButton);
}

void MixerView::bindToSession(SessionController *sessionController)
{
    session = sessionController;

    // conecta ao sinal de faixa criada
    connect(session, &SessionController::trackAdded, this, [=](TrackModel *track) {
        addChannel(track);
    });

    // inicializa com as faixas já existentes
    for (TrackModel *track : session->getTracks()) {
        addChannel(track);
    }
}

void MixerView::addChannel(TrackModel *track)
{
    ChannelWidget *channel = new ChannelWidget(track->name(), this);
    layout->insertWidget(layout->count() - 1, channel); // antes do botão "+"
    channelWidgets.append(channel);
}
