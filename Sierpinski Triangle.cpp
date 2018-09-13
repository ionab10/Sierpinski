#include <iostream>
#include <cstdlib>
#include <math.h>

#include <allegro.h>

using namespace std;              
                                                                                                                   
#define WHITE makecol(212,111, 249)

class POINT {
    private:
    
        int x, y;
    public:
        POINT() { x=0; y=0; }
        POINT(int a, int b) { x=a; y=b; }
        void setPoint(int a, int b) { x=a; y=b; }
        void setPoint(POINT a) { x=a.x; y=a.y; }
        POINT midPoint(POINT a, POINT b) { 
              POINT mid;
              mid.setPoint((a.x + b.x)/2, (a.y + b.y)/2);
            return mid;
        }
        POINT putPoint() {
            putpixel(screen, x, y, WHITE);
        }
};

int main() {
    // Allegro  initialization
    allegro_init();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 640, 0 , 0);
    install_keyboard();
    
    // Declare the vertex
    POINT vertex[3];
    POINT mid;
        
    vertex[0].setPoint(320, 50);
    vertex[1].setPoint(160, 400);
    vertex[2].setPoint(480, 400);
    
    POINT current(vertex[0]);
    
    while (! key[KEY_ESC]) {    
       for (int i=0; i<3; i++) 
           vertex[i].putPoint();
          
       for (int i=0; i<3; i++){   
       vertex[3].setPoint(vertex[0].midPoint(vertex[3], vertex[rand() % 3 + 0]));
       vertex[3].putPoint();
       }
       
       rest(10);   // slow down painting  

    }
              
    system("pause");
    return 0;
}
END_OF_MAIN()
