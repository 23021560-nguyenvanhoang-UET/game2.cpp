#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "graphics.h"
#include "moving.h"
#include "char.h"

int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();
    int tus(2);
    Sprite dino;
    Mouse diNo;
    diNo.x=200;
    diNo.y=435;
    Mouse cactus;
    cactus.x=400;
    cactus.y=422;
    Mouse cactus1;
    cactus1.x=800;
    cactus1.y=422;
    Mouse cactus2;
    cactus2.x=1200;
    cactus2.y=422;
    int jumptimes=17;
    SDL_Event e;
    SDL_Texture*dinoTexture=graphics.loadTexture(DINO_SPRITE_FILE);
    dino.init(dinoTexture,6,DINO_CLIPS);
    int time(0);
    SDL_Texture*cactusTexture=graphics.loadTexture("images\\cactus.png");
    SDL_Texture*gameoverTexture=graphics.loadTexture("images\\lose.png");

    ScrollingBackground l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
    l1.setTexture(graphics.loadTexture("images\\layer01.png"));
    l2.setTexture(graphics.loadTexture("images\\layer02.png"));
    l3.setTexture(graphics.loadTexture("images\\layer03.png"));
    l4.setTexture(graphics.loadTexture("images\\layer04.png"));
    l5.setTexture(graphics.loadTexture("images\\layer05.png"));
    l6.setTexture(graphics.loadTexture("images\\layer06.png"));
    l7.setTexture(graphics.loadTexture("images\\layer07.png"));
    l8.setTexture(graphics.loadTexture("images\\layer08.png"));
    l9.setTexture(graphics.loadTexture("images\\layer09.png"));
    l10.setTexture(graphics.loadTexture("images\\layer11.png"));


    bool quit = false;

    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = true;
        }
         Mix_Music *gMusic = graphics.loadMusic("sounds\\bkgr_audio.wav");
        graphics.play(gMusic);
        Mix_Chunk *gJump = loadSound("sounds\\lose_sound.wav");

        if(isCollisionwithenemy(diNo.x+12,diNo.y+9,32,41,cactus.x+3,cactus.y,40,56)||isCollisionwithenemy(diNo.x+12,diNo.y+9,32,41,cactus1.x+3,cactus1.y,40,56)||isCollisionwithenemy(diNo.x+12,diNo.y+9,32,41,cactus2.x+3,cactus2.y,40,56))
        {
            play(gJump);
            graphics.renderTexture(gameoverTexture,0,0);
            graphics.presentScene();
            waitUntilKeyPressed();
            quit=true;
        }

        l1.scroll(0);
        l2.scroll(2);
        l3.scroll(3);
        l4.scroll(4);
        l5.scroll(5);
        l6.scroll(6);
        l7.scroll(4);
        l8.scroll(4);
        l9.scroll(3);
        l10.scroll(5);
        graphics.render(l1);
        graphics.render(l2);
        graphics.render(l3);
        graphics.render(l4);
        graphics.render(l5);
        graphics.render(l6);
        graphics.render(l7);
        graphics.render(l8);
        graphics.render(l9);
        graphics.render(l10);
        graphics.render2(diNo.x,diNo.y,dino);
        dino.tick();


        graphics.renderTexture(cactusTexture,cactus.x,cactus.y);
        graphics.renderTexture(cactusTexture,cactus1.x,cactus1.y);
        graphics.renderTexture(cactusTexture,cactus2.x,cactus2.y);

        cactus.x-=5;
        cactus1.x -= 5;
        cactus2.x -= 5;
        if(cactus.x<=-100) cactus.x=SCREEN_WIDTH + rand()%300;
        if(cactus1.x<=-100) cactus1.x=SCREEN_WIDTH+ rand() % 300;
        if(cactus2.x<=-100) cactus2.x=SCREEN_WIDTH + rand() % 300;


        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if(currentKeyStates[SDL_SCANCODE_UP]) tus=1;

        if (currentKeyStates[SDL_SCANCODE_UP]&&tus==1 &&jumptimes>0)
        {
            if(diNo.y>=390) diNo.y-=20;
            if(diNo.y>280)diNo.y-=10;
            if(diNo.y>270)diNo.y-=1;
            jumptimes--;
        }
        else tus=2;
        if(diNo.y<=435&&tus==2) diNo.y+=10;


        if(diNo.y>=435) jumptimes=25;
       // graphics.drawRect(diNo.x+12,diNo.y+9,32,41);
        //graphics.drawRect(cactus.x+3,cactus.y,40,56);
        //graphics.drawRect(cactus1.x+3,cactus1.y,40,56);
        //graphics.drawRect(cactus2.x+3,cactus2.y,40,56);

        graphics.presentScene();
        SDL_Delay(30);
    }


    graphics.quit();

}
