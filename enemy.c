#include "vars.c";
#include "player.c";
var boss_coins =1000;

//skill5= health, 4=speed, 3=near, 2=far, 1=timer
action ANPC()
{
		my.scale_x = 1.907;
		my.scale_y = 1.907;
			my.scale_z = 1.907;
			while (my.skill4==0){wait(1);}
	
	var j=100;
	my.skill5=1;
	vec_set(my.min_x,vector(-20,-20,-240)); // set bounding box to individual values
   vec_set(my.max_x,vector(20,20,150));
	//set(my,PASSABLE);
 	my.min_z *= 0.5;
 	var speed_down = 0;   // downward speed by gravity
   var anim_percent = 0; // animation percentage
   var lplayer_direction=0;
   VECTOR vFeet;
   vec_for_min(vFeet,me); // vFeet.z = distance from player origin to lowest vertex
   var lattacktimer;
   var lattackpercent;
   var lanimpercent=0;
   
	while (my.skill5>0)
	{

		my.frame = 1;
		var dist_down; 
      if (c_trace(my.x,vector(my.x,my.y,my.z-5000),IGNORE_ME | IGNORE_SPRITES | IGNORE_PASSABLE | USE_BOX) > 0)
         dist_down = my.z + vFeet.z - target.z; // get distance between player's feet and the ground
      else
         dist_down = -1;
		
	   if (dist_down > 0)  // above floor, fall down with increasing speed
         dist_down = clamp(dist_down,0,accelerate(speed_down,5,0.1));
      else                // on or below floor, set downward speed to zero
         speed_down = 0;
      lplayer_direction =0; 
      if (FPlayerLife>0){
      if (vec_dist(my.x,player.x) >my.skill3) 
      {
      	if (vec_dist(my.x,player.x)  <my.skill2)
      	{
      		lattacktimer = my.skill1;
      	//	if (my.x>player.x){lplayer_direction=-1;}
      	//	if (my.x<player.x){
      			lplayer_direction=1;
      			//}
      			
      					if (my.x>player.x){my.pan=90;}
      		if (my.x<player.x){my.pan=270;}		
      		
      		lanimpercent = lanimpercent+my.skill4*0.05*time_step;
      		if (lanimpercent>4){lanimpercent=1;}
      		
      		my.frame=lanimpercent+1;	
      	}
      }
      else
      {
      	if (lattacktimer>0)
      	{
      		lattacktimer=lattacktimer-1;
      		lattackpercent=0;
      		my.frame = 1;
      	}
      	else
      	{
      		my.frame = 6+lattackpercent/30;
      		if (FPlayerAttack>50){my.skill5=0;snd_play(hit_snd,100,0);}
      		lattackpercent=lattackpercent+(10*time_step*LevelMultiptex);
      		if (lattackpercent>90)
      		{
      			lattacktimer= my.skill1;
      			lattackpercent=0;      			
      		}
      		if (lattackpercent>50)
      		{
      			if (vec_dist(my.x,player.x)  <my.skill3)
      			{
      				FHitPlayer();
      				j=j-1;
      				//lattacktimer = my.skill1;
      				
      			}
      		}
      	} 
      }	
      }
         
      var dist_ahead = (lplayer_direction)*time_step;
      
      dist_ahead = sign(dist_ahead)*(abs(dist_ahead) + 0.5*dist_down); // adapt the speed on slopes	
         
       c_move(me,vector(0,(my.skill4/8)*dist_ahead,0),vector(0,0,-dist_down),IGNORE_PASSABLE | IGNORE_SPRITES | GLIDE); // move the player
       wait(1);
	}
	set(my,PASSABLE);
	my.frame = 9;
	FPlayerPickupCount=FPlayerPickupCount+j;
	deathcounter=deathcounter+1;
//	ent_remove(me);
}


action ABoss1SuperPower()
{
	set(my,PASSABLE);
	my.z=my.z-80;
	if (my.x>player.x){my.pan=90;}
   if (my.x<player.x){my.pan=270;}	
	var i;
   for (i=0; i<500; i++) 
   {
   	c_move(me,vector(0,1,0),vector(0,0,0),IGNORE_SPRITES | GLIDE);
   	if (vec_dist(my.x,player.x)  <150)
   	if (lcanjump==true)
      			{
      				boss_coins=boss_coins-1;
      				FHitPlayer();		
      			}
   	wait(1);
   }	
   if (FPlayerLife>0)
   ent_remove(me);
}


action ABoss1()
{
	boss_coins =1000;
	my.skill5=5;
	vec_set(my.min_x,vector(-20,-20,-240)); // set bounding box to individual values
   vec_set(my.max_x,vector(20,20,150));
   FBossHealth =0;
   	vec_set(my.min_x,vector(-20,-20,-240)); // set bounding box to individual values
   vec_set(my.max_x,vector(20,20,150));
	FBossHealth=0;
 	my.min_z *= 0.5;
 	var speed_down = 0;   // downward speed by gravity
   var anim_percent = 0; // animation percentage
   var lplayer_direction=0;
   VECTOR vFeet;
   vec_for_min(vFeet,me); // vFeet.z = distance from player origin to lowest vertex
   var lattacktimer;
   var lattackpercent;
   
   var LAnimPercent=0;
   if (my.x>player.x){my.pan=90;}
   if (my.x<player.x){my.pan=270;}	
   random_seed(0);
   while (vec_dist(my.x,player.x)>500) 			//ждем игрока
	{
		LAnimPercent=LAnimPercent+1*time_step;
		if (LAnimPercent>20){LAnimPercent=0;}
		my.frame = 1;
		if (LAnimPercent>10){my.frame = 2;}
		wait(1);
	}															// запускаем диалог
		 
		FPlayerCanMove = 0;	
		var ldiag=4;
		ShowDialog=1;
		if (debug==0)
		while (ldiag<13)
		{
		DialogId=ldiag;
		wait(-0.5);
		my.frame = 2;
		wait(-0.5);
		my.frame = 1;
		wait(-0.5);
		my.frame = 2;
		wait(-0.5);
		my.frame = 1;
				wait(-0.5);
		my.frame = 2;
		wait(-0.5);
		my.frame = 1;
		wait(-0.5);
		my.frame = 2;
		wait(-0.5);
		my.frame = 1;
				wait(-0.5);
		my.frame = 2;
		wait(-0.5);
		my.frame = 1;
		ldiag=ldiag+1;	
		}
ShowDialog=0;
	
		FPlayerCanMove = 1;
		
															// начало битвы
		
	while (my.skill5>0)
	{
		FBossHealth =my.skill5*100;
		set(panel_boss,SHOW);
		if (my.x>player.x){my.pan=90;}
      if (my.x<player.x){my.pan=270;}
      var dist_down; 
      if (c_trace(my.x,vector(my.x,my.y,my.z-5000),IGNORE_ME | IGNORE_PASSABLE | IGNORE_SPRITES | USE_BOX) > 0)
         dist_down = my.z + vFeet.z - target.z; // get distance between player's feet and the ground
      else
         dist_down = 0;
		
	   if (dist_down > 0)  // above floor, fall down with increasing speed
         dist_down = clamp(dist_down,0,accelerate(speed_down,5,0.1));
      else                // on or below floor, set downward speed to zero
         speed_down = 0;
      lplayer_direction =0; 
      if (FPlayerLife>0)   
      if (random (5) > 4.995)	// пуляем супер способность
      	{
      		my.frame = 10;
      			snd_play(fire0_snd,100,0);
      		wait(-0.2);	
      		my.frame = 11;
      		wait(-0.2);
      		my.frame = 12;
      		ent_create("wave.dds",my.x,ABoss1SuperPower);
      		wait(-0.1);
      		my.frame = 1;
      		wait(-0.1);
      		my.frame = 2;
      	}
      if (FPlayerLife>0)
      if (vec_dist(my.x,player.x) >my.skill3) // пока игрок далеко- идем к нему
      {
      	lattacktimer = my.skill1;
      	//	if (my.x>player.x){lplayer_direction=-1;}
      	//	if (my.x<player.x){
      			lplayer_direction=1;
      			//}
      			
      					if (my.x>player.x){my.pan=90;}
      		if (my.x<player.x){my.pan=270;}		
      		
      		LAnimPercent = LAnimPercent+my.skill4*0.1*time_step;
      		if (LAnimPercent>4){LAnimPercent=1;}
      		
      		my.frame=LAnimPercent+2;		
      }
      else
      {
      	if (lattacktimer>0)
      	{
      		lattacktimer=lattacktimer-1;
      		lattackpercent=0;
      		my.frame = 1;
      	}
      	else
      	{
      		my.frame = 7+lattackpercent/30;
      		if (FPlayerAttack>50)
      		{
      			my.frame = 13;	
      			my.skill5=my.skill5-(0.5*(0.5/LevelMultiptex)); //получение урона
      			snd_play(hit_snd,100,0);
      			wait(-1);
      		}
      		lattackpercent=lattackpercent+(10*time_step*LevelMultiptex);
      		if (lattackpercent>90)
      		{
      			lattacktimer= my.skill1;
      			lattackpercent=0;      			
      		}
      		if (lattackpercent>50)
      		{
      			if (vec_dist(my.x,player.x)  <my.skill3)
      			{
      				FHitPlayer();
      				boss_coins = boss_coins-1;
      				//lattacktimer = my.skill1;
      				
      			}
      		}
      	} 
      	}
      	var dist_ahead = (lplayer_direction)*time_step;
      
      dist_ahead = sign(dist_ahead)*(abs(dist_ahead) + 0.5*dist_down); // adapt the speed on slopes	
         
       c_move(me,vector(0,(my.skill4)*dist_ahead,0),vector(0,0,-dist_down),IGNORE_PASSABLE | IGNORE_SPRITES | GLIDE); // move the player

	wait(1);	
	}	


	my.frame = 14;	
	//FPlayerCanMove = 0;
	FPlayerPickupCount = FPlayerPickupCount+boss_coins;

	reset(panel_boss,SHOW);
	
	ShowDialog=1;

		DialogId=13;
		wait(-2);
		DialogId=14;
		wait(-2);
	ShowDialog=0;	

	if (LevelMultiptex==0.5){LevelProgressEasy=3; if (LevelMaxEasy<3){LevelMaxEasy=3;}}
	if (LevelMultiptex==1){LevelProgressNormal=3; if (LevelMaxNormal<3){LevelMaxNormal=3;}}
	if (LevelMultiptex==2){LevelProgressHard=3;   if (LevelMaxHard<3){LevelMaxHard=3;}}
	game_save("save",0,SV_VARS);
		fade_in();
	wait(-2);
	
	if (LevelMultiptex==0.5){StartGame=1;}
	if (LevelMultiptex==1){StartGame=2;}
	if (LevelMultiptex==2){StartGame=3;}

}