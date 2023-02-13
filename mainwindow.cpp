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

Mat ResizeImage(Mat &image, float scale)
{
  Mat resized;
  resize(image, resized, Size(image.cols*scale, image.rows*scale), INTER_LINEAR);
  return resized;
}

void blur(cv::Mat &image)
{
  GaussianBlur(image, image, cv::Size(7,7), -1);
}

vector<pair<int,int>> Limit(int t_number,int n)
{
  vector<pair<int,int>> ranges;
  int range = t_number/n;
  for(int i=0; i<n; i++){
      ranges.push_back(make_pair(i*range+1,(i+1)*range));
    }

  return ranges;
}

int filtro(Mat img1,Mat img2,int k)
{
  cv::Mat image01,image02,image02bw,d;
  img1.convertTo(image01, CV_8UC1);
  img2.convertTo(image02, CV_8UC1);
  //      imshow("image01", RI(image01,0.5));
  //      imshow("image02", RI(image02,0.5));
  rectangle(image01, Point2d(50,50),Point2d(800,120), (127,0,0),-1, LINE_8);
  rectangle(image02, Point2d(50,50),Point2d(800,120), (127,0,0),-1, LINE_8);
  //imshow("image01", RI(image01,0.5));
  cvtColor(image01, image01, COLOR_RGB2GRAY, 1);
  cvtColor(image02, image02bw, COLOR_RGB2GRAY, 1);
  absdiff(image01, image02bw, d);
  //imshow("d", RI(d,0.5));
  GaussianBlur(d, d, Size(k, k), 5, 3);
  Canny(d, d, 45, 80);

  Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
  dilate(d, d, kernel);


  //imshow("dd", RI(d,0.5));
  int nonZero = (img1.rows*img1.cols)- countNonZero(d);
  //cout<<"No zero: "<<nonZero<<endl;
  //video.write(img2);

  return abs(nonZero-img1.rows*img1.cols);
}

void foo(int m,int n,string nameW)
{
  Mat frame,frame1;
  cv::VideoCapture capture;
  capture.open("/home/yrsn/Videos/test.mp4");

  for (int i=m; i<n; i++ ) {
      capture.set(CAP_PROP_POS_FRAMES, i);
      capture >> frame;
      capture >> frame1;
      //cout<<nameW<<"  -  "<<filtro(frame,frame1,7)<<endl;
      //imshow(nameW,ResizeImage(frame,0.5));
      //waitKey(0);
    }

}

void spawnThreads(int n)
{
  cv::VideoCapture cap;
  cap.open("/home/yrsn/Videos/test.mp4");

  int NumberFrames = cap.get(CAP_PROP_FRAME_COUNT);
  cout<<"Number frames: "<<NumberFrames<<endl;
  vector<pair<int,int>> goo = Limit(NumberFrames,n);

  for(int i=0; i<goo.size(); i++){
      cout<<goo[i].first<<" ---- "<<goo[i].second<<endl;
    }

  std::vector<thread> threads(n);
  // spawn n threads:
  for (int i = 0; i < n; i++) {
      threads[i] = thread(foo,goo[i].first,goo[i].second,"f");
    }

  for (auto& th : threads) {
      th.join();
    }
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
  ui->progressBar->setValue(0);

  QIntValidator *portValidator = new QIntValidator(0, 255);
  ui->camPort->setValidator(portValidator);
  connect(ui->PBTrun, SIGNAL(clicked()), this, SLOT(runCamera()));
  connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
  //connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->sensitivity_1,SLOT(setText(String)));

  connect(ui->horizontalSlider,&QSlider::sliderMoved,this,[=]{
      int val=ui->horizontalSlider->value();
      ui->sensitivity_1->setText(QString::number(val));
    });

  it = 1;
  count = 1;
  no_movement = 1;
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
      ui->SRC->setPixmap(QPixmap::fromImage(dummy_img_3ch).scaled(ui->SRC->width(), ui->SRC->height(), Qt::KeepAspectRatio));


      ui->preview->setPixmap(QPixmap::fromImage(dummy_img_3ch).scaled(ui->preview->width(), ui->preview->height(), Qt::KeepAspectRatio));
      ui->preview_3->setPixmap(QPixmap::fromImage(dummy_img_4ch).scaled(ui->preview_3->width(), ui->preview_3->height(), Qt::KeepAspectRatio));


      //ui->SRC_2->setPixmap(QPixmap::fromImage(dummy_img_3ch).scaled(ui->SRC->width(), ui->SRC_2->height(), Qt::KeepAspectRatio));

      ui->PBTrun->setText("Run");

    }else if(this->RUNNING==false){
      QString file = ui->camPort->text();
      cv::VideoCapture cap(0);
      //cap.open(NameVideo);
      //cap.open(0);
      //      cap.set(CAP_PROP_FRAME_WIDTH, 800);
      //      cap.set(CAP_PROP_FRAME_HEIGHT, 600);
      //cap.set(CAP_PROP_FPS, 30);

      //int fps = cap.get(CAP_PROP_FPS);



      //VideoCapture cap("/home/yrsn/Videos/video.mp4");
      //cap.open(file);

      if(!cap.isOpened()){
          QMessageBox::critical(this, "ERROR", "Please check your camera and port number.", QMessageBox::Ok);
          return;
        }

      //this->camPort = NameVideo.toString();
      ui->PBTrun->setText("Stop");

      this->RUNNING = true;

      Mat frame,frame1,mov;
      int NumberFrames = cap.get(CAP_PROP_FRAME_COUNT);

      ui->ValueNumberFrames->setText(QString::fromStdString(to_string(NumberFrames)));

      std::vector<pair<cv::Mat,cv::Mat>> Limages;

      //cout<<frame_Number<<endl;

      //LengthVideo = (NumberFrames/fps);
      //ui->ValueDuracion->setText(QString::fromStdString(to_string(LengthVideo/60)));

      int iter(0);
      int value(0);

      while(RUNNING==true){

          cap >> frame;
          cap >> frame1;



          QString a = ui->sensitivity_1->text();
          //qDebug() << "change: " << a;
          //          std::thread first (foo,frame,3000);
          //          first.join();


          QImage src,srcmov;
          // value acumula el valor de movimiento de cada 100 frames

          //cout<<(filters(frame,frame1,count,7))<<endl;
          value += filters(frame,frame1,mov,7);
          //Limages.push_back(make_pair(frame,frame1));


          if(iter%FRAME_RANGE==0){
              int line = ValueLines(value);
              cout<<"movement value: "<<line<<endl;
              add_lines(line);
              value=0;
              //Limages.clear();
            }

          cvtColor(frame, frame, COLOR_BGR2RGB);
          cvtColor(mov, mov, COLOR_BGR2RGB);

          src = QImage(frame.data, frame.cols, frame.rows, QImage::Format_RGB888);

          srcmov = QImage(mov.data, mov.cols, mov.rows, QImage::Format_RGB888);

          ui->SRC->setPixmap(QPixmap::fromImage(srcmov).scaled(ui->SRC->width(), ui->SRC->height(), Qt::KeepAspectRatio));
          ui->preview_3->setPixmap(QPixmap::fromImage(srcmov).scaled(ui->preview_3->width(), ui->preview_3->height(), Qt::KeepAspectRatio));
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
  NameVideo = filename.toLocal8Bit().constData();
  //set video name
  ui->ValueNameVideo->setText(QString::fromStdString(NameVideo));

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


int MainWindow::filters(Mat img1,Mat img2,Mat &mov,int k)
{
  cv::Mat image01,image02,image02bw,d;
  img1.convertTo(image01, CV_8UC1);
  img2.convertTo(image02, CV_8UC1);

  rectangle(image01, Point2d(50,50),Point2d(800,120), (127,0,0),-1, LINE_8);
  rectangle(image02, Point2d(50,50),Point2d(800,120), (127,0,0),-1, LINE_8);
  //imshow("image01", RI(image01,0.5));
  cvtColor(image01, image01, COLOR_RGB2GRAY, 1);
  cvtColor(image02, image02bw, COLOR_RGB2GRAY, 1);
  absdiff(image01, image02bw, d);

  GaussianBlur(d, d, Size(k, k), 5, 3);
  Canny(d, d, 45, 80);

  Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
  dilate(d, d, kernel);



//  imshow("d", ResizeImage(d,0.5));
//  imshow("img1", ResizeImage(img1,0.5));
  int nonZero = (img1.rows*img1.cols)- countNonZero(d);
  mov = d.clone();

  return abs(nonZero-img1.rows*img1.cols);
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



void MainWindow::on_analyze_clicked()
{

  cv::VideoCapture cap;
  cap.open("/home/yrsn/Videos/test.mp4");


  //  int NumberFrames = cap.get(CAP_PROP_FRAME_COUNT);
  //  cout<<"Number frames: "<<NumberFrames<<endl;
  //  vector<pair<int,int>> goo = Limit(NumberFrames,4);

  //  for(int i=0; i<goo.size(); i++){
  //      cout<<goo[i].first<<" ---- "<<goo[i].second<<endl;
  //    }
  //cap.set(CAP_PROP_FRAME_WIDTH, 800);
  //cap.set(CAP_PROP_FRAME_HEIGHT, 600);
  //cap.set(CAP_PROP_FPS, 30);

  if(!cap.isOpened()){
      QMessageBox::critical(this, "ERROR", "Please check your camera and port number.", QMessageBox::Ok);
      return;
    }

  this->RUNNING = true;

  Mat frame,frame1;


  QString a = ui->sensitivity_1->text();
  qDebug() << "change: " << a;

  //  std::thread first (foo,1,10,"primero");
  //  std::thread second (foo,5550,5560,"segundo");
  //  std::thread third(foo,6336,6340,"tercero");
  //  first.join();
  //  second.join();
  //  third.join();

  spawnThreads(10);

  //  foo(1,10);
  //  foo(5550,5555);
  //  foo(6340,6344);
  //aitKey(0);
  cap.release();


  //  while(RUNNING==true){
  //      cap >> frame;
  //      cap >> frame1;
  //      cv::imshow("Frame0", ResizeImage(frame,0.5));
  //      waitKey(1);
  //    }
  //  cap.release();
}

int MainWindow::ValueLines(int val)
{
  if(val<MAX_VALUE and val > MAX_MID_VALUE){
      return 8;
    }
  else if (val<MAX_MID_VALUE and val > MID_value ) {
      return 6;
    }
  else if (val<MID_value and val > MIN_MID_VALUE ) {
      return 4;
    }
  else if (val<MIN_MID_VALUE and val > MIN_VALUE ) {
      return 2;
    }
  else if ( val > MAX_VALUE ) {
      return 10;
    }
  return no_movement;
}

