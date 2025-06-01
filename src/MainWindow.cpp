#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUI();
}

MainWindow::~MainWindow() {}


void MainWindow::setupUI() {
    sessionController = new SessionController(this);

    trackView = new TrackView(this);
    setCentralWidget(trackView);

    actionBar = new ActionBar(this);
    actionBar->setMovable(false);
    addToolBar(Qt::BottomToolBarArea, actionBar);

    multiRack = new MultiRack(this);
    multiRack->bindSession(sessionController);
    rackDock = new QDockWidget(this);
    rackDock->setWidget(multiRack);
    addDockWidget(Qt::BottomDockWidgetArea, rackDock);

    browserDock = new QDockWidget("Browser", this);
    browserPanel = new BrowserPanel(this);
    browserDock->setWidget(browserPanel);
    browserDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
    addDockWidget(Qt::LeftDockWidgetArea, browserDock);

    connect(actionBar, &ActionBar::showBrowser, [=]() {
        browserDock->setVisible(!browserDock->isVisible());
    });

    connect(actionBar, &ActionBar::showMixer, [=]() {
        if (rackDock->isVisible() && multiRack->isShowingMixer()) {
            rackDock->setVisible(false);
        } else {
            rackDock->setVisible(true);
            multiRack->showMixer();
        }
    });

    connect(actionBar, &ActionBar::showEffects, [=]() {
        if (rackDock->isVisible() && multiRack->isShowingEffects()) {
            rackDock->setVisible(false);
        } else {
            rackDock->setVisible(true);
            multiRack->showEffects();
        }
    });

    connect(sessionController, &SessionController::trackAdded, this, [=](TrackModel *track) {
        auto *trackWidget = new TrackWidget(track, this);
        trackView->addTrackWidget(trackWidget);
    });

    connect(trackView, &TrackView::addTrackRequested,
        sessionController, &SessionController::addTrack);
    }

void MainWindow::addTrack()
{
    sessionController->addTrack();
}

