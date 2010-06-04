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

#include "question.h"

#include <algorithm>

#include <QRadioButton>
#include <QSpinBox>
#include <QLineEdit>



Question::Question(QWidget *parent)
    : QWidget(parent)
{
    questionNumber = 0;
    myParent = parent;  // kludge
    guessed = false;    // Initially we haven't guessed right
    uiBuilt = false;      // kludge; we'll set it to true when we finalize the UI

    Q_ASSERT (parent->layout());
    questionLabel = new QLabel();
    myParent->layout()->addWidget(questionLabel);
//    myParent->layout()->addWidget(new QLabel("Hello, world!"));
}


void Question::setQuestion(QString s)
{
    question = s;
    updateUi();
}

void Question::setQuestionOk(QString s)
{
    questionOk = s;
    updateUi();
}

// Unimplemented
//
//    QString Question::questionInitial();
//    QString Question::questionIfCorrect();

/*
 * Check against the known good answers and call the helper functions
 * (so not to duplicate code in the overloaded function)
 *
 * XXX This should be done by templating
 */
bool Question::guess(QString guess)
{
    if (correctAnswersStrings.contains(guess)) {
        guessedRight();
        return true;
    } else {
        guessedWrong();
        return false;
    }
}
bool Question::guess(int guess)
{
    if (correctAnswersInts.contains(guess)) {
        guessedRight();
        return true;
    } else {
        guessedWrong();
        return false;
    }
}

/* Update the widget */
void Question::guessedRight()
{
    // XXX
}

/* Update the widget */
void Question::guessedWrong()
{
    // XXX
}

void Question::insertCorrectAnswer(QString value)
{
    correctAnswersStrings << value;
}

void Question::insertCorrectAnswer(int value)
{
    correctAnswersInts << value;
}

void Question::insertOption(QString value)
{
    optionPoolStrings << value;
}

void Question::insertOption(int value)
{
    optionPoolInts << value;
}


// XXX Should be slot??
void Question::updateUi()
{
    /* Nothing to do if we haven't built the UI */
    if (!uiBuilt) return;

    if (guessed) {
        questionLabel->setText(tr("%1. ").arg(questionNumber)
                               + "<span style=\"color: green\">" + questionOk + "</span>");
    } else {
        questionLabel->setText(tr("%1. ").arg(questionNumber) + question);
    }
}

void Question::setQuestionNumber(int questionNumber)
{
    this->questionNumber = questionNumber;
    updateUi();
}

/* Get all the elements of the Question–Answer and build a consistent UI */
void Question::buildUi()
{
    //
    // We work with several assumptions here:
    //
    // (1) There is only one correct answer
    // (2) The spinner is a suitable method for entering large integers
    // (3) …

    // Number. Question
    uiBuilt = true;     // updateUi() checks this
    updateUi();

    Q_ASSERT_X (!correctAnswersStrings.isEmpty() || !correctAnswersInts.isEmpty(), "buildUi()", "Need at least one correct answer");

    // Decide which kind of answer vehicle to use: multiple option / spinner / free text input
    if (!optionPoolInts.isEmpty() || !optionPoolStrings.isEmpty()) {
        // Multiple options
        // Treat them as strings
        QList<QString> options;
        foreach (QString s, correctAnswersStrings) {
            options << s;
        }
        foreach (QString s, optionPoolStrings) {
            options << s;
        }
        foreach (int i, correctAnswersInts) {
            options << QString::number(i);
        }
        foreach (int i, optionPoolInts) {
            options << QString::number(i);
        }
        std::random_shuffle(options.begin(), options.end());
        foreach (QString s, options) {
            myParent->layout()->addWidget(new QRadioButton(s));
        }
    } else if (correctAnswersStrings.isEmpty()) {
        // Integer (with no options) => spinner
        Q_ASSERT(!correctAnswersInts.isEmpty());
        myParent->layout()->addWidget(new QSpinBox());

    } else {
        // String with no options => freeform text input
        Q_ASSERT(!correctAnswersStrings.isEmpty());
        myParent->layout()->addWidget(new QLineEdit());
    }
}
