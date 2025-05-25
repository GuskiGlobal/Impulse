#include "gui/panels/BrowserPanel.h"
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLayout>

BrowserPanel::BrowserPanel(QWidget *parent)
  :QWidget(parent)
{
  browserContent = new QTabWidget(this);
  browserContent->setObjectName("browserTabWidget");
  filesTab = new QWidget(this);
  pluginsTab = new QWidget(this);
  effectsTab = new QWidget(this);
  browserFiles = new QListWidget(this);
  browserPlugins = new QListWidget(this);
  browserEffects = new QListWidget(this);
  browserFiles->addItems({"Plugin 1", "Sample 1.wav", "Reverb.fx"});
  browserPlugins->addItems({"EQ", "Compressor", "Reverb", "Delay", "Synth"});
  browserEffects->addItems({"Distortion", "Chorus", "Flanger"});
  QVBoxLayout *filesLayout = new QVBoxLayout(filesTab);
  QVBoxLayout *pluginsLayout = new QVBoxLayout(pluginsTab);
  QVBoxLayout *effectsLayout = new QVBoxLayout(effectsTab);
  filesLayout -> addWidget(browserFiles);
  pluginsLayout -> addWidget(browserPlugins);
  effectsLayout -> addWidget(browserEffects);
  filesLayout->setContentsMargins(0, 0, 0, 0);
  pluginsLayout->setContentsMargins(0, 0, 0, 0);
  effectsLayout->setContentsMargins(0, 0, 0, 0);
  //files -> setLayout(filesLayout);
  //plugins -> setLayout(pluginsLayout);
  //effects -> setLayout(effectsLayout);
  browserContent ->addTab(filesTab,"Files");
  browserContent ->addTab(pluginsTab, "Plugins");
  browserContent ->addTab(effectsTab, "Effects");
  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->addWidget(browserContent);
  setLayout(layout);
}
