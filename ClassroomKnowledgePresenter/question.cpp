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
#include <iostream>

#include <QRadioButton>
#include <QSpinBox>
#include <QLineEdit>
#include <QButtonGroup>
#include <QAbstractButton>

Question::Question(QWidget *parent)
    : QWidget(parent)
{
    questionNumber = 0;
    myParent = parent;  // kludge
    guessed = false;    // Initially we haven't guessed right
    uiBuilt = false;      // kludge; we'll set it to true when we finalize the UI

    Q_ASSERT (parent->layout());
    questionLabel = new QLabel();
    questionLabel->setWordWrap(true);
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
 * Check against the known good answers and update the UI
 */
void Question::guess(QString guess)
{
    /* If we can convert value to int and back, without loss, try if it is in the Ints */
    guessed = (QString::number(guess.toInt()) == guess && correctAnswersInts.contains(guess.toInt()))
    /* Failing that, try if it is in the Strings */
               || correctAnswersStrings.contains(guess);
}
void Question::guess(int guess)
{
    guessed = correctAnswersInts.contains(guess);
}
/*
 * Thin wrapper around guess(QString) -- only needed because this is a slot,
 * and the best signal we can connect to emits QAbstractButton*
 */
void Question::guess(QAbstractButton *button)
{
    guess(button->text());
}
/**
 * Match the guess loosely to known answers
 *
 * Disregard whitespace, case, and some punctuation
 */
void Question::guessLoose(QString guess)
{
    QRegExp ignoredCharacters("[ \t-.]");
    QString mangledGuess(guess.toLower().replace(ignoredCharacters, ""));

    foreach(QString s, correctAnswersStrings) {
        if (mangledGuess == s.toLower().replace(ignoredCharacters, "")) {
            guessed = true;
            return;
        }
    }

    /* Let guess(QString) handle the eventuality that guess is really an int
       -- this is inefficient, as it duplicates the matching above */
    this->guess(mangledGuess);
}


void Question::insertCorrectAnswer(QString value)
{
    /* If we can convert value to int and back, without loss, it really is an int */
    if (QString::number(value.toInt()) == value) {
        correctAnswersInts << value.toInt();
    } else {
        correctAnswersStrings << value;
    }
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
    // (1) There is one and only one correct answer
    // (2) The spinner is a suitable method for entering large integers
    // (3) …

    // Number. Question
    uiBuilt = true;     // updateUi() checks this
    updateUi();

    Q_ASSERT_X (!correctAnswersStrings.isEmpty() || !correctAnswersInts.isEmpty(),
                "buildUi()", "Need at least one correct answer");

    // Decide which kind of answer vehicle to use: multiple option / spinner / free text input
    if (!optionPoolInts.isEmpty() || !optionPoolStrings.isEmpty()) {
        // Multiple options
        QList<QString> options;
        QRadioButton *radioButton;
        QButtonGroup *buttonGroup = new QButtonGroup();

        // Treat both int and QString options as strings
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
            radioButton = new QRadioButton(s);
            buttonGroup->addButton(radioButton);
            myParent->layout()->addWidget(radioButton);
            connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(guess(QAbstractButton*)));
            connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(updateUi()));
        }
    } else if (correctAnswersStrings.isEmpty()) {
        // Integer (with no options) => spinner
        Q_ASSERT(!correctAnswersInts.isEmpty());
        QSpinBox *spinBox = new QSpinBox;
        myParent->layout()->addWidget(spinBox);
        connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(guess(int)));
        connect(spinBox, SIGNAL(editingFinished()), this, SLOT(updateUi()));
    } else {
        // String with no options => freeform text input
        Q_ASSERT(!correctAnswersStrings.isEmpty());
        QLineEdit *lineEdit = new QLineEdit;
        myParent->layout()->addWidget(lineEdit);
        if (matchStrict) {
            connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(guess(QString)));
        } else {
            connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(guessLoose(QString)));
        }
        connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(updateUi()));
    }
}
