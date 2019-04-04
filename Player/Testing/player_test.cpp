#include "../Header/player.h"
#include "../../FarmAnimal/Header/bull.h"
#include "../../FarmAnimal/Header/platypus.h"
#include "CUnit/Basic.h"
#include <sstream>

void playerTest(){
    Player p;
    CU_ASSERT_EQUAL(p.getWater(),DEFWATER);
    CU_ASSERT_EQUAL(p.getMoney(),DEFMONEY);
}

void talkTest(){
    Player p;
    Bull b;
    string s = p.talk(b);
    CU_ASSERT_EQUAL(s, "(Manly) Moooo...");
    Platypus pl;
    string s = p.talk(pl);
    CU_ASSERT_EQUAL(s, "krrrrrrr...");
}

void interactWellTest(){
    Player p;
    for (int i = DEFWATER; i<MAXWATER; i++){
        p.interactWell();
    }

    bool isError = false;
    try{
        p.interactWell();
    }catch(char const* e){
        if(strcmp(e, "Ember penuh\n")){
            isError = true;
        }
    }
    CU_ASSERT_TRUE(isError);
}

void interactMixerTest(){
    Player p;
}

void interactTruckTest(){
    Player p;
    
}

void interactTest(){
    Player p;
    Bull b;
    Platypus pl;
    bool e = false;
    try{
        p.interact(b);
        CU_ASSERT_EQUAL(p.getInventory().getElmt(getLastIdx()).getID(),3);
    }catch (char const* err){
        if(strcmp(err,"Tidak bisa berinteraksi dengan meat producing animal\n")){
            e = true;
        }
    }

    e = false;
    try{
        int id;
        p.interact(pl);
        if (p.getInventory().getElmt(getLastIdx()).getID() == 5 || p.getInventory().getElmt(getLastIdx()).getID() == 6)
            id = true;
        CU_ASSERT_TRUE(id);
        CU_ASSERT_EQUAL(p.getInventory().getLastIdx(),0);
    }catch (char const* err){
        if(strcmp(err,"Tidak bisa berinteraksi dengan meat producing animal\n")){
            e = true;
        }
    }

    for (int i=1; i<MAXBAG; i++){
        Platypus p1;
        p.interact(p1);
    }

    bool isError = false;
    try{
        Platypus p1;
        p.interact(p1);
    }catch(char const* e){
        if(strcmp(e, "Inventory penuh\n")){
            isError = true;
        }
    }
    CU_ASSERT_TRUE(isError);
}

void killTest(){
    Player p;
    Bull b1;
    p.kill(b1);
    CU_ASSERT_EQUAL(p.getInventory().getElmt(0).getID(), 3); 
    for (int i=1; i<MAXBAG; i++){
        Bull b;
        p.kill(b);
    }

    bool isError = false;
    try{
        Bull b;
        p.kill(b);
    }catch(char const* e){
        if(strcmp(e, "Inventory penuh\n")){
            isError = true;
        }
    }
    CU_ASSERT_TRUE(isError);
}

void growTest(){
    Player p;
    bool e = false;
    try{
        p.grow();
        CU_ASSERT_EQUAL(p.getWater(),24);
    }catch(char const* err){
        if(strcmp(err,"Air tidak cukup\n")){
            e = true;
        }
    }
    CU_ASSERT_TRUE(e);
}

void renderTest(){
    Player P;
    CU_ASSERT_EQUAL(p.render(),22);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("player.cpp", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "player", playerTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run the tests and show the run summary
    CU_basic_run_tests();
    return CU_get_error();
}