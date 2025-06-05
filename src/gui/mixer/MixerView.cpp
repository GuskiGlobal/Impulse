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
    //layout->addStretch();

    containerWidget->setLayout(layout);
    scrollArea->setWidget(containerWidget);
    mainLayout->addWidget(scrollArea);

    createAddButton();

    setLayout(mainLayout);

    
}

void MixerView::createAddButton()
{
    addChannelButton = new QPushButton("+", this);
    addChannelButton->setFixedSize(30, 100);
    connect(addChannelButton, &QPushButton::clicked, this, [=]() {
        emit requestNewTrack(); 
    });
    layout->addWidget(addChannelButton);
    layout->addStretch(); 
}

void MixerView::bindToSession(SessionController *sessionController)
{
    session = sessionController;


    connect(session, &SessionController::trackAdded, this, [=](TrackModel *track) {
        addChannel(track);
    });

    for (TrackModel *track : session->getTracks()) {
        addChannel(track);
    }
}

void MixerView::addChannel(TrackModel *track)
{
    ChannelModel *channelModel = new ChannelModel(track->id(), 80, 0.0f, track);
    ChannelWidget *channel = new ChannelWidget(channelModel, this);
    layout->insertWidget(layout->count() - 2, channel);
    channelWidgets.append(channel);
}

void MixerView::getVolume(TrackModel *track, int &volume)
{
    for (ChannelWidget *channel : channelWidgets) {
        if (channel->trackId() == track->id()) {
            volume = channel->volume();
            return;
        }
    }
    volume = 0; 
}
void MixerView::setVolume(TrackModel *track, int volume)
{
    for (ChannelWidget *channel : channelWidgets) {
        if (channel->trackId() == track->id()) {
            channel->setVolume(volume);
            return;
        }
    }
}
