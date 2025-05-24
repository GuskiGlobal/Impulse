
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QGraphicsView>
#include <QToolBar>

class ActionBar;
class MultiRack;

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

    void setupUI();
};

#endif // MAINWINDOW_H

