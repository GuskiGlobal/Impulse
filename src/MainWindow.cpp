
#include "MainWindow.h"
#include "gui/ActionBar.h"
#include "gui/MultiRack.h"
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
    timelineView = new QGraphicsView(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 2000, 800);
    timelineView->setScene(scene);
    setCentralWidget(timelineView);

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
    QListWidget *browserContent = new QListWidget();
    browserContent->addItems({"Plugin 1", "Sample 1.wav", "Reverb.fx"});
    browserDock->setWidget(browserContent);
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

