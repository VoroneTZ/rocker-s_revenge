#include "vars.c";
#include "enemy.c";
SOUND* lift_snd = "files/machan.wav";
SOUND* cage_snd = "files/explo.wav";


action cutscenesprite()
{
  my.scale_x = 1.907;
  my.scale_y = 1.907;
  my.scale_z = 1.907;
}

action guitarV()
{
  if
  (FWeaponRating[1][0] == 0) {
    while (vec_dist(my.x, player.x) > 50)
    {
      wait(1);
    }
    FWeaponRating[1][0] = 1;
    if (FStudyGuitar == 0) {
      DialogId = -1;
      ShowDialog = 1;
      wait(-2);
      ShowDialog = 0;
      FStudyGuitar = 1;
    }
  }
  ent_remove(me);
}

//5 wait, 6 count,7 type
action npc_generator()
{
  set(my, PASSABLE);
  set(my, INVISIBLE);
  while (my.skill7 == 0)
  {
    wait(1);
  }
  var i = 0;
  var j = 0;
  while (i < my.skill6)
  {
    i = i + 1;
    if (my.skill7 == 3) {
      ENTITY* npc = ent_create("files/gopwalk+9.dds", my.x, ANPC);
      npc.skill1 = my.skill1;
      npc.skill2 = my.skill2;
      npc.skill3 = my.skill3;
      npc.skill4 = my.skill4;
      npc.y = player.y + 10;
    }
    if (my.skill7 == 1) {
      ENTITY* npc = ent_create("files/rap1+9.dds", my.x, ANPC);
      npc.skill1 = my.skill1;
      npc.skill2 = my.skill2;
      npc.skill3 = my.skill3;
      npc.skill4 = my.skill4;
      npc.y = player.y + 10;
    }
    if (my.skill7 == 2) {
      ENTITY* npc = ent_create("files/goprun+9.dds", my.x, ANPC);
      npc.skill1 = my.skill1;
      npc.skill2 = my.skill2;
      npc.skill3 = my.skill3;
      npc.skill4 = my.skill4;
      npc.y = player.y + 10;
    }
    while (j < my.skill5) {
      wait(-1);
      j = j + 1;
    }
    j = 0;
  }
  ent_remove(me);
}

action amv()
{ my.albedo = 200;
  set(my, BRIGHT);
  my.scale_x = 0.569;
  my.scale_y = 0.569;
  my.scale_z = 0.569;
  wait(1);
}

action abr()
{ set(my, BRIGHT); my.albedo = 200;
  my.scale_x = 0.189;
  my.scale_y = 0.189;
  my.scale_z = 0.189;
  wait(1);
}

action apl()
{ set(my, BRIGHT);
  my.albedo = 200;
  my.scale_x = 0.769;
  my.scale_y = 0.769;
  my.scale_z = 0.769;
  while (1)
  {
    if (FCutScene == 0)
    {
      my.frame = 1;
    } else {
      my.frame = 4;
    }
    wait(-0.5);
    if (FCutScene == 0)
    {
      my.frame = 2;
    } else {
      my.frame = 6;
    }
    wait(-0.5);
  }
}

function Level4Ending()
{
  fade_in();
  wait(-2);
  level_load("files/lvl43.wmb");
  ENTITY* mv = ent_create("files/mv+2.dds", vector(43, 0, 70), amv);
  ENTITY* pl = ent_create("files/playerL+20.dds", vector(-144, 0, 0), apl);
  fade_out();
  wait(-1);
  Dialog(2, 15); while (FDialog == 1) {
    wait(1);
  }
  Dialog(2, 16);
  mv.frame = 2;
  FCutScene = 1;
  while (pl.x < 21)
  {
    pl.x = pl.x + 5 * time_step;
    wait(1);
  }
  FCutScene = 0;
  ENTITY* br = ent_create("files/beer.dds", vector(69, -10, 20), abr);
  Dialog(4, 17); while (FDialog == 1) {
    wait(1);
  }

  mv.frame = 1;
  Dialog(4, 18); while (FDialog == 1) {
    wait(1);
  }
  mv.frame = 2;
  Dialog(4, 19); while (FDialog == 1) {
    wait(1);
  }
  mv.frame = 1;
  Dialog(4, 20); while (FDialog == 1) {
    wait(1);
  }
  mv.frame = 2;
  Dialog(4, 21); while (FDialog == 1) {
    wait(1);
  }
  mv.frame = 1;
  Dialog(4, 22); while (FDialog == 1) {
    wait(1);
  }
  mv.frame = 2;
  Dialog(4, 23); while (FDialog == 1) {
    wait(1);
  }
  mv.frame = 1;
  Dialog(4, 24); while (FDialog == 1) {
    wait(1);
  }
  mv.frame = 2;
  Dialog(4, 25); while (FDialog == 1) {
    wait(1);
  }
  ShowDialog = 0;
  set(LevelSelect, SHOW);
}

action lvl4_end()
{
  my.frame = 1;
  while (vec_dist(my.x, player.x) > 250)
  {
    wait(1);
  }
  Level4Ending();
}

action Switch()
{
  FKey = 0;
  my.frame = 1;
  while (vec_dist(my.x, player.x) > 50)
  {
    wait(1);
  }
  my.frame = 2;
  FKey = 1;
}

action Elevator()
{
  while (vec_dist(my.x, player.x) > 200)
  {
    wait(1);
  }
  wait(-2);
  snd_play(lift_snd, 100, 0);
  while (my.z < my.skill1)
  {
    player.z = player.z + 8 * time_step;
    my.z = my.z + 8 * time_step;
    wait(1);
  }
}


action Cage()
{
  while (vec_dist(my.x, player.x) > 300 || FAttackType != 3 || my.z > player.z || FPlayerWeapon != 0)
  {
    wait(1);
  }

  snd_play(cage_snd, 100, 0);
  ent_remove(me);
}

action end3()
{
  wait(-2);
  while (vec_dist(my.x, player.x) > 400)
  {
    wait(1);
  }
  if (LevelMultiptex == 0.5) {
    LevelProgressEasy = 4;
    if (LevelMaxEasy < 4) {
      LevelMaxEasy = 4;
    }
  }
  if (LevelMultiptex == 1) {
    LevelProgressNormal = 4;
    if (LevelMaxNormal < 4) {
      LevelMaxNormal = 4;
    }
  }
  if (LevelMultiptex == 2) {
    LevelProgressHard = 4;
    if (LevelMaxHard < 4) {
      LevelMaxHard = 4;
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

action Train()
{
  wait(-1);
  while (vec_dist(my.x, player.x) > 150)
  {
    wait(1);
  }
  FPlayerCanMove = 0;
  fade_in();
  wait(-1);
  level_load("lvl41.wmb");
  fade_out();
  FPlayerCanMove = 1;
  deathcounter = 0;
  deathcounterwork = 1;
  while ((deathcounter < 23) && (deathcounterwork == 1))
  {
    wait(1);
  }
  if (deathcounterwork == 1)
  {
    deathcounterwork = 0;
    fade_in();
    wait(-1);
    level_load("lvl42.wmb");
    fade_out();
  }
}

action Door()
{

  wait(2);
  while (FKey == 0)
  {
    wait(10);
  }
  snd_play(lift_snd, 100, 0);
  ent_remove(me);
}

action ADrummer()
{
  while (1)
  {
    if (FCutScene == 5) {
      my.frame = 3;
    }
    else
    {
      my.frame = 1;
      wait(-0.2);
      my.frame = 2;
      wait(-0.2);
    }
    wait(1);

  }
}

action Vinyl()
{
  if (FVinyls[my.skill1][my.skill2] == 0)
  {
    while (vec_dist(my.x, player.x) > 50)
    {
      wait(1);
    }
    FVinyls[my.skill1][my.skill2] = 1;
    media_play("files/gtr.mp3", NULL, 100);
    FPlayerPickupCount = FPlayerPickupCount + 1000;
    if (FStudyVinyl == 0) {
      set(my, INVISIBLE);
      DialogId = -2;
      ShowDialog = 1;
      wait(-4);
      ShowDialog = 0;
      FStudyVinyl = 1;
    }
  }
  ent_remove(me);
}

action Beer()
{
  while (vec_dist(my.x, player.x) > 50)
  {
    wait(1);
  }
  FPlayerHealth = FPlayerHealth + 2;
  ent_remove(me);
}