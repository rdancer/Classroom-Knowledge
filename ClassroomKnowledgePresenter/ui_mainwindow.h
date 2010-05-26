/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed May 26 02:14:08 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionVisual;
    QAction *actionApplied;
    QAction *actionInteractive;
    QAction *actionText;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *visualPanePrevious;
    QPushButton *visualPaneNext;
    QLabel *visualPicture;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *question1;
    QRadioButton *question1Answer1;
    QRadioButton *question1Answer2;
    QRadioButton *question1Answer3;
    QRadioButton *question1Answer4;
    QLabel *question2;
    QSpinBox *question2Answer;
    QLabel *question3;
    QLineEdit *question3Answer;
    QSpacerItem *verticalSpacer;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_3;
    QWebView *webView;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(619, 427);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionVisual = new QAction(MainWindow);
        actionVisual->setObjectName(QString::fromUtf8("actionVisual"));
        actionApplied = new QAction(MainWindow);
        actionApplied->setObjectName(QString::fromUtf8("actionApplied"));
        actionInteractive = new QAction(MainWindow);
        actionInteractive->setObjectName(QString::fromUtf8("actionInteractive"));
        actionText = new QAction(MainWindow);
        actionText->setObjectName(QString::fromUtf8("actionText"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMinimumSize(QSize(193, 0));

        horizontalLayout->addWidget(treeWidget);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        visualPanePrevious = new QPushButton(tab);
        visualPanePrevious->setObjectName(QString::fromUtf8("visualPanePrevious"));

        gridLayout_2->addWidget(visualPanePrevious, 0, 1, 1, 1);

        visualPaneNext = new QPushButton(tab);
        visualPaneNext->setObjectName(QString::fromUtf8("visualPaneNext"));

        gridLayout_2->addWidget(visualPaneNext, 0, 2, 1, 1);

        visualPicture = new QLabel(tab);
        visualPicture->setObjectName(QString::fromUtf8("visualPicture"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(visualPicture->sizePolicy().hasHeightForWidth());
        visualPicture->setSizePolicy(sizePolicy);
        visualPicture->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(visualPicture, 1, 0, 1, 3);


        verticalLayout_3->addLayout(gridLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 357, 323));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        question1 = new QLabel(scrollAreaWidgetContents);
        question1->setObjectName(QString::fromUtf8("question1"));
        question1->setWordWrap(true);

        verticalLayout->addWidget(question1);

        question1Answer1 = new QRadioButton(scrollAreaWidgetContents);
        question1Answer1->setObjectName(QString::fromUtf8("question1Answer1"));

        verticalLayout->addWidget(question1Answer1);

        question1Answer2 = new QRadioButton(scrollAreaWidgetContents);
        question1Answer2->setObjectName(QString::fromUtf8("question1Answer2"));

        verticalLayout->addWidget(question1Answer2);

        question1Answer3 = new QRadioButton(scrollAreaWidgetContents);
        question1Answer3->setObjectName(QString::fromUtf8("question1Answer3"));

        verticalLayout->addWidget(question1Answer3);

        question1Answer4 = new QRadioButton(scrollAreaWidgetContents);
        question1Answer4->setObjectName(QString::fromUtf8("question1Answer4"));

        verticalLayout->addWidget(question1Answer4);

        question2 = new QLabel(scrollAreaWidgetContents);
        question2->setObjectName(QString::fromUtf8("question2"));
        question2->setWordWrap(true);

        verticalLayout->addWidget(question2);

        question2Answer = new QSpinBox(scrollAreaWidgetContents);
        question2Answer->setObjectName(QString::fromUtf8("question2Answer"));

        verticalLayout->addWidget(question2Answer);

        question3 = new QLabel(scrollAreaWidgetContents);
        question3->setObjectName(QString::fromUtf8("question3"));

        verticalLayout->addWidget(question3);

        question3Answer = new QLineEdit(scrollAreaWidgetContents);
        question3Answer->setObjectName(QString::fromUtf8("question3Answer"));

        verticalLayout->addWidget(question3Answer);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        horizontalLayout_3 = new QHBoxLayout(tab_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        webView = new QWebView(tab_4);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl("about:blank"));

        horizontalLayout_3->addWidget(webView);

        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_4 = new QHBoxLayout(tab_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 619, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "eLearning - Classroom Knowledge Presenter", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionVisual->setText(QApplication::translate("MainWindow", "Visual", 0, QApplication::UnicodeUTF8));
        actionApplied->setText(QApplication::translate("MainWindow", "Applied", 0, QApplication::UnicodeUTF8));
        actionInteractive->setText(QApplication::translate("MainWindow", "Interactive", 0, QApplication::UnicodeUTF8));
        actionText->setText(QApplication::translate("MainWindow", "Text", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Human brain", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Structure", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "General features", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Cortical divisions", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem3->child(0);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Four lobes", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem3->child(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Functional divisions", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Topography", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "Lateralization", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "Development", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "Sources of information", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "EEG", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem9->child(1);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "MEG", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem9->child(2);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "Structural and functional imaging", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem9->child(3);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "Effects of brain damage", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem14 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWindow", "Language", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem15 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MainWindow", "Pathology", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem16 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MainWindow", "Metabolism", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem17 = treeWidget->topLevelItem(6);
        ___qtreewidgetitem17->setText(0, QApplication::translate("MainWindow", "See also", 0, QApplication::UnicodeUTF8));
        treeWidget->setSortingEnabled(__sortingEnabled);

        visualPanePrevious->setText(QApplication::translate("MainWindow", "<< &Previous", 0, QApplication::UnicodeUTF8));
        visualPaneNext->setText(QApplication::translate("MainWindow", "&Next >>", 0, QApplication::UnicodeUTF8));
        visualPicture->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Visual", 0, QApplication::UnicodeUTF8));
        question1->setText(QApplication::translate("MainWindow", "1. Which lobe is responsible for conscious thought?", 0, QApplication::UnicodeUTF8));
        question1Answer1->setText(QApplication::translate("MainWindow", "Frontal", 0, QApplication::UnicodeUTF8));
        question1Answer2->setText(QApplication::translate("MainWindow", "Temporal", 0, QApplication::UnicodeUTF8));
        question1Answer3->setText(QApplication::translate("MainWindow", "Parietal", 0, QApplication::UnicodeUTF8));
        question1Answer4->setText(QApplication::translate("MainWindow", "Occipital", 0, QApplication::UnicodeUTF8));
        question2->setText(QApplication::translate("MainWindow", "2. Which Brodmann area number denotes the primary somatosensory cortex?", 0, QApplication::UnicodeUTF8));
        question3->setText(QApplication::translate("MainWindow", "3. What does EEG stand for?", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Interactive", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Text", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<h1>To be implemented</h1>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Applied", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
