/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "consolelineedit.h"
#include "lcdwidget.h"
#include "mainwindow.h"
#include "usblinktreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionReset;
    QAction *actionDebugger;
    QAction *actionQuit;
    QAction *actionPause;
    QAction *actionRestart;
    QAction *actionScreenshot;
    QAction *actionConnect;
    QAction *actionSave;
    QAction *actionCreate_flash;
    QAction *actionXModem;
    QAction *actionSuspend;
    QAction *actionResume;
    QAction *actionSuspend_to_file;
    QAction *actionResume_from_file;
    QAction *actionRecord_GIF;
    QAction *actionAbout_Firebird;
    QAction *actionAbout_Qt;
    QAction *actionLCD_Window;
    QAction *actionConfiguration;
    QAction *actionSwitch_to_Mobile_UI;
    QAction *actionLeavePTT;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *buttonReset;
    QToolButton *buttonPause;
    QToolButton *buttonScreenshot;
    QToolButton *buttonUSB;
    QPushButton *buttonSpeed;
    LCDWidget *lcdView;
    QTabWidget *tabWidget;
    QWidget *tabDebugger;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *debugConsole;
    ConsoleLineEdit *lineEdit;
    QWidget *tabFiles;
    QVBoxLayout *verticalLayout_2;
    USBLinkTreeWidget *usblinkTree;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *refreshButton;
    QProgressBar *progressBar;
    QWidget *tabSerial;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *serialConsole;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_5;
    QQuickWidgetLessBroken *keypadWidget;
    QStatusBar *statusBar;
    QMenuBar *menubar;
    QMenu *menuEmulation;
    QMenu *menuRestart_with_Kit;
    QMenu *menuBoot_Diags_with_Kit;
    QMenu *menuFlash;
    QMenu *menuTools;
    QMenu *menuLanguage;
    QMenu *menuState;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(714, 370);
        MainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/resources/org.firebird-emus.firebird-emu.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/resources/icons/system-reboot.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon1);
        actionDebugger = new QAction(MainWindow);
        actionDebugger->setObjectName(QString::fromUtf8("actionDebugger"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/resources/icons/tools-report-bug.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDebugger->setIcon(icon2);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/resources/icons/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon3);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionPause->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/resources/icons/Actions-media-playback-pause-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon4);
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QString::fromUtf8("actionRestart"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/resources/icons/edit-bomb.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestart->setIcon(icon5);
        actionScreenshot = new QAction(MainWindow);
        actionScreenshot->setObjectName(QString::fromUtf8("actionScreenshot"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/resources/icons/camera-photo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScreenshot->setIcon(icon6);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionConnect->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/resources/icons/Actions-network-disconnect-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/icons/resources/icons/Actions-network-connect-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionConnect->setIcon(icon7);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/resources/icons/media-floppy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon8);
        actionCreate_flash = new QAction(MainWindow);
        actionCreate_flash->setObjectName(QString::fromUtf8("actionCreate_flash"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/resources/icons/flash-create.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_flash->setIcon(icon9);
        actionXModem = new QAction(MainWindow);
        actionXModem->setObjectName(QString::fromUtf8("actionXModem"));
        actionSuspend = new QAction(MainWindow);
        actionSuspend->setObjectName(QString::fromUtf8("actionSuspend"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/resources/icons/system-suspend.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSuspend->setIcon(icon10);
        actionResume = new QAction(MainWindow);
        actionResume->setObjectName(QString::fromUtf8("actionResume"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/resources/icons/system-suspend-hibernate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionResume->setIcon(icon11);
        actionSuspend_to_file = new QAction(MainWindow);
        actionSuspend_to_file->setObjectName(QString::fromUtf8("actionSuspend_to_file"));
        actionSuspend_to_file->setIcon(icon10);
        actionResume_from_file = new QAction(MainWindow);
        actionResume_from_file->setObjectName(QString::fromUtf8("actionResume_from_file"));
        actionResume_from_file->setIcon(icon11);
        actionRecord_GIF = new QAction(MainWindow);
        actionRecord_GIF->setObjectName(QString::fromUtf8("actionRecord_GIF"));
        actionRecord_GIF->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/resources/icons/kmplayer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecord_GIF->setIcon(icon12);
        actionAbout_Firebird = new QAction(MainWindow);
        actionAbout_Firebird->setObjectName(QString::fromUtf8("actionAbout_Firebird"));
        actionAbout_Firebird->setIcon(icon);
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionLCD_Window = new QAction(MainWindow);
        actionLCD_Window->setObjectName(QString::fromUtf8("actionLCD_Window"));
        actionLCD_Window->setCheckable(true);
        actionConfiguration = new QAction(MainWindow);
        actionConfiguration->setObjectName(QString::fromUtf8("actionConfiguration"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/resources/icons/preferences-other.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfiguration->setIcon(icon13);
        actionSwitch_to_Mobile_UI = new QAction(MainWindow);
        actionSwitch_to_Mobile_UI->setObjectName(QString::fromUtf8("actionSwitch_to_Mobile_UI"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/resources/icons/smartphone.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSwitch_to_Mobile_UI->setIcon(icon14);
        actionLeavePTT = new QAction(MainWindow);
        actionLeavePTT->setObjectName(QString::fromUtf8("actionLeavePTT"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        buttonReset = new QToolButton(frame);
        buttonReset->setObjectName(QString::fromUtf8("buttonReset"));
        buttonReset->setIcon(icon1);
        buttonReset->setIconSize(QSize(24, 24));
        buttonReset->setAutoRaise(true);

        horizontalLayout_7->addWidget(buttonReset);

        buttonPause = new QToolButton(frame);
        buttonPause->setObjectName(QString::fromUtf8("buttonPause"));
        buttonPause->setIcon(icon4);
        buttonPause->setIconSize(QSize(24, 24));
        buttonPause->setCheckable(true);
        buttonPause->setAutoRaise(true);

        horizontalLayout_7->addWidget(buttonPause);

        buttonScreenshot = new QToolButton(frame);
        buttonScreenshot->setObjectName(QString::fromUtf8("buttonScreenshot"));
        buttonScreenshot->setIcon(icon6);
        buttonScreenshot->setIconSize(QSize(24, 24));
        buttonScreenshot->setAutoRaise(true);

        horizontalLayout_7->addWidget(buttonScreenshot);

        buttonUSB = new QToolButton(frame);
        buttonUSB->setObjectName(QString::fromUtf8("buttonUSB"));
        buttonUSB->setIcon(icon7);
        buttonUSB->setIconSize(QSize(24, 24));
        buttonUSB->setCheckable(true);
        buttonUSB->setAutoRaise(true);

        horizontalLayout_7->addWidget(buttonUSB);

        buttonSpeed = new QPushButton(frame);
        buttonSpeed->setObjectName(QString::fromUtf8("buttonSpeed"));
        buttonSpeed->setCheckable(true);
        buttonSpeed->setFlat(true);

        horizontalLayout_7->addWidget(buttonSpeed);


        verticalLayout_6->addLayout(horizontalLayout_7);

        lcdView = new LCDWidget(frame);
        lcdView->setObjectName(QString::fromUtf8("lcdView"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdView->sizePolicy().hasHeightForWidth());
        lcdView->setSizePolicy(sizePolicy);
        lcdView->setMinimumSize(QSize(320, 240));
        lcdView->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_6->addWidget(lcdView);


        verticalLayout_8->addWidget(frame);


        horizontalLayout->addLayout(verticalLayout_8);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabDebugger = new QWidget();
        tabDebugger->setObjectName(QString::fromUtf8("tabDebugger"));
        verticalLayout = new QVBoxLayout(tabDebugger);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        debugConsole = new QPlainTextEdit(tabDebugger);
        debugConsole->setObjectName(QString::fromUtf8("debugConsole"));
        QFont font;
        font.setFamily(QString::fromUtf8("Droid Sans Mono"));
        debugConsole->setFont(font);
        debugConsole->setUndoRedoEnabled(false);
        debugConsole->setLineWrapMode(QPlainTextEdit::NoWrap);
        debugConsole->setReadOnly(true);
        debugConsole->setPlainText(QString::fromUtf8(""));

        verticalLayout->addWidget(debugConsole);

        lineEdit = new ConsoleLineEdit(tabDebugger);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setFont(font);

        verticalLayout->addWidget(lineEdit);

        tabWidget->addTab(tabDebugger, icon2, QString());
        tabFiles = new QWidget();
        tabFiles->setObjectName(QString::fromUtf8("tabFiles"));
        verticalLayout_2 = new QVBoxLayout(tabFiles);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        usblinkTree = new USBLinkTreeWidget(tabFiles);
        usblinkTree->setObjectName(QString::fromUtf8("usblinkTree"));
        usblinkTree->setContextMenuPolicy(Qt::CustomContextMenu);
        usblinkTree->header()->setDefaultSectionSize(219);

        verticalLayout_2->addWidget(usblinkTree);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        refreshButton = new QPushButton(tabFiles);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setIcon(icon1);
        refreshButton->setIconSize(QSize(20, 20));
        refreshButton->setFlat(true);

        horizontalLayout_6->addWidget(refreshButton);

        progressBar = new QProgressBar(tabFiles);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_6->addWidget(progressBar);


        verticalLayout_2->addLayout(horizontalLayout_6);

        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/resources/icons/document.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabFiles, icon15, QString());
        tabSerial = new QWidget();
        tabSerial->setObjectName(QString::fromUtf8("tabSerial"));
        verticalLayout_3 = new QVBoxLayout(tabSerial);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        serialConsole = new QPlainTextEdit(tabSerial);
        serialConsole->setObjectName(QString::fromUtf8("serialConsole"));
        serialConsole->setUndoRedoEnabled(false);
        serialConsole->setLineWrapMode(QPlainTextEdit::NoWrap);
        serialConsole->setReadOnly(true);

        verticalLayout_3->addWidget(serialConsole);

        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/resources/icons/utilities-terminal.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabSerial, icon16, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_5 = new QHBoxLayout(tab);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        keypadWidget = new QQuickWidgetLessBroken(tab);
        keypadWidget->setObjectName(QString::fromUtf8("keypadWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(keypadWidget->sizePolicy().hasHeightForWidth());
        keypadWidget->setSizePolicy(sizePolicy1);
        keypadWidget->setMinimumSize(QSize(265, 90));
        keypadWidget->setMaximumSize(QSize(999999, 999999));
        keypadWidget->setFocusPolicy(Qt::NoFocus);
        keypadWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
        keypadWidget->setSource(QUrl(QString::fromUtf8("qrc:/qml/qml/ScrollingKeypad.qml")));

        horizontalLayout_5->addWidget(keypadWidget);

        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/resources/icons/preferences-desktop-keyboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon17, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 714, 19));
        menuEmulation = new QMenu(menubar);
        menuEmulation->setObjectName(QString::fromUtf8("menuEmulation"));
        menuRestart_with_Kit = new QMenu(menuEmulation);
        menuRestart_with_Kit->setObjectName(QString::fromUtf8("menuRestart_with_Kit"));
        menuRestart_with_Kit->setIcon(icon5);
        menuBoot_Diags_with_Kit = new QMenu(menuEmulation);
        menuBoot_Diags_with_Kit->setObjectName(QString::fromUtf8("menuBoot_Diags_with_Kit"));
        menuBoot_Diags_with_Kit->setIcon(icon5);
        menuFlash = new QMenu(menubar);
        menuFlash->setObjectName(QString::fromUtf8("menuFlash"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuLanguage = new QMenu(menuTools);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        menuState = new QMenu(menubar);
        menuState->setObjectName(QString::fromUtf8("menuState"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuEmulation->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuState->menuAction());
        menubar->addAction(menuFlash->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuEmulation->addAction(actionReset);
        menuEmulation->addAction(actionPause);
        menuEmulation->addAction(actionRestart);
        menuEmulation->addAction(menuRestart_with_Kit->menuAction());
        menuEmulation->addAction(menuBoot_Diags_with_Kit->menuAction());
        menuEmulation->addSeparator();
        menuEmulation->addSeparator();
        menuEmulation->addAction(actionConfiguration);
        menuEmulation->addSeparator();
        menuEmulation->addAction(actionQuit);
        menuFlash->addAction(actionSave);
        menuFlash->addAction(actionCreate_flash);
        menuTools->addAction(actionScreenshot);
        menuTools->addAction(actionRecord_GIF);
        menuTools->addAction(actionConnect);
        menuTools->addSeparator();
        menuTools->addAction(actionLCD_Window);
        menuTools->addSeparator();
        menuTools->addAction(actionDebugger);
        menuTools->addSeparator();
        menuTools->addAction(actionXModem);
        menuTools->addAction(actionLeavePTT);
        menuTools->addAction(actionSwitch_to_Mobile_UI);
        menuTools->addSeparator();
        menuTools->addAction(menuLanguage->menuAction());
        menuState->addAction(actionSuspend);
        menuState->addAction(actionResume);
        menuState->addSeparator();
        menuState->addAction(actionSuspend_to_file);
        menuState->addAction(actionResume_from_file);
        menuAbout->addAction(actionAbout_Firebird);
        menuAbout->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Firebird Emu", nullptr));
        actionReset->setText(QCoreApplication::translate("MainWindow", "&Reset", nullptr));
        actionDebugger->setText(QCoreApplication::translate("MainWindow", "Enter &Debugger", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
        actionPause->setText(QCoreApplication::translate("MainWindow", "&Pause", nullptr));
#if QT_CONFIG(tooltip)
        actionPause->setToolTip(QCoreApplication::translate("MainWindow", "Pause execution", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRestart->setText(QCoreApplication::translate("MainWindow", "Re&start", nullptr));
        actionScreenshot->setText(QCoreApplication::translate("MainWindow", "&Screenshot", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect &USB", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
        actionCreate_flash->setText(QCoreApplication::translate("MainWindow", "&Create Flash", nullptr));
        actionXModem->setText(QCoreApplication::translate("MainWindow", "Send &file over XModem", nullptr));
        actionSuspend->setText(QCoreApplication::translate("MainWindow", "&Suspend", nullptr));
        actionResume->setText(QCoreApplication::translate("MainWindow", "&Resume", nullptr));
        actionSuspend_to_file->setText(QCoreApplication::translate("MainWindow", "Save &to file", nullptr));
        actionResume_from_file->setText(QCoreApplication::translate("MainWindow", "Load &from file", nullptr));
        actionRecord_GIF->setText(QCoreApplication::translate("MainWindow", "&Record GIF", nullptr));
        actionAbout_Firebird->setText(QCoreApplication::translate("MainWindow", "&About Firebird", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About &Qt", nullptr));
        actionLCD_Window->setText(QCoreApplication::translate("MainWindow", "&External LCD", nullptr));
        actionConfiguration->setText(QCoreApplication::translate("MainWindow", "&Configuration", nullptr));
        actionSwitch_to_Mobile_UI->setText(QCoreApplication::translate("MainWindow", "Switch to Mobile UI", nullptr));
        actionLeavePTT->setText(QCoreApplication::translate("MainWindow", "Leave &PTT", nullptr));
        buttonReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        buttonPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        buttonScreenshot->setText(QCoreApplication::translate("MainWindow", "Screenshot", nullptr));
        buttonUSB->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
#if QT_CONFIG(tooltip)
        buttonSpeed->setToolTip(QCoreApplication::translate("MainWindow", "Enable Fullspeed", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonSpeed->setText(QCoreApplication::translate("MainWindow", "Speed: 0 %", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDebugger), QCoreApplication::translate("MainWindow", "Debugger", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = usblinkTree->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "Size", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Filename", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabFiles), QCoreApplication::translate("MainWindow", "File Transfer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSerial), QCoreApplication::translate("MainWindow", "Serial Monitor", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        menuEmulation->setTitle(QCoreApplication::translate("MainWindow", "&Emulation", nullptr));
        menuRestart_with_Kit->setTitle(QCoreApplication::translate("MainWindow", "Restart &with Kit", nullptr));
        menuBoot_Diags_with_Kit->setTitle(QCoreApplication::translate("MainWindow", "&Boot Diags with Kit", nullptr));
        menuFlash->setTitle(QCoreApplication::translate("MainWindow", "&Flash", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "&Tools", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
        menuState->setTitle(QCoreApplication::translate("MainWindow", "S&napshot", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "Abo&ut", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
