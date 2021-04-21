#include "vars.c";
#include "panels.c";
SOUND* miss_snd = "files/miss.wav"; 
SOUND* fire0_snd = "files/fire-0.wav"; 
SOUND* lift_snd = "files/machan.wav"; 
SOUND* hit_snd = "files/hit.wav";  

function GameOver()
{
	fade_in();
	reset(panel_boss,SHOW);
	wait(-3);
	level_load("files/door.wmb");
	reset(panel_boss,SHOW);
set(LevelSelect,SHOW);
	reset(hud_pan,SHOW);	
	fade_out();
}

function FHitPlayer()
{
  FFHitPlayer=1;
  
  
}


action ARealPlayer()
{ 
  player = me;
  vec_set(my.min_x, vector(-20, -20, -240));
  vec_set(my.max_x, vector(20, 20, 150));
  my.min_z *= 0.5;
  var speed_down = 0;
  var anim_percent = 0;
  VECTOR vFeet;
  vec_for_min(vFeet, me);
 
  var lanimpercent = 0;
  var lacc = 0;

  var lneedjumpacc = false;
  while (FPlayerLife > 0)
  {
    lacc = 0;
    fcrouch = false;
    if (key_s && lcanjump==1) {
      fcrouch = true;
    }
    else
    {
      if (key_a) {
        my.pan = 90;
        lacc = 1;
      }
      if (key_d) {
        my.pan = 270;
        lacc = 1;
      }
      var dist_down;
      if (c_trace(my.x, vector(my.x, my.y, my.z - 5000), IGNORE_ME | IGNORE_PASSABLE | USE_BOX | IGNORE_SPRITES) > 0)
        dist_down = my.z + vFeet.z - target.z;
      else
        dist_down = 1;

      if (dist_down > 0)
        dist_down = clamp(dist_down, 0, accelerate(speed_down, 5, 0.1));
      else
        speed_down = 0;

      if (FPlayerAttack == 0 && mouse_left) {
        FPlayerAttack = 1;
        snd_play(miss_snd, 100, 0);
      }
      if (FPlayerAttack > 0) {
        FPlayerAttack = FPlayerAttack + 5 * time_step;
      }
      if (FPlayerAttack > 100) {
        FPlayerAttack = 0;
      }

      if (ljump > 0) {
        ljump = ljump - (15 * time_step);
        speed_down = (ljump) / 5;
      }
      else
      {
        if (lcanjump != 1 && lneedjumpacc == true) {
          speed_down = 0;
          lneedjumpacc = false;
        }
        if ((c_trace(my.x, vector(my.x, my.y, my.z - 5000), IGNORE_ME | IGNORE_PASSABLE | USE_BOX) < 1) && key_space == false) {
          lcanjump = 1;
        }
        if (key_space && lcanjump!=-1) {
          ljump = 150;
          lcanjump = lcanjump-1;
          lneedjumpacc = true;
        }
      }

      var dist_ahead = 7 * (lacc) * time_step;
      dist_ahead = sign(dist_ahead) * (abs(dist_ahead) + 0.5 * dist_down);
      if (FPlayerCanMove == 1) {
        if (ljump < 1) {
          c_move(me, vector(0, dist_ahead, 0), vector(0, 0, -dist_down), IGNORE_PASSABLE | GLIDE | IGNORE_SPRITES); 
        }
        else
        {
          c_move(me, vector(0, dist_ahead, 0), vector(0, 0, dist_down), IGNORE_PASSABLE | GLIDE | IGNORE_SPRITES); 
        }
      }
    }
    camera.x = my.x;
    camera.y = my.y - 4738;
    camera.z = my.z + 76;
    camera.pan = -270;
    camera.tilt = 0;
    wait(1);
  }
}

action APlayer()
{

  set(my, PASSABLE);
  my.min_z *= 0.5;
  var speed_down = 0;
  var anim_percent = 0;
 // VECTOR vFeet;
 // vec_for_min(vFeet, me);
  
  var lanimpercent = 0;
 // var lacc = 0;

  var lneedjumpacc = false;
  while (FPlayerLife > 0)
  {
    my.x = player.x;
    my.y = player.y - 30;
    my.z = player.z;

    if (key_a|| FCutScene ==5) {
      my.pan = 90;
     // lacc = 1;
    }
    if (key_d || FCutScene ==4) {
      my.pan = 270;
    //  lacc = 1;
    }
    if (fcrouch) {
      my.frame = 3;
    } else if (FPlayerHitTimer > 0) {
      my.frame = 11;
    }
    else if (FPlayerAttack > 0)
    {
      my.frame = 8;
      if (FPlayerAttack > 40) {
        my.frame = 9;
      }
      if (FPlayerAttack > 60) {
        my.frame = 10;
      }
    } else if (lcanjump < 1)
    {
      if (ljump > 70) {
        my.frame = 13;
      } else
      if (ljump < 70  && ljump > 5) {
        my.frame = 14;
      } else
      if (ljump < 5)
      {
        my.frame = 15;
      }
    }
    else if (key_a || key_d || FCutScene == 1)
    {

      lanimpercent = lanimpercent + my.skill4 * 0.1 * time_step;
      if (lanimpercent > 4) {
        lanimpercent = 0;
      }

      my.frame = lanimpercent + 4;
    }
    else
    {
     // lacc = 0;
      lanimpercent = lanimpercent + my.skill4 * 0.1 * time_step;
      if (lanimpercent > 3) {
        lanimpercent = 0;
      }

      my.frame = lanimpercent;
    }
    if (FPlayerCanMove == 0 && FCutScene == 0) {
     // lacc = 0;
      lanimpercent = lanimpercent + my.skill4 * 0.1 * time_step;
      if (lanimpercent > 3) {
        lanimpercent = 0;
      }

      my.frame = lanimpercent;
    }
    if (FCutScene == 2) {
      my.frame = 18;
    }
    if (FCutScene == 3) {
      my.frame = 19;
    }

    wait(1);
  }
  my.frame = 12;
  wait(-2);


}
