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

#include <iostream>
#include "Lexer.h"
#include "TokenDecls.h"
#include "AutomataDecls.h"

namespace Regexp {

    Lexer::Lexer() {
        source_ = "";
    }

    Lexer::Lexer(std::string source)
            : source_(source)
    {
        addAutomata();
    }

    Token Lexer::nextToken() {

        size_t chars_lexed = 0;

        if (source_.empty()) // if source is empty then return no token
            return Token(TAG_EOF, "");

        // set string to parse
        for (typename std::vector<match_pair_type>::iterator it = match_list.begin(); it != match_list.end(); it++)
            it->first.setString(source_);


        if (source_.length() == 1) // if there is only one char then advance and return the tag
        {
            advance();
            std::string lexeme = source_; // the biggest lexeme is the source itself
            source_ = ""; // consume final char
            return Token( match(), lexeme );
        }

        Token::Tag tag_new; // tag after advancing
        Token::Tag tag_old; // tag before advancing

        // This do-while cycle iterates until it can't find a matching pattern
        // When it ends, it has memorized the last matching pattern in tag_old
        // This means we find the largest lexeme in the source
        do
        {
            advance();
            chars_lexed++;

            tag_old = tag_new;
            tag_new = match();

        } while (tag_new != TAG_NONE && chars_lexed != source_.length());

        std::string lexeme = source_.substr(0,chars_lexed-1); // copy lexeme into variable
        source_ = source_.substr(chars_lexed-1); // consume chars

        return Token(tag_old, lexeme);
    }

    Token::Tag Lexer::match() {
        for (typename std::vector<match_pair_type>::iterator it = match_list.begin(); it != match_list.end(); it++)
        {
            if ( it->first.accepts() ) // if the automata is at an accepting state
            {
                return it->second; // return its associated token tag
            }
        }

        return TAG_NONE;
    }

    void Lexer::advance() {
        for (typename std::vector<match_pair_type>::iterator it = match_list.begin(); it != match_list.end(); it++)
            it->first.advance();
    }

    // edit this function to add more automata
    void Lexer::addAutomata() {
        match_list.push_back( std::make_pair( KLEENE_NFA, TAG_KLEENE_STAR ) );
        match_list.push_back( std::make_pair( ALPHA_CHAR_NFA, TAG_CHAR ) );
    }

    void Lexer::setSource(std::string source) {
        source_ = source;
    }

}