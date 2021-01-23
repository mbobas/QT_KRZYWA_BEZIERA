#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <QtMath>
#include<QDebug>

namespace Ui {
class MainWindow;
}

// Deklaracja głównej klasy naszego programu
// Jest ona podklasą klasy QMainWindow
// standardowej klasy Qt reprezentującej główne okno aplikacji
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// Sloty to specjalne funkcje (metody) wywoływane
// po wystąpieniu pewnych zdarzeń np. po kliknięciu przycisku
private slots:
    void on_exitButton_clicked();
    void on_cleanButton_clicked();

    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent( QMouseEvent * event );

    void on_XChanged(int arg1);
    void on_YChanged(int arg1);
    void on_X1Changed(int arg1);
    void on_Y1Changed(int arg1);
    void on_X2Changed(int arg1);
    void on_Y2Changed(int arg1);
    void on_X3Changed(int arg1);
    void on_Y3Changed(int arg1);

    bool check(int x0, int y0, int x1, int y1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();


private:
    // ui to wskaźnik za pomocą którego mamy dostęp
    // do elementów interfejsu użytkownika
    Ui::MainWindow *ui;

    QImage *img; 
    int width, height, startX, startY,x0, y0, x1, y1, x2, y2, x3, y3, option;
    int counter = 0;
    double r =0;
    int red=255;
    int green=255;
    int blue=255;
    int tab[100];
    //int taby[100];


    void clean();
    void drawPixel(int x, int y);
    void draw_section(int x0, int y0, int x1, int y1);
   // void draw_bezier(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);
    void draw_bezier();
    void drawBigPixel(int x,int y);

};

#endif // MAINWINDOW_H
