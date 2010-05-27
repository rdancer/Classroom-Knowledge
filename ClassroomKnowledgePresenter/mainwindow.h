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


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;
    QStringList visualPictures;
    int visualPicturesIndex; // can't declare with type QStringListIterator here, for some reason
    QImage originalImage;
    QString BASE;
    QString IMAGE_BASE;
    void updateVisualPicture();
    void setUpTextTab();
    void setUpVisualTab();

private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem* item, int column);
    void on_actionQuit_triggered();
    void on_question3Answer_editingFinished();
    void on_question2Answer_editingFinished();
    void on_spinBox_editingFinished();
    void on_question1Answer1_toggled(bool checked);
    void on_visualPanePrevious_clicked();
    void on_visualPaneNext_clicked();
    void on_tabWidget_currentChanged(int index);
};

#endif // MAINWINDOW_H
