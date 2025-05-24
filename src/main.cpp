#include <QApplication>
#include "MainWindow.h"
#include "gui/Theme.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setStyle("Fusion");

    if (!Theme::applyTheme("assets/style.qss")) {
        qWarning() << "[Main] Falha ao aplicar o tema.";
    }

    MainWindow window;
    window.setWindowTitle("Impulse");
    window.resize(1280, 720);
    window.show();

    return app.exec();
}

