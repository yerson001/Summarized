#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>
#include <QDebug>
#include <fstream>
#include <sstream>
#include <iostream>



using namespace std;
using namespace cv;
//************ windows to show opencv images******
Mat dummy_1ch = Mat::zeros(Size(800, 600), CV_8UC1);
Mat dummy_3ch = Mat::zeros(Size(800, 600), CV_8UC3);
QImage dummy_img_1ch(dummy_1ch.data, dummy_1ch.cols, dummy_1ch.rows, QImage::Format_Grayscale8);
QImage dummy_img_3ch(dummy_3ch.data, dummy_3ch.cols, dummy_3ch.rows, QImage::Format_RGB888);

Mat dummy_2ch = Mat::zeros(Size(800, 600), CV_8UC1);
Mat dummy_4ch = Mat::zeros(Size(800, 600), CV_8UC3);
QImage dummy_img_2ch(dummy_2ch.data, dummy_2ch.cols, dummy_2ch.rows, QImage::Format_Grayscale8);
QImage dummy_img_4ch(dummy_4ch.data, dummy_4ch.cols, dummy_4ch.rows, QImage::Format_RGB888);



MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  // *** to start with the firts stackwindows ********
  ui->stackedWidget->setCurrentIndex(0);
  //**** init frame value ********
  FRAME_RANGE = 100;
  no_movement = 0;

  //**** init config ******
  configSensivility();
  connect(ui->start, SIGNAL(clicked()), this, SLOT(on_start_clicked()));



  //***********QGRAPHICS***********
  //QGraphicsScene *m_scene = new QGraphicsScene(this);
  histogramConfig();
  item->setPos(0,477);
  //connect(ui->xpos,SIGNAL(valueChanged(QString)),this,SLOT(item->getXpos()));

}

MainWindow::~MainWindow()
{
  delete ui;
  delete[] arr;
}

void MainWindow::on_mainpage_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_videopage_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_analisispage_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_openfile_clicked()
{
  QString filename=QFileDialog::getOpenFileName(this,tr("openfile"),QDir::currentPath());
  NameVideo = filename.toLocal8Bit().constData();
  //set video name
  ui->ValueNameVideo->setText(QString::fromStdString(NameVideo));

  cap.open(NameVideo);
  //****** get and set number frames value ************
  int NumberFrames = cap.get(CAP_PROP_FRAME_COUNT);
  ui->ValueNumberFrames->setText(QString::fromStdString(to_string(NumberFrames)));

  //****** get and set number of frames **************
  int fps = cap.get(CAP_PROP_FPS);
  LengthVideo = (NumberFrames/fps);
  ui->ValueDuracion->setText(QString::fromStdString(to_string(LengthVideo/60)));
}


void MainWindow::on_start_clicked()
{
  if(this->RUNNING==true){
      ui->preview->setPixmap(QPixmap::fromImage(dummy_img_3ch).scaled(ui->preview->width(), ui->preview->height(), Qt::KeepAspectRatio));
      ui->movement->setPixmap(QPixmap::fromImage(dummy_img_4ch).scaled(ui->movement->width(), ui->movement->height(), Qt::KeepAspectRatio));
    }else if(this->RUNNING==false){

      //****opencv camera *****
      cap.open(NameVideo);
      ;
      if(!cap.isOpened()){
          QMessageBox::critical(this, "ERROR", "Porfavor carge el video.", QMessageBox::Ok);
          return;
        }
      this->RUNNING = true;
      Mat frame,frame1,mov;

      int value(0),iter(0);

      while(RUNNING==true){
          cap >> frame;
          cap >> frame1;

          int kernel = ui->spinBoxsensivility->value();
          //** Qimage to preview and movement ****
          QImage src,srcmov;
          //** function to acumulate movement value ********
          value += filters(frame,frame1,mov,kernel);

          if(iter%FRAME_RANGE==0){
              int line = ValueLines(value);
              //cout<<"movement value: "<<line<<endl;
              add_lines(line);
              //qDebug()<<iter<<"  "<<line;

              //*********In this part we add line and frame value to .CSV file*******************
              histogramCsv.push_back(make_pair(iter,line));

              value=0;
              //Limages.clear();
            }
          cvtColor(frame, frame, COLOR_BGR2RGB);
          cvtColor(mov, mov, COLOR_BGR2RGB);

          //******* opencv frame to Qimage *********
          src = QImage(frame.data, frame.cols, frame.rows, QImage::Format_RGB888);
          srcmov = QImage(mov.data, mov.cols, mov.rows, QImage::Format_RGB888);

          ui->movement->setPixmap(QPixmap::fromImage(srcmov).scaled(ui->movement->width(), ui->movement->height(), Qt::KeepAspectRatio));
          ui->preview->setPixmap(QPixmap::fromImage(src).scaled(ui->preview->width(), ui->preview->height(), Qt::KeepAspectRatio));
          iter++;
          waitKey(1);
        }
      cap.release();
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

  GaussianBlur(d, d, Size(k, k), 5,3);
  Canny(d, d, 45, 80);

  Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
  dilate(d, d, kernel);
  int nonZero = (img1.rows*img1.cols)- countNonZero(d);
  mov = d.clone();

  return abs(nonZero-img1.rows*img1.cols);
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

void MainWindow::add_lines(int value)
{
  it++;
  arr[count] = value;
  count++;
  if(ui->ShowHistogram->isChecked()){
      drawlines(scene, arr, it,GREEN);
    }
  else{
      scene->clear();
      ui->graphicsView->items().clear();
    }
}

void MainWindow::configSensivility()
{
  ui->spinBoxsensivility->setRange(1,11);
  ui->spinBoxsensivility->setValue(7);
}

void MainWindow::histogramConfig()
{
  it = 1;
  count = 1;
  forwad = 0;
  color = 1;
  arr = new int [100000];
  scene = new QGraphicsScene();
  als_scene = new QGraphicsScene();

  arr[0] = 0;
  flag =0;
  ui->graphicsView->setScene(scene);
  ui->graphicsView_2->setScene(als_scene);
  drawlines(scene, arr, it,GREEN);

}


void MainWindow::drawlines(QGraphicsScene *scene, int *array, size_t sizeGiven,QColor c)
{
  arr = array;
  // Randomize array(?)
  size = sizeGiven;
  m_scene = scene;
  //qDebug() << sizeGiven;

  //m_width = (512/size < 1) ? 1 : 512/size;
  m_width = 3;
  //debug(size);
  //debug(m_width);
  for(size_t i = 0; i < size; ++i) {
      int height = (arr[i] + 1) * m_width+2;
      float left = (i * m_width);
      int up = 540-height;
      QPen pen = QPen(Qt::black);
      QBrush brush = QBrush(c);
      m_rects.push_back(m_scene->addRect(left, up, m_width, height, pen, brush));
    }
}

void MainWindow::on_mainpage_2_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_openfileAnalisis_clicked()
{
  QString filename=QFileDialog::getOpenFileName(this,tr("openfile"),QDir::currentPath());
  NameVideo = filename.toLocal8Bit().constData();
  //set video name
  ui->ValueNameVideo1->setText(QString::fromStdString(NameVideo));
  cap.open(NameVideo);
  //****** get and set number frames value ************
  int NumberFrames = cap.get(CAP_PROP_FRAME_COUNT);
  ui->ValueNumberFrames1->setText(QString::fromStdString(to_string(NumberFrames)));

  //****** get and set number of frames **************
  int fps = cap.get(CAP_PROP_FPS);
  LengthVideo = (NumberFrames/fps);
  ui->ValueDuracion1->setText(QString::fromStdString(to_string(LengthVideo/60)));

}

void MainWindow::SetHistogram()
{
  int count_ = 0;
  ifstream ip("test.csv");
  if(!ip.is_open()) qDebug() << "ERROR: File Open" << '\n';
  int cont = 738;
  string frame,line;
  while(ip.good() && cont--)
    {
      it++;
      getline(ip,frame,',');     // 1
      getline(ip,line,'\n');// 2
      arr[count_] = stoi(line);
      histogramValues.push_back(make_pair(QString::fromStdString (frame).toInt(),QString::fromStdString (line).toInt()));
      count_++;
      //cout<<"frame: "<<frame<<" |"<<"line: "<<line<<" |"<<endl;
      //drawlines(als_scene, arr, it,ORANGE);
    }
  drawlines(als_scene, arr, it,ORANGE);

  als_scene->addItem(item);
  //ui->xpos->setText(QString::number(mouse.x()));

  ip.close();
}

void MainWindow::on_draw_clicked()
{
  SetHistogram();
}

void MainWindow::on_goFrame_clicked()
{
  int xpos = item->getXpos();
  ui->pos->setText(QString::number(xpos));
  getFrame();
}

void MainWindow::getFrame()
{
  Mat frame;
  QImage srcmov;
  cap.open(NameVideo);
  if(!cap.isOpened()){
      QMessageBox::critical(this, "ERROR", "Porfavor carge el video.", QMessageBox::Ok);
      return;
    }
  cap.set(CAP_PROP_POS_FRAMES, (ui->pos->text()).toInt());
  cap>>frame;
  cvtColor(frame, frame, COLOR_BGR2RGB);
  srcmov = QImage(frame.data, frame.cols, frame.rows, QImage::Format_RGB888);
  ui->view->setPixmap(QPixmap::fromImage(srcmov).scaled(ui->view->width(), ui->view->height(), Qt::KeepAspectRatio));
}

void MainWindow::on_next_clicked()
{
  QString value = ui->pos->text();
  int change = value.toInt() + 7;
  ui->pos->setText(QString::number(change));
  on_goFrame_clicked();
}


void MainWindow::on_back_clicked()
{
  QString value = ui->pos->text();
  int change = value.toInt() - 7;
  ui->pos->setText(QString::number(change));
  on_goFrame_clicked();
}


void MainWindow::on_guardar_clicked()
{
  ofstream myfile;
  myfile.open("test1.csv");
  int t = histogramCsv.size();
  t=10;
  for(size_t i =0; i<t; i++){
      myfile<<histogramCsv[i].first<<","<<histogramCsv[i].second<<std::endl;
    }
  QMessageBox::information(this, "Guardar", "Se guardo el archivo");
      //critical(this, "ERROR", "Please check your camera and port number.", QMessageBox::Ok);
  RUNNING = false;
}

