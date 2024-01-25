#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <windows.h>

using namespace std;

void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void menu(SDL_Renderer *Renderer);
void blue(SDL_Renderer *Renderer);
void red(SDL_Renderer *Renderer);
void green(SDL_Renderer *Renderer);
void start_game();
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );


int main( int argc, char * argv[] )
{
    int W = 600;
    int L = 600;

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


    int RNX = 200, RNY = 200;
    SDL_Event *event = new SDL_Event();

    while (1)
    {
        menu(m_renderer);
        start_game();
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

void menu(SDL_Renderer *Renderer)
{
    rectangleRGBA(Renderer,100,150,250,250,255,0,0,255);//red
    rectangleRGBA(Renderer,350,150,500,250,0,255,0,255);//blue
    rectangleRGBA(Renderer,100,400,250,500,0,0,255,255);//green
    rectangleRGBA(Renderer,350,400,500,500,255,255,0,255);//yellow

    SDL_RenderPresent(Renderer);

    SDL_Event *e = new SDL_Event();

    bool Exit = false;
    int x_m;
    int y_m;

    while(!Exit)
    {
        if( SDL_PollEvent( e ) )
        {
            if( e ->type != SDL_KEYDOWN )
                {
                    x_m=e->button.x;
                    y_m=e->button.y;
                    if (e->type==SDL_MOUSEBUTTONDOWN)
                    {
                        if(x_m>100&&x_m<250&&y_m>150&&y_m<250)//Red
                            red(Renderer);
                        if(x_m>350&&x_m<500&&y_m>150&&y_m<250)//Green
                            green(Renderer);
                        if(x_m>100&&x_m<250&&y_m>400&&y_m<500)//Blue
                            blue(Renderer);
                        if(x_m>350&&x_m<500&&y_m>400&&y_m<500)//EXIT
                            Exit = true;

                    }
                }
        }
    }
    cout<<"This Function Ended!";
    filledCircleRGBA(Renderer,300,300,10000,0,0,0,255);
    SDL_RenderPresent(Renderer);
}


void start_game()
{
    while(1)
    {
        ///TODO
        cout<<"The Game is Palying!"<<endl;
    }
}
