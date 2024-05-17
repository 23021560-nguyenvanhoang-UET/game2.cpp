
#ifndef GAME_H
#define GAME_H

#define INITIAL_SPEED 10

struct Mouse {
    int x, y;

    int dx = 0, dy = 0;
    int speed = INITIAL_SPEED;
    void move() {
        x += dx;
        y += dy;
    }
    void turnNorth(int &time) {
       y-=30;
    }
    void freeFalling()
    {
        y+=8;
    }
};

void render(const Mouse& mouse, const Graphics& graphics) {
    SDL_Rect filled_rect;
    filled_rect.x = mouse.x;
    filled_rect.y = mouse.y;
    filled_rect.w = 10;
    filled_rect.h = 10;
    SDL_SetRenderDrawColor(graphics.renderer, 0, 255, 0, 255); // green
    SDL_RenderFillRect(graphics.renderer, &filled_rect);
}


 bool isCollision (SDL_Rect rect1,SDL_Rect rect2)
{
    return SDL_HasIntersection(&rect1, &rect2);
}

bool isCollisionwithenemy(int x1,int y1,int manwidth,int manheight,int x2,int y2,int monsterwidth,int monsterheight)
{
    SDL_Rect manRect = {x1,y1,manwidth,manheight };
    SDL_Rect monsterRect = { x2,y2,monsterwidth,monsterheight };
    if(isCollision(manRect,monsterRect))
    {
        return true;
    }
    return false;


}

#endif // GAME_H
