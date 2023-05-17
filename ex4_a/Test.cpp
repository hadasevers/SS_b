#include <string.h>
#include <stdio.h>
#include "doctest.h"
#include "sources/Team.hpp"

using namespace std;
using namespace ariel;


TEST_SUITE("Point Test")
{
    TEST_CASE("Point Constructor Test")
    {
        // check positive and negative
        CHECK_NOTHROW(Point (5,3)); //true
        CHECK_NOTHROW(Point (-5,3)); //true
        CHECK_NOTHROW(Point (5,-3)); //true
        CHECK_NOTHROW(Point (-5,-3)); //true

        // check double and integer
        CHECK_NOTHROW(Point (5.0,3)); //true
        CHECK_NOTHROW(Point (5,3.0)); //true
        CHECK_NOTHROW(Point (5.0,3.0)); //true

        // check with zero
        CHECK_NOTHROW(Point (5,0)); //true
        CHECK_NOTHROW(Point (0,3)); //true
        CHECK_NOTHROW(Point (0,0)); //true
    }

    TEST_CASE("Point setters Test")
    {
        Point a(5,3);

        CHECK(a.getx() == 5.0);
        CHECK(a.gety() == 3.0);

        CHECK_NOTHROW(a.setx(-5)); //true
        CHECK_NOTHROW(a.sety(-3)); //true
        CHECK(a.getx() == -5.0);
        CHECK(a.gety() == -3.0);

        CHECK_NOTHROW(a.setx(5.0)); //true
        CHECK_NOTHROW(a.sety(3.0)); //true
        CHECK(a.getx() == 5.0);
        CHECK(a.gety() == 3.0);

        CHECK_NOTHROW(a.setx(0)); //true
        CHECK_NOTHROW(a.sety(0)); //true
        CHECK(a.getx() == 0.0);
        CHECK(a.gety() == 0.0);
    }

    TEST_CASE("Point getters Test")
    {
        Point a(5,3);
        Point b(-5,-3);
        Point c(5.0,3.0);

        // positive and int
        CHECK_NOTHROW(a.getx()); //true
        CHECK_NOTHROW(a.gety()); //true

        // negative and int
        CHECK_NOTHROW(b.getx()); //true
        CHECK_NOTHROW(b.gety()); //true

        // positive and double
        CHECK_NOTHROW(c.getx()); //true
        CHECK_NOTHROW(c.gety()); //true

        CHECK(a.getx() == 5.0);
        CHECK(a.gety() == 3.0);

        CHECK(b.getx() == -5.0);
        CHECK(b.gety() == -3.0);

        CHECK(c.getx() == 5.0);
        CHECK(c.gety() == 3.0);

        CHECK(a.getx() == c.getx());
        CHECK(a.getx() == (-1)*b.getx());
    }

    TEST_CASE("Distance Test")
    {
        Point a(4,3); 
        Point a2(4,3);  //same position but different point
        Point b(-4,-3);
        Point c(0,0);

        CHECK_NOTHROW(a.distance(a));
        CHECK_NOTHROW(a.distance(b));
        CHECK_NOTHROW(a.distance(c));

        CHECK(a.distance(c) == b.distance(c));
        CHECK(a.distance(c) == 5.0); // sqrt((a.x-c.x)^2 + (a.y-c.y)^2)
        CHECK(a.distance(a) == 0);
        CHECK(a.distance(a2) == 0);
    }

    TEST_CASE("Print Test")
    {
        Point a(4,3); 
        Point b(-4,-3);
        Point c(0,0);

        CHECK_NOTHROW(a.print());
        CHECK_NOTHROW(b.print());
        CHECK_NOTHROW(c.print());
    }

    TEST_CASE("Print Test")
    {
        Point a(4,3); 
        Point b(-4,-3);
        Point c(0,0);

        CHECK_NOTHROW(Point::moveTowards(a,a,0));
        CHECK_NOTHROW(Point::moveTowards(a,a,1));
        CHECK_NOTHROW(Point::moveTowards(a,b,5));
        CHECK_THROWS(Point::moveTowards(a,b,-5)); // distance unable be negative

        Point a1(Point::moveTowards(a,a,20)); // src point and dist point is same
        CHECK(a.getx() == a1.getx());
        CHECK(a.gety() == a1.gety()); 

        Point a2(Point::moveTowards(a,b,0)); //distance 0 rteurn the src point
        CHECK(a.getx() == a2.getx());
        CHECK(a.gety() == a2.gety());  

        Point b1(Point::moveTowards(a,b,10)); //distance that equal to the distance between src to dest, return dest point
        CHECK(b.getx() == b1.getx());
        CHECK(b.gety() == b1.gety()); 

        Point b2(Point::moveTowards(a,b,50)); //distance that bigger from the distance between src to dest, return dest point
        CHECK(b.getx() == b2.getx());
        CHECK(b.gety() == b2.gety()); 
    }
}

TEST_SUITE("Characters Test")
{
    //only character function
    TEST_CASE("Character Test")
    {
        Point p(3,4);
        CHECK_NOTHROW(Cowboy("myCowboy", p));

        Cowboy a("myCowboy", p);
        CHECK(a.getHit() == 110);
        CHECK(a.getInto() == false);

        CHECK_NOTHROW(a.setInto());
        a.setInto();
        CHECK(a.getInto());

        CHECK_NOTHROW(a.isAlive());
        CHECK(a.isAlive());

        Cowboy c("other", p);
        CHECK_NOTHROW(a.distance(&c));
        CHECK(a.distance(&c) == 0.0);

        CHECK_NOTHROW(a.hit(0));
        a.hit(0);
        CHECK(a.getHit() == 110);

        CHECK_NOTHROW(a.hit(10));
        a.hit(10);
        CHECK(a.getHit() == 100);

        CHECK_NOTHROW(a.hit(100));
        a.hit(100);
        CHECK(a.getHit() == 0);

        // check minus numHit equal to zero numHit
        CHECK_NOTHROW(a.hit(1));
        a.hit(1);
        CHECK(a.getHit() == 0);

        // check isAlive with zero numHit 
        CHECK(a.isAlive() == false);

        CHECK_NOTHROW(a.setName("first"));
        a.setName("first");
        CHECK_NOTHROW(a.getName());
        CHECK(a.getName().compare("first"));

        Point p2(4,5);
        CHECK_NOTHROW(a.setLocation(p2));
        a.setLocation(p2);
        CHECK_NOTHROW(a.getLocation());
        //CHECK(a.getLocation() == p2);

        CHECK_NOTHROW(a.setHit(110));
        a.setHit(110);
        CHECK_NOTHROW(a.getHit());
        CHECK(a.getHit() == 110);
    }
    

    TEST_CASE("Cowboy Test")
    {
        // check constructor
        Point p(3,4);
        Cowboy a("myCowboy", p);

        CHECK(a.getBullet() == 6);
        CHECK(a.getHit() == 110);
        CHECK(a.isAlive());

        // print when the Cowboy alive
        CHECK_NOTHROW(a.print());
        CHECK(a.print().compare("C"+a.getName()+", "+to_string(a.getHit())+", ("+to_string(a.getLocation().getx())+","+to_string(a.getLocation().gety())+")"));

        // check isAlive with zero numHit 
        a.hit(110);
        CHECK(a.isAlive() == false);

        // print when the Cowboy not alive
        CHECK_NOTHROW(a.print());
        CHECK(a.print().compare("C("+a.getName()+"), ("+to_string(a.getLocation().getx())+","+to_string(a.getLocation().gety())+")"));

        a.setHit(110);

        CHECK_NOTHROW(a.hasboolets());
        CHECK(a.hasboolets());

        Cowboy b("Cowboy2", p);
        int lives = b.getHit();

        CHECK_NOTHROW(a.shoot(&b));
        a.shoot(&b);
        CHECK(a.hasboolets());
        CHECK(a.getBullet() == 5);

        for (int i = 0; i < 5; i++)
            a.shoot(&b);
        
        CHECK(a.hasboolets() == false);
        CHECK(a.getBullet() == 0);

        a.shoot(&b); // -1 is same to zero bullet
        CHECK(a.hasboolets() == false);
        CHECK(a.getBullet() == 0);

        CHECK_NOTHROW(a.reload());
        a.reload();
        CHECK(a.getBullet() == 6);

        CHECK(b.getHit() < lives); // check that b really hurt
    }


    TEST_CASE("YoungNinja Test")
    {
        Point p(3,4);
        CHECK_NOTHROW(YoungNinja("myYoungNinja", p));

        YoungNinja a("myYoungNinja", p);
        CHECK(a.getSpeed() == 14);
        CHECK(a.getHit() == 100);

        // print when the YoungNinja alive
        CHECK_NOTHROW(a.print());
        CHECK(a.print().compare("N"+a.getName()+", "+to_string(a.getHit())+", ("+to_string(a.getLocation().getx())+","+to_string(a.getLocation().gety())+")"));

        // check isAlive with zero numHit 
        a.hit(110);
        CHECK(a.isAlive() == false);

        // print when the YoungNinja not alive
        CHECK_NOTHROW(a.print());
        string prt = "N("+a.getName()+"), ("+to_string(a.getLocation().getx())+","+to_string(a.getLocation().gety())+")";
        CHECK(a.print().compare(prt));

        Point p2(8,4);
        YoungNinja y1("other_1", p);
        YoungNinja y2("other_2", p);
        CHECK_NOTHROW(a.move(&y1));
        CHECK_NOTHROW(a.move(&y2));

        Cowboy c1("enemy_1", Point(3.5,4)); // close enemy
        Cowboy c2("enemy_2", Point(70,50)); // far enemy

        // when the ninje deid - nothing happened
        CHECK_NOTHROW(a.slash(&c1));
        CHECK_NOTHROW(a.slash(&c2));

        a.slash(&c1);
        CHECK(c1.getHit() == 110);

        a.slash(&c2);
        CHECK(c1.getHit() == 110);

        // when the ninje alive
        a.setHit(100);
        CHECK_NOTHROW(a.slash(&c1));
        CHECK_NOTHROW(a.slash(&c2)); // nothing happened

        a.slash(&c1);
        CHECK(c1.getHit() == 70);

        a.slash(&c2);
        CHECK(c1.getHit() == 110);

        Cowboy c3("enemy_2", Point(3.5,4));
        c3.hit(110); // died
        CHECK_THROWS(a.slash(&c3));
    }

    TEST_CASE("TrainedNinja Test")
    {
        Point p(3,4);
        CHECK_NOTHROW(TrainedNinja("myTrainedNinja", p));

        TrainedNinja a("myTrainedNinja", p);
        CHECK(a.getSpeed() == 12);
        CHECK(a.getHit() == 120);

        // print when the YoungNinja alive
        CHECK_NOTHROW(a.print());
        CHECK(a.print().compare("N"+a.getName()+", "+to_string(a.getHit())+", ("+to_string(a.getLocation().getx())+","+to_string(a.getLocation().gety())+")"));

        // check isAlive with zero numHit 
        a.hit(120);
        CHECK(a.isAlive() == false);

        // print when the YoungNinja not alive
        CHECK_NOTHROW(a.print());
        CHECK(a.print().compare("N("+a.getName()+"), ("+to_string(a.getLocation().getx())+","+to_string(a.getLocation().gety())+")"));
    }

    TEST_CASE("OldNinja Test")
    {
        Point p(3,4);
        CHECK_NOTHROW(OldNinja("myOldNinja", p));

        OldNinja a("myOldNinja", p);
        CHECK(a.getSpeed() == 8);
        CHECK(a.getHit() == 150);

        // print when the YoungNinja alive
        CHECK_NOTHROW(a.print());
        CHECK(a.print().compare("N"+a.getName()+", "+to_string(a.getHit())+", ("+to_string(a.getLocation().getx())+","+to_string(a.getLocation().gety())+")"));

        // check isAlive with zero numHit 
        a.hit(150);
        CHECK(a.isAlive() == false);

        // print when the YoungNinja not alive
        CHECK_NOTHROW(a.print());
        CHECK(a.print().compare("N("+a.getName()+"), ("+to_string(a.getLocation().getx())+","+to_string(a.getLocation().gety())+")"));
    }
}

TEST_SUITE("Team Test")
{
    //only Team function
    TEST_CASE("Team Test")
    {
        Cowboy *c1 = new Cowboy("c1", Point(0,0));
        Cowboy *c2 = new Cowboy("c2", Point(1,1));
        Cowboy *c3 = new Cowboy("c3", Point(1,2));
        Cowboy *c4 = new Cowboy("c4", Point(2,3.5));

        YoungNinja *y1 = new YoungNinja("y1", Point(0.5, 4));
        YoungNinja *y2 = new YoungNinja("y2", Point(0.8, 2));
        YoungNinja *y3 = new YoungNinja("y3", Point(2.5, -0.6));
        YoungNinja *y4 = new YoungNinja("y4", Point(5.2, 4));

        TrainedNinja *t1 = new TrainedNinja("t1", Point(-1,3));
        TrainedNinja *t2 = new TrainedNinja("t2", Point(0.5,3));
        TrainedNinja *t3 = new TrainedNinja("t3", Point(2.4,4));
        TrainedNinja *t4 = new TrainedNinja("t4", Point(4,1.2));

        OldNinja *o1 = new OldNinja("o1", Point(13,4));
        OldNinja *o2 = new OldNinja("o2", Point(5,3));
        OldNinja *o3 = new OldNinja("o3", Point(2,4));
        OldNinja *o4 = new OldNinja("o4", Point(1,0));

        //CHECK_NOTHROW(Team(c1));
        Team team_a(c1);
        Team team_b(c2);

        CHECK(team_a.getSize()==1);
        CHECK(team_b.getSize()==1);

        // check the leader is realy c1;
        CHECK_NOTHROW(team_a.getLeader());
        CHECK(team_a.getLeader()->getName().compare("c1"));
        CHECK(team_a.getLeader()->getLocation().getx() == 0.0);
        CHECK(team_a.getLeader()->getLocation().gety() == 0.0);

        CHECK_NOTHROW(team_a.setLeader(c3));
        team_a.setLeader(c3);
        CHECK(team_a.getLeader()->getName().compare("c3"));
        CHECK(team_a.getLeader()->getLocation().getx() == 1.0);
        CHECK(team_a.getLeader()->getLocation().gety() == 2.0);

        // now in team a ther are two warrior
        CHECK_NOTHROW(team_a.add(c4));
        CHECK_NOTHROW(team_a.add(y1));
        CHECK_NOTHROW(team_a.add(y2));
        CHECK_NOTHROW(team_a.add(y3));
        CHECK_NOTHROW(team_a.add(y4));
        // now in team a ther are seven warrior

        CHECK_THROWS(team_a.add(c2)); // c2 in team b

        CHECK_NOTHROW(team_a.add(t1));
        CHECK_NOTHROW(team_a.add(t2));
        CHECK_NOTHROW(team_a.add(t3));
        // now in team a ther are ten warrior

        CHECK(team_a.getSize()==10);
        CHECK_THROWS(team_a.add(t4)); // there are 10 earrior in team a
        
        CHECK_NOTHROW(team_b.add(t4));
        CHECK_NOTHROW(team_b.add(o1));
        CHECK_NOTHROW(team_b.add(o2));
        CHECK_NOTHROW(team_b.add(o3));
        CHECK_NOTHROW(team_b.add(o4));

        CHECK(team_b.getSize()==6);

        CHECK_NOTHROW(team_a.stillAlive());
        CHECK_NOTHROW(team_b.stillAlive());
        CHECK(team_a.stillAlive()==10);
        CHECK(team_a.stillAlive()==6);

        while (team_a.stillAlive()>0 && team_b.stillAlive()>0)
        {
            CHECK_NOTHROW(team_a.attack(&team_b));
            CHECK_NOTHROW(team_b.attack(&team_a));
        }

        CHECK((team_a.stillAlive()==0 || team_b.stillAlive()==0));
        
        CHECK_NOTHROW(team_a.print());
        CHECK_NOTHROW(team_b.print());
    }
}