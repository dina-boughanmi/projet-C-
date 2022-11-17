/********************************************************************************
** Form generated from reading UI file 'log_param.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_PARAM_H
#define UI_LOG_PARAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_log_param
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_ajout_pwd_admin;
    QLineEdit *lineEdit_ajout_username_2;
    QLineEdit *lineEdit_ajout_pwd;
    QPushButton *pushButton_ajout_user;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_modifer_username;
    QLineEdit *lineEdit_modifer_oldpwd_admin;
    QLineEdit *lineEdit_modifer_newpwd;
    QPushButton *pushButton_modiferuser;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_supp_pwdadmin;
    QLineEdit *lineEdit_supp_username;
    QPushButton *pushButton_supp_user;
    QLabel *label_SHILD;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *log_param)
    {
        if (log_param->objectName().isEmpty())
            log_param->setObjectName(QStringLiteral("log_param"));
        log_param->resize(855, 710);
        QIcon icon;
        icon.addFile(QStringLiteral(":/IMG8RES FOR QT/on air.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        log_param->setWindowIcon(icon);
        log_param->setStyleSheet(QLatin1String("QWidget {\n"
"    background-color: rgb(225, 225, 225);\n"
"    color: rgb(225, 225, 225);\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"\n"
"/* QGroupBox */\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"QGroupBox {\n"
"    border: 2px solid;\n"
"    border-radius: 5px;\n"
"\n"
"    margin-top: 20px;\n"
"    margin-bottom: 10px;\n"
"\n"
"    border-color: rgb(80, 80, 200);\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding-left: 3px;\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"QFrame#horizontalLineMiddleSeparator {\n"
"    background-color: rgb(80, 80, 200 );\n"
"}\n"
"\n"
"/* Process Scanner QFrame horizontal lines  */\n"
"/* --------------------------------------------------------------------------------------"
                        "-------------- */\n"
"QFrame#lineScanner {\n"
"    background-color: rgb(80, 80, 200);\n"
"}\n"
"\n"
"QFrame#lineScanFilters {\n"
"    background-color: rgb(80, 80, 200);\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"\n"
"/* QSpinBox  */\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"QSpinBox {\n"
"    border: 1px solid rgb(80, 80, 200);\n"
"}\n"
"\n"
"QSpinBox::up-arrow {\n"
"    image: url(:/icons/up-arrow.png);\n"
"}\n"
"\n"
"QSpinBox::down-arrow {\n"
"    image: url(:/icons/down-arrow.png);\n"
"}\n"
"\n"
"QSpinBox::text {\n"
"    background-color: rgb(80, 80, 200);\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"\n"
"\n"
"\n"
"/* QSlider horizontal/vertical  */\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"QSlider:ho"
                        "rizontal,\n"
"QSlider:vertical {\n"
"    background-color: rgb(40, 40, 100);\n"
"    height: 18px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    height: 18px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background-color: rgb(80, 80, 200);\n"
"    width: 10px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover,\n"
"QSlider::handle:vertical:hover {\n"
"    background-color: rgb(150, 150, 250);\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"\n"
"\n"
"\n"
"/* QLineEdit & QTextEdit */\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"QLineEdit,\n"
"QTextEdit {\n"
"    border: 1px solid;\n"
"    border-radius: 2px;\n"
"    border-color: rgb(80, 80, 200);\n"
"    min-height: 25px;\n"
"    padding-left: 5px;\n"
"}\n"
"\n"
"QLineEdit[text=\"\"] {\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QLineEdit::disabl"
                        "ed {\n"
"    color: rgb(100, 100, 150);\n"
"    border-color: rgb(50, 50, 100);\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"\n"
"\n"
"\n"
"/* QMenu */\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"QMenu {\n"
"    border: 1px solid;\n"
"    border-radius: 2px;\n"
"    border-color: rgb(80, 80, 200);\n"
"\n"
"}\n"
"\n"
"QMenu::item {\n"
"    color: rgb(150, 150, 250);\n"
"    border: 1px solid;\n"
"    border-color: rgb(80, 80, 200);\n"
"\n"
"    padding: 5px;\n"
"\n"
"    outline: 0;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: rgb(40, 40, 200);\n"
"}\n"
"\n"
"QMenu::indicator {\n"
"    margin-left: 4px;\n"
"}\n"
"\n"
"QMenu::indicator:checked {\n"
"    border: 2px solid;\n"
"    border-radius: 2px;\n"
"\n"
"    border-color:   rgb(80, 80, 200);\n"
"    background-color: rgb(80, 80, 200);\n"
"\n"
"}\n"
"\n"
"QMenu::indicator:unchecked {\n"
"   "
                        " border: 2px solid;\n"
"    border-radius: 2px;\n"
"\n"
"    border-color:   rgb(80, 80, 200);\n"
"    color: rgb(100, 100, 150);\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"\n"
"\n"
"\n"
"/* QHeaderView */\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"QHeaderView::section:horizontal,\n"
"QHeaderView::section:vertical\n"
"{\n"
"    background-color: rgb(30, 30, 100);\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"\n"
"\n"
"\n"
"/* QScrollBar  */\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"QScrollBar:vertical,\n"
"QScrollBar:horizontal {\n"
"\n"
"    border-color: rgb(90, 90, 255);\n"
"}\n"
"\n"
"QScrollBar::handle:vertical,\n"
"QScrollBar::handle:horizontal {\n"
"    background-color: rgb(40, 40, 150);\n"
"}\n"
"\n"
""
                        "QScrollBar::handle:hover:vertical,\n"
"QScrollBar::handle:hover:horizontal {\n"
"    background-color: rgb(40, 40, 200);\n"
"}\n"
"\n"
"QScrollBar::up-arrow:horizontal,\n"
"QScrollBar::down-arrow:horizontal,\n"
"QScrollBar::sub-line:vertical,\n"
"QScrollBar::add-line:vertical {\n"
"    background-color: rgb(20, 20, 30);\n"
"    color: rgb(20, 20, 30);\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical,\n"
"QScrollBar::down-arrow:vertical,\n"
"QScrollBar::up-arrow:horizontal,\n"
"QScrollBar::down-arrow:horizontal {\n"
"    background-color: rgb(20, 20, 30);\n"
"    border-color: rgb(20, 20, 30);\n"
"    color: rgb(20, 20, 30);\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal,\n"
"QScrollBar::sub-page:horizontal,\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical {\n"
"    background-color: rgb(20, 20, 30);\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"/* Tree/List/Table Views  */\n"
"/* ----------------"
                        "------------------------------------------------------------------------------------ */\n"
"QTreeView,\n"
"QListView,\n"
"QListView {\n"
"    border: 2px solid;\n"
"    border-color: rgb(80, 80, 200);\n"
"    border-radius: 5px;\n"
"    outline: 0;\n"
"}\n"
"\n"
"QTreeView::item,\n"
"QListView::item,\n"
"QTableView::item {\n"
"    background-color: rgb(20, 20, 90);\n"
"    outline: 0;\n"
"}\n"
"\n"
"QTreeView::item:alternate,\n"
"QListView::item:alternate,\n"
"QTableView::item:alternate {\n"
"    background-color: rgb(30, 30, 110);\n"
"    outline: 0;\n"
"}\n"
"\n"
"QTreeView::item:hover,\n"
"QTreeView::item:alternate:hover,\n"
"QListView::item:hover,\n"
"QListView::item:alternate:hover,\n"
"QTableView::item:hover,\n"
"QTableView::item:alternate:hover {\n"
"    background-color: rgb(30, 30, 150);\n"
"}\n"
"\n"
"QListView::item:selected,\n"
"QTreeView::item:selected,\n"
"QTableView::item:selected,\n"
"QTreeView::item:alternate:selected,\n"
"QListVew::item:alternate:selected,\n"
"QTableView::item:alternate:selec"
                        "ted {\n"
"    background-color: rgb(40, 40, 200);\n"
"    color: rgb(150, 150, 250);\n"
"    outline: 0;\n"
"}\n"
"\n"
"QTreeView:branch {\n"
"    background-color: rgb(20, 20, 90);\n"
"}\n"
"\n"
"QTreeView:branch:has-siblings:adjoins-item {\n"
"  border-image: url(\":/icons/branch-child-guide.png\") 0;\n"
"}\n"
"\n"
"QTreeView:branch:!has-children:!has-siblings:adjoins-item {\n"
"    border-image: url(\":/icons/branch-end-guide.png\") 0;\n"
"}\n"
"\n"
"QTreeView:branch:has-children:!has-siblings:closed,\n"
"QTreeView:branch:closed:has-children:has-siblings {\n"
"  border-image: none;\n"
"  image: url(:/icons/branch-closed.png);\n"
"}\n"
"\n"
"QTreeView:branch:open:has-children:!has-siblings,\n"
"QTreeView:branch:open:has-children:has-siblings {\n"
"    border-image: none;\n"
"    image: url(://icons/branch-open.png);\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"/* QComboBox  */\n"
"/* ---------------------------------------------"
                        "------------------------------------------------------- */\n"
"QComboBox {\n"
"    border: 1px solid;\n"
"    border-color: rgb(80, 80, 200);\n"
"    min-height: 25px;\n"
"    padding-left: 5px;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QComboBox::hover {\n"
"    background-color: rgb(40, 40, 200);\n"
"}\n"
"\n"
"QComboBox:disabled {\n"
"\n"
"    color: rgb(100, 100, 150);\n"
"    border-color: rgb(50, 50, 100);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border: 0px solid;\n"
"    border-radius: 2px;\n"
"    border-color: rgb(80, 80, 200);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item {\n"
"    color: rgb(150, 150, 250);\n"
"\n"
"    border: 1px solid;\n"
"    border-color: rgb(80, 80, 200);\n"
"\n"
"\n"
"    padding-top: 3px;\n"
"    padding-bottom: 3px;\n"
"\n"
"    outline: 0;\n"
"}\n"
"\n"
"\n"
"QComboBox QAbstractItemView::indicator:checked {\n"
"    border: 2px solid;\n"
"    border-radius: 2px;\n"
"\n"
"    border-color:   rgb(80, 80, 200);\n"
"    background-color: rgb(80, 80, 200);\n"
"}"
                        "\n"
"\n"
"\n"
"QComboBox QAbstractItemView::indicator:unchecked {\n"
"    border: 2px solid;\n"
"    border-radius: 2px;\n"
"\n"
"    border-color:   rgb(80, 80, 200);\n"
"    color: rgb(100, 100, 150);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item:hover {\n"
"    background-color: rgb(40, 40, 200);\n"
"    color: rgb(150, 150, 250);\n"
"    outline: 0;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::focus {\n"
"    border-color: rgb(150, 130, 250);\n"
"    outline: 0;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/down-arrow.png);\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"\n"
"\n"
"\n"
"/* QCheckBox  */\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"QCheckBox::indicator:checked {\n"
"    border: 2px solid;\n"
"    border-radius: 2px;\n"
"\n"
"    border-color:   rgb(80, 80, 200);\n"
"    background-color: rgb(80, 80, 200);\n"
"}\n"
"\n"
"\n"
""
                        "QCheckBox::indicator:unchecked {\n"
"    border: 2px solid;\n"
"    border-radius: 2px;\n"
"\n"
"    border-color:   rgb(80, 80, 200);\n"
"    color: rgb(100, 100, 150);\n"
"}\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"\n"
"\n"
"\n"
"\n"
"/* QPushButton */\n"
"/* ---------------------------------------------------------------------------------------------------- */\n"
"QPushButton {\n"
"    border: 1px solid;\n"
"    border-radius: 3px;\n"
"    background-color: rgb(30, 30, 100);\n"
"    border-color: rgb(80, 80, 200);\n"
"    min-height: 25px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"    background-color: rgb(40, 40, 200);\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"    background-color: rgb(50, 50, 220);\n"
"}\n"
"\n"
"QPushButton::disabled {\n"
"    background-color: rgb(20, 20, 50);\n"
"    color: rgb(100, 100, 150);\n"
"    border-color: rgb(50, 50, 100);\n"
"}\n"
"\n"
"QPushButton::"
                        "focus {\n"
"    border-color: rgb(130, 130, 200);\n"
"    outline: 0;\n"
"}"));
        centralwidget = new QWidget(log_param);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 0, 811, 661));
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QStringLiteral("color: rgb(85, 85, 255);"));
        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(50, 60, 261, 261));
        QFont font1;
        font1.setPointSize(10);
        groupBox_6->setFont(font1);
        groupBox_6->setStyleSheet(QStringLiteral("color: rgb(85, 85, 255);"));
        verticalLayout_3 = new QVBoxLayout(groupBox_6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lineEdit_ajout_pwd_admin = new QLineEdit(groupBox_6);
        lineEdit_ajout_pwd_admin->setObjectName(QStringLiteral("lineEdit_ajout_pwd_admin"));

        verticalLayout_3->addWidget(lineEdit_ajout_pwd_admin);

        lineEdit_ajout_username_2 = new QLineEdit(groupBox_6);
        lineEdit_ajout_username_2->setObjectName(QStringLiteral("lineEdit_ajout_username_2"));

        verticalLayout_3->addWidget(lineEdit_ajout_username_2);

        lineEdit_ajout_pwd = new QLineEdit(groupBox_6);
        lineEdit_ajout_pwd->setObjectName(QStringLiteral("lineEdit_ajout_pwd"));

        verticalLayout_3->addWidget(lineEdit_ajout_pwd);

        pushButton_ajout_user = new QPushButton(groupBox_6);
        pushButton_ajout_user->setObjectName(QStringLiteral("pushButton_ajout_user"));

        verticalLayout_3->addWidget(pushButton_ajout_user);

        groupBox_7 = new QGroupBox(groupBox);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(420, 360, 261, 251));
        groupBox_7->setFont(font1);
        groupBox_7->setStyleSheet(QStringLiteral("color: rgb(85, 85, 255);"));
        verticalLayout = new QVBoxLayout(groupBox_7);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit_modifer_username = new QLineEdit(groupBox_7);
        lineEdit_modifer_username->setObjectName(QStringLiteral("lineEdit_modifer_username"));

        verticalLayout->addWidget(lineEdit_modifer_username);

        lineEdit_modifer_oldpwd_admin = new QLineEdit(groupBox_7);
        lineEdit_modifer_oldpwd_admin->setObjectName(QStringLiteral("lineEdit_modifer_oldpwd_admin"));

        verticalLayout->addWidget(lineEdit_modifer_oldpwd_admin);

        lineEdit_modifer_newpwd = new QLineEdit(groupBox_7);
        lineEdit_modifer_newpwd->setObjectName(QStringLiteral("lineEdit_modifer_newpwd"));

        verticalLayout->addWidget(lineEdit_modifer_newpwd);

        pushButton_modiferuser = new QPushButton(groupBox_7);
        pushButton_modiferuser->setObjectName(QStringLiteral("pushButton_modiferuser"));

        verticalLayout->addWidget(pushButton_modiferuser);

        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(50, 360, 261, 251));
        groupBox_8->setFont(font1);
        groupBox_8->setStyleSheet(QStringLiteral("color: rgb(85, 85, 255);"));
        verticalLayout_2 = new QVBoxLayout(groupBox_8);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_supp_pwdadmin = new QLineEdit(groupBox_8);
        lineEdit_supp_pwdadmin->setObjectName(QStringLiteral("lineEdit_supp_pwdadmin"));

        verticalLayout_2->addWidget(lineEdit_supp_pwdadmin);

        lineEdit_supp_username = new QLineEdit(groupBox_8);
        lineEdit_supp_username->setObjectName(QStringLiteral("lineEdit_supp_username"));

        verticalLayout_2->addWidget(lineEdit_supp_username);

        pushButton_supp_user = new QPushButton(groupBox_8);
        pushButton_supp_user->setObjectName(QStringLiteral("pushButton_supp_user"));

        verticalLayout_2->addWidget(pushButton_supp_user);

        label_SHILD = new QLabel(groupBox);
        label_SHILD->setObjectName(QStringLiteral("label_SHILD"));
        label_SHILD->setGeometry(QRect(480, 90, 301, 221));
        log_param->setCentralWidget(centralwidget);
        menubar = new QMenuBar(log_param);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 855, 26));
        log_param->setMenuBar(menubar);
        statusbar = new QStatusBar(log_param);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        log_param->setStatusBar(statusbar);

        retranslateUi(log_param);

        QMetaObject::connectSlotsByName(log_param);
    } // setupUi

    void retranslateUi(QMainWindow *log_param)
    {
        log_param->setWindowTitle(QApplication::translate("log_param", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("log_param", "Administration utilisateur", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("log_param", "ajouter d'un utilisateur", Q_NULLPTR));
        lineEdit_ajout_pwd_admin->setText(QString());
        lineEdit_ajout_pwd_admin->setPlaceholderText(QApplication::translate("log_param", "pwd admin", Q_NULLPTR));
        lineEdit_ajout_username_2->setPlaceholderText(QApplication::translate("log_param", "user name", Q_NULLPTR));
        lineEdit_ajout_pwd->setPlaceholderText(QApplication::translate("log_param", "pwd", Q_NULLPTR));
        pushButton_ajout_user->setText(QApplication::translate("log_param", "ok", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("log_param", "modifer user", Q_NULLPTR));
        lineEdit_modifer_username->setPlaceholderText(QApplication::translate("log_param", "user name", Q_NULLPTR));
        lineEdit_modifer_oldpwd_admin->setText(QString());
        lineEdit_modifer_oldpwd_admin->setPlaceholderText(QApplication::translate("log_param", "old pwd", Q_NULLPTR));
        lineEdit_modifer_newpwd->setText(QString());
        lineEdit_modifer_newpwd->setPlaceholderText(QApplication::translate("log_param", "new pwd", Q_NULLPTR));
        pushButton_modiferuser->setText(QApplication::translate("log_param", "ok", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("log_param", "spprimer user", Q_NULLPTR));
        lineEdit_supp_pwdadmin->setText(QString());
        lineEdit_supp_pwdadmin->setPlaceholderText(QApplication::translate("log_param", "pwd admin", Q_NULLPTR));
        lineEdit_supp_username->setText(QString());
        lineEdit_supp_username->setPlaceholderText(QApplication::translate("log_param", "user name", Q_NULLPTR));
        pushButton_supp_user->setText(QApplication::translate("log_param", "ok", Q_NULLPTR));
        label_SHILD->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class log_param: public Ui_log_param {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_PARAM_H
