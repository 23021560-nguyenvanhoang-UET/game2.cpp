
#ifndef _CHAR__H
#define _CHAR__H
struct character{
    int x,y;
    int tus;
    bool OnGround(){ return (x == 422);}
    void HandleEvent(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
			case SDL_SCANCODE_UP:
			{
				if (OnGround())
				{
					tus = 1;
				}
			}
		}
	}
}
void Move()
{
	if (tus == 1 && y >= MAX_HEIGHT)
	{
		y += -JUMP_SPEED;
	}
	if (y <= MAX_HEIGHT)
	{
		tus = 2;
	}
	if (tus == 2 && y < 422)
	{
		y += FALL_SPEED;
	}
}



int GetPosX()
{
	return x;
}

int GetPosY()
{
	return y;
}
};
#endif
