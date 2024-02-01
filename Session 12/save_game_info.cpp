#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>

using namespace std;

struct ball{
    int x,y,color_r,color_g,color_b;
};

vector <ball> balls;
struct ball crash_ball;
bool is_crash_ball_moved = false;
bool is_crash_ball_crashed = false;

int x_mouse;
int y_mouse;

int dx = 10;
int dy = 10;
int rad_ball = 25;

string name = "";
bool namefound = false;

void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );
void intial_ball(SDL_Renderer *Renderer,int L,int W,int r,int n_line);
void draw_ball(SDL_Renderer *Renderer,int L,int W,int r,int n_line);
void intial_crash_ball();
void crashed_ball(SDL_Renderer *Renderer);
void save_ball_data();
void load_name();

int main( int argc, char * argv[] )
{
    int W = 600;
    int L = 1200;

    cout<<"Please Enter Your Name : ";
    cin>>name;

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


    int numebr_of_lines = 4;

    load_name();
    intial_ball(m_renderer,L,W,rad_ball,numebr_of_lines);
    intial_crash_ball();
    draw_ball(m_renderer,L,W,rad_ball,numebr_of_lines);
    SDL_RenderPresent(m_renderer);


    int RNX = 200, RNY = 200;
    SDL_Event *event = new SDL_Event();

    while (1)
    {
        rect(m_renderer,0,0,L,W,0,0,0,1);
        draw_ball(m_renderer,L,W,rad_ball,numebr_of_lines);
        crashed_ball(m_renderer);
        if( SDL_PollEvent(event) )
            {
                if( event->type == SDL_KEYDOWN )
                {
                    switch( event->key.keysym.sym )
                    {
                        case SDLK_RIGHT:
                            {
                                break;
                            }
                        case SDLK_LEFT:
                            {
                                break;
                            }
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
            /*if( event ->type != SDL_KEYDOWN )
                {
                    x_mouse = event->button.x;
                    y_mouse = event->button.y;
                    if (event->type==SDL_MOUSEBUTTONDOWN)
                    {

                    }
                }*/
        }
        SDL_RenderPresent(m_renderer);
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

void intial_ball(SDL_Renderer *Renderer,int L,int W,int r,int n_line)
{
    cout<<"Intial!!"<<endl;
    if(!namefound){
        cout<<"Run_Intial!!"<<endl;
        int x_center = r;
        int y_center = r;
        int n_colum = L/(2*r);
        int color = 0;
        //color 0 = red;
        //color 1 = blue;
        //color 2 = green;
        //color 3 = yellow;
        //color 4 = white;
        struct ball new_ball;
        for(int i=0;i<n_line;i++)
        {
            for(int j=0;j<n_colum;j++)
            {
                new_ball.x = x_center;
                new_ball.y = y_center;
                switch(rand()%5){
                    case 0:{
                        new_ball.color_r = 255;
                        new_ball.color_g = 0;
                        new_ball.color_b = 0;
                        break;
                    }
                    case 1:{
                        new_ball.color_r = 0;
                        new_ball.color_g = 255;
                        new_ball.color_b = 0;
                        break;
                    }
                    case 2:{
                        new_ball.color_r = 0;
                        new_ball.color_g = 0;
                        new_ball.color_b = 255;
                        break;
                    }
                    case 3:{
                        new_ball.color_r = 255;
                        new_ball.color_g = 255;
                        new_ball.color_b = 0;
                        break;
                    }
                    case 4:{
                        new_ball.color_r = 255;
                        new_ball.color_g = 255;
                        new_ball.color_b = 255;
                        break;
                    }
                }
                balls.push_back(new_ball);
                x_center+=2*r;
            }
            x_center = r;
            y_center+=2*r;
        }
        save_ball_data();
    }

}

void intial_crash_ball()
{
    crash_ball.x = 600;
    crash_ball.y = 500;

    switch(rand()%5){
        case 0:{
            crash_ball.color_r = 255;
            crash_ball.color_g = 0;
            crash_ball.color_b = 0;
            break;
        }
        case 1:{
            crash_ball.color_r = 0;
            crash_ball.color_g = 255;
            crash_ball.color_b = 0;
            break;
        }
        case 2:{
            crash_ball.color_r = 0;
            crash_ball.color_g = 0;
            crash_ball.color_b = 255;
            break;
        }
        case 3:{
            crash_ball.color_r = 255;
            crash_ball.color_g = 255;
            crash_ball.color_b = 0;
            break;
        }
        case 4:{
            crash_ball.color_r = 255;
            crash_ball.color_g = 255;
            crash_ball.color_b = 255;
            break;
        }
    }

    is_crash_ball_crashed = false;
    is_crash_ball_moved = false;
}
void draw_ball(SDL_Renderer *Renderer,int L,int W,int r,int n_line)
{
    for(int i=0;i<balls.size();i++)
    {
        filledCircleRGBA(Renderer,balls[i].x,balls[i].y,r,balls[i].color_r,balls[i].color_g,balls[i].color_b,255);
    }
}

void crashed_ball(SDL_Renderer *Renderer)
{
    SDL_Event *event = new SDL_Event();

    filledCircleRGBA(Renderer,crash_ball.x,crash_ball.y,25,crash_ball.color_r,crash_ball.color_g,crash_ball.color_b,255);
    if (!is_crash_ball_crashed)
    {
        if(!is_crash_ball_moved){
            aalineRGBA(Renderer,crash_ball.x,crash_ball.y,x_mouse,y_mouse,255,0,0,255);
        }
        else{
            if(crash_ball.x>1200||crash_ball.x<0)
                dx*=-1;
            if(crash_ball.y>600||crash_ball.y<0)
                dy*=-1;

            crash_ball.x+=dx;
            crash_ball.y+=dy;

            for(int i=0;i<balls.size();i++)
            {
                if(abs(crash_ball.x-balls[i].x)<rad_ball&&abs(crash_ball.y-balls[i].y)<rad_ball)
                {
                    is_crash_ball_crashed = true;
                    crash_ball.x -= crash_ball.x%rad_ball;
                    crash_ball.y -= crash_ball.y%rad_ball;
                    crash_ball.y += 2*rad_ball;
                    if(crash_ball.color_r==balls[i].color_r&&crash_ball.color_g==balls[i].color_g&&crash_ball.color_b==balls[i].color_b)
                    {
                        balls.erase(next(balls.begin(),i));
                        intial_crash_ball();
                    }
                    else{
                        balls.push_back(crash_ball);
                        intial_crash_ball();
                    }
                    break;
                }
            }
        }

        if( SDL_PollEvent(event) )
            {
                if( event->type == SDL_KEYDOWN )
                {
                    switch( event->key.keysym.sym )
                    {
                        case SDLK_SPACE:
                            {
                                if(!is_crash_ball_crashed){
                                    is_crash_ball_moved = true;
                                    dx = (x_mouse - crash_ball.x)/20;
                                    dy = (y_mouse - crash_ball.y)/20;
                                    break;
                                }
                            }
                }
            }
            if( event ->type != SDL_KEYDOWN )
                {
                    x_mouse = event->button.x;
                    y_mouse = event->button.y;
                }
        }
    }
}

void save_ball_data()
{
    string filename=name+".txt";
    remove(filename.c_str());
    ofstream output;
    output.open(filename.c_str(),ios::out);
    if(output.good())
    {
        output<<balls.size()<<endl;
        for(int i=0;i<balls.size();i++)
        {
            output<<balls[i].x<<" "<<balls[i].y<<" "<<balls[i].color_r<<" "<<balls[i].color_g<<" "<<balls[i].color_b<<endl;
        }
    }
    output.close();
}

void load_name()
{
    cout<<"Load!!"<<endl;
    ifstream input;
    string filename=name+".txt";
    input.open(filename.c_str(),ios::in);

    struct ball load_ball;

    int size_balls = 0;

    if(input.good())
    {
        input>>size_balls;
        for(int i=0; i<size_balls;i++)
        {
            input>>load_ball.x;
            cout<<load_ball.x<<" ";
            input>>load_ball.y;
            cout<<load_ball.y<<" ";
            input>>load_ball.color_r;
            cout<<load_ball.color_r<<" ";
            input>>load_ball.color_g;
            cout<<load_ball.color_g<<" ";
            input>>load_ball.color_b;
            cout<<load_ball.color_b<<endl;
            balls.push_back(load_ball);
        }
        namefound=true;
    }
    else namefound=false;
    input.close();

    is_crash_ball_crashed = false;
    is_crash_ball_moved = false;
}



