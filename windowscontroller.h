#ifndef WINDOWSCONTROLLER_H
#define WINDOWSCONTROLLER_H
#include <QObject>
#include "gamewindow.h"
#include "menuwindow.h"
#include "WINDOW.h"
#include "gamecontroller.h"
#include <QTcpSocket>

class WindowsController: public QObject
{
    Q_OBJECT
private:
    MenuWindow *menuWindow;
    GameWindow *gameWindow;
    ToolsWindow *settingsWindow;
    bool onApplicationStart;
    bool gameStarted;
    QTcpSocket *client;

public:
    WindowsController(QObject *parent=0);
    ~WindowsController();
    QStringList userData;

public slots:
    void ShowMenuWindow(bool isGameWindowActive=false);
private slots:
    void StartGameSlot();
    void SettingsSlot();
    void QuitGameSlot();
    void ReturnToMenuSlot();
    void StartRead();
};

#endif // WINDOWSCONTROLLER_H
