//<editor-fold desc="Preamble">
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Copyright (C) 3/23/17 Carlos Brito
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.*
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
//</editor-fold>

//<editor-fold desc="Description">
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Author: Carlos Brito (carlos.brito524@gmail.com)
 * Date: 3/22/17.
 *
 * Description:
 *
 * TODO:
 * 
 * 
 * 
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
//</editor-fold>

#ifndef MYREGEX_REGEXPTOKENS_H
#define MYREGEX_REGEXPTOKENS_H

#include "Token.h"
#include "TokenTag.h"

enum {
    TOK_EOF = -1,
    TOK_NONE = 0,

    TOK_LPAREN,
    TOK_RPAREN,
    TOK_KLEENE,
    TOK_ALTER,
    TOK_CONCAT,
    TOK_QMARK,

    TOK_CHAR,
    TOK_ESCAPE_SEQUENCE
};

// Declare token tags
static const TokenTag TAG_LPAREN(TOK_LPAREN, "left parentheses");
static const TokenTag TAG_RPAREN(TOK_RPAREN, "right parentheses");
static const TokenTag TAG_KLEENE_STAR(TOK_KLEENE, "kleene star");
static const TokenTag TAG_ALTER(TOK_ALTER, "alternation");
static const TokenTag TAG_CONCAT(TOK_CONCAT, "concatenation");
static const TokenTag TAG_QMARK(TOK_QMARK, "question mark");
static const TokenTag TAG_CHAR(TOK_CHAR, "character");
static const TokenTag TAG_ESCAPE_SEQUENCE(TOK_ESCAPE_SEQUENCE, "escape sequence");

static const TokenTag TAG_EOF(TOK_EOF, "eof");
static const TokenTag TAG_NONE(TOK_NONE, "");


// Declare the operator tokens
static const Token LPAREN(TAG_LPAREN, "(");
static const Token RPAREN(TAG_RPAREN, ")");
static const Token KLEENE_STAR(TAG_KLEENE_STAR, "*");
static const Token ALTER(TAG_ALTER, "|");
static const Token CONCAT(TAG_CONCAT, "&");
static const Token QMARK(TAG_QMARK, "?");
static const Token T_EOF(TAG_EOF, "eof");
static const Token NONE(TAG_NONE, "");


#endif //MYREGEX_REGEXPTOKENS_H
