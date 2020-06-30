#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFont>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_file_triggered()
{
    mFileName = ""; // no file name
    ui->textEdit->setPlainText(""); // notepad text is empty
    this->setWindowTitle("Untitled");   // window title is set to untitled
}
void MainWindow::on_actionOpen_file_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open a file");    // gives path of selected file

    if(!file.isEmpty()) // if file is selected
    {
        QFile sFile(file);  // interface to read and write in file
        if(sFile.open(QFile::ReadOnly | QFile::Text ))
        {
            mFileName = file;
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);

            // setting fileName as WindowTitle
            QFileInfo fileInfo(sFile.fileName());
            this->setWindowTitle(fileInfo.fileName());
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    // test for blank file
    // if no file name is specified call save as method.
    if(mFileName.isEmpty())
        on_actionSave_as_triggered();

    QFile sFile(mFileName);

    if(sFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&sFile);
        out<< ui->textEdit->toPlainText();
        sFile.flush();
        sFile.close();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Save File");

    QFile sFile(file);

    // setting fileName as WindowTitle
    QFileInfo fileInfo(sFile.fileName());
    this->setWindowTitle(fileInfo.fileName());

    if(!file.isEmpty())
    {
        mFileName = file;
        on_actionSave_triggered();
    }

}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionBold_triggered()
{
    // if fontWeight is Bold make it normal
    if(ui->textEdit->fontWeight() == QFont::Bold)
        ui->textEdit->setFontWeight(QFont::Normal);

    // otherwise make it bold
    else
        ui->textEdit->setFontWeight(QFont::Bold);
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->textEdit->setFontFamily(font.family());
        ui->textEdit->setFontPointSize(font.pointSize());
    }
    return;
}
