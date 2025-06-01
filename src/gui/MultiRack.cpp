#include "gui/MultiRack.h"

MultiRack::MultiRack(QWidget *parent)
    : QWidget(parent)
{
    blankPanel = new QWidget();
    mixerPanel = new MixerView(this);
    effectsPanel = new QWidget(); // painel real futuramente

    rackStack = new QStackedWidget(this);
    rackStack->addWidget(blankPanel);
    rackStack->addWidget(mixerPanel);
    rackStack->addWidget(effectsPanel);
    rackStack->setCurrentWidget(blankPanel);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(rackStack);
    setLayout(layout);
}

void MultiRack::showMixer() {
    rackStack->setCurrentWidget(mixerPanel);
}

void MultiRack::showEffects() {
    rackStack->setCurrentWidget(effectsPanel);
}

bool MultiRack::isShowingMixer() const {
    return rackStack->currentWidget() == mixerPanel;
}

bool MultiRack::isShowingEffects() const {
    return rackStack->currentWidget() == effectsPanel;
}

void MultiRack::bindSession(SessionController *session)
{
    mixerPanel->bindToSession(session);

    connect(mixerPanel, &MixerView::requestNewTrack,
            session, &SessionController::addTrack);
}
