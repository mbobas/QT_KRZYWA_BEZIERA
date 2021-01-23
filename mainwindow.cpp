#include "mainwindow.h"
#include "ui_mainwindow.h"

// Konstruktor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Pobieramy współrzędne (względem głównego okna) lewego, górnego naroznika ramki
    startX = ui->frame->x();
    startY = ui->frame->y();

    // Pobieramy wymiary ramki
    width = ui->frame->width();
    height = ui->frame->height();

    // Tworzymy obiekt klasy QImage o wymiarach równych wymiarom ramki
    // Format_RGB32 to 32 bitowe RGB (z kanałem alfa ustawionym na wartość 255)
    img = new QImage(width, height, QImage::Format_RGB32);
}
//*****************************************************************************************************


// Destruktor
MainWindow::~MainWindow()
{
    delete ui;
}
//*****************************************************************************************************


// Funkcja ,,odrysowująca'' okno aplikacji. Wywoływana automatycznie podczas uruchamiania aplikacji
// i w innych sytuacjach, w których zachodzi konieczność ponownego narysowania okna.
// Można też wymusić jej wywołanie za pomocą funkcji update()
void MainWindow::paintEvent(QPaintEvent*)
{
    // Obiekt przy pomocy, którego możemy rysować po elementach interfejsu graficznego aplikacji
    QPainter p(this);

    // Metoda drawImage wyświetla zawartość obiektu *img klasy QImage w głównym oknie aplikacji
    // startX i startY to współrzędne (względem głównego okna) lewego górnego narożnika
    // wyświetlanego obiektu
    p.drawImage(startX, startY, *img);
}
//*****************************************************************************************************


// Funkcja zamalowująca na czarno wszystkie piksele obrazu *img
void MainWindow::clean()
{
    // deklaracja wskaźnika do poruszania się po pikselach obrazu
    unsigned char *wsk;

    // przechodzimy po wszystkich wierszach obrazu
    for(int i=0; i<height; i++)
    {
        // ustawiamy wskaźnik na początku i-tego wiersza
        wsk = img->scanLine(i);

        // przechodzimy po wszystkich piselach i-tego wiersza
        // i nadajemy im wartość (0,0,0) odpowiadającą kolorowi czarnemu
        for(int j=0; j<width; j++)
        {
            wsk[4*j] = 0;   // ustawiamy składową ,,niebieską'' na 0
            wsk[4*j+1] = 0; // ustawiamy składową ,,zielonąą'' na 0
            wsk[4*j+2] = 0; // ustawiamy składową ,,czerwoną'' na 0
        }
    }
}
//*****************************************************************************************************



//*****************************************************************************************************


//
void MainWindow::drawBigPixel(int x,int y)
{
    x=x-5;
    y=y-5;

    red=255;
    green=0;
    blue=0;

    for(int i=0; i<=10; i++){
        for (int j=0; j<=10; j++) {
            drawPixel(x+i,y+j);
        }

    }

}
// rysuje krzywa beziera dla 4 punktow - 3go stopnia
void MainWindow::draw_bezier()
{
    int x,y;

    QTextStream(stdout) << x0<<y0 << " \n";
    for (float t=0; t<=1; t+=0.001) {
        x=qPow((1-t),3)*tab[0]+3*(qPow((1-t),2))*t*tab[2]+3*(1-t)*qPow(t,2)*tab[4]+qPow(t,3)*tab[6];
        y=qPow((1-t),3)*tab[1]+3*(qPow((1-t),2))*t*tab[3]+3*(1-t)*qPow(t,2)*tab[5]+qPow(t,3)*tab[7];

        drawPixel(x,y);

//        red=255;
//        green=0;
//        blue=0;
    }

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
        //counter = 0
        //pobieramy 4 punkty do tablicy.
        // Pobieramy współrzędne 4 punktow
        if (counter <= 7) {
            tab[counter] = event->x();
            tab[counter+1] = event->y();

            tab[counter] = tab[counter] - startX;
            tab[counter+1] = tab[counter+1] - startY;

            drawBigPixel(tab[counter], tab[counter+1]);

            on_XChanged(tab[counter]);
            on_YChanged(tab[counter+1]);
            update();
            counter++;
            counter++;
        }

        if (counter >= 7) {
             draw_bezier();
        }


//        x0 = event->x();
//        y0 = event->y();

//        // Współrzędne obliczane są względem głównego okna programu
//        // aby uzyskać współrzędne względem obszaru rysowania (ramki) musimy je przesunąć
//        // tak aby punkt (0,0) pokrywał się z lewym górnym naroznikiem obszaru rysowania
//        x0 = x0 - startX;
//        y0 = y0 - startY;

//        // Jeżeli wciśnięto lewy przycisk to zamalowujemy piksel na biało
//        if(event->button() == Qt::LeftButton)
//        {
//            drawPixel(x0,y0);
//        }
//        // a w przeciwnym wypadku na czerwono
//        else
//        {
//            drawPixel(x0,y0);
//        }

//        on_XChanged(x0);
//        on_YChanged(y0);
//        update();

}

// Metoda wywoływana po wciśnięciu przycisku myszy
// Inne metody związane z obsługą myszy to
// void MainWindow::mouseReleaseEvent(QMouseEvent *event)
// wywoływana po puszczeniu przycisku myszy i
// void MainWindow::mouseMoveEvent(QMouseEvent *event)
// wywoływana po każdym ruchu myszy
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

//    // Pobieramy współrzędne punktu puszczenia myszy
//    x1 = event->x();
//    y1 = event->y();
//    // Współrzędne obliczane są względem głównego okna programu
//    // aby uzyskać współrzędne względem obszaru rysowania (ramki) musimy je przesunąć
//    // tak aby punkt (0,0) pokrywał się z lewym górnym naroznikiem obszaru rysowania
//    x1 = x1 - startX;
//    y1 = y1 - startY;

//    // Jeżeli wciśnięto lewy przycisk to zamolowujemy piksel na biało
//    if(event->button() == Qt::LeftButton)
//    {
//        drawPixel(x1,y1);
//    }

//    switch(option)
//    {
//    case 1:
//        drawPixel(x0,y0);
//        break;

//    case 2:

//        break;
//    case 3:

//        break;
//    default:
//       break;
//    }


//    on_X1Changed(x1);
//    on_Y1Changed(y1);

//    update();
}
//*****************************************************************************************************



void MainWindow::mouseMoveEvent( QMouseEvent * event ) {

//    if (option == 5){
//    // Pobieramy współrzędne punktu kliknięcia
//    x0 = event->x();
//    y0 = event->y();
//    // Współrzędne obliczane są względem głównego okna programu
//    // aby uzyskać współrzędne względem obszaru rysowania (ramki) musimy je przesunąć
//    // tak aby punkt (0,0) pokrywał się z lewym górnym naroznikiem obszaru rysowania
//    x0 = x0 - startX;
//    y0 = y0 - startY;

//    // Jeżeli wciśnięto lewy przycisk to zamolowujemy piksel na biało
//    if(event->button() == Qt::LeftButton)
//    {
//        drawPixel(x0,y0);
//    }
//    // a w przeciwnym wypadku na czerwono
//    else
//    {
//        drawPixel(x0,y0);
//    }

//    on_XChanged(x0);
//    on_YChanged(y0);
//    update();

}


// zamalowuje piksel (x,y) na kolor (red,green,blue), domyślnie na biało
void MainWindow::drawPixel(int x, int y)
{
    unsigned char *wsk;

    // sprawdzamy czy (x,y) leży w granicach rysunku
    if(x>=0 && y>=0 && x<width && y<height)
    {
        wsk = img->scanLine(y);
        wsk[4*x] = blue;
        wsk[4*x+1] = green;
        wsk[4*x+2] = red;
    }

}
//sprawdzamy kierunek lini z lewaej do prawe lub prawej do lewej,
bool MainWindow::check(int x0, int y0, int x1, int y1) {
    if (x1>x0 && y1>y0) {
        if (x1-x0>y1-y0) {
            return true;
        }else {
            return false;
        }
    }

}
// zamalowuje odcinek (x0,y0 -> x1,y1) na kolor (red,green,blue), domyślnie na biało
void MainWindow::draw_section(int x0, int y0, int x1, int y1)

{

    float a, b,y;
    float x;
    //sprawdzamy kierunek lini z lewaej do prawe lub prawej do lewej,
    bool verify = check(x0,y0,x1,y1);

    //rownanie prostej
    a=((float)y1-y0)/(x1-x0);
    b=y0-a*x0;

    if (verify) {
        //rysuj od lewej do prawej
        if (x1>x0){
            for (x=x0; x<=x1; x++) {
              y=a*x+b;
              drawPixel(x, y);
            }
        //rysuj od prawej do lewej
        }else if(x0>x1) {
            for (x=x0; x>=x1; x--) {
              y=a*x+b;
              drawPixel(x, y);
            }
           //linia prosta z lewej do prawej gęsto - do poprawy.
            //heh - rysuj prostokat wyszlo :)
        }
//        if(x1-x0 >=0 && x1-x0 <=15 ){
//                    int diff=x1-x0;
//                    for(y=y0;y>=y1;y--){
//                        for(x=x0;x<=x1;x++){
//                            drawPixel(x,y);
//                        }
//                    }
//                }
    }

}






// Metoda wywoływana po nacisnięciu przycisku exitButton (,,Wyjście'')
void MainWindow::on_exitButton_clicked()
{
    // qApp to globalny wskaźnik na obiekt aplikacji
    // metoda quit() powoduje zakończenie działania aplikacji z kodem wyjścia 0 (sukces)
    qApp->quit();
}
//*****************************************************************************************************

// Metoda wywoływana po nacisnięciu przycisku exitButton (,,Wyjście'')
void MainWindow::on_cleanButton_clicked()
{
    clean();
    counter = 0;
    // Po zmodyfikowaniu obiektu QImage odświeżamy okno aplikacji, aby zobaczyc zmiany
    update();
}

void MainWindow::on_XChanged(int x0)
{
   ui->labelX->setText(QString::number(x0));
}

void MainWindow::on_YChanged(int y0)
{
   ui->labelY->setText(QString::number(y0));
}
void MainWindow::on_X1Changed(int x1)
{
   ui->labelX_2->setText(QString::number(x1));
}

void MainWindow::on_Y1Changed(int y1)
{
   ui->labelY_2->setText(QString::number(y1));
}
void MainWindow::on_X2Changed(int x2)
{
   ui->labelX_3->setText(QString::number(x2));
}

void MainWindow::on_Y2Changed(int y2)
{
   ui->labelY_3->setText(QString::number(y2));
}
void MainWindow::on_X3Changed(int x3)
{
   ui->labelX_4->setText(QString::number(x3));
}

void MainWindow::on_Y3Changed(int y3)
{
   ui->labelY_4->setText(QString::number(y3));
}

void MainWindow::on_radioButton_clicked()
{
    option=1;
}

void MainWindow::on_radioButton_2_clicked()
{
    option=2;
}

void MainWindow::on_radioButton_3_clicked()
{
    option=3;
}

void MainWindow::on_radioButton_4_clicked()
{
    red=255;
    green=0;
    blue=0;
}

void MainWindow::on_radioButton_6_clicked()
{
    red=0;
    green=255;
    blue=0;
}

void MainWindow::on_radioButton_5_clicked()
{
    red=255;
    green=255;
    blue=255;
}


