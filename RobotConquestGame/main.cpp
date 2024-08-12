#include <iostream>
//Base Header files 
#include "robot.h"
#include "bulldozer.h"
#include "humanic.h"
#include "roomba.h"
#include "optimusprime.h"
#include "robocop.h"

using namespace std;

void match(robot&, robot&); //function to make a contest between two class

int main()
{
    srand(time(NULL)); //Gets the pseudorandom sequence for random number generator once in program
    
        bulldozer b, b1, b2;
        cout << b.getType() << endl;
        b.print_stats();
        b.getDamage();
        
        cout << "=============================" << endl;
        
        robocop r, r1, r2;
        cout << r.getType() << endl;
        r.print_stats();
        r.getDamage();
        
        cout << "=============================" << endl;
        
        optimusprime o, o1, o2;
        cout << o.getType() << endl;
        o.print_stats();
        o.getDamage();
        
        cout << "=============================" << endl;
        
        roomba ro, ro1, ro2;
        cout << ro.getType() << endl;
        ro.print_stats();
        ro.getDamage();
        
        cout << "=============================" << endl << endl << endl;
    
    match(b, r);
    cout << "=============================" << endl << endl;
    
    match(b1, o);
    cout << "=============================" << endl << endl;
    
    match(b2, ro);
    cout << "=============================" << endl << endl;
    
    match(r1, o1);
    cout << "=============================" << endl << endl;
    
    match(r2, ro1);
    cout << "=============================" << endl << endl;
    
    match(o2, ro2);
    cout << "=============================" << endl << endl;
    
    
    return 0;
}


//A contest between two robots
void match(robot &p1, robot &p2)  
{
    bool prev_con = false;
    bool p1_c = false;
    bool p2_c = false; 
    
    int p1_dmg;
    int p2_dmg;
        
    if( p1.getHP() <= 0 || p2.getHP() <= 0 )
    {
        prev_con = true;
    }
        if(p1.getType() == "roomba")
        {
            p1_c = true;
        }
        if(p2.getType() == "roomba")
        {
            p2_c = true;
        }
    
    
    if( prev_con == false )
    {
        cout << "Contest between " << p1.getType() << " and " << p2.getType() << " has begun!" << endl;
        cout << "-----------------------------------------" << endl;
            do
            {
                p1_dmg = p1.getDamage();
                p2_dmg = p2.getDamage();
                
                cout << "# " << p1.getType() << " has done " << p1_dmg << " damage to " << p2.getType() << endl;
                cout << "# " << p2.getType() << " has done " << p2_dmg << " damage to " << p1.getType() << endl;
                    
                p1.compAttack(p2_dmg);
                p2.compAttack(p1_dmg);
                
                if(p1_c == true)
                {
                    p1_dmg = p1.getDamage();
                    cout << "# " << p1.getType() << " is just so fast instantly attacked again" << 
                    "(" << p1_dmg << " points" << ")" << endl;
                    p2.compAttack(p1_dmg);
                }
                if(p2_c == true)
                {
                    p2_dmg = p2.getDamage();
                    cout << "# " << p2.getType() << " is just so fast instantly dealt another attack" << 
                    "(" << p2_dmg << " points" << ")" << endl;
                    p1.compAttack(p2_dmg);
                }
                
                if(p1.getHP() < 0)
                    cout << "|-> " << p1.getType() << " has 0 hitpoints left" << endl;   
                else
                    cout << "|-> " << p1.getType() << " has " << p1.getHP() << " hitpoints left" << endl;
                
                if(p2.getHP() < 0)
                    cout << "|-> " << p2.getType() << " has 0 hitpoints left" << endl;
                else
                    cout << "|-> " << p2.getType() << " has " << p2.getHP() << " hitpoints left" << endl;
                
                
                cout << "=============================" << endl;
            }while( p1.getHP() > 0 && p2.getHP() > 0 );
            
            if(p1.getHP() <= 0 && p2.getHP() > 0)
            {
                cout << p2.getType() << " has won the contest!" << endl << " ~~ ALL HAIL TO " << p2.getType() << " ~~" << endl;
            }
            else if(p2.getHP() <= 0 && p1.getHP() > 0)
            {
                cout << p1.getType() << " has won the contest!" << endl << " ~~ ALL HAIL TO " << p1.getType() << " ~~" << endl;
            }
            else
                cout << p1.getType() << " has won the contest since it did attack first" << endl << " ~~ ALL HAIL TO " << p1.getType() << " ~~" << endl;
    }
    else
    {
        cout << "One of opponents has been defeated recently in a contest (create a new robot)" << endl;
    }
    
    
        
        
    
}
