/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *main;
    QPushButton *videopage;
    QPushButton *analisispage;
    QWidget *analisis;
    QGraphicsView *graphicsView_2;
    QFrame *frame_4;
    QLabel *view;
    QLineEdit *pos;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *back;
    QPushButton *goFrame;
    QPushButton *next;
    QPushButton *mainpage_2;
    QTableView *tableView;
    QFrame *frame_6;
    QPushButton *openfileAnalisis;
    QPushButton *analyze_4;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *NameVideo_2;
    QLabel *NumberFrames_2;
    QLabel *Duracion_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *ValueNameVideo1;
    QLineEdit *ValueNumberFrames1;
    QLineEdit *ValueDuracion1;
    QPushButton *draw;
    QWidget *video;
    QFrame *frame;
    QPushButton *openfile;
    QPushButton *analyze_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *NameVideo;
    QLabel *NumberFrames;
    QLabel *Duracion;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *ValueNameVideo;
    QLineEdit *ValueNumberFrames;
    QLineEdit *ValueDuracion;
    QGraphicsView *graphicsView;
    QFrame *frame_2;
    QPushButton *start;
    QCheckBox *ShowHistogram;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *range;
    QLineEdit *framespersecond;
    QDial *dial;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *sensitivity;
    QSpinBox *spinBoxsensivility;
    QPushButton *guardar;
    QFrame *frame_3;
    QLabel *label;
    QLabel *label_4;
    QPushButton *mainpage;
    QFrame *frame_5;
    QProgressBar *progressBar;
    QLCDNumber *lcdNumber;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QLabel *preview;
    QLabel *movement;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1106, 535);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1121, 521));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"    background-color:rgb(50, 64, 77)\n"
"}"));
        stackedWidget->setLineWidth(3);
        main = new QWidget();
        main->setObjectName(QString::fromUtf8("main"));
        videopage = new QPushButton(main);
        videopage->setObjectName(QString::fromUtf8("videopage"));
        videopage->setGeometry(QRect(370, 100, 71, 51));
        analisispage = new QPushButton(main);
        analisispage->setObjectName(QString::fromUtf8("analisispage"));
        analisispage->setGeometry(QRect(500, 100, 71, 51));
        stackedWidget->addWidget(main);
        analisis = new QWidget();
        analisis->setObjectName(QString::fromUtf8("analisis"));
        graphicsView_2 = new QGraphicsView(analisis);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(330, 330, 741, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(13);
        font.setBold(false);
        font.setWeight(50);
        graphicsView_2->setFont(font);
        graphicsView_2->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"    background-color:rgb(64, 64, 64);\n"
"}"));
        graphicsView_2->setFrameShape(QFrame::Box);
        graphicsView_2->setFrameShadow(QFrame::Raised);
        graphicsView_2->setLineWidth(1);
        frame_4 = new QFrame(analisis);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(330, 30, 741, 301));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);
        view = new QLabel(frame_4);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(170, 20, 441, 231));
        view->setFrameShape(QFrame::Box);
        view->setFrameShadow(QFrame::Raised);
        view->setAlignment(Qt::AlignCenter);
        pos = new QLineEdit(frame_4);
        pos->setObjectName(QString::fromUtf8("pos"));
        pos->setGeometry(QRect(560, 260, 51, 25));
        QFont font1;
        font1.setPointSize(9);
        pos->setFont(font1);
        pos->setAlignment(Qt::AlignCenter);
        widget = new QWidget(frame_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(180, 260, 101, 31));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        back = new QPushButton(widget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  border-radius: 40px;\n"
"  margin:30px;\n"
"  padding:30px;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/bt_backward.png"), QSize(), QIcon::Normal, QIcon::Off);
        back->setIcon(icon);
        back->setIconSize(QSize(30, 20));

        horizontalLayout_7->addWidget(back);

        goFrame = new QPushButton(widget);
        goFrame->setObjectName(QString::fromUtf8("goFrame"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(9);
        goFrame->setFont(font2);
        goFrame->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  border-radius: 40px;\n"
"  margin:30px;\n"
"  padding:30px;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        goFrame->setIcon(icon1);
        goFrame->setIconSize(QSize(40, 40));

        horizontalLayout_7->addWidget(goFrame);

        next = new QPushButton(widget);
        next->setObjectName(QString::fromUtf8("next"));
        next->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  border-radius: 40px;\n"
"  margin:30px;\n"
"  padding:30px;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/bt_forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        next->setIcon(icon2);
        next->setIconSize(QSize(30, 20));

        horizontalLayout_7->addWidget(next);

        mainpage_2 = new QPushButton(analisis);
        mainpage_2->setObjectName(QString::fromUtf8("mainpage_2"));
        mainpage_2->setGeometry(QRect(10, 0, 81, 21));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainpage_2->setIcon(icon3);
        tableView = new QTableView(analisis);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 190, 311, 241));
        frame_6 = new QFrame(analisis);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(10, 30, 311, 151));
        frame_6->setAutoFillBackground(false);
        frame_6->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"    background-color:rgb(50, 64, 77)\n"
"}"));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_6->setLineWidth(2);
        openfileAnalisis = new QPushButton(frame_6);
        openfileAnalisis->setObjectName(QString::fromUtf8("openfileAnalisis"));
        openfileAnalisis->setGeometry(QRect(10, 10, 121, 24));
        openfileAnalisis->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgb(0, 170, 255);\n"
"}"));
        analyze_4 = new QPushButton(frame_6);
        analyze_4->setObjectName(QString::fromUtf8("analyze_4"));
        analyze_4->setGeometry(QRect(330, 540, 21, 20));
        layoutWidget_2 = new QWidget(frame_6);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(12, 50, 241, 88));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        NameVideo_2 = new QLabel(layoutWidget_2);
        NameVideo_2->setObjectName(QString::fromUtf8("NameVideo_2"));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setWeight(75);
        font3.setStrikeOut(false);
        NameVideo_2->setFont(font3);
        NameVideo_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: white;\n"
"}"));

        verticalLayout_3->addWidget(NameVideo_2);

        NumberFrames_2 = new QLabel(layoutWidget_2);
        NumberFrames_2->setObjectName(QString::fromUtf8("NumberFrames_2"));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        NumberFrames_2->setFont(font4);
        NumberFrames_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: white;\n"
"}"));

        verticalLayout_3->addWidget(NumberFrames_2);

        Duracion_2 = new QLabel(layoutWidget_2);
        Duracion_2->setObjectName(QString::fromUtf8("Duracion_2"));
        Duracion_2->setFont(font4);
        Duracion_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: white;\n"
"}"));

        verticalLayout_3->addWidget(Duracion_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        ValueNameVideo1 = new QLineEdit(layoutWidget_2);
        ValueNameVideo1->setObjectName(QString::fromUtf8("ValueNameVideo1"));
        QFont font5;
        font5.setPointSize(8);
        ValueNameVideo1->setFont(font5);

        verticalLayout_4->addWidget(ValueNameVideo1);

        ValueNumberFrames1 = new QLineEdit(layoutWidget_2);
        ValueNumberFrames1->setObjectName(QString::fromUtf8("ValueNumberFrames1"));

        verticalLayout_4->addWidget(ValueNumberFrames1);

        ValueDuracion1 = new QLineEdit(layoutWidget_2);
        ValueDuracion1->setObjectName(QString::fromUtf8("ValueDuracion1"));

        verticalLayout_4->addWidget(ValueDuracion1);


        horizontalLayout_3->addLayout(verticalLayout_4);

        draw = new QPushButton(analisis);
        draw->setObjectName(QString::fromUtf8("draw"));
        draw->setGeometry(QRect(70, 230, 41, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/histogram.png"), QSize(), QIcon::Normal, QIcon::Off);
        draw->setIcon(icon4);
        draw->setIconSize(QSize(30, 30));
        stackedWidget->addWidget(analisis);
        video = new QWidget();
        video->setObjectName(QString::fromUtf8("video"));
        frame = new QFrame(video);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 30, 311, 151));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"    background-color:rgb(50, 64, 77)\n"
"}"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        openfile = new QPushButton(frame);
        openfile->setObjectName(QString::fromUtf8("openfile"));
        openfile->setGeometry(QRect(10, 10, 121, 24));
        openfile->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgb(0, 170, 255);\n"
"}"));
        analyze_3 = new QPushButton(frame);
        analyze_3->setObjectName(QString::fromUtf8("analyze_3"));
        analyze_3->setGeometry(QRect(330, 540, 21, 20));
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 50, 241, 88));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        NameVideo = new QLabel(layoutWidget);
        NameVideo->setObjectName(QString::fromUtf8("NameVideo"));
        NameVideo->setFont(font3);
        NameVideo->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: white;\n"
"}"));

        verticalLayout->addWidget(NameVideo);

        NumberFrames = new QLabel(layoutWidget);
        NumberFrames->setObjectName(QString::fromUtf8("NumberFrames"));
        NumberFrames->setFont(font4);
        NumberFrames->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: white;\n"
"}"));

        verticalLayout->addWidget(NumberFrames);

        Duracion = new QLabel(layoutWidget);
        Duracion->setObjectName(QString::fromUtf8("Duracion"));
        Duracion->setFont(font4);
        Duracion->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: white;\n"
"}"));

        verticalLayout->addWidget(Duracion);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ValueNameVideo = new QLineEdit(layoutWidget);
        ValueNameVideo->setObjectName(QString::fromUtf8("ValueNameVideo"));
        ValueNameVideo->setFont(font5);

        verticalLayout_2->addWidget(ValueNameVideo);

        ValueNumberFrames = new QLineEdit(layoutWidget);
        ValueNumberFrames->setObjectName(QString::fromUtf8("ValueNumberFrames"));

        verticalLayout_2->addWidget(ValueNumberFrames);

        ValueDuracion = new QLineEdit(layoutWidget);
        ValueDuracion->setObjectName(QString::fromUtf8("ValueDuracion"));

        verticalLayout_2->addWidget(ValueDuracion);


        horizontalLayout_2->addLayout(verticalLayout_2);

        graphicsView = new QGraphicsView(video);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(330, 390, 751, 51));
        graphicsView->setFont(font);
        graphicsView->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"    background-color:rgb(64, 64, 64);\n"
"}"));
        graphicsView->setFrameShape(QFrame::Box);
        graphicsView->setFrameShadow(QFrame::Raised);
        graphicsView->setLineWidth(1);
        frame_2 = new QFrame(video);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 200, 311, 241));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        start = new QPushButton(frame_2);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(10, 10, 91, 24));
        start->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgb(2, 100, 10);\n"
"}"));
        ShowHistogram = new QCheckBox(frame_2);
        ShowHistogram->setObjectName(QString::fromUtf8("ShowHistogram"));
        ShowHistogram->setGeometry(QRect(10, 120, 171, 23));
        QFont font6;
        font6.setBold(true);
        font6.setWeight(75);
        ShowHistogram->setFont(font6);
        ShowHistogram->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: white;\n"
"}"));
        layoutWidget1 = new QWidget(frame_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 41, 261, 52));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        range = new QLabel(layoutWidget1);
        range->setObjectName(QString::fromUtf8("range"));
        range->setFont(font4);
        range->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: white;\n"
"}"));

        horizontalLayout_4->addWidget(range);

        framespersecond = new QLineEdit(layoutWidget1);
        framespersecond->setObjectName(QString::fromUtf8("framespersecond"));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font7.setBold(true);
        font7.setWeight(75);
        framespersecond->setFont(font7);
        framespersecond->setAlignment(Qt::AlignCenter);
        framespersecond->setCursorMoveStyle(Qt::VisualMoveStyle);

        horizontalLayout_4->addWidget(framespersecond);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        dial = new QDial(layoutWidget1);
        dial->setObjectName(QString::fromUtf8("dial"));

        horizontalLayout_5->addWidget(dial);

        layoutWidget2 = new QWidget(frame_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(12, 85, 139, 27));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        sensitivity = new QLabel(layoutWidget2);
        sensitivity->setObjectName(QString::fromUtf8("sensitivity"));
        sensitivity->setFont(font4);
        sensitivity->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: white;\n"
"}"));

        horizontalLayout_6->addWidget(sensitivity);

        spinBoxsensivility = new QSpinBox(layoutWidget2);
        spinBoxsensivility->setObjectName(QString::fromUtf8("spinBoxsensivility"));

        horizontalLayout_6->addWidget(spinBoxsensivility);

        guardar = new QPushButton(frame_2);
        guardar->setObjectName(QString::fromUtf8("guardar"));
        guardar->setGeometry(QRect(200, 120, 71, 25));
        frame_3 = new QFrame(video);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(330, 30, 681, 41));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 10, 101, 21));
        QFont font8;
        font8.setPointSize(13);
        font8.setBold(true);
        font8.setWeight(75);
        label->setFont(font8);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: white;\n"
"}"));
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(460, 10, 121, 21));
        label_4->setFont(font8);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: white;\n"
"}"));
        mainpage = new QPushButton(video);
        mainpage->setObjectName(QString::fromUtf8("mainpage"));
        mainpage->setGeometry(QRect(10, 0, 71, 21));
        frame_5 = new QFrame(video);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(1010, 30, 71, 361));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_5->setLineWidth(2);
        progressBar = new QProgressBar(frame_5);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 58, 24, 281));
        progressBar->setMaximum(10);
        progressBar->setValue(1);
        progressBar->setOrientation(Qt::Vertical);
        progressBar->setInvertedAppearance(false);
        lcdNumber = new QLCDNumber(frame_5);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(20, 10, 31, 31));
        lcdNumber->setLayoutDirection(Qt::RightToLeft);
        lcdNumber->setAutoFillBackground(false);
        lcdNumber->setDigitCount(1);
        layoutWidget3 = new QWidget(video);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(330, 70, 681, 321));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        preview = new QLabel(layoutWidget3);
        preview->setObjectName(QString::fromUtf8("preview"));
        preview->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"    background-color:rgb(0, 0, 0);\n"
"}"));
        preview->setFrameShape(QFrame::Box);
        preview->setFrameShadow(QFrame::Raised);
        preview->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(preview);

        movement = new QLabel(layoutWidget3);
        movement->setObjectName(QString::fromUtf8("movement"));
        movement->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"    background-color:rgb(0, 0, 0);\n"
"}"));
        movement->setFrameShape(QFrame::Box);
        movement->setFrameShadow(QFrame::Raised);
        movement->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(movement);

        stackedWidget->addWidget(video);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1106, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        stackedWidget->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        videopage->setText(QApplication::translate("MainWindow", "Video", nullptr));
        analisispage->setText(QApplication::translate("MainWindow", "Analisis", nullptr));
        view->setText(QString());
        pos->setText(QApplication::translate("MainWindow", "0", nullptr));
        back->setText(QString());
        goFrame->setText(QString());
        next->setText(QString());
        mainpage_2->setText(QApplication::translate("MainWindow", "Main", nullptr));
        openfileAnalisis->setText(QApplication::translate("MainWindow", "Abrir archivo", nullptr));
        analyze_4->setText(QString());
        NameVideo_2->setText(QApplication::translate("MainWindow", "Nombre:", nullptr));
        NumberFrames_2->setText(QApplication::translate("MainWindow", "N\302\260 fotogramas:", nullptr));
        Duracion_2->setText(QApplication::translate("MainWindow", "Duracion:", nullptr));
        ValueNameVideo1->setText(QString());
        ValueNumberFrames1->setText(QString());
        ValueDuracion1->setText(QString());
        draw->setText(QString());
        openfile->setText(QApplication::translate("MainWindow", "Abrir archivo", nullptr));
        analyze_3->setText(QString());
        NameVideo->setText(QApplication::translate("MainWindow", "Nombre:", nullptr));
        NumberFrames->setText(QApplication::translate("MainWindow", "N\302\260 fotogramas:", nullptr));
        Duracion->setText(QApplication::translate("MainWindow", "Duracion:", nullptr));
        ValueNameVideo->setText(QString());
        ValueNumberFrames->setText(QString());
        ValueDuracion->setText(QString());
        start->setText(QApplication::translate("MainWindow", "Empezar", nullptr));
        ShowHistogram->setText(QApplication::translate("MainWindow", "Mostrar Histograma", nullptr));
        range->setText(QApplication::translate("MainWindow", "Rango", nullptr));
        framespersecond->setText(QApplication::translate("MainWindow", "1000", nullptr));
        sensitivity->setText(QApplication::translate("MainWindow", "Sensibilidad", nullptr));
        guardar->setText(QApplication::translate("MainWindow", "Guardar", nullptr));
        label->setText(QApplication::translate("MainWindow", "Original", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Movimiento", nullptr));
        mainpage->setText(QApplication::translate("MainWindow", "Main", nullptr));
        preview->setText(QString());
        movement->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
