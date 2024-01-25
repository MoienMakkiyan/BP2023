#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <windows.h>
#include<vector>

using namespace std;

void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian);
void TextBox (SDL_Renderer *Renderer);

string name;

int main( int argc, char * argv[] )
{
    int W = 600;
    int L = 1200;

    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( L, W, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    window_color(m_renderer,0,0,0);

    TextBox(m_renderer);

    int RNX = 200, RNY = 200;
    SDL_Event *event = new SDL_Event();

    while (1)
    {
        if( SDL_PollEvent(event) )
            {
                if( event->type == SDL_KEYDOWN )
                {
                    switch( event->key.keysym.sym )
                    {
                        case SDLK_ESCAPE:
                            {
                                SDL_DestroyWindow(m_window);
                                SDL_DestroyRenderer(m_renderer);
                                IMG_Quit();
                                SDL_Quit();
                                return 0;
                            }
                }
            }
        }
    }
}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor(Renderer,R,G,B,255);
    SDL_RenderClear(Renderer);
    SDL_RenderPresent(Renderer);
}

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian )
{
    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    if (fill_boolian==1)
        SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
}

void TextBox (SDL_Renderer *Renderer)
{
    const char * font_address_02="c:\\PROGRA~2\\CodeBlocks\\share\\CodeBlocks\\assets\\arial.ttf";
    bool caps_lock = false;
    int x_position=400;
    int y_position=150;
    int R=100;
    int G =100;
    int B=100;
    int A=255;
    int W = 370;
    int H = 200;
    bool quit = false ;
    char ch=0;
    textRGBA(Renderer,x_position , y_position , "Enter your name :", 2 , 24 , R ,G , B , A);
    rectangleRGBA(Renderer,x_position -10 , y_position -10 ,x_position +W+10 , y_position +H-10 ,R , G , B , 255);
    SDL_RenderPresent(Renderer);
    y_position = 150;

    SDL_Event *event = new SDL_Event();

    while (!quit)
    {
        if(SDL_PollEvent(event))
        {
            if(event -> type == SDL_KEYUP)
            {
                switch(event->key.keysym.sym)
                {
                    case SDLK_SPACE:
                    quit = true;
                    break;
                    case SDLK_CAPSLOCK:
                    ch=0;
                    if(!caps_lock)
                    caps_lock = true;
                    else
                    caps_lock = false;
                    break;
                    case SDLK_BACKSPACE:
                    ch = 0;
                    if(name.length()!=0)
                    {
                    textRGBA(Renderer,x_position +20 , y_position +H-105 , name.c_str(), 2 , 24 , 0 ,0 ,0 , A);
                    name = name.substr(0,name.length()-1);
                    }

                    break;
                    default :
                    if(event->key.keysym.sym != SDLK_UP && event->key.keysym.sym != SDLK_DOWN && event->key.keysym.sym != SDLK_LEFT && event->key.keysym.sym != SDLK_RIGHT)
                    ch = event->key.keysym.sym;
                    break;
                }
                if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') && name.length()<25 && !quit)
                {
                    if(caps_lock )
                    name+=ch + 'A' - 'a';
                    else
                    name+=ch ;
                }
                if(name != "" && !quit)
                textRGBA(Renderer,x_position +20 , y_position +H-105 , name.c_str(), 2 , 24 , 255 ,255 , 255 , A);
                SDL_RenderPresent(Renderer);
                cout<<name<<endl;
            }
        }
    }

}
