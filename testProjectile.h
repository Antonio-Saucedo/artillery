/***********************************************************************
 * Header File:
 *    Test Position : Test the Projectile class
 * Author:
 *    Antonio Saucedo, Thomas Vargas
 * Summary:
 *    All the unit tests for Projectile
 ************************************************************************/

#pragma once
#include <iostream>
#include "projectile.h"
#include "position.h"
#include <cassert>
#include <list>

using namespace std;

class TestProjectile
{
public:
    void run()
    {
        test_getPreviousPoints_noPoints(); // Error: Max interval exceeded
        test_getPreviousPoints_onePoint();
        test_getPreviousPoints_tenPoints();

        test_updatePoint_noInterval(); // Interval required
        test_updatePoint_lowerInnerBoundaryInterval();
        test_updatePoint_upperLimitInterval();
        test_updatePoint_upperOutterBoundaryInterval(); // Max interval exceeded
        test_updatePoint_unreasonableInterval(); // Max interval exceeded
        test_updatePoint_negativeInterval(); // Error: Negative interval
        test_updatePoint_wrongDataType(); // Error: Wrong data type

        test_hit(); // Check hit value updated
    }

private:
    void test_getPreviousPoints_noPoints()
    {
        // setup
        float previousPoint = Projectile::previous;
        list<Position> previous = {};
        previousPoint = previous;

        // exercise
        list<Position> previousActual = Projectile.getPreviousPoints();
        
        // verify
        assert(previousActual.size == 0);
        
        // teardown
        Position::previous = previous;
    }

    void test_getPreviousPoints_onePoint()
    {
        // setup
        float previousPoint = Projectile::previous;
        Projectile::previous = {Position.setMetersX(10), Position.setMetersY(10)};
        list<Position> previous = {};
        previousPoint = previous;

        // exercise
        list<Position> previousActual = Projectile.getPreviousPoints();

        // verify
        assert(previousActual.size == 1);

        // teardown
        Position::previous = previous;
    }

    void test_getPreviousPoints_tenPoints()
    {
        // setup
        float previousPoint = Projectile::previous;
        Projectile::previous = {
            Position.setMetersX(10), Position.setMetersY(10),
            Position.setMetersX(10), Position.setMetersY(10),
            Position.setMetersX(10), Position.setMetersY(10),
            Position.setMetersX(10), Position.setMetersY(10),
            Position.setMetersX(10), Position.setMetersY(10),
            Position.setMetersX(10), Position.setMetersY(10),
            Position.setMetersX(10), Position.setMetersY(10),
            Position.setMetersX(10), Position.setMetersY(10),
            Position.setMetersX(10), Position.setMetersY(10),
            Position.setMetersX(10), Position.setMetersY(10)
        };
        list<Position> previous = {};
        previousPoint = previous;

        // exercise
        list<Position> previousActual = Projectile.getPreviousPoints();

        // verify
        assert(previousActual.size == 10);

        // teardown
        Position::previous = previous;
    }

    void test_updatePoint_noInterval()
    {
        // setup
        float interval = Projectile::interval;
        Projectile::interval = NULL;

        // exercise
        float intervalActual = Projectile::interval;

        // verify
        assert(intervalActual == NULL);

        // teardown
        Projectile::interval = interval;
    }

    void test_updatePoint_lowerInnerBoundaryInterval()
    {
        // setup
        float interval = Projectile::interval;
        Projectile::interval = 0.01;

        // exercise
        float intervalActual = Projectile::interval;

        // verify
        assert(intervalActual == 0.01);

        // teardown
        Projectile::interval = interval;
    }

    void test_updatePoint_upperLimitInterval()
    {
        // setup
        float interval = Projectile::interval;
        Projectile::interval = 1;

        // exercise
        float intervalActual = Projectile::interval;

        // verify
        assert(intervalActual == 1);

        // teardown
        Projectile::interval = interval;
    }

    void test_updatePoint_upperOutterBoundaryInterval()
    {
        // setup
        float interval = Projectile::interval;
        Projectile::interval = 1.001;

        // exercise
        float intervalActual = Projectile::interval;

        // verify
        assert(intervalActual == 1.001);

        // teardown
        Projectile::interval = interval;
    }

    void test_updatePoint_unreasonableInterval()
    {
        // setup
        float interval = Projectile::interval;
        Projectile::interval = 10;

        // exercise
        float intervalActual = Projectile::interval;

        // verify
        assert(intervalActual == 10);

        // teardown
        Projectile::interval = interval;
    }

    void test_updatePoint_negativeInterval()
    {
        // setup
        float interval = Projectile::interval;
        Projectile::interval = -1;

        // exercise
        float intervalActual = Projectile::interval;

        // verify
        assert(intervalActual == -1);

        // teardown
        Projectile::interval = interval;
    }

    void test_updatePoint_wrongDataType()
    {
        // setup
        float interval = Projectile::interval;
        Projectile::interval = "A";

        // exercise
        float intervalActual = Projectile::interval;

        // verify
        assert(intervalActual == "A");

        // teardown
        Projectile::interval = interval;
    }

    void test_hit()
    {
        // setup
        bool hit = Projectile::hit;
        Projectile::hit = true;

        // exercise
        bool hitActual = Projectile::hit;

        // verify
        assert(hitActual == true);

        // teardown
        Projectile::hit = hit;
    }
};
