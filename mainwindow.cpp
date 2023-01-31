#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <QIntValidator>
#include <QDebug>
#include <QThread>
#include <QMouseEvent>
#include <QScrollArea>
#include <qfiledialog.h>
#include <cstdlib>
#include <unistd.h>
#include <omp.h>

using namespace std;
using namespace cv;

float get_pix_x=0;
float get_pix_y=0;

Mat RI(Mat &image, float scale)
{
    Mat resized;
    resize(image, resized, Size(image.cols*scale, image.rows*scale), INTER_LINEAR);
    return resized;
}

Mat dummy_1ch = Mat::zeros(Size(800, 600), CV_8UC1);
Mat dummy_3ch = Mat::zeros(Size(800, 600), CV_8UC3);
QImage dummy_img_1ch(dummy_1ch.data, dummy_1ch.cols, dummy_1ch.rows, QImage::Format_Grayscale8);
QImage dummy_img_3ch(dummy_3ch.data, dummy_3ch.cols, dummy_3ch.rows, QImage::Format_RGB888);


Mat dummy_2ch = Mat::zeros(Size(800, 600), CV_8UC1);
Mat dummy_4ch = Mat::zeros(Size(800, 600), CV_8UC3);
QImage dummy_img_2ch(dummy_2ch.data, dummy_2ch.cols, dummy_2ch.rows, QImage::Format_Grayscale8);
QImage dummy_img_4ch(dummy_4ch.data, dummy_4ch.cols, dummy_4ch.rows, QImage::Format_RGB888);



MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIntValidator *portValidator = new QIntValidator(0, 255);
    ui->camPort->setValidator(portValidator);
    connect(ui->PBTrun, SIGNAL(clicked()), this, SLOT(runCamera()));



    it = 1;
    count = 1;
    no_movement = 1;
    count_movi = 0;
    arr = new int [10000];
    scene = new QGraphicsScene();

    //  int arry[] = {2};
    //  for(size_t i = 0; i < size; ++i) {
    //arr[i] = rand() % 10 + 1;
    //std::cout<<arr[i]<<std::endl;
    arr[0] = no_movement;
    //}


    ui->graphicsView->setScene(scene);

    //  sort = new mergesort(scene, arr);
    drawlines(scene, arr, it, 10000);

}



void MainWindow::runCamera(void){
    if(this->RUNNING==true){
        ui->SRC->setPixmap(QPixmap::fromImage(dummy_img_4ch).scaled(ui->SRC->width(), ui->SRC->height(), Qt::KeepAspectRatio));
        ui->preview->setPixmap(QPixmap::fromImage(dummy_img_3ch).scaled(ui->preview->width(), ui->preview->height(), Qt::KeepAspectRatio));
        //ui->SRC_2->setPixmap(QPixmap::fromImage(dummy_img_3ch).scaled(ui->SRC->width(), ui->SRC_2->height(), Qt::KeepAspectRatio));


        ui->PBTrun->setText("Run");

    }else if(this->RUNNING==false){
        QString file = ui->camPort->text();

        //      QString filename=QFileDialog::getOpenFileName(this,tr("openfile"),QDir::currentPath());

        //      string path = filename.toLocal8Bit().constData();


        cv::VideoCapture cap;
        cap.open(path);
        double fps = cap.get(CAP_PROP_FPS);

        ui->ValueNameVideo->setText(QString::fromStdString(path));

        //VideoCapture cap("/home/yrsn/Videos/video.mp4");
        //cap.open(file);

        if(!cap.isOpened()){
            QMessageBox::critical(this, "ERROR", "Please check your camera and port number.", QMessageBox::Ok);
            return;
        }

        //this->camPort = path.toString();
        ui->PBTrun->setText("Stop");

        this->RUNNING = true;

        Mat frame,frame1;
        Mat init;
        int frame_Number = cap.get(CAP_PROP_FRAME_COUNT);

        ui->ValueNumberFrames->setText(QString::fromStdString(to_string(frame_Number)));
        //->setText(QString::fromStdString(path));
        std::vector<pair<cv::Mat,cv::Mat>> Limages;



        //cout<<frame_Number<<endl;

        float segundos = frame_Number/fps;

        // cout<<"Duracion "<<segundos/60<<":"<<int(segundos)%60<<endl;

        ui->ValueDuracion->setText(QString::fromStdString(to_string(segundos/60)));



        int iter(0);
        while(RUNNING==true){
            cap >> frame;
            cap >> frame1;
            QImage src;
            QImage mov;

            if(vo.filters(frame,frame1,count,7)) {
                //cout<<"se detecto movimiento"<<endl;
            }

            init = vo.Movement(frame,frame1,count,7);

            //cv::imshow("video",init);

            //            if(it%1000==0){
            //                cout<<it<<endl;
            //            }


            //            Limages.push_back(make_pair(frame,frame1));
            if(iter%100==0){
                //                int flag(0);
                //                //cout<<"vector Limage size: "<<it<<" : "<<Limages.size()<<endl;

                //                #pragma omp parallel for
                //                for(int i=0; i<Limages.size(); i++){
                //                    if(filters(Limages[i].first,Limages[i].second,count,7))
                //                    {
                //                        cout<<"se detecto movimiento"<<endl;
                //                        flag++;
                //                    }
                //                }

                //                if(flag > 70)
                //                {
                //                    add_lines(2);
                //                }else if (flag < 50) {

                //                    add_lines(2);
                //                }else{
                //                    add_lines(no_movement);
                //                }

                add_lines(no_movement);
                Limages.clear();
            }

            //movimiento = filters(frame,frame1,count,7);

            cvtColor(frame, frame, COLOR_BGR2RGB);
            src = QImage(frame.data, frame.cols, frame.rows, QImage::Format_RGB888);

            cvtColor(init, init, COLOR_BGR2RGB);
            mov = QImage(init.data, init.cols, init.rows, QImage::Format_RGB888);
            //filters(Limages[i].first,Limages[i].second,count,7);
            ui->SRC->setPixmap(QPixmap::fromImage(mov).scaled(ui->SRC->width(), ui->SRC->height(), Qt::KeepAspectRatio));

            ui->preview->setPixmap(QPixmap::fromImage(src).scaled(ui->preview->width(), ui->preview->height(), Qt::KeepAspectRatio));

            iter++;
            waitKey(1);
        }
        cap.release();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_PBTrun_2_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("openfile"),QDir::currentPath());
    path = filename.toLocal8Bit().constData();
}



void MainWindow::drawlines(QGraphicsScene *scene, int *array, size_t sizeGiven, int delay)
{
    arr = array;
    // Randomize array(?)
    size = sizeGiven;
    m_scene = scene;
    m_delay = delay;
    //m_width = (512/size < 1) ? 1 : 512/size;
    m_width = 2;
    //debug(size);
    //debug(m_width);
    for(size_t i = 0; i < size; ++i) {
        int height = (arr[i] + 1) * m_width+2;
        float left = (i * m_width);
        //int intLeft = left * 1;

        //          if(left - intLeft < 0.1) {
        //              left = intLeft;
        //            } else if(left - intLeft < 0.6) {
        //              left = intLeft + 0.5;
        //            } else {
        //              left = intLeft + 1;
        //            }

        int up = 540-height;
        QPen pen = QPen(Qt::black);
        QBrush brush = QBrush(ORANGE);
        m_rects.push_back(m_scene->addRect(left, up, m_width, height, pen, brush));
    }
}



void MainWindow::add_lines(int value)
{
    it++;
    arr[count] = value;
    count++;
    drawlines(scene, arr, it, 10000);
}


void MainWindow::on_rand_clicked()
{
    it++;
    arr[count] = rand() % 10 + 1;
    count++;
    drawlines(scene, arr, it, 10000);
}
