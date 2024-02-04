#include "vars.c";





BMAP* button10pcx = "files/button.png";
BMAP* button60pcx = "files/button_w.png";
BMAP* menubmp = "files/menu.dds";
BMAP* shopbmp = "files/shop.dds";
BMAP* menubmp2 = "files/main_menu.dds";
BMAP* vtz_logobmp = "files/vtz_logo.dds";
BMAP* zo_logobmp = "files/zo_logo.dds";
BMAP* dialogbmp = "files/dialog.dds";
BMAP* guit1bmp = "files/lespaul.dds";
BMAP* guit2bmp = "files/v.dds";
BMAP* guit3bmp = "files/bass.dds";
BMAP* guit4bmp = "files/ironbird.dds";

BMAP* pause1bmp = "files/pause.dds";
BMAP* pause2bmp = "files/pause2.dds";

PANEL* main_menu;
PANEL* shop_menu;
PANEL* pan_pause;

function LoadGame()
{
	media_stop(FMusic);
	if (game_load("save",0)<=0){game_save("save",0,SV_VARS);}
	FMusic=media_loop("files/metallica-master_of_puppets.mid",NULL,100);
}

function SaveGame()
{
	game_save("save",0,SV_VARS);
}

function Exit1()
{
	sys_exit("123");
}

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


PANEL* vtz_logo =
{
	pos_x = 0;
	pos_y = 0;
	bmap = vtz_logobmp;
	
	layer = 10;
	flags = OVERLAY | OUTLINE;
}

PANEL* zo_logo =
{
	pos_x = 0;
	pos_y = 0;
	bmap = zo_logobmp;
	
	layer = 10;
	flags = OVERLAY | OUTLINE;
}

PANEL* panel_black_menu =
{
	pos_x = 0; pos_y = 0;
	size_x = 1920; size_y = 1080;
	red = 0;
	green = 0;
	blue = 0;
		layer = 9;
	flags = LIGHT | SHOW | TRANSLUCENT ;
	
}

PANEL* panel_black =
{
	pos_x = 0; pos_y = 0;
	size_x = 1920; size_y = 1080;
	red = 0;
	green = 0;
	blue = 0;
		layer = 11;
	flags = LIGHT | SHOW | TRANSLUCENT ;
	
}



PANEL* panel_red =
{
	pos_x = 0; pos_y = 0;
	size_x = 1920; size_y = 1080;
	red = 255;
	green = 0;
	blue = 0;
		layer = 2;
	flags = LIGHT | TRANSLUCENT | SHOW ;
	
}



function StartGameEasy()
{
	LevelMultiptex=0.5;
	StartGame=1;
}

function StartGameNorm()
{
	LevelMultiptex=1;
	StartGame=2;
}

function StartGameHard()
{
	LevelMultiptex=2;
	StartGame=3;
}


PANEL* LevelSelect =
{
	pos_x = 0;
	pos_y = 0;
	bmap = menubmp;
	
	digits(60,30, "LEVEL SELECT", "Courier#40bi", 1, NULL);
	
	
	digits(30,100, "Easy                  < %2.0f >", "Courier#30b", 1, LevelProgressEasy);  
	digits(30,150, "Normal                < %2.0f >", "Courier#30b", 1, LevelProgressNormal); 
	digits(30,200, "Hard                  < %2.0f >", "Courier#30b", 1, LevelProgressHard); 
//	digits(30,250, "Î÷åíü ñëîæíûé         < %.1f >", "Courier#30b", 1, NULL); 
//	digits(30,300, "Äèìàñ äîëæåí óìåðåòü  < %.1f >", "Courier#30b", 1, NULL); 
//	digits(30,350, "Ðîê èëè ðýï           < %.1f >", "Courier#30b", 1, NULL);	
   digits(30,400, "RATING ", "Courier#30b", 1, NULL);
   digits(30,450, "GALLERY", "Courier#30b", 1, NULL);
	digits(30,500, "SAVE        LOAD        EXIT ", "Courier#30b", 1, NULL);
	
	button=400,100,button10pcx,button10pcx,button10pcx,min_easy,NULL,NULL;
	button=480,100,button10pcx,button10pcx,button10pcx,plus_easy,NULL,NULL;
	button=400,150,button10pcx,button10pcx,button10pcx,min_norm,NULL,NULL;
	button=480,150,button10pcx,button10pcx,button10pcx,plus_norm,NULL,NULL;
	button=400,200,button10pcx,button10pcx,button10pcx,min_hard,NULL,NULL;
	button=480,200,button10pcx,button10pcx,button10pcx,plus_hard,NULL,NULL;
	
	button=30,100,button60pcx,button60pcx,button60pcx,StartGameEasy,NULL,NULL;
	button=30,150,button60pcx,button60pcx,button60pcx,StartGameNorm,NULL,NULL;
	button=30,200,button60pcx,button60pcx,button60pcx,StartGameHard,NULL,NULL;
	button=30,450,button60pcx,button60pcx,button60pcx,NULL,NULL,NULL;
	button=30,500,button60pcx,button60pcx,button60pcx,SaveGame,NULL,NULL;
	button=230,500,button60pcx,button60pcx,button60pcx,LoadGame,NULL,NULL;
	button=430,500,button60pcx,button60pcx,button60pcx,Exit1,NULL,NULL;
	button=30,400,button60pcx,button60pcx,button60pcx,NULL,NULL,NULL;
	
	layer = 10;
	flags = OVERLAY | OUTLINE;
}


PANEL* panel_dialog =
{
		bmap = dialogbmp;
	pos_x = 0; 
	pos_y = 0;
	red = 0;
	green = 0;
	blue = 0;
		layer = 199;
	flags =  OVERLAY ;
	
}

PANEL* panel_boss =
{
	pos_x = 100;
	pos_y = 10;
	digits(20,70, "BOSS HEALTH: %.0f", "System#30b", 1, FBossHealth); 
	flags =  OUTLINE;
}

function DialogLoop()
{
  PANEL* DialogText_panel = pan_create(NULL,200);
  FONT* my_font = font_create("System#40b");
  DialogText_panel.pos_x = ((screen_size.x)/2)-(bmap_width(panel_dialog.bmap)/2)+40; 
  DialogText_panel.pos_y = 40;
  pan_setstring(DialogText_panel,0,0,0,my_font,str_create(""));
  pan_setstring(DialogText_panel,0,0,40,my_font,str_create(""));
  pan_setstring(DialogText_panel,0,0,80,my_font,str_create(""));
  while(1)
  {
  	 if (ShowDialog==1){set(DialogText_panel,SHOW);set(panel_dialog,SHOW);ShowDialog=3; }
  	 if (ShowDialog==0){reset(DialogText_panel,SHOW);reset(panel_dialog,SHOW);ShowDialog=3; }
  	 
  	 
  	 if (DialogId==-2){
  	 	pan_setstring(DialogText_panel,1,0,0,my_font,str_create("Collect 4 pieces of album vynyl"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("to open guitar super solo!"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;}
  	 	
  	 if (DialogId==-1){
  	 	pan_setstring(DialogText_panel,1,0,0,my_font,str_create(""));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("Use numeric buttons to select guitar"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;}
  	 
  	 if (DialogId==1){
  	 	pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Stranger"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("Yo dirty dogs, get out from here"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("ROCK sucks, let it RAP atmosphere"));
  	 	DialogId=0;}
  	 	
  	if (DialogId==2){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Rocker"));
  	   pan_setstring(DialogText_panel,2,0,50,my_font,str_create("???"));
  	   pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;} 
  		
  	if (DialogId==3){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Stranger"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("we'll smash your faces into mush!"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;} 
  	 	
  	 if (DialogId==4){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Rocker"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("man, what's up? Why are these"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("second-rate poets spoiling our rock?"));
  	 	DialogId=0;} 
  	 	
  	if (DialogId==5){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Producer"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("before I answer you, let me tell you a joke"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("Hatfield, Osbourne and GG get into a bar and want to order beer"));
  	 	DialogId=0;} 
  	 	
  	if (DialogId==6){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Producer"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("and the bartender answers them:"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("guys, you are 30 years late. Do you dare?"));
  	 	DialogId=0;} 
  	 	
  	 if (DialogId==7){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Rocker"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("wait, I didn’t come here to listen to your mothball"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("jokes, but to distribute rock in this hole!"));
  	 	DialogId=0;}  
  	 	
  	if (DialogId==8){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Producer"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("OK, let's put it another way, there are two chairs, one has the main"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("money, the other has tattered jackets, do you know what I mean?"));
  	 	DialogId=0;}  	
  	 	
  	 if (DialogId==9){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Rocker"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("man, stop with your philosophy"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("I'm a rocker, not an applicant"));
  	 	DialogId=0;} 
  	 	
  	if (DialogId==10){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Producer"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("you see, Roker, we created some vibes with you"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("it was a glorious time, but times have changed"));
  	 	DialogId=0;}   	
  	 	
  	if (DialogId==11){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*ÏðîäþñProducerñåð"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("there is no place for the old school anymore, your contract"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("with the label is broken, and you are no longer welcome in this place"));
  	 	DialogId=0;}  
  	 	
  	 if (DialogId==12){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Rocker"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("We'll see"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;}  
  	 	
  	  if (DialogId==13){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Rocker"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("There’s nothing better for a jerk"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("than a great beer.."));
  	 	DialogId=0;}  
  	 	
  	  if (DialogId==14){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Rocker"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("Troubled times have come"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("we need real rock stars help!"));
  	 	DialogId=0;}  
  	 	
  	 if (DialogId==15){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Rocker"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("Hi MV!"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;} 	
  	 	
  	 if (DialogId==16){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Mr.V"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("Yo Rocker!"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;} 
  	 	
  	 if (DialogId==17){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Rocker"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("we are no longer welcome in this city"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("rock is losing its position under the yoke of dull recitative"));
  	 	DialogId=0;} 	
  	 	
  	 	if (DialogId==18){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Rocker"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("and monkey antics in wide pants."));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("we must fight rap, are you with me?"));
  	 	DialogId=0;} 		
  	 	
  	 	
  	 	if (DialogId==19){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Mr.V"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("I knew this day would come. Rockers can't stay on"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("top forever, rap has declared war on us"));
  	 	DialogId=0;} 
  	 	
  	 	if (DialogId==20){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Mr.V"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("and the corrupt commercial rats jumped ship. and"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("what is important to them? ideas? rhythm? melodica? No!"));
  	 	DialogId=0;} 
  	 	
  		if (DialogId==21){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Mr.V"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("dollar, dollar, dollar!"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("dirty green piece of paper!"));
  	 	DialogId=0;} 
  	 	
  	 	if (DialogId==22){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Mr.V"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("we must fight now so that the next generations of rockers"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("with heavy metal in their souls will move forward"));
  	 	DialogId=0;} 
  	 	
  	 		if (DialogId==23){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Mr.V"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("we must not let these rotten rap seeds grow in our fertile rocker soil"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("we will become the executioners of rock"));
  	 	DialogId=0;} 
  	 	
  	 	if (DialogId==24){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Mr.V"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("and our name is"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("neighborhood patrol!"));
  	 	DialogId=0;} 
  	 	
  	 	if (DialogId==25){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*End of demo version"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("To be continued..."));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;} 
  	 	
  	 wait(2);
  }
}


function fade_in()
{
	set(panel_black,SHOW);
	panel_black.alpha = 0;
	var i=50;
	{
	while (panel_black.alpha <80)
	{
		panel_black.alpha += 8*time_step; 
		wait(2);
	}
	panel_black.alpha = 100;
	wait(1);	
	}
}

function fade_out()
{
	media_tune(FMusic,1,0,0);
	panel_black.alpha = 100;
	var i=1;	
	{
	while (panel_black.alpha >20)
	{
		panel_black.alpha -= 8*time_step; 
		wait(2);
	}
	panel_black.alpha = 0;
		media_tune(FMusic,50,0,0);	
	}
	reset(panel_black,SHOW);
}


function ShowLevelSelect()
{
	reset(main_menu,SHOW);
	set(LevelSelect,SHOW);
}

function Authors()
{
}


PANEL* main_menu =
{
	pos_x = 0;
	pos_y = 0;
	bmap = menubmp2;


	button=300,500,button60pcx,button60pcx,button60pcx,ShowLevelSelect,NULL,NULL;
	button=550,500,button60pcx,button60pcx,button60pcx,Authors,NULL,NULL;
	button=650,500,button60pcx,button60pcx,button60pcx,Exit1,NULL,NULL;
	
	layer = 10;
	flags = OVERLAY | OUTLINE;
}

PANEL* hud_pan =
{
	bmap = hud_map;	
  pos_x = 4; pos_y = 4;
  window(78,40,439,13,compass_map,compass_x,compass_y);
  digits(52,70, "$%.0f", "System#15b", 1, FPlayerPickupCount); 
  flags = OVERLAY;
}




PANEL* pan_guitar1 =
{
	pos_x = 0;
	pos_y = 0;
	bmap = guit1bmp;	
	layer = 11;
	flags = OVERLAY | OUTLINE;
}

PANEL* pan_guitar2 =
{
	pos_x = 0;
	pos_y = 0;
	bmap = guit2bmp;	
	layer = 11;
	flags = OVERLAY | OUTLINE;
}

PANEL* pan_guitar3 =
{
	pos_x = 0;
	pos_y = 0;
	bmap = guit3bmp;	
	layer = 11;
	flags = OVERLAY | OUTLINE;
}

PANEL* pan_guitar4 =
{
	pos_x = 0;
	pos_y = 0;
	bmap = guit4bmp;	
	layer = 11;
	flags = OVERLAY | OUTLINE;
}





function ShowGuitar()
{
	if (FWeaponRating[FPlayerWeapon][1]==0){PriceStrings=5000;}else{PriceStrings=0;}
	if (FWeaponRating[FPlayerWeapon][2]==0){PricePickup=10000;}else{PricePickup=0;}
	if (FWeaponRating[FPlayerWeapon][3]==0){PriceKolk=7000;}else{PriceKolk=0;}
	
	reset(pan_guitar1,SHOW);
	reset(pan_guitar2,SHOW);
	reset(pan_guitar3,SHOW);
	reset(pan_guitar4,SHOW);
	
	if (FPlayerWeapon==0){set(pan_guitar1,SHOW);}
	if (FPlayerWeapon==1){set(pan_guitar2,SHOW);}
	if (FPlayerWeapon==2){set(pan_guitar3,SHOW);}
	if (FPlayerWeapon==3){set(pan_guitar4,SHOW);}
}

function nextguitar()
{
	var i=FPlayerWeapon+1;
	if (i==5){i=0;}
	while(FWeaponRating[i][0]==0)
	{
		i=i+1;
		if (i==5){i=0;}
	}
	FPlayerWeapon=i;
	ShowGuitar();
}

function pervguitar()
{
	var i=FPlayerWeapon-1;
	if (i==-1){i=4;}
	while(FWeaponRating[i][0]==0)
	{
		i=i-1;
		if (i==-1){i=4;}
	}
	FPlayerWeapon=i;
	ShowGuitar();
}

function buyg1()
{
	if (FWeaponRating[FPlayerWeapon][1]==0) 
	{
		if (FPlayerPickupCount>5000)
		{
			FPlayerPickupCount=FPlayerPickupCount-5000;
			PriceStrings=0;
			FWeaponRating[FPlayerWeapon][1]=1;
		}
	}
}

function buyg2()
{
		if (FWeaponRating[FPlayerWeapon][2]==0) 
	{
		if (FPlayerPickupCount>10000)
		{
			FPlayerPickupCount=FPlayerPickupCount-10000;
			PricePickup=0;
			FWeaponRating[FPlayerWeapon][2]=1;
		}
	}
}

function buyg3()
{
		if (FWeaponRating[FPlayerWeapon][3]==0) 
	{
		if (FPlayerPickupCount>7000)
		{
			FPlayerPickupCount=FPlayerPickupCount-7000;
			PriceKolk=0;
			FWeaponRating[FPlayerWeapon][3]=1;
		}
	}
}

function buybeer()
{
	if (FPlayerPickupCount>PriceBeer)
	{
		FPlayerPickupCount=FPlayerPickupCount-PriceBeer;
		PriceBeer =PriceBeer+2000;
		FInventory[0]=FInventory[0]+1;
	}
}

function buyenergy()
{
	if (FPlayerPickupCount>PriceEnergy)
	{
		FPlayerPickupCount=FPlayerPickupCount-PriceEnergy;
		PriceEnergy =PriceEnergy+2000;
		FInventory[1]=FInventory[1]+1;
	}
}

function buylife()
{
	if (FPlayerPickupCount>PriceLife)
	{
		FPlayerPickupCount=FPlayerPickupCount-PriceLife;
		PriceLife =PriceLife+2000;
		FInventory[3]=FInventory[3]+1;
	}
}


function buypick()
{
	if (FPlayerUpgrade[0]==0)
	{
		if (FPlayerPickupCount>10000)
		{
		FPlayerPickupCount=FPlayerPickupCount-10000;
		PricePick = 15000;
		FPlayerUpgrade[0]=1;
		}
	}	
	else
	if (FPlayerUpgrade[0]==1)
	{
		if (FPlayerPickupCount>15000)
		{
		FPlayerPickupCount=FPlayerPickupCount-15000;
		PricePick = 0;
		FPlayerUpgrade[0]=2;
		}	
	}
}

function buydistortion()
{
		if (FPlayerUpgrade[1]==0)
	{
		if (FPlayerPickupCount>20000)
		{
		FPlayerPickupCount=FPlayerPickupCount-20000;
		PriceDistortion = 25000;
		FPlayerUpgrade[1]=1;
		}
	}	
	else
	if (FPlayerUpgrade[1]==1)
	{
		if (FPlayerPickupCount>25000)
		{
		FPlayerPickupCount=FPlayerPickupCount-25000;
		PriceDistortion = 0;
		FPlayerUpgrade[1]=2;
		}	
	}
}

function buywire()
{	
	if (FPlayerUpgrade[2]==0)
	{
		if (FPlayerPickupCount>15000)
		{
		FPlayerPickupCount=FPlayerPickupCount-15000;
		PriceWire = 20000;
		FPlayerUpgrade[2]=1;
		}
	}	
	else
	if (FPlayerUpgrade[2]==1)
	{
			if (FPlayerPickupCount>20000)
		{
		FPlayerPickupCount=FPlayerPickupCount-20000;
		PriceWire = 0;
		FPlayerUpgrade[2]=2;
		}	
	}
}

function buyguitar()
{
	if (FPlayerPickupCount>100000)
	{
		FPlayerPickupCount=FPlayerPickupCount-100000;
		PriceGuitar = 0;
		FWeaponRating[3][0]=1;
	}	
}

function exitShop()
{
	FPlayerCanMove=1;
	reset(shop_menu,SHOW);	
	reset(pan_guitar1,SHOW);
	reset(pan_guitar2,SHOW);
	reset(pan_guitar3,SHOW);
	reset(pan_guitar4,SHOW);
}

PANEL* shop_menu =
{
	pos_x = 0;
	pos_y = 0;
	bmap = shopbmp;
//	digits(30,100, "Ëåãêèé                < %2.0f >", "Courier#30b", 1, LevelProgressEasy);  

   digits(336,70, "Replace strings        %2.0f", "Courier#20b", 1, PriceStrings);
   digits(336,105, "Replace pickups        %2.0f", "Courier#20b", 1, PricePickup);
   digits(336,145, "Replace pegs           %2.0f", "Courier#20b", 1, PriceKolk);
   
   digits(450,255, "Beer          (%2.0fpcs)", "Courier#20b", 1, FInventory[0]);
   digits(450,255, "                     %2.0f", "Courier#20b", 1, PriceBeer);
   
   digits(450,320, "Energy drink  (%2.0fpcs)", "Courier#20b", 1, FInventory[1]);
   digits(450,320, "                     %2.0f", "Courier#20b", 1, PriceEnergy);
   
   digits(450,376, "Elixir of life(%2.0fpcs)", "Courier#20b", 1, FInventory[3]);
   digits(450,376, "                     %2.0f", "Courier#20b", 1, PriceLife);
   
   digits(76,259, "Pick      Lv:%2.0f", "Courier#20b", 1, FPlayerUpgrade[0]);
   digits(76,319, "Pedal  lv:%2.0f", "Courier#20b", 1, FPlayerUpgrade[1]);
   digits(76,376, "Wire lv:%2.0f", "Courier#20b", 1, FPlayerUpgrade[2]);
   digits(76,431, "BCRich Ironbird   (not realized)%2.0f", "Courier#20b", 1, PriceGuitar);
   digits(76,259, "                %2.0f", "Courier#20b", 1, PricePick);
   digits(76,319, "                %2.0f", "Courier#20b", 1, PriceDistortion);
   digits(76,376, "                %2.0f", "Courier#20b", 1, PriceWire);
     
	digits(250,125, ">", "Courier#30b", 1, NULL);  
	digits(50,125, "<", "Courier#30b", 1, NULL);  
	
	digits(600,561, "Continue  ", "Courier#30b", 1, NULL);  
	button=250,125,button10pcx,button10pcx,button10pcx,nextguitar,NULL,NULL;
	button=50,125,button10pcx,button10pcx,button10pcx,pervguitar,NULL,NULL;
	button=336,70,button60pcx,button60pcx,button60pcx,buyg1,NULL,NULL;
	button=336,105,button60pcx,button60pcx,button60pcx,buyg2,NULL,NULL;
	button=336,145,button60pcx,button60pcx,button60pcx,buyg3,NULL,NULL;
	button=450,255,button60pcx,button60pcx,button60pcx,buybeer,NULL,NULL;
	button=450,320,button60pcx,button60pcx,button60pcx,buyenergy,NULL,NULL;
	button=450,376,button60pcx,button60pcx,button60pcx,buylife,NULL,NULL;	
	
	button=76,259,button60pcx,button60pcx,button60pcx,buypick,NULL,NULL;
	button=76,319,button60pcx,button60pcx,button60pcx,buydistortion,NULL,NULL;
	button=76,376,button60pcx,button60pcx,button60pcx,buywire,NULL,NULL;
	button=76,431,button60pcx,button60pcx,button60pcx,buyguitar,NULL,NULL;
	button=600,561,button60pcx,button60pcx,button60pcx,exitShop,NULL,NULL;
	
	layer = 10;
	flags = OVERLAY | OUTLINE ;
}

function game_continue()
{
	freeze_mode=0;
	reset(pan_pause,SHOW);
}

function exit_level()
{
	freeze_mode=0;
	FPlayerLife=-9;
	FPlayerHealth=-10;
	FFHitPlayer=1;
	reset(pan_pause,SHOW);
}

function use_beer()
{
	if (FPlayerHealth<20*(0.5/LevelMultiptex))
	{
		if (FInventory[0]>0){
			FPlayerHealth=FPlayerHealth+3;
			FInventory[0]=FInventory[0]-1;}
	}
}


PANEL* pan_pause =
{
	pos_x = 0;
	pos_y = 0;
	bmap = pause1bmp;
	
	digits(69,60, "Continue  ", "Courier#30b", 1, NULL); 
	digits(69,160, "Exit ", "Courier#30b", 1, NULL); 
	digits(341,36, "Inventory", "Courier#30b", 1, NULL); 
	digits(463,80, "x%2.0f", "Courier#30b", 1, FInventory[0]); 
	digits(463,156, "x%2.0f", "Courier#30b", 1, FInventory[1]); 
	
	button=69,60,button60pcx,button60pcx,button60pcx,game_continue,NULL,NULL;
	button=69,160,button60pcx,button60pcx,button60pcx,exit_level,NULL,NULL;
	button=463,80,button60pcx,button60pcx,button60pcx,use_beer,NULL,NULL;
	button=463,156,button60pcx,button60pcx,button60pcx,NULL,NULL,NULL;	
	layer = 13;
	flags = OVERLAY | OUTLINE;
}

function pause_game()
{
	freeze_mode=1;
	set(pan_pause,SHOW);
}

function YESlife()
{
	FPlayerHealth=20*(0.5/LevelMultiptex);
	FPlayerLife=1;
	FInventory[3]=FInventory[3]-1;
}

function NOlife()
{
FPlayerLife=-10;	
}

PANEL* pan_pause2 =
{
	pos_x = 0;
	pos_y = 0;
	bmap = pause2bmp;	
	digits(69,60, "use the elixir of life?", "Courier#30b", 1, NULL);
	digits(69,160, "YES", "Courier#30b", 1, NULL); 
	digits(341,160, "NO", "Courier#30b", 1, NULL); 
	button=69,160,button60pcx,button60pcx,button60pcx,YESlife,NULL,NULL;
	button=341,160,button60pcx,button60pcx,button60pcx,NOlife,NULL,NULL;
	layer = 12;
	flags = OVERLAY | OUTLINE;
}
