#pragma once

#include <Arduino.h>
#include <array>

#include "SudokuSquare.h"

class SudokuState
{
public:
    SudokuState() = default;

protected:
    std::array<std::array<SudokuSquare,9>,9>     Squares;

public:
    void            GenerateEmpty() { for( uint8_t x = 0 ; x < 9 ; x++ ) for( uint8_t y = 0 ; y < 9 ; y++ ) Squares[x][y] = SudokuSquare(); };
    void            GenerateFromString( String str );

    bool            Propagate();        // returns true if any changes were made
    bool            PropagateOnce( uint16_t iLoop = 0 ); // returns true if a change was made
    bool            SolveByIdentifingUniques();  // returns true if solved
    bool            SolveByGuessing();  // returns true if solved

    bool            Valid() const;
    bool            Solved() const;
    uint16_t        SumCount() const;

    Point<uint8_t>  FindLowestCountUnsolvedSquare() const;

    SudokuSquare&   GetSquare( Point<uint8_t> pt ) { return GetSquare(pt.x,pt.y); };
    SudokuSquare&   GetSquare( uint8_t x, uint8_t y ) { return Squares[x][y]; };

    void            Dump() const;

};
