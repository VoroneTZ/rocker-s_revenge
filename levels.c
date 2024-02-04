#include "vars.c";

#ifdef LRus
#include "panels.c";
#endif
#ifdef LEng
#include "panelsEng.c";
#endif

#include "other.c";

function ShowStudy1()
{
	if (FStudy1==0)
	{
		FStudy1=1;
		Dialog(3, -3);
		wait(-4);
		Dialog(3, -4);
		wait(-4);
		Dialog(3, -5);	
	}	
	
}

function StartLevel1()
{
  var i = 0;
  fade_in();
  wait(-2);
  FMusic = media_loop("files/metallica-fuel.mid", NULL, 100);
  level_load("files/lvl1.wmb");
  fade_out();
  wait(-1);
  FPlayerCanMove = 0;
  if (debug == 0)
  {
    while (i < 15)
    {
      FCutScene = 2;
      wait(-0.2);
      FCutScene = 3;
      wait(-0.2);
      i = i + 1;
    }
    FCutScene = 5;
    ENTITY* rap1 = ent_create("files/rap1+9.dds", vector(-349, -116, 179), cutscenesprite);
    wait(-1);

    Dialog(3, 1); while (FDialog == 1) {
      wait(1);
    }
    Dialog(2, 2); while (FDialog == 1) {
      wait(1);
    }
    Dialog(2, 3); while (FDialog == 1) {
      wait(1);
    }

    ent_remove(rap1);
    FCutScene = 0;

  }
  ShowStudy1();
  deathcounter = 0;
  FPlayerCanMove = 1;
  ENTITY* gen1 = ent_create("files/rockenemy1+9.dds", vector(-349, -116, 179), npc_generator);
  gen1.skill1 = 1;
  gen1.skill2 = 600;
  gen1.skill3 = 150;
  gen1.skill4 = 4;
  gen1.skill5 = 5;
  gen1.skill6 = 5;
  gen1.skill7 = 1;

  ENTITY* gen2 = ent_create("files/rockenemy1+9.dds", vector(531, 157, 179), npc_generator);
  gen2.skill1 = 1;
  gen2.skill2 = 600;
  gen2.skill3 = 150;
  gen2.skill4 = 4;
  gen2.skill5 = 7;
  gen2.skill6 = 5;
  gen2.skill7 = 1;
  deathcounterwork = 1;
  while ((deathcounter < 10) && (deathcounterwork == 1))
  {
    wait(2);
  }
  if (deathcounterwork == 1)
  { deathcounterwork = 0;
    if (LevelMultiptex == 0.5) {
      LevelProgressEasy = 2;
      if (LevelMaxEasy < 2) {
        LevelMaxEasy = 2;
      }
    }
    if (LevelMultiptex == 1) {
      LevelProgressNormal = 2;
      if (LevelMaxNormal < 2) {
        LevelMaxNormal = 2;
      }
    }
    if (LevelMultiptex == 2) {
      LevelProgressHard = 2;
      if (LevelMaxHard < 2) {
        LevelMaxHard = 2;
      }
    }
    game_save("save", 0, SV_VARS);
    fade_in();
    wait(-2);

    if (LevelMultiptex == 0.5) {
      StartGame = 1;
    }
    if (LevelMultiptex == 1) {
      StartGame = 2;
    }
    if (LevelMultiptex == 2) {
      StartGame = 3;
    }
  }
}

function StartLevel2()
{
  level_load("files/lvl2.wmb");
  fade_out();
  FMusic = media_loop("files/megadeth-she_wolf.mid", NULL, 100);
}

function StartLevel3()
{
  level_load("files/lvl3.wmb");
  fade_out();
  FMusic = media_loop("files/zz_top-beer_drinkers_hell_raisers.mid", NULL, 100);


}

function StartLevel4()
{
  level_load("files/lvl4.wmb");
  fade_out();
  FMusic = media_loop("files/osbourne_ozzy-crazy_train.mid", NULL, 100);
  ShowGuitar();
  set(shop_menu, SHOW);
  FPlayerCanMove = 0;
}



function StartLevel5()
{
}

function StartLevel6()
{
}

function StartLevel7()
{
}

function StartLevel8()
{
}

function StartLevel9()
{
}

function StartLevel10()
{
}

function StartLevel11()
{
}

function StartLevel12()
{
}

function StartLevel13()
{
}

function StartLevel14()
{
}

function StartLevel15()
{
}

function StartLevel16()
{
}

function StartLevel17()
{
}

function StartLevel18()
{
}

function StartLevel19()
{
}

function StartLevel20()
{
}

