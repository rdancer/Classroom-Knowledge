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
#include "quiz.h"
#include "question.h"

#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLayout>
#include <QLabel>
#include <QScrollArea>
#include <QList>
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>


Quiz::~Quiz(){}

Quiz::Quiz(QWidget *parent)
    : QWidget(parent)
{
    /*
     * Make sure the questions are laid out nicely
     */
    setLayout(new QVBoxLayout());

    /*
     * Add the questions
     */
    addQuestions();

    /*
     * Add stretchable vertical spacer at the bottom
     */
    (qobject_cast<QVBoxLayout *>(this->layout()))->addStretch();
}


/*
 * Add questions to the (likely empty) quiz
 */
void Quiz::addQuestions()
{
    QString BASE = "data/Wikipedia/"; // XXX kludge -- at least define in one place!!!

    /*
     * XML backend
     */

    questions = new QList<Question *>();

    /* Scour the XML for questions and populate the list */

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
