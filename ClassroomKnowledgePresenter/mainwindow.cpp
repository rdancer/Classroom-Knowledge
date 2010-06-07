#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringListIterator>


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
    setUpQuizTab();
}

void MainWindow::setUpQuizTab()
{
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


void MainWindow::on_question1Answer1_toggled(bool checked)
{
    const bool CORRECT_ANSWER = true;
    QString questionText[2] = {
        "1. Which lobe is responsible for conscious thought?",
        "1. <span style=\"color: green\"><strong>Frontal</strong> lobe is responsible for <strong>conscious thought</strong></span>"
    };

    ui->question1->setText(questionText[checked == CORRECT_ANSWER ? 1 : 0]);
}


# if 0
void MainWindow::on_question2Answer_editingFinished()
{
    const int CORRECT_ANSWER = 1;
    QString questionText[2] = {
        "2. Which Brodmann area number denotes the primary somatosensory cortex?",
        "2. <span style=\"color: green\"><strong>Brodman area 1</strong> denotes the primary <strong>somatosensory</strong> cortex</span>"
    };

    ui->question2->setText(questionText[ui->question2Answer->value() == CORRECT_ANSWER ? 1 : 0]);
}
#else /* 0 */
void MainWindow::on_question2Answer_editingFinished()
{
    // XXX Magic number to suppress "may be used uninitialized in this function" warning
    int correctAnswer = -42;
    QMultiMap<QString, QString> questionText;

  /* Adapted from <http://doc.trolltech.com/4.6/qdomdocument.html#details> */

  /* Init the XML engine */
    QDomDocument doc("mydocument");
    QFile file(BASE + "Human_brain-text_only.html");
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    /* Locate the <question> tag */
    QDomNode docElem = doc.elementsByTagName("question").at(0);

    QDomNode n = docElem.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            /* get the <correctAnswer> */
            if (e.tagName() == "correctAnswer") {
                correctAnswer = e.text().toInt();
            } else if (e.tagName() == "questionText") {
                questionText.insert(e.attribute("display"), e.text());
            } else if (e.tagName() == "input") {
                // TODO draw the input
            }
        }
        n = n.nextSibling();
    }

    /* draw the <questionText>s */
    ui->question2->setText(questionText.value(ui->question2Answer->value() == correctAnswer ? "success" : "default"));
}
#endif /* 0 */

void MainWindow::on_question3Answer_editingFinished()
{
    QSet<QString> CORRECT_ANSWERS;
    CORRECT_ANSWERS << "electroencephalography" << "electroencephalograph";
    QString questionText[2] = {
        "3. What does EEG stand for?",
        "3. <span style=\"color: green\">EEG stands for <strong>%1</strong></span>"
    };

    QString guess = ui->question3Answer->text().toLower().replace(QRegExp("[ \t-.]"), "");

    ui->question3->setText(CORRECT_ANSWERS.contains(guess) ? questionText[1].arg(guess) : questionText[0]);

}

// XXX There must be a template or something
void MainWindow::on_actionQuit_triggered()
{
    exit(0);
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
