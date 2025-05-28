
#include "MainWindow.h"
#include "gui/ActionBar.h"
#include "gui/MultiRack.h"
#include "gui/panels/BrowserPanel.h"
#include "gui/panels/TrackView.h"

#include <QGraphicsScene>
#include <QListWidget>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUI();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI() {
    // === Timeline central ===
    trackView = new TrackView(this);
    setCentralWidget(trackView);

    // === ActionBar ===
    actionBar = new ActionBar(this);
    actionBar->setMovable(false);
    addToolBar(Qt::BottomToolBarArea, actionBar);

    // === MultiRack (mixer/effects) ===
    multiRack = new MultiRack(this);
    rackDock = new QDockWidget(this);
    rackDock->setWidget(multiRack);
    addDockWidget(Qt::BottomDockWidgetArea, rackDock);

    // === Browser ===
    browserDock = new QDockWidget("Browser", this);
    browserPanel = new BrowserPanel(this);
    browserDock->setWidget(browserPanel);
    browserDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
    addDockWidget(Qt::LeftDockWidgetArea, browserDock);

    // === Sinais da ActionBar ===
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
}

