
#include "Controller.h"

int RepairVenicle::coming = 0;

int main() {
    Controller ctl;
    ctl.addCar();

    ctl.addRoad();
   // Road r(10000,10);
   // r.printDangerLevels();
    for (int i = 0; i < 5; ++i) {
       ctl.loop();
       sleep(1);
    }

    return 0;
}