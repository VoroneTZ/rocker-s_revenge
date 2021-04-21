#include "vars.c";

var DialogId;
var ShowDialog=3;
var StartGame=0;

BMAP* button10pcx = "files/button.png";
BMAP* button60pcx = "files/button_w.png";
BMAP* menubmp = "files/menu.dds";
BMAP* menubmp2 = "files/main_menu.dds";
BMAP* vtz_logobmp = "files/vtz_logo.dds";
BMAP* zo_logobmp = "files/zo_logo.dds";
BMAP* dialogbmp = "files/dialog.dds";

PANEL* main_menu;

function LoadGame()
{
	media_stop(FMusic);
	if (game_load("save",0)<=0){game_save("save",0,SV_VARS);}
}

function SaveGame()
{
	game_save("save",0,SV_VARS);
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
	
	button=30,100,button60pcx,button60pcx,button60pcx,StartGameEasy,NULL,NULL;
	button=30,150,button60pcx,button60pcx,button60pcx,StartGameNorm,NULL,NULL;
	button=30,200,button60pcx,button60pcx,button60pcx,StartGameHard,NULL,NULL;
	button=30,450,button60pcx,button60pcx,button60pcx,NULL,NULL,NULL;
	button=30,500,button60pcx,button60pcx,button60pcx,SaveGame,NULL,NULL;
	button=230,500,button60pcx,button60pcx,button60pcx,LoadGame,NULL,NULL;
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
  	 
  	 if (DialogId==1){
  	 	pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Незнакомец"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("йо немытые собаки, валите отсюда"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("эта точка наша, а ваш рок параша"));
  	 	DialogId=0;}
  	 	
  	if (DialogId==2){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*РОКЕР"));
  	   pan_setstring(DialogText_panel,2,0,50,my_font,str_create("???"));
  	   pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;} 
  		
  	if (DialogId==3){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Незнакомец"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("разнесем ши вам в кашу!"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;} 
  	 	
  	 if (DialogId==4){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*РОКЕР"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("мужик, че за дела? почему эти второсортные"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("стихоплёты портят нам рок?"));
  	 	DialogId=0;} 
  	 	
  	if (DialogId==5){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Продюссер"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("прежде чем я тебе отвечу, давай я расскажу анекдот"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("Задохят Хэтфилд, Озборн и Горшок в бар и хотят заказать пиво"));
  	 	DialogId=0;} 
  	 	
  	if (DialogId==6){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Продюссер"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("а бармен им отвечает:"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("пацаны, вы опоздали на 30 лет. Смекаешь?"));
  	 	DialogId=0;} 
  	 	
  	 if (DialogId==7){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*РОКЕР"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("погоди, я пришел сюда не слушать твои нафталиновые"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("шутки, а раздать рока в этой дыре!"));
  	 	DialogId=0;}  
  	 	
  	if (DialogId==8){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Продюссер"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("ладно, давай по другой, есть два стула, на одном бабки"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("главные, на другом касухи дранные, понимаешь о чем я?"));
  	 	DialogId=0;}  	
  	 	
  	 if (DialogId==9){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*РОКЕР"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("старик, завязывай со своей философией"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("я рокер, а не абитуриент"));
  	 	DialogId=0;} 
  	 	
  	if (DialogId==10){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Продюссер"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("понимаешь, Рокер, мы наводили с тобой движуху"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("это было славное время, но времена изменились"));
  	 	DialogId=0;}   	
  	 	
  	if (DialogId==11){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Продюссер"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("тут больше нет места старой школе, твой контракт"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("с лейблом разорван, и в этом месте вам больше не рады"));
  	 	DialogId=0;}  
  	 	
  	 if (DialogId==12){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*РОКЕР"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("это мы еще посмотрим"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;}  
  	 	
  	  if (DialogId==13){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*РОКЕР"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("лучше нету для рывка"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("чем отличного пивка.."));
  	 	DialogId=0;}  
  	 	
  	  if (DialogId==14){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*РОКЕР"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("смутные времена наступили"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("нужна помощь настоящей рок звезды!"));
  	 	DialogId=0;}  
  	 	
  	 if (DialogId==15){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*РОКЕР"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("здарова МВ!"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;} 	
  	 	
  	 if (DialogId==16){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*МВ"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("здарова Рокер"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create(""));
  	 	DialogId=0;} 
  	 	
  	 if (DialogId==17){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*РОКЕР"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("в этом городе нам больше не рады,"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("рок теряет свои позиции под гнётом унылого речетатива"));
  	 	DialogId=0;} 	
  	 	
  	 	if (DialogId==18){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*РОКЕР"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("и обезьяних кривляний в широких штанах"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("мы должны дать бой рэпу, ты со мной?"));
  	 	DialogId=0;} 		
  	 	
  	 	
  	 	if (DialogId==19){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*МВ"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("я знал что этот день настанет. Рокеры не могут"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("вечно оставатся на вершине олимпа, рэп объявил нам войну"));
  	 	DialogId=0;} 
  	 	
  	 	if (DialogId==20){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*МВ"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("и продажные коммерческие крысы сбежали с корабля"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("а что для них важно? идеи? ритм? мелодика? нет!"));
  	 	DialogId=0;} 
  	 	
  		if (DialogId==21){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*МВ"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("доллар, доллар, доллар!"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("грязная зеленая бумажка!"));
  	 	DialogId=0;} 
  	 	
  	 	if (DialogId==22){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*МВ"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("мы должны дать бой сейчас, что бы следующие поколения"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("рокеров с хэвимэталом в душе мутили движуху"));
  	 	DialogId=0;} 
  	 	
  	 		if (DialogId==23){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*МВ"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("мы не должны дать этим глиным семенам рэпа взойти на"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("нашей плодородной рокерской почве, мы станем палачами рока"));
  	 	DialogId=0;} 
  	 	
  	 	if (DialogId==24){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*МВ"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("и имя нам"));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("патруль района!"));
  	 	DialogId=0;} 
  	 	
  	 	if (DialogId==25){
  		pan_setstring(DialogText_panel,1,0,0,my_font,str_create("*Конец демо-версии"));
  	 	pan_setstring(DialogText_panel,2,0,50,my_font,str_create("Продолжение следует..."));
  	 	pan_setstring(DialogText_panel,3,0,100,my_font,str_create("Специально для IGDC.RU"));
  	 	DialogId=0;} 
  	 	
  	 wait(2);
  }
}


function fade_in()
{
	set(panel_black,SHOW);
	panel_black.alpha = 0;
	var i=50;
//	while (i>1)
	{
	while (panel_black.alpha <80)
	{
		panel_black.alpha += 8*time_step; 
	//	if (i>1)
		//media_tune(FMusic,i,0,0);
	//	i=i-0.2;
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
	//	if (i<=50)
	//	media_tune(FMusic,i,0,0);
	 //  i=i+0.2;
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

function Exit1()
{
	printf("d");	
	sys_exit("");
}

PANEL* main_menu =
{
	pos_x = 0;
	pos_y = 0;
	bmap = menubmp2;


	button=300,500,button60pcx,button60pcx,button60pcx,ShowLevelSelect,NULL,NULL;
	button=550,500,button60pcx,button60pcx,button60pcx,Authors,NULL,NULL;
	button=650,400,button60pcx,button60pcx,button60pcx,Exit1,NULL,NULL;
	
	layer = 10;
	flags = OVERLAY | OUTLINE;
}

PANEL* hud_pan =
{
	bmap = hud_map;	
  pos_x = 4; pos_y = 4;
  window(78,40,439,13,compass_map,compass_x,compass_y);
  flags = OVERLAY;
}