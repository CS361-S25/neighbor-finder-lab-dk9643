/*
AUTHOR: DEXTER KONG, 4/7/25
programming assignment for a lab about finding neighbors
implements a function that draws on a website and then another function
that gets one point and that point is drawn in black. All neighbors are drawn in red
*/

#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"
#include "emp/math/math.hpp"

emp::web::Document doc{"target"};

const int width = 50;
const int height = 50;
const int cubewidth = 10;
const int cubeheight = 10;

class NFAnimator : public emp::web::Animate {
    emp::web::Canvas canvas{width*cubewidth, height*cubeheight, "canvas"};
    public:
        void FindNeighbors(int x, int y) {
            std::vector<std::vector<int>> neighbors = {
                {x-1, y-1},
                {x, y-1},
                {x+1, y-1},
                {x-1, y},
                {x+1, y},
                {x-1, y+1},
                {x, y+1},
                {x+1, y+1},        
            };
            canvas.Rect(10*x, 10*y, cubewidth, cubeheight, "black", "black");
            for (std::vector<int> neighbor : neighbors) {
                canvas.Rect(10*emp::Mod(neighbor[0], width), 10*emp::Mod(neighbor[1], height), cubewidth, cubeheight, "red", "black");
            }
        }
        NFAnimator() {
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    canvas.Rect(cubewidth*x, cubeheight*y, cubewidth, cubeheight, "white", "black");
                }
            }
            FindNeighbors(0, 0);
            FindNeighbors(25, 25);
            doc << canvas;
            doc << "Hi";
        }
        
};

NFAnimator animator;

int main() {
    animator.Step();
}