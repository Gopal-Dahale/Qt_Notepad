#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_file_triggered();

    void on_actionOpen_file_triggered();

    void on_actionCopy_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionBold_triggered();

//    void setFontItalic(bool italic);

    void on_actionFont_triggered();

private:
    Ui::MainWindow *ui;
    QString mFileName;
};
#endif // MAINWINDOW_H
