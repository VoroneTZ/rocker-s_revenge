#include "vars.c";

var DialogId;
var ShowDialog=3;
var StartGame=0;

BMAP* button10pcx = "button.dds";
BMAP* button60pcx = "button_w.dds";


function min_easy()
{
	if (LevelProgressEasy>1){LevelProgressEasy=LevelProgressEasy-1;	}
}
function plus_easy()
{
	if (LevelProgressEasy<LevelMaxEasy){LevelProgressEasy=LevelProgressEasy+1;	}
}
function min_norm()
{
	if (LevelProgressNormal>1){LevelProgressNormal=LevelProgressNormal-1;	}
}
function plus_norm()
{
	if (LevelProgressNormal<LevelMaxNormal){LevelProgressNormal=LevelProgressNormal+1;	}
}
function min_hard()
{
	if (LevelProgressHard>1){LevelProgressHard=LevelProgressHard-1;	}
}
function plus_hard()
{
	if (LevelProgressHard<LevelMaxHard){LevelProgressHard=LevelProgressHard+1;	}
}
function start_easy()
{
StartGame=1;	
}
function start_normal()
{
StartGame=2;	
}
function start_hard()
{
StartGame=3;	
}

PANEL* LevelSelect =
{
	pos_x = 0;
	pos_y = 0;
	bmap = "menu.dds";
	digits(60,30, "ВЫБОР УРОВНЯ", "Courier#40bi", 1, NULL);
	
	digits(30,100, "Легкий                < %2.0f >", "Courier#30b", 1, LevelProgressEasy);  
	digits(30,150, "Нормальный            < %2.0f >", "Courier#30b", 1, LevelProgressNormal); 
	digits(30,200, "Сложный               < %2.0f >", "Courier#30b", 1, LevelProgressHard); 
//	digits(30,250, "Очень сложный         < %.1f >", "Courier#30b", 1, NULL); 
//	digits(30,300, "Димас должен умереть  < %.1f >", "Courier#30b", 1, NULL); 
//	digits(30,350, "Рок или рэп           < %.1f >", "Courier#30b", 1, NULL);	
   digits(30,400, "РЕЙТИНГ", "Courier#30b", 1, NULL);
   digits(30,450, "ГАЛЛЕРЕЯ", "Courier#30b", 1, NULL);
	digits(30,500, "Сохранить   Загрузить", "Courier#30b", 1, NULL);
	
	button=400,100,button10pcx,button10pcx,button10pcx,min_easy,NULL,NULL;
	button=480,100,button10pcx,button10pcx,button10pcx,plus_easy,NULL,NULL;
	button=400,150,button10pcx,button10pcx,button10pcx,min_norm,NULL,NULL;
	button=480,150,button10pcx,button10pcx,button10pcx,plus_norm,NULL,NULL;
	button=400,200,button10pcx,button10pcx,button10pcx,min_hard,NULL,NULL;
	button=480,200,button10pcx,button10pcx,button10pcx,plus_hard,NULL,NULL;
	
	button=30,100,button60pcx,button60pcx,button60pcx,NULL,NULL,NULL;
	button=30,150,button60pcx,button60pcx,button60pcx,NULL,NULL,NULL;
	button=30,200,button60pcx,button60pcx,button60pcx,NULL,NULL,NULL;
	button=30,450,button60pcx,button60pcx,button60pcx,NULL,NULL,NULL;
	button=30,500,button60pcx,button60pcx,button60pcx,NULL,NULL,NULL;
	button=230,500,button60pcx,button60pcx,button60pcx,NULL,NULL,NULL;
	button=30,400,button60pcx,button60pcx,button60pcx,NULL,NULL,NULL;
	
	layer = 10;
	flags = OVERLAY | SHOW | OUTLINE;
}

function DialogLoop()
{
  PANEL* DialogText_panel = pan_create(NULL,0);
  FONT* my_font = font_create("System#40b");
  DialogText_panel.pos_x = (screen_size.x - 10)/2; 
  DialogText_panel.pos_y = (screen_size.y - 10)/2;
  while(1)
  {
  	 if (ShowDialog==1){set(DialogText_panel,SHOW);ShowDialog=3; }
  	 if (ShowDialog==0){reset(DialogText_panel,SHOW);ShowDialog=3; }
  	 
  	 if (DialogId==1){pan_setstring(DialogText_panel,1,0,0,my_font,str_create("Test2!"));DialogId=0;}
  	 wait(2);
  }
}
