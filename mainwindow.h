#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_colorComboBox_activated(int index);

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_insertImgBtn_clicked();


    void on_insertletter_clicked();

private:
    std::map<QString,Qt::GlobalColor> colors;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
