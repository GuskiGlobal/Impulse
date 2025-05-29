#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gui/ActionBar.h"
#include "gui/MultiRack.h"
#include "gui/panels/BrowserPanel.h"
#include "gui/panels/TrackView.h"
#include "core/tracks/TrackModel.h"
#include "gui/tracks/TrackWidget.h"
#include "core/SessionController.h"

#include <QGraphicsScene>
#include <QListWidget>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMainWindow>
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
    SessionController *sessionController;
    QGraphicsView *timelineView;
    QDockWidget   *browserDock;
    QDockWidget   *rackDock;

    ActionBar     *actionBar;
    MultiRack     *multiRack;
    BrowserPanel   *browserPanel;
    TrackView     *trackView;

    void addTrack();
    
    void setupUI();
};

#endif // MAINWINDOW_H

