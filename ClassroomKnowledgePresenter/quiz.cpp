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
}

/*
 * Add questions to the (likely empty) quiz
 */
void Quiz::addQuestions()
{
    /*
     * XML backend
     */

    //QList<Question> *questions = new QList<Question>();

    /* Scour the XML for questions and populate the list */

    for (int i = 1; /* forever */; i++) {
        Question myQuestion(this);
//        questions->append(myQuestion);

        myQuestion.insertCorrectAnswer("Snow White");
        myQuestion.setQuestion("Who is the most beautiful woman of all?");
        myQuestion.setQuestionOk("<strong>Snow White</strong> is more beautiful than you");
        myQuestion.setQuestionNumber(i);
        break;
    }
}
