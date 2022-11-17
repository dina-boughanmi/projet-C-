/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTabWidget *tabwidget;
    QWidget *tab_4;
    QGroupBox *groupBox_6;
    QFormLayout *formLayout_2;
    QLabel *label_10;
    QLineEdit *lineEdit_ajout_id;
    QLabel *label_9;
    QLineEdit *lineEdit_ajout_capasiti;
    QLabel *label_11;
    QDateTimeEdit *dateTimeEdit_ajout1;
    QLabel *label_13;
    QDateTimeEdit *dateTimeEdit_ajout2;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_supp;
    QFormLayout *formLayout_26;
    QLabel *label_63;
    QLineEdit *lineEdit_supp;
    QPushButton *pushButton_29;
    QGroupBox *groupBox_modifer;
    QFormLayout *formLayout_3;
    QLabel *label_65;
    QLineEdit *le_modifer_id_studio;
    QLabel *label_66;
    QLineEdit *le_modifer_capasi;
    QLabel *label_67;
    QDateTimeEdit *dateTimeEdit_modifer1;
    QLabel *label_68;
    QDateTimeEdit *dateTimeEdit_modifer2;
    QPushButton *modiferbotton;
    QTableView *tableView_6;
    QLabel *label_param;
    QWidget *mail;
    QGroupBox *groupBoxMessage;
    QVBoxLayout *verticalLayout_42;
    QVBoxLayout *verticalLayout_43;
    QLabel *labelSubject_6;
    QLineEdit *lineEditSubject_6;
    QVBoxLayout *verticalLayout_44;
    QLabel *labelContent_6;
    QTextEdit *textEditContent_6;
    QGroupBox *groupBoxFrom;
    QVBoxLayout *verticalLayout_45;
    QVBoxLayout *verticalLayout_46;
    QLabel *labelEmailFrom_6;
    QLineEdit *lineEditEmailFrom_6;
    QGroupBox *groupBoxCredentials;
    QVBoxLayout *verticalLayout_47;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEditHost_6;
    QLabel *labelEmailCredentials_6;
    QSpinBox *spinBoxPort_6;
    QLineEdit *lineEditPasswordCredentials_6;
    QLineEdit *lineEditEmailCredentials_6;
    QLabel *labelHost_6;
    QLabel *labelPasswordCredentials_6;
    QLabel *labelPort_6;
    QGroupBox *groupBoxTo;
    QVBoxLayout *verticalLayout_48;
    QVBoxLayout *verticalLayout_49;
    QLabel *labelEmail_6;
    QLineEdit *lineEditEmailTo_6;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButtonSend_6;
    QPushButton *pushButtonClear_6;
    QLabel *label_gif_mail;
    QWidget *afficher_studio;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QTableView *tableView_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_recherche;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_9;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(890, 750);
        MainWindow->setMinimumSize(QSize(850, 750));
        MainWindow->setMaximumSize(QSize(950, 850));
        QIcon icon;
        icon.addFile(QStringLiteral(":/IMG8RES FOR QT/on air.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("QCheckBox::indicator:checked, QRadioButton::indicator:checked\n"
"{\n"
"    border: 1px solid #444;\n"
"       background-color: #3995D7;\n"
"}\n"
"\n"
"\n"
"QToolTip\n"
"{\n"
"     border: 1px solid black;\n"
"     background-color:#3995D7;\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     opacity: 100;\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QWidget:item:hover\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#3995D7, stop: 1 #ca0619);\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:item:selected\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#3995D7, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"    background: transparent;\n"
"    border: 1px solid#3995D7;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"    background: #444;\n"
"    border: 1px solid #000;\n"
"    background-c"
                        "olor: QLinearGradient(\n"
"        x1:0, y1:0,\n"
"        x2:0, y2:1,\n"
"        stop:1 #212121,\n"
"        stop:0.4 #343434/*,\n"
"        stop:0.2 #343434,\n"
"        stop:0.1#3995D7*/\n"
"    );\n"
"    margin-bottom:-1px;\n"
"    padding-bottom:1px;\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"    border: 1px solid #000;\n"
"}\n"
"\n"
"QMenu::item\n"
"{\n"
"    padding: 2px 20px 2px 20px;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:disabled\n"
"{\n"
"    color: #404040;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QAbstractItemView\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0.1 #646464, stop: 1 #5d5d5d);\n"
"}\n"
"\n"
"QWidget:focus\n"
"{\n"
"    /*border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#3995D7, stop: 1 #d7801a);*/\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0 #646464, stop: 1 #5d5d5d);\n"
"    paddin"
                        "g: 1px;\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-width: 1px;\n"
"    border-color: #1e1e1e;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    font-size: 12px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"    selection-background-color:#3995D7;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-style: solid;\n"
"    border: 1px s"
                        "olid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QComboBox:hover,QPushButton:hover\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#3995D7, stop: 1 #3995D7);\n"
"}\n"
"\n"
"\n"
"QComboBox:on\n"
"{\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"    selection-background-color:#3995D7;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    border: 2px solid darkgray;\n"
"    selection-background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#3995D7, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     border-left-width: 0px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same r"
                        "adius as the QComboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"     image: url(:/down_arrow.png);\n"
"}\n"
"\n"
"QGroupBox:focus\n"
"{\n"
"border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#3995D7, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QTextEdit:focus\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#3995D7, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"     border: 1px solid #222222;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"     height: 7px;\n"
"     margin: 0px 16px 0 16px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0#3995D7, stop: 0.5 #d7801a, stop: 1#3995D7);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2p"
                        "x;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0#3995D7, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"      subcontrol-position: right;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0#3995D7, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"      width: 7px;\n"
"      m"
                        "argin: 16px 0 16px 0;\n"
"      border: 1px solid #222222;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#3995D7, stop: 0.5 #d7801a, stop: 1#3995D7);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#3995D7, stop: 1 #d7801a);\n"
"      height: 14px;\n"
"      subcontrol-position: bottom;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #d7801a, stop: 1#3995D7);\n"
"      height: 14px;\n"
"      subcontrol-position: top;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical\n"
"{\n"
"      border: 1px"
                        " solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"}\n"
"\n"
"QCheckBox:disabled\n"
"{\n"
"color: #414141;\n"
"}\n"
"\n"
"QDockWidget::title\n"
"{\n"
"    text-align: center;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button, QDockWidget::float-button\n"
"{\n"
"    text-align: center;\n"
"    "
                        "spacing: 1px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover\n"
"{\n"
"    background: #242424;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed, QDockWidget::float-button:pressed\n"
"{\n"
"    padding: 1px -1px -1px 1px;\n"
"}\n"
"\n"
"QMainWindow::separator\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #4c4c4c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QMainWindow::separator:hover\n"
"{\n"
"\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d7801a, stop:0.5 #b56c17 stop:1#3995D7);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"    spacing: 3px; /"
                        "* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QToolBar::handle\n"
"{\n"
"     spacing: 3px; /* spacing between items in the tool bar */\n"
"     background: url(:/images/handle.png);\n"
"}\n"
"\n"
"QMenu::separator\n"
"{\n"
"    height: 2px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QProgressBar\n"
"{\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"    background-color:#3995D7;\n"
"    width: 2.15px;\n"
"    margin: 0.5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    color: #b1b1b1;\n"
"    border: 1px solid #444;\n"
"    border-bottom-style: none;\n"
"    background-color: #323232;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 3px;\n"
"    padding-bottom: 2px;\n"
"    margin-right"
                        ": -1px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #444;\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:last\n"
"{\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"    border-top-right-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:first:!selected\n"
"{\n"
" margin-left: 0px; /* the last selected tab has nothing to overlap with on the right */\n"
"\n"
"\n"
"    border-top-left-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"    color: #b1b1b1;\n"
"    border-bottom-style: solid;\n"
"    margin-top: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:.4 #343434);\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    margin-bottom: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover\n"
"{\n"
"    /*border-top: 2px solid#3995D7;\n"
"    padding-bottom: 3px;*/\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
""
                        "    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:0.4 #343434, stop:0.2 #343434, stop:0.1#3995D7);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked, QRadioButton::indicator:unchecked{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"    background-color: qradialgradient(\n"
"        cx: 0.5, cy: 0.5,\n"
"        fx: 0.5, fy: 0.5,\n"
"        radius: 1.0,\n"
"        stop: 0.25#3995D7,\n"
"        stop: 0.3 #323232\n"
"    );\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    width: 9px;\n"
"    height: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator\n"
"{\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover, QCheckBox::indicator:hover\n"
"{\n"
"    border: 1px solid#3995D7;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/images/"
                        "checkbox.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled\n"
"{\n"
"    border: 1px solid #444;\n"
"}"));
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 841, 681));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        tabwidget = new QTabWidget(groupBox);
        tabwidget->setObjectName(QStringLiteral("tabwidget"));
        tabwidget->setGeometry(QRect(10, 30, 821, 640));
        tabwidget->setMinimumSize(QSize(701, 0));
        QFont font1;
        font1.setPointSize(8);
        tabwidget->setFont(font1);
        tabwidget->setAutoFillBackground(false);
        tabwidget->setStyleSheet(QStringLiteral(""));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_6 = new QGroupBox(tab_4);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 30, 296, 187));
        groupBox_6->setFont(font);
        formLayout_2 = new QFormLayout(groupBox_6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_10 = new QLabel(groupBox_6);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_10);

        lineEdit_ajout_id = new QLineEdit(groupBox_6);
        lineEdit_ajout_id->setObjectName(QStringLiteral("lineEdit_ajout_id"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_ajout_id);

        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_9);

        lineEdit_ajout_capasiti = new QLineEdit(groupBox_6);
        lineEdit_ajout_capasiti->setObjectName(QStringLiteral("lineEdit_ajout_capasiti"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_ajout_capasiti);

        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_11);

        dateTimeEdit_ajout1 = new QDateTimeEdit(groupBox_6);
        dateTimeEdit_ajout1->setObjectName(QStringLiteral("dateTimeEdit_ajout1"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, dateTimeEdit_ajout1);

        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_13);

        dateTimeEdit_ajout2 = new QDateTimeEdit(groupBox_6);
        dateTimeEdit_ajout2->setObjectName(QStringLiteral("dateTimeEdit_ajout2"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, dateTimeEdit_ajout2);

        pushButton_2 = new QPushButton(groupBox_6);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        formLayout_2->setWidget(4, QFormLayout::SpanningRole, pushButton_2);

        groupBox_supp = new QGroupBox(tab_4);
        groupBox_supp->setObjectName(QStringLiteral("groupBox_supp"));
        groupBox_supp->setGeometry(QRect(620, 30, 190, 124));
        groupBox_supp->setFont(font);
        formLayout_26 = new QFormLayout(groupBox_supp);
        formLayout_26->setObjectName(QStringLiteral("formLayout_26"));
        label_63 = new QLabel(groupBox_supp);
        label_63->setObjectName(QStringLiteral("label_63"));

        formLayout_26->setWidget(0, QFormLayout::LabelRole, label_63);

        lineEdit_supp = new QLineEdit(groupBox_supp);
        lineEdit_supp->setObjectName(QStringLiteral("lineEdit_supp"));

        formLayout_26->setWidget(1, QFormLayout::LabelRole, lineEdit_supp);

        pushButton_29 = new QPushButton(groupBox_supp);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));

        formLayout_26->setWidget(2, QFormLayout::SpanningRole, pushButton_29);

        groupBox_modifer = new QGroupBox(tab_4);
        groupBox_modifer->setObjectName(QStringLiteral("groupBox_modifer"));
        groupBox_modifer->setGeometry(QRect(310, 30, 296, 187));
        groupBox_modifer->setFont(font);
        formLayout_3 = new QFormLayout(groupBox_modifer);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_65 = new QLabel(groupBox_modifer);
        label_65->setObjectName(QStringLiteral("label_65"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_65);

        le_modifer_id_studio = new QLineEdit(groupBox_modifer);
        le_modifer_id_studio->setObjectName(QStringLiteral("le_modifer_id_studio"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, le_modifer_id_studio);

        label_66 = new QLabel(groupBox_modifer);
        label_66->setObjectName(QStringLiteral("label_66"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_66);

        le_modifer_capasi = new QLineEdit(groupBox_modifer);
        le_modifer_capasi->setObjectName(QStringLiteral("le_modifer_capasi"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, le_modifer_capasi);

        label_67 = new QLabel(groupBox_modifer);
        label_67->setObjectName(QStringLiteral("label_67"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_67);

        dateTimeEdit_modifer1 = new QDateTimeEdit(groupBox_modifer);
        dateTimeEdit_modifer1->setObjectName(QStringLiteral("dateTimeEdit_modifer1"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, dateTimeEdit_modifer1);

        label_68 = new QLabel(groupBox_modifer);
        label_68->setObjectName(QStringLiteral("label_68"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_68);

        dateTimeEdit_modifer2 = new QDateTimeEdit(groupBox_modifer);
        dateTimeEdit_modifer2->setObjectName(QStringLiteral("dateTimeEdit_modifer2"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, dateTimeEdit_modifer2);

        modiferbotton = new QPushButton(groupBox_modifer);
        modiferbotton->setObjectName(QStringLiteral("modiferbotton"));

        formLayout_3->setWidget(4, QFormLayout::SpanningRole, modiferbotton);

        tableView_6 = new QTableView(tab_4);
        tableView_6->setObjectName(QStringLiteral("tableView_6"));
        tableView_6->setGeometry(QRect(10, 250, 600, 331));
        label_param = new QLabel(tab_4);
        label_param->setObjectName(QStringLiteral("label_param"));
        label_param->setGeometry(QRect(620, 270, 200, 211));
        tabwidget->addTab(tab_4, QString());
        mail = new QWidget();
        mail->setObjectName(QStringLiteral("mail"));
        groupBoxMessage = new QGroupBox(mail);
        groupBoxMessage->setObjectName(QStringLiteral("groupBoxMessage"));
        groupBoxMessage->setGeometry(QRect(80, 330, 478, 216));
        verticalLayout_42 = new QVBoxLayout(groupBoxMessage);
        verticalLayout_42->setSpacing(9);
        verticalLayout_42->setObjectName(QStringLiteral("verticalLayout_42"));
        verticalLayout_43 = new QVBoxLayout();
        verticalLayout_43->setSpacing(6);
        verticalLayout_43->setObjectName(QStringLiteral("verticalLayout_43"));
        labelSubject_6 = new QLabel(groupBoxMessage);
        labelSubject_6->setObjectName(QStringLiteral("labelSubject_6"));

        verticalLayout_43->addWidget(labelSubject_6);

        lineEditSubject_6 = new QLineEdit(groupBoxMessage);
        lineEditSubject_6->setObjectName(QStringLiteral("lineEditSubject_6"));

        verticalLayout_43->addWidget(lineEditSubject_6);


        verticalLayout_42->addLayout(verticalLayout_43);

        verticalLayout_44 = new QVBoxLayout();
        verticalLayout_44->setSpacing(6);
        verticalLayout_44->setObjectName(QStringLiteral("verticalLayout_44"));
        labelContent_6 = new QLabel(groupBoxMessage);
        labelContent_6->setObjectName(QStringLiteral("labelContent_6"));

        verticalLayout_44->addWidget(labelContent_6);

        textEditContent_6 = new QTextEdit(groupBoxMessage);
        textEditContent_6->setObjectName(QStringLiteral("textEditContent_6"));

        verticalLayout_44->addWidget(textEditContent_6);


        verticalLayout_42->addLayout(verticalLayout_44);

        groupBoxFrom = new QGroupBox(mail);
        groupBoxFrom->setObjectName(QStringLiteral("groupBoxFrom"));
        groupBoxFrom->setGeometry(QRect(80, 154, 478, 82));
        verticalLayout_45 = new QVBoxLayout(groupBoxFrom);
        verticalLayout_45->setObjectName(QStringLiteral("verticalLayout_45"));
        verticalLayout_46 = new QVBoxLayout();
        verticalLayout_46->setObjectName(QStringLiteral("verticalLayout_46"));
        verticalLayout_46->setContentsMargins(-1, 0, -1, -1);
        labelEmailFrom_6 = new QLabel(groupBoxFrom);
        labelEmailFrom_6->setObjectName(QStringLiteral("labelEmailFrom_6"));

        verticalLayout_46->addWidget(labelEmailFrom_6);

        lineEditEmailFrom_6 = new QLineEdit(groupBoxFrom);
        lineEditEmailFrom_6->setObjectName(QStringLiteral("lineEditEmailFrom_6"));

        verticalLayout_46->addWidget(lineEditEmailFrom_6);


        verticalLayout_45->addLayout(verticalLayout_46);

        groupBoxCredentials = new QGroupBox(mail);
        groupBoxCredentials->setObjectName(QStringLiteral("groupBoxCredentials"));
        groupBoxCredentials->setGeometry(QRect(80, 16, 478, 132));
        verticalLayout_47 = new QVBoxLayout(groupBoxCredentials);
        verticalLayout_47->setSpacing(6);
        verticalLayout_47->setObjectName(QStringLiteral("verticalLayout_47"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(9);
        gridLayout_6->setVerticalSpacing(6);
        lineEditHost_6 = new QLineEdit(groupBoxCredentials);
        lineEditHost_6->setObjectName(QStringLiteral("lineEditHost_6"));

        gridLayout_6->addWidget(lineEditHost_6, 3, 1, 1, 1);

        labelEmailCredentials_6 = new QLabel(groupBoxCredentials);
        labelEmailCredentials_6->setObjectName(QStringLiteral("labelEmailCredentials_6"));

        gridLayout_6->addWidget(labelEmailCredentials_6, 0, 1, 1, 1);

        spinBoxPort_6 = new QSpinBox(groupBoxCredentials);
        spinBoxPort_6->setObjectName(QStringLiteral("spinBoxPort_6"));
        spinBoxPort_6->setMinimumSize(QSize(50, 0));
        spinBoxPort_6->setAlignment(Qt::AlignCenter);
        spinBoxPort_6->setMaximum(999999);
        spinBoxPort_6->setValue(465);

        gridLayout_6->addWidget(spinBoxPort_6, 3, 3, 1, 1);

        lineEditPasswordCredentials_6 = new QLineEdit(groupBoxCredentials);
        lineEditPasswordCredentials_6->setObjectName(QStringLiteral("lineEditPasswordCredentials_6"));
        lineEditPasswordCredentials_6->setEchoMode(QLineEdit::Password);

        gridLayout_6->addWidget(lineEditPasswordCredentials_6, 1, 3, 1, 1);

        lineEditEmailCredentials_6 = new QLineEdit(groupBoxCredentials);
        lineEditEmailCredentials_6->setObjectName(QStringLiteral("lineEditEmailCredentials_6"));

        gridLayout_6->addWidget(lineEditEmailCredentials_6, 1, 1, 1, 1);

        labelHost_6 = new QLabel(groupBoxCredentials);
        labelHost_6->setObjectName(QStringLiteral("labelHost_6"));

        gridLayout_6->addWidget(labelHost_6, 2, 1, 1, 1);

        labelPasswordCredentials_6 = new QLabel(groupBoxCredentials);
        labelPasswordCredentials_6->setObjectName(QStringLiteral("labelPasswordCredentials_6"));

        gridLayout_6->addWidget(labelPasswordCredentials_6, 0, 3, 1, 1);

        labelPort_6 = new QLabel(groupBoxCredentials);
        labelPort_6->setObjectName(QStringLiteral("labelPort_6"));

        gridLayout_6->addWidget(labelPort_6, 2, 3, 1, 1);


        verticalLayout_47->addLayout(gridLayout_6);

        groupBoxTo = new QGroupBox(mail);
        groupBoxTo->setObjectName(QStringLiteral("groupBoxTo"));
        groupBoxTo->setGeometry(QRect(80, 242, 478, 82));
        verticalLayout_48 = new QVBoxLayout(groupBoxTo);
        verticalLayout_48->setSpacing(6);
        verticalLayout_48->setObjectName(QStringLiteral("verticalLayout_48"));
        verticalLayout_49 = new QVBoxLayout();
        verticalLayout_49->setSpacing(6);
        verticalLayout_49->setObjectName(QStringLiteral("verticalLayout_49"));
        labelEmail_6 = new QLabel(groupBoxTo);
        labelEmail_6->setObjectName(QStringLiteral("labelEmail_6"));

        verticalLayout_49->addWidget(labelEmail_6);

        lineEditEmailTo_6 = new QLineEdit(groupBoxTo);
        lineEditEmailTo_6->setObjectName(QStringLiteral("lineEditEmailTo_6"));

        verticalLayout_49->addWidget(lineEditEmailTo_6);


        verticalLayout_48->addLayout(verticalLayout_49);

        layoutWidget = new QWidget(mail);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(74, 570, 571, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        pushButtonSend_6 = new QPushButton(layoutWidget);
        pushButtonSend_6->setObjectName(QStringLiteral("pushButtonSend_6"));
        pushButtonSend_6->setMinimumSize(QSize(100, 30));
        pushButtonSend_6->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButtonSend_6);

        pushButtonClear_6 = new QPushButton(layoutWidget);
        pushButtonClear_6->setObjectName(QStringLiteral("pushButtonClear_6"));
        pushButtonClear_6->setMinimumSize(QSize(100, 30));
        pushButtonClear_6->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButtonClear_6);

        label_gif_mail = new QLabel(mail);
        label_gif_mail->setObjectName(QStringLiteral("label_gif_mail"));
        label_gif_mail->setGeometry(QRect(580, 130, 230, 271));
        tabwidget->addTab(mail, QString());
        afficher_studio = new QWidget();
        afficher_studio->setObjectName(QStringLiteral("afficher_studio"));
        scrollArea_2 = new QScrollArea(afficher_studio);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(40, 90, 711, 470));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 709, 468));
        tableView_2 = new QTableView(scrollAreaWidgetContents_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(10, 10, 691, 450));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        layoutWidget1 = new QWidget(afficher_studio);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 30, 625, 32));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox = new QCheckBox(layoutWidget1);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_3->addWidget(checkBox);

        checkBox_3 = new QCheckBox(layoutWidget1);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setAutoFillBackground(false);
        checkBox_3->setChecked(false);

        horizontalLayout_3->addWidget(checkBox_3);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        lineEdit_recherche = new QLineEdit(layoutWidget1);
        lineEdit_recherche->setObjectName(QStringLiteral("lineEdit_recherche"));

        horizontalLayout_2->addWidget(lineEdit_recherche);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        layoutWidget2 = new QWidget(afficher_studio);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 570, 760, 28));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(147, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_4);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        pushButton_9 = new QPushButton(layoutWidget2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        horizontalLayout_13->addWidget(pushButton_9);

        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/IMG8RES FOR QT/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);

        horizontalLayout_13->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/IMG8RES FOR QT/stat.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);

        horizontalLayout_13->addWidget(pushButton_4);


        horizontalLayout_14->addLayout(horizontalLayout_13);

        horizontalSpacer_5 = new QSpacerItem(117, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_5);

        tabwidget->addTab(afficher_studio, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 890, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabwidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ON AIR ", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Gestion studio", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tabwidget->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_6->setTitle(QApplication::translate("MainWindow", "ajouter studio", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "studio identifan", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "capacite", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "reservation from", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "reservation to", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "ok", Q_NULLPTR));
        groupBox_supp->setTitle(QApplication::translate("MainWindow", "supprimer studio  ", Q_NULLPTR));
        label_63->setText(QApplication::translate("MainWindow", "donner ID de studio", Q_NULLPTR));
        lineEdit_supp->setText(QString());
        lineEdit_supp->setPlaceholderText(QApplication::translate("MainWindow", "....", Q_NULLPTR));
        pushButton_29->setText(QApplication::translate("MainWindow", "ok", Q_NULLPTR));
        groupBox_modifer->setTitle(QApplication::translate("MainWindow", "modifer studio", Q_NULLPTR));
        label_65->setText(QApplication::translate("MainWindow", "ID de studio", Q_NULLPTR));
        le_modifer_id_studio->setPlaceholderText(QString());
        label_66->setText(QApplication::translate("MainWindow", "capacite", Q_NULLPTR));
        le_modifer_capasi->setPlaceholderText(QString());
        label_67->setText(QApplication::translate("MainWindow", "reservation from", Q_NULLPTR));
        label_68->setText(QApplication::translate("MainWindow", "reservation to", Q_NULLPTR));
        modiferbotton->setText(QApplication::translate("MainWindow", "ok", Q_NULLPTR));
        label_param->setText(QString());
        tabwidget->setTabText(tabwidget->indexOf(tab_4), QApplication::translate("MainWindow", "Pararametre studio", Q_NULLPTR));
        groupBoxMessage->setTitle(QApplication::translate("MainWindow", "Message", Q_NULLPTR));
        labelSubject_6->setText(QApplication::translate("MainWindow", "Subject", Q_NULLPTR));
        labelContent_6->setText(QApplication::translate("MainWindow", "Content", Q_NULLPTR));
        groupBoxFrom->setTitle(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        labelEmailFrom_6->setText(QApplication::translate("MainWindow", "E-mail", Q_NULLPTR));
        groupBoxCredentials->setTitle(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        lineEditHost_6->setText(QApplication::translate("MainWindow", "smtp.gmail.com", Q_NULLPTR));
        labelEmailCredentials_6->setText(QApplication::translate("MainWindow", "E-mail", Q_NULLPTR));
        labelHost_6->setText(QApplication::translate("MainWindow", "Host", Q_NULLPTR));
        labelPasswordCredentials_6->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        labelPort_6->setText(QApplication::translate("MainWindow", "Port", Q_NULLPTR));
        groupBoxTo->setTitle(QApplication::translate("MainWindow", "To", Q_NULLPTR));
        labelEmail_6->setText(QApplication::translate("MainWindow", "E-mail", Q_NULLPTR));
        pushButtonSend_6->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        pushButtonClear_6->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        label_gif_mail->setText(QString());
        tabwidget->setTabText(tabwidget->indexOf(mail), QApplication::translate("MainWindow", "mail", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "CAPASITE", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "ID STUDIO", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "CHERCHE", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "ACTUALISER", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "save as pdf ", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "statistique top 5", Q_NULLPTR));
        tabwidget->setTabText(tabwidget->indexOf(afficher_studio), QApplication::translate("MainWindow", "afficher studio", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
