///////////////////////////////
#include <acknex.h>
#include <default.c>

#include "panels.c";
#include "vars.c";
#include "levels.c";
#include "player.c";
#include "npc.c";
#include "enemy.c";
#include "other.c";


///////////////////////////////

function StartLevel()
{
  FPlayerHealth = 20 * (0.5 / LevelMultiptex);
  FPlayerLife = 1;
  media_stop(FMusic);

  set(hud_pan, SHOW);
  reset(LevelSelect, SHOW);
  var LevelId;
  if (StartGame == 1) {
    LevelId = LevelProgressEasy;
    LevelMultiptex = 0.5;
  }
  if (StartGame == 2) {
    LevelId = LevelProgressNormal;
    LevelMultiptex = 1;
  }
  if (StartGame == 3) {
    LevelId = LevelProgressHard;
    LevelMultiptex = 2;
  }
  if (LevelId == 1) {
    StartLevel1();
  } else if (LevelId == 2) {
    StartLevel2();
  } else if (LevelId == 3) {
    StartLevel3();
  } else if (LevelId == 4) {
    StartLevel4();
  } else if (LevelId == 5) {
    StartLevel5();
  } else if (LevelId == 6) {
    StartLevel6();
  } else if (LevelId == 7) {
    StartLevel7();
  } else if (LevelId == 8) {
    StartLevel8();
  } else if (LevelId == 9) {
    StartLevel9();
  } else if (LevelId == 10) {
    StartLevel10();
  } else if (LevelId == 11) {
    StartLevel11();
  } else if (LevelId == 12) {
    StartLevel12();
  } else if (LevelId == 13) {
    StartLevel13();
  } else if (LevelId == 14) {
    StartLevel14();
  } else if (LevelId == 15) {
    StartLevel15();
  } else if (LevelId == 16) {
    StartLevel16();
  } else if (LevelId == 17) {
    StartLevel17();
  } else if (LevelId == 18) {
    StartLevel18();
  } else if (LevelId == 19) {
    StartLevel19();
  } else if (LevelId == 20) {
    StartLevel20();
  }
  on_esc = pause_game;
  on_joy8 = pause_game;
}

function FirstTitles()
{
  panel_red.alpha = 0;
  FMusic = media_loop("files/metallica-master_of_puppets.mid", NULL, 100);
  panel_black.alpha = 100;
  var i = 50;

  LevelSelect.pos_x = (screen_size.x - bmap_width(LevelSelect.bmap)) / 2;
  LevelSelect.pos_y = (screen_size.y - bmap_height(LevelSelect.bmap)) / 2;


  pan_pause.pos_x = (screen_size.x - bmap_width(pan_pause.bmap)) / 2;
  pan_pause.pos_y = (screen_size.y - bmap_height(pan_pause.bmap)) / 2;

  pan_pause2.pos_x = (screen_size.x - bmap_width(pan_pause.bmap)) / 2;
  pan_pause2.pos_y = (screen_size.y - bmap_height(pan_pause.bmap)) / 2;

  main_menu.pos_x = (screen_size.x - bmap_width(main_menu.bmap)) / 2;
  main_menu.pos_y = (screen_size.y - bmap_height(main_menu.bmap)) / 2;

  panel_dialog.pos_x = (screen_size.x - bmap_width(panel_dialog.bmap)) / 2;


  vtz_logo.pos_x = (screen_size.x - bmap_width(vtz_logo.bmap)) / 2;
  vtz_logo.pos_y = (screen_size.y - bmap_height(vtz_logo.bmap)) / 2;

  shop_menu.pos_x = (screen_size.x - bmap_width(shop_menu.bmap)) / 2;
  shop_menu.pos_y = (screen_size.y - bmap_height(shop_menu.bmap)) / 2;

  pan_guitar4.pos_x = ((screen_size.x - bmap_width(shop_menu.bmap)) / 2) + 113;
  pan_guitar4.pos_y = ((screen_size.y - bmap_height(shop_menu.bmap)) / 2) + 89;

  pan_guitar3.pos_x = ((screen_size.x - bmap_width(shop_menu.bmap)) / 2) + 113;
  pan_guitar3.pos_y = ((screen_size.y - bmap_height(shop_menu.bmap)) / 2) + 89;

  pan_guitar2.pos_x = ((screen_size.x - bmap_width(shop_menu.bmap)) / 2) + 113;
  pan_guitar2.pos_y = ((screen_size.y - bmap_height(shop_menu.bmap)) / 2) + 89;

  pan_guitar1.pos_x = ((screen_size.x - bmap_width(shop_menu.bmap)) / 2) + 113;
  pan_guitar1.pos_y = ((screen_size.y - bmap_height(shop_menu.bmap)) / 2) + 89;

  zo_logo.pos_x = (screen_size.x - bmap_width(zo_logo.bmap)) / 2;
  zo_logo.pos_y = (screen_size.y - bmap_height(zo_logo.bmap)) / 2;
  if (debug == 0) {
    set(vtz_logo, SHOW);
    wait(1);
    while (panel_black.alpha > 1)
    {
      panel_black.alpha -= 8 * time_step;
      if (i <= 50)
        media_tune(FMusic, i, 0, 0);
      i = i + 0.2;
      wait(2);
    }
    panel_black.alpha = 0;
    wait(-1);
    while (panel_black.alpha < 100)
    {
      panel_black.alpha += 8 * time_step;
      if (i > 1)
        media_tune(FMusic, i, 0, 0);
      i = i - 0.2;
      wait(2);
    }
    reset(vtz_logo, SHOW);
    panel_black.alpha = 100;
    set(zo_logo, SHOW);
    while (panel_black.alpha > 1)
    {
      panel_black.alpha -= 8 * time_step;
      if (i <= 50)
        media_tune(FMusic, i, 0, 0);
      i = i + 0.2;
      wait(2);
    }
    panel_black.alpha = 0;
    wait(-1);
    while (panel_black.alpha < 100)
    {
      panel_black.alpha += 8 * time_step;
      if (i > 1)
        media_tune(FMusic, i, 0, 0);
      i = i - 0.2;
      wait(2);
    }
    panel_black.alpha = 100;
    reset(zo_logo, SHOW);
  }
  else
  {
    LevelMaxEasy = 20;
    LevelMaxNormal = 20;
    LevelMaxHard = 20;
  }
  set(main_menu, SHOW);
  while (panel_black.alpha > 1)
  {
    panel_black.alpha -= 8 * time_step;
    if (i <= 50)
      media_tune(FMusic, i, 0, 0);
    i = i + 0.2;
    wait(2);
  }
  reset(panel_black, SHOW);
}

function main()
{
  on_esc = beep;
  FWeaponRating[0][0] = 1;
  var i = 0;
  video_mode = 12;

  // video_screen = 1;
  mouse_mode = 4;
  wait(1);
  vec_set(screen_color, vector(1, 1, 1)); // dark blue
  vec_set(sky_color, vector(50, 1, 1)); // dark blue
  video_window(NULL, NULL, 0, "Rocker`s Revenge");
  d3d_antialias = 1;
  shadow_stencil = 3;

  // level_load("my_level.wmb");
  vec_set(camera.x, vector(-250, 0, 50));
  vec_set(camera.pan, vector(0, -15, 0));

  camera.arc = 20;

  FirstTitles();
  FInventory[3] = 1;
  DialogLoop();
  while (1)
  {
    if (joy_hat == 0)  {
      if (FWeaponRating[3][0] == 1) {
        FPlayerWeapon = 3;
      }
    }
    if (joy_hat == 180) {
      if (FWeaponRating[0][0] == 1) {
        FPlayerWeapon = 0;
      }
    }
    if (joy_hat == 90) {
      if (FWeaponRating[1][0] == 1) {
        FPlayerWeapon = 1;
      }
    }

    if (key_1) {
      if (FWeaponRating[0][0] == 1) {
        FPlayerWeapon = 0;
      }
    }
    if (key_2) {
      if (FWeaponRating[1][0] == 1) {
        FPlayerWeapon = 1;
      }
    }
    if (key_3) {
      if (FWeaponRating[2][0] == 1) {
        FPlayerWeapon = 2;
      }
    }
    if (key_4) {
      if (FWeaponRating[3][0] == 1) {
        FPlayerWeapon = 3;
      }
    }
    if (key_5) {
      if (FWeaponRating[4][0] == 1) {
        FPlayerWeapon = 4;
      }
    }
    FPlayerWeaponMuliplex = 1 + FWeaponRating[FPlayerWeapon][1] * 0.25 + FWeaponRating[FPlayerWeapon][2] * 0.25 + FWeaponRating[FPlayerWeapon][3] * 0.25 + FPlayerUpgrade[0] * 0.25 + FPlayerUpgrade[1] * 0.4 + FPlayerUpgrade[2] * 0.3;
    if (StartGame > 0) {
      StartLevel();
      StartGame = 0;
    }
    compass_x = 415 - ((415 / (20 * (0.5 / LevelMultiptex))) * (FPlayerHealth));
    if (FFHitPlayer == 1) {
      if (FPlayerHitTimer < 1)
      {
        snd_play(hit_snd, 100, 0);
        FPlayerHitTimer = 8;
        FPlayerHealth -= 1;
        if (FPlayerHealth < 1)
        {
          FPlayerLife -= 1;
          if (FPlayerLife > 0)
          {
            FPlayerHealth = 4;
          }
          else
          { on_esc = beep;
            if (FInventory[3] > 0)
            {
              freeze_mode = 1;
              if (FPlayerLife != -10) {
                FPlayerLife = 0;
              }
              set(pan_pause2, SHOW);
              while (FPlayerLife == 0)
              {
                wait(1);
              }
              reset(pan_pause2, SHOW);
              freeze_mode = 0;
              if (FPlayerLife == -10) {
                GameOver();
              }
            }
            else
            {
              GameOver();
            }
          }
        }
        while (FPlayerHitTimer > 0)
        {
          FPlayerHitTimer -= (1 * time_step) * LevelMultiptex;
          wait(1);
        }
        FFHitPlayer = 0;
      }
    }


    wait(1);

  }

}
