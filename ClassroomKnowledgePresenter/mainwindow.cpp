/*
 * Copyright © 2010 Jan Minář <rdancer@rdancer.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 (two),
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringListIterator>
#include <QIcon>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * Set up the UI
     *
     * TODO: Use a XML-backed content
     */

    BASE = ":/data/Wikipedia/";
    IMAGE_BASE = ":/data/Wikipedia/visualPane/";

    setUpTextTab();
    setUpVisualTab();
    setUpInteractiveTab();
    setUpQuizTab();
}

void MainWindow::setUpInteractiveTab()
{
    quizView = new Quiz();
    ui->interactiveLayout->insertWidget(0, quizView);
}

void MainWindow::setUpQuizTab()
{
    // Remove this tab -- we don't want it
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->quizTab));
    return;

    quizView = new Quiz(/*ui->quizScrollAreaContents*/);
    ui->quizLayout->addWidget(quizView);
}

void MainWindow::setUpTextTab()
{
    ui->webView->load(QUrl("qrc" + BASE + "Human_brain-text_only.html"));
}

void MainWindow::setUpVisualTab()
{
    /* Get the files in the directory & set up the iterator */
    visualPictures = QDir(IMAGE_BASE).entryList(QDir::Files)
                                        .replaceInStrings(QRegExp("^"), IMAGE_BASE);
    // XXX Use iterator
    visualPicturesIndex = -1;  // will get incremented during the initial call to "Next" slot

    /* Call the "next" slot */
    /*
     * XXX the slot in turn calls updateVisualPicture(), but, for some reason, the picture
     * doesn't get scaled initially.  We work around this by initially display another tab,
     * and calling updateVisualPicture() from on_tabWidget_currentChanged().
     */
    on_visualPaneNext_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/*
 * Implement the constant-aspect image scaling
 *
 * Adapted from <http://doc.trolltech.com/4.6/desktop-screenshot.html>
 */
void MainWindow::resizeEvent(QResizeEvent * /* event */)
{
// Note: Skip the checks and blindly resize
//
////    QPixmap p = ui->visualPicture->pixmap();
//    QSize scaledSize = ui->visualPicture->pixmap()->size();
//
//    scaledSize.scale(ui->visualPicture->size(), Qt::KeepAspectRatio);
//    if (scaledSize != ui->visualPicture->pixmap()->size())
        updateVisualPicture();
}

/* Same source as MainWindow::resizeEvent(QResizeEvent *) */
void MainWindow::updateVisualPicture()
{
    // XXX Handle errors properly
    if (originalImage.isNull()) {
        std::cout << "originalImage is null" << std::endl;
        return;
    }

    ui->visualPicture->setPixmap(QPixmap::fromImage(originalImage).scaled(ui->visualPicture->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));
}


/*
 * If an action is needed when tabs are switched…
 */
void MainWindow::on_tabWidget_currentChanged(int index)
{
    Q_UNUSED(index);

    // resize the *Visual* picture to good size
    // Note: we could just do this when the *Visual* tab is selected,
    // this is a bit of an overkill to do it any time any tab is selected
    updateVisualPicture();
}

void MainWindow::on_visualPaneNext_clicked()
{
    if (visualPicturesIndex + 1 < visualPictures.size()) {
        if (!originalImage.load(visualPictures[++visualPicturesIndex])) {
            std::cout << "can't load image "
                    /*<< visualPictures[visualPicturesIndex]*/ << std::endl;
            return;
        }
        updateVisualPicture();
    }
}

void MainWindow::on_visualPanePrevious_clicked()
{
    if (visualPicturesIndex > 0) {
        if (!originalImage.load(visualPictures[--visualPicturesIndex])) {
            std::cout << "can't load image "
                    << QString(visualPictures[visualPicturesIndex]).toStdString() << std::endl;
            return;
        }
        updateVisualPicture();
    }
}

// XXX There must be a template or something
void MainWindow::on_actionQuit_triggered()
{
    exit(0);
}


/**
 * Populate the Table of Contents
 */
void MainWindow::populateTableOfContents(QFile xmlFile, int column = 0)
{
    QString BASE = "data/Wikipedia/"; // XXX kludge -- at least define in one place!!!

    /*
     * XML backend
     */

    QList<Question *> questions;

    /* Scour the XML for questions and populate the list */

    /* Adapted from <http://doc.trolltech.com/4.6/qdomdocument.html#details> */

    /* Init the XML engine */
    QDomDocument doc("mydocument");
    if (!xmlFile.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&xmlFile)) {
        xmlFile.close();
        return;
    }
    xmlFile.close();

    /* Locate the <question> tag */
    QDomNodeList allQuestionElements = doc.elementsByTagName("question");

    for (int i = 0; i < allQuestionElements.size(); i++) {
        Question *question = new Question(this);

        questions->append(question),
        question->setQuestionNumber(questions->count()); // Make sure not to append() another in-between

        /* Go through the children of <question> and populate the Question */
        for(QDomNode node = allQuestionElements.at(i).firstChild(); !node.isNull(); node = node.nextSibling()) {
            QDomElement element = node.toElement(); // try to convert the node to an element.
            if(!element.isNull()) {
                /* switch: individual fields of Question */
                if (element.tagName() == "answer") {
                    if (!element.attribute("correct").isNull()) {
                        question->insertCorrectAnswer(element.text());
                    } else {
                        question->insertOption(element.text());
                    }
                } else if (element.tagName() == "questionText") {
                    if (element.attribute("display") == "default") {
                        question->setQuestion(element.text());
                    } else if (element.attribute("display") == "success") {
                        question->setQuestionOk(element.text());
                    } else {
                        // TODO Unrecognized
                    }
                } else {
                    // TODO Unrecognized
                }
            }
        }
        question->buildUi();
    }
}


/* Change the fragment part of the viewed URL */
void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem* item, int column)
{
    // Emulate fragments -- there are symbolic links all pointing
    // to the one HTML file, and a JavaScript fragment loads the correct
    // fragment from within the document
    ui->webView->load(QUrl("qrc" + BASE + "Human_brain-text_only.FRAGMENT_"
                           + item->text(column).replace(" ", "_") + "_FRAGMENT.html"));

    return;

    ////////////////////////////////////////////////////////////////////////////

    // XXX DNW: The URL is correct, but the setUrl(url) leads to a blank webView
    //
    // Qt doesn't support fragments with the 'file' scheme??

    QUrl url = ui->webView->url();

    url.setFragment(item->text(column));
    ui->webView->setUrl(url);
}

void MainWindow::on_mainWindowSplitter_splitterMoved(int pos, int index)
{
    Q_UNUSED(pos);
    Q_UNUSED(index);

    // Resize the *Visual* tab picture
    updateVisualPicture();
}

/**
 * The *About* box (Help > About...)
 *
 * Adapted from the »Custom Completer Example« from the Qt 4.6 documentation
 */
void MainWindow::about()
{
    QMessageBox::about(this, tr("About %1").arg(PROGRAM_NAME),
//                       tr("<div style='display: block; float: left'><img src='%1' /></div><div style='display: block; float: right'><h3>%2</h3><p>Built on %3 at %4</p><p>%5</p></div>")
                       tr("<table width='500' cellpadding='0' cellspacing='0' border='0'><tr><td><img src='%1' /></td><td>&nbsp;&nbsp;</td><td><h3>%2</h3><p>Built on %3 at %4</p><p>%5</p></td></tr></table>")
                       .arg(":/data/Wikipedia/Gray728.nolabels.dropshadow.128x94.png")
                       .arg(PROGRAM_NAME)
                       .arg(__DATE__)
                       .arg(__TIME__)
                       .arg(COPYRIGHT_STATEMENT_HTML));

}

void MainWindow::on_actionAbout_Classroom_Knowledge_triggered()
{
    about();
}
