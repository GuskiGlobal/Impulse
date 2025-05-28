#include "gui/panels/BrowserPanel.h"

BrowserPanel::BrowserPanel(QWidget *parent)
  : QWidget(parent)
{
  browserContent = new QTabWidget(this);
  browserContent->setObjectName("browserTabWidget");

  // Tabs
  filesTab = new FileBrowserWidget(this);  // substitui QWidget simples
  pluginsTab = new QWidget(this);
  effectsTab = new QWidget(this);

  // Plugins e Efeitos
  browserPlugins = new QListWidget(this);
  browserEffects = new QListWidget(this);
  browserPlugins->addItems({"EQ", "Compressor", "Reverb", "Delay", "Synth"});
  browserEffects->addItems({"Distortion", "Chorus", "Flanger"});

  QVBoxLayout *pluginsLayout = new QVBoxLayout(pluginsTab);
  QVBoxLayout *effectsLayout = new QVBoxLayout(effectsTab);
  pluginsLayout->addWidget(browserPlugins);
  effectsLayout->addWidget(browserEffects);
  pluginsLayout->setContentsMargins(0, 0, 0, 0);
  effectsLayout->setContentsMargins(0, 0, 0, 0);

  browserContent->addTab(filesTab, "Files");
  browserContent->addTab(pluginsTab, "Plugins");
  browserContent->addTab(effectsTab, "Effects");

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->addWidget(browserContent);
  setLayout(layout);
}

