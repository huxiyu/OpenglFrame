#include "cpp/OglContainer.h"
#include <QQmlApplicationEngine>
#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    qmlRegisterType<COglContainer>("QMLOglContainer", 1, 0, "QMLOglContainer");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));

    return app.exec();
}
