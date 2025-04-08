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
            /*
            This function takes in an x and y coordinate. It then
            colors the box at that coordinate black and then all neighboring
            cells red. This function supports a toroidal structure.
            */
            std::vector<std::vector<int>> neighbors;
            //define all neighbors
            for (int i = x-1; x < x+2; x++) {
                for (int j = y-1; y < y+2; y++) {
                    neighbors.push_back({i, j});
                }
            }
            //color in all squares including center square red
            for (std::vector<int> neighbor : neighbors) {
                canvas.Rect(10*emp::Mod(neighbor[0], width), 10*emp::Mod(neighbor[1], height), cubewidth, cubeheight, "red", "black");
            }
            //overwrite center cube with black
            canvas.Rect(10*emp::Mod(x, width), 10*emp::Mod(y, width), cubewidth, cubeheight, "black", "black");
        }
        NFAnimator() {
            /*
            draws up initial grid
            */
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    canvas.Rect(cubewidth*x, cubeheight*y, cubewidth, cubeheight, "white", "black");
                }
            }
            //testing FindNeighbors function
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