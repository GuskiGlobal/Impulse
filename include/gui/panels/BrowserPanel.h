#ifndef BROWSERPANEL_H
#define BROWSERPANEL_H

#include <QTabWidget>
#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLayout>
#include "gui/browser/FileBrowserWidget.h"


class BrowserPanel : public QWidget
{
  Q_OBJECT

  public:
    explicit BrowserPanel(QWidget *parent = nullptr);

  private:
  
    QTabWidget *browserContent;
    QWidget *filesTab;
    QWidget *pluginsTab;
    QWidget *effectsTab;
    QListWidget *browserFiles;
    QListWidget *browserPlugins;
    QListWidget *browserEffects;
};

#endif // BROWSERPANEL_H
