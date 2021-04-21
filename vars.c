var debug=0;
var deathcounter=0;
var FBossHealth=0;
var LevelMultiptex=1; //множитель сложности
var LevelProgressEasy=1;
var LevelProgressNormal=1;
var LevelProgressHard=1;
var LevelMaxEasy=1;
var LevelMaxNormal=1;
var LevelMaxHard=1;
var Rating[20][5];
var FPlayerHitTimer=0;
var FPlayerHealth=20;
var FPlayerLife=1;
var FFHitPlayer=0;
var FMusic;
var fcrouch=false;
var FCutScene=0;
var FPlayerPickupCount =0;
var FPlayerAttack=0;
var FPlayerAttackDmg=0;
var FPlayerComboId=0;

BMAP* compass_map = "files/compass.dds";
BMAP* hud_map = "files/hud.dds";
var compass_x = 0;
var compass_y = 0;


var FPlayerCanMove=1;

var FPlayerWeapon=1;
int FWeaponRating[5][3]; //струны, звукосниматели, колки
int FPlayerUpgrade[3][2]; // медиатор (пластик\метал), примочка (босс метал зон\ех метал маф), джек (экранированный джек, балансный +экран)
int FVinyls[5][4];  

var lcanjump=1;
 var ljump = 0;

var FStatTotalAttack=0;
var FStatTotalDmg=0;
var FStatAvgStyle=0;
var FStyle=0;
var FPickups=0;
var FTime=0;
var FStatTotal=0;

var FKey=0;

