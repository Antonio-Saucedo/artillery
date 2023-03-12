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
#include <cmath>

using namespace std;

template <typename T>
bool isEqual(T a, T b, double tolerance = 0.01) {
    return std::abs(a - b) <= tolerance;
}

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

        test_hit(); // Check hit value updated

        cout << "Projectile Tests Passed\n";
    }

private:
    void test_getPreviousPoints_noPoints()
    {
        // setup
        Projectile p;
        p.previous = {};
        // exercise
        list<Position> previousActual = p.getPreviousPoints();
        // verify
        assert(previousActual.size() == 0);
        // teardown
        // no teardown needed, the Projectile object will be destroyed when it goes out of scope
    }

    void test_getPreviousPoints_onePoint()
    {
        // setup
        Projectile p;
        p.previous = {Position()};
        // exercise
        list<Position> previousActual = p.getPreviousPoints();
        // verify
        assert(previousActual.size() == 1);
        // teardown
        // no teardown needed, the Projectile object will be destroyed when it goes out of scope
    }

    void test_getPreviousPoints_tenPoints()
    {
        // setup
        Projectile p;
        p.previous = {Position(), Position(), Position(), 
                        Position(), Position(), Position(),
                        Position(), Position(), Position(), 
                        Position()};
        // exercise
        list<Position> previousActual = p.getPreviousPoints();
        // verify
        assert(previousActual.size() == 10);
        // teardown
        // no teardown needed, the Projectile object will be destroyed when it goes out of scope
    }

    void test_updatePoint_noInterval()
    {
        // setup
        Projectile p;
        p.current = Position(50,50);
        p.velocity = Velocity(300, 100);
        // exercise
        p.updatePoint(0);
        // verify
        assert(p.current.getMetersX() == 50);
        assert(p.current.getMetersY() == 50);
        // teardown
        // no teardown needed, the Projectile object will be destroyed when it goes out of scope
    }

    void test_updatePoint_lowerInnerBoundaryInterval()
    {
        // setup
        Projectile p;
        p.current = Position(50, 50);
        p.velocity = Velocity(300, 100);
        // exercise
        p.updatePoint(0.01f);
        // verify
        assert(isEqual(p.current.getMetersX(), 53.0));
        assert(isEqual(p.current.getMetersY(), 51.0));
        // teardown
        // no teardown needed, the Projectile object will be destroyed when it goes out of scope
    }

    void test_updatePoint_upperLimitInterval()
    {
        // setup
        Projectile p;
        p.current = Position(50, 50);
        p.velocity = Velocity(300, 100);
        // exercise
        p.updatePoint(1);
        // verify
        assert(isEqual(p.current.getMetersX(), 350.0));
        assert(isEqual(p.current.getMetersY(), 145.1));
        // teardown
        // no teardown needed, the Projectile object will be destroyed when it goes out of scope
    }

    void test_updatePoint_upperOutterBoundaryInterval()
    {
        // setup
        Projectile p;
        p.current = Position(50, 50);
        p.velocity = Velocity(300, 100);
        // exercise and verify
        try { 
            p.updatePoint(1.001);
            assert(false);
        }
        catch (const std::exception& e) {
            assert(true);
        }
        // teardown
        // no teardown needed, the Projectile object will be destroyed when it goes out of scope
    }

    void test_updatePoint_unreasonableInterval()
    {
        // setup
        Projectile p;
        p.current = Position(50, 50);
        p.velocity = Velocity(300, 100);
        // exercise and verify
        try {
            p.updatePoint(10);
            assert(false);
        }
        catch (const std::exception& e) {
            assert(true);
        }
        // teardown
        // no teardown needed, the Projectile object will be destroyed when it goes out of 
    }

    void test_updatePoint_negativeInterval()
    {
        // setup
        Projectile p;
        p.current = Position(50, 50);
        p.velocity = Velocity(300, 100);
        // exercise and verify
        try {
            p.updatePoint(-1);
            assert(false);
        }
        catch (const std::exception& e) {
            assert(true);
        }
        // teardown
        // no teardown needed, the Projectile object will be destroyed when it goes out of 
    }

    void test_hit()
    {
        // setup
        Projectile p;
        p.airborne = true;

        // exercise
        p.hit();
        // verify
        assert(p.airborne == false);

        // teardown
        // no teardown needed, the Projectile object will be destroyed when it goes out of 
    }
};
