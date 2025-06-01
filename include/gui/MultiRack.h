#ifndef MULTIRACK_H
#define MULTIRACK_H

#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>

#include "gui/mixer/MixerView.h"
#include "core/SessionController.h"

class MultiRack : public QWidget {
    Q_OBJECT

public:
    explicit MultiRack(QWidget *parent = nullptr);

    void showMixer();
    void showEffects();
    bool isShowingMixer() const;
    bool isShowingEffects() const;

    void bindSession(SessionController *session);

private:
    QStackedWidget *rackStack;
    QWidget *blankPanel;
    QWidget *effectsPanel;
    MixerView *mixerPanel;
};

#endif // MULTIRACK_H
