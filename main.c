///////////////////////////////
#include <acknex.h>
#include <default.c>
#define PRAGMA_PATH "files";
#include "panels.c";
#include "vars.c";
#include "levels.c";

///////////////////////////////

function StartLevel()
{
	var LevelId;
	if (StartGame==1){LevelId=LevelProgressEasy; LevelMultiptex=0.5;}
	if (StartGame==2){LevelId=LevelProgressNormal; LevelMultiptex=1;}
	if (StartGame==3){LevelId=LevelProgressHard;LevelMultiptex=2;}
	if (LevelId==1){StartLevel1();} else
	if (LevelId==2){StartLevel2();} else
	if (LevelId==3){StartLevel3();} else
	if (LevelId==4){StartLevel4();} else
	if (LevelId==5){StartLevel5();} else
	if (LevelId==6){StartLevel6();} else
	if (LevelId==7){StartLevel7();} else
	if (LevelId==8){StartLevel8();} else
	if (LevelId==9){StartLevel9();} else
	if (LevelId==10){StartLevel10();} else
	if (LevelId==11){StartLevel11();} else
	if (LevelId==12){StartLevel12();} else
	if (LevelId==13){StartLevel13();} else
	if (LevelId==14){StartLevel14();} else
	if (LevelId==15){StartLevel15();} else
	if (LevelId==16){StartLevel16();} else
	if (LevelId==17){StartLevel17();} else
	if (LevelId==18){StartLevel18();} else
	if (LevelId==19){StartLevel19();} else
	if (LevelId==20){StartLevel20();}	
}

function main()
{
	
  video_mode = 12;
  mouse_mode = 4; 
  wait(1);
  vec_set(screen_color,vector(1,1,1)); // dark blue
  vec_set(sky_color,vector(50,1,1)); // dark blue
  video_window(NULL,NULL,0,"Rocker`s Revenge");
  d3d_antialias = 1;
  shadow_stencil = 3;
  
 // level_load("my_level.wmb");
  vec_set(camera.x,vector(-250,0,50));
  vec_set(camera.pan,vector(0,-15,0));
  
  LevelSelect.pos_x = (screen_size.x - bmap_width(LevelSelect.bmap))/2; 
  LevelSelect.pos_y = (screen_size.y - bmap_height(LevelSelect.bmap))/2;
  DialogLoop();
  
  while (1)
  {
  		if (StartGame>0){StartLevel();StartGame=0;}
		wait(1);
  }
 
}
