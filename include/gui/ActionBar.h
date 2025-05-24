#ifndef ACTIONBAR_H
#define ACTIONBAR_H

#include <QToolBar>
#include <QAction>

class ActionBar : public QToolBar
{
    Q_OBJECT

public:
    explicit ActionBar(QWidget *parent = nullptr);

signals:
    void playClicked();
    void stopClicked();
    void recordClicked();
    void showBrowser();
    void showMixer();
    void showEffects();

private:
    QAction *playAction;
    QAction *stopAction;
    QAction *recAction;
    QAction *browserAction;
    QAction *mixerAction;
    QAction *effectsAction;
};

#endif // ACTIONBAR_H

