#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QGraphicsView>
#include <QToolBar>

class ActionBar;
class MultiRack;
class BrowserPanel;
class TrackView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsView *timelineView;
    QDockWidget   *browserDock;
    QDockWidget   *rackDock;

    ActionBar     *actionBar;
    MultiRack     *multiRack;
    BrowserPanel   *browserPanel;
    TrackView     *trackView;

    void setupUI();
};

#endif // MAINWINDOW_H

