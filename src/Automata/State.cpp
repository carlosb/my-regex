//<editor-fold desc="Preamble">
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Copyright (C) 3/24/17 Carlos Brito
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
/**
 * @file NFA.cpp
 * @author Carlos Brito (carlos.brito524@gmail.com)
 * @date 3/22/17
 *
 * # Description
 * This is the .cpp file which contains the implementation for all the methods declared in the header file Stae.h
 *
 * # TODO
 * Nothing for the moment.
 */
//</editor-fold>

#include "State.h"
#include "Transition.h"

namespace Automata {

    State::State(std::string name, bool is_end, size_t bucket_count)
            : name_(name),
              is_end_(is_end) {
        transitions_ = new Set<Transition, Transition::Hasher>(bucket_count);
    }

    std::string State::name() const {
        return name_;
    }

    bool State::isEnd() const {
        return is_end_;
    }

    void State::addTransition(State *destination, char symbol) {

        Transition t(this, destination, symbol); // add transition from this state to destination
        transitions_->insert(t);
    }

    void State::setEnd(bool is_end) {
        is_end_ = is_end;
    }

    void State::setName(std::string name) {
        name_ = name;
    }

    State::transition_set_type & State::transition_set() {
        return *transitions_;
    }

    State::transition_set_type const& State::transition_set() const {
        return *transitions_;
    }

    State::~State() {
//        delete transitions_;
    }

}
