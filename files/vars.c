var LevelMultiptex=1; //множитель сложности
var LevelProgressEasy=1;
var LevelProgressNormal=1;
var LevelProgressHard=1;
var LevelMaxEasy=20;
var LevelMaxNormal=20;
var LevelMaxHard=20;
var Rating[20][5];
var FPlayerHitTimer=0;
var FPlayerHealth=4;
var FPlayerLife=4;
var FMusic;
var fcrouch=false;
var FCutScene=0;
var FPlayerPickupCount =0;
var FPlayerAttack=0;
var FPlayerAttackDmg=0;
var FPlayerComboId=0;

var FPlayerCanMove=1;

var FPlayerWeapon=1;
int FWeaponRating[5][3]; //струны, звукосниматели, колки
int FPlayerUpgrade[3][2]; // медиатор (пластик\метал), примочка (босс метал зон\ех метал маф), джек (экранированный джек, балансный +экран)  

var lcanjump=true;

var FStatTotalAttack=0;
var FStatTotalDmg=0;
var FStatAvgStyle=0;
var FStyle=0;
var FPickups=0;
var FTime=0;
var FStatTotal=0;