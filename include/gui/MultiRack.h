#ifndef MULTIRACK_H
#define MULTIRACK_H

#include <QWidget>
#include <QStackedWidget>

class MultiRack : public QWidget
{
    Q_OBJECT

public:
    explicit MultiRack(QWidget *parent = nullptr);

    void showMixer();
    void showEffects();
    bool isShowingMixer() const;
    bool isShowingEffects() const;

private:
    QWidget *blankPanel;
    QWidget *mixerPanel;
    QWidget *effectsPanel;
    QStackedWidget *rackStack;
};

#endif // MULTIRACK_H

