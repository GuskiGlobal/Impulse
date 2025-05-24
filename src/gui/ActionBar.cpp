#include "gui/ActionBar.h"

ActionBar::ActionBar(QWidget *parent)
    : QToolBar(parent)
{
    QWidget *leftSpacer = new QWidget(this);
    leftSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    QWidget *rightSpacer = new QWidget(this);
    rightSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);


    setMovable(false);

    browserAction = addAction(QString::fromUtf8("󱁾"));
    addSeparator();

    addWidget(leftSpacer);

    addSeparator();
    playAction = addAction("▶");
    stopAction = addAction("■");
    recAction  = addAction("●");
    addSeparator();

    addWidget(rightSpacer);

    addSeparator();
    mixerAction   = addAction("Mixer");
    effectsAction = addAction("Effects");


    // Conecta sinais personalizados
    connect(playAction, &QAction::triggered, this, &ActionBar::playClicked);
    connect(stopAction, &QAction::triggered, this, &ActionBar::stopClicked);
    connect(recAction,  &QAction::triggered, this, &ActionBar::recordClicked);
    connect(browserAction, &QAction::triggered, this, &ActionBar::showBrowser);
    connect(mixerAction,   &QAction::triggered, this, &ActionBar::showMixer);
    connect(effectsAction, &QAction::triggered, this, &ActionBar::showEffects);
}

