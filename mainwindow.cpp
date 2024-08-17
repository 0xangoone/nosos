#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <pugixml.hpp>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    colors["red"] = Qt::red;
    colors["blue"] = Qt::blue;
    colors["white"] = Qt::white;
    colors["black"] = Qt::black;
    colors["yellow"] = Qt::yellow;
    colors["green"] = Qt::green;
    colors["pink"] = Qt::GlobalColor::magenta;
    ui->setupUi(this);

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_colorComboBox_activated(int index)
{

    QString color = ui->colorComboBox->itemText(index);
    QTextCharFormat format;
    format.setForeground(QBrush(colors[color]));

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);
    ui->textEdit->setTextCursor(cursor);
}


void MainWindow::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->textEdit->setFont(f);
}


void MainWindow::on_insertImgBtn_clicked()
{
    QString f = QFileDialog::getOpenFileName(this);
    if (f == nullptr){
        return;
    }
    ui->textEdit->setHtml(ui->textEdit->toHtml() + "<img src=\"" + f +"\"></img>" );
}



void MainWindow::on_insertletter_clicked()
{
    // just a test
    QString unicode;
    unicode += (QChar)0xFDFA;
    ui->textEdit->setPlainText(ui->textEdit->toPlainText() + unicode);
}

