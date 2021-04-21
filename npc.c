action AAnimSprite()
{
	while(1)
	{
		my.frame += 1; 
		if (my.frame > my.skill2) 
		{ 
			my.frame = 1; // loop 
		}  
	wait (-0.5);
	}
}