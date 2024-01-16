#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <time.h>

using namespace std;

SDL_Window *m_window;
SDL_Renderer *m_renderer;
int X0,Y0;
void SetRenderDrawColor(int R, int G, int B){SDL_SetRenderDrawColor(m_renderer, R,G,B,255);}
void RenderClear(){SDL_RenderClear(m_renderer);}
void RenderPresent(){SDL_RenderPresent(m_renderer);}
void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++) for(int j=0;j<n-1-i;j++) if(arr[j]<arr[j+1]) swap(arr[j],arr[j+1]);
}
void rect( int x,int y,int w,int h,int R, int G, int B, int fill_boolian ){
    SDL_Rect Rect;
    Rect.x = x;
    Rect.y = y;
    Rect.w = w;
    Rect.h = h;
    SDL_SetRenderDrawColor(m_renderer, R, G, B, 255);
    if (fill_boolian==1) SDL_RenderFillRect(m_renderer, &Rect);
    SDL_RenderDrawRect(m_renderer, &Rect);
}

void ellipse( int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian){
    if(fill_boolian==1) filledEllipseRGBA(m_renderer,X0-x,Y0-y,Radius1,Radius2,R,G,B,255);
    if(fill_boolian==0) ellipseRGBA(m_renderer,X0-x,Y0-y,Radius1,Radius2,R,G,B,255);
}

void elipse( int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian){
    if(fill_boolian==1) filledEllipseRGBA(m_renderer,x,y,Radius1,Radius2,R,G,B,255);
    if(fill_boolian==0) ellipseRGBA(m_renderer,x,y,Radius1,Radius2,R,G,B,255);
}

double sine(int x,int y){
    double X=x;
    double Y=y;
    return Y/pow((X*X+Y*Y),0.5);
}
double cos(int x,int y){
    double X=x;
    double Y=y;
    return (X/pow((X*X+Y*Y),0.5));
}
bool Sort(int x1,int y1,int x2,int y2){
    if(cos(x1,y1)<cos(x2,y2))
        return true;
    return false;
}

void my_line(int x,int y, double theta,int l){
    thickLineRGBA(m_renderer,x,y,x+l*cos(theta),y+l*sin(theta),3,255,0,0,255);
}
int main(int argc, char * argv[]){
    int n,N=0;
    cin>>n;
    X0=1200;
    Y0=800;
    int arr[n][2];
    int x,y,Ymax=0,Imax;

    for(int i=0;i<n;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
        if(Ymax<arr[i][1]){
                Ymax=arr[i][1];
                Imax=i;
        }
    }
    swap(arr[Imax],arr[n-1]);
    n--;
    int xo=arr[n][0];
    int yo=arr[n][1];
    for(int i=0;i<n;i++){
        arr[i][0]-=xo;
        arr[i][1]-=yo;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1-i;j++)
            if(Sort(arr[j][0],arr[j][1],arr[j+1][0],arr[j+1][1]))
                swap(arr[j],arr[j+1]);
     for(int i=0;i<n;i++){
        arr[i][0]+=xo;
        arr[i][1]+=yo;
    }
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( X0, Y0, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    SetRenderDrawColor( 255, 255, 255);
    RenderClear();

    double theta=0;
    int m=0;
    for(int i=0;i<=n;i++)
        elipse(arr[i][0],arr[i][1],5,5,255,0,0,1);
    thickLineRGBA(m_renderer,arr[n][0],arr[n][1],arr[0][0],arr[0][1],3,0,0,0,255);
    for(int i=0;i<n-1;i++){
        thickLineRGBA(m_renderer,arr[i][0],arr[i][1],arr[i+1][0],arr[i+1][1],3,0,0,0,255);
    }
    thickLineRGBA(m_renderer,arr[n][0],arr[n][1],arr[n-1][0],arr[n-1][1],3,0,0,0,255);
    RenderPresent();

    SDL_Delay(10000);
}








