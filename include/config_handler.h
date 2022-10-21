#ifndef CONFIGHANDLER_H
#define CONFIGHANDLER_H

#include <QObject>
#include "../src/ui_mainwindow.h"
#include "extern.h"

class ConfigHandler : public QObject
{
    Q_OBJECT
public:
    ConfigHandler(Ui::MainWindow*& ui, QObject *parent = nullptr);
    ~ConfigHandler();

private:
    Ui::MainWindow *ui;

};


#endif // CONFIGHANDLER_H