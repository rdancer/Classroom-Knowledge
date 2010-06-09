#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QUrl>
#include <QDir>
#include <QStringList>
#include <QStringListIterator>
#include <QSet>
#include <QTreeWidgetItem>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QMessageBox>
#include <QMultiMap>
#include <QImage>
#include <iostream>

#include "quiz.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void about();

protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;
    QStringList visualPictures;
    Quiz *quizView;

    int visualPicturesIndex; // can't declare with type QStringListIterator here, for some reason
    QImage originalImage;
    QString BASE;
    QString IMAGE_BASE;
    void updateVisualPicture();
    void setUpTextTab();
    void setUpVisualTab();
    void setUpQuizTab();
    void setUpInteractiveTab();

private slots:
    void on_actionAbout_Classroom_Knowledge_triggered();
    void on_mainWindowSplitter_splitterMoved(int pos, int index);
    void on_treeWidget_itemClicked(QTreeWidgetItem* item, int column);
    void on_actionQuit_triggered();
    void on_question3Answer_editingFinished();
    void on_question2Answer_editingFinished();
    void on_question1Answer1_toggled(bool checked);
    void on_visualPanePrevious_clicked();
    void on_visualPaneNext_clicked();
    void on_tabWidget_currentChanged(int index);
};

const QString PROGRAM_NAME = "Classroom Knowledge";
const QString COPYRIGHT_STATEMENT_HTML = "Copyright &copy; 2010 Jan Min&aacute;&#x0159; &lt;rdancer@rdancer.org&gt;<br />"
                                         "and other parties.<br /><br />"
                                         "Content from Wikipedia provided under the Creative Commons Attribution-ShareAlike License&mdash;for details see"
                                         " <a href='http://creativecommons.org/licenses/by-sa/3.0/'>http://creativecommons.org/licenses/by-sa/3.0/</a>."
                                         " This project uses the Qt library, which is licensed under LGPL version 2.1";

#endif // MAINWINDOW_H
