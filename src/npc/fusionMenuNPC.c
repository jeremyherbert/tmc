#include "global.h"
#include "entity.h"
#include "npc.h"

void FusionMenuNPC(Entity* this) {
    if (gNPCFunctions[this->subtimer][2] != NULL) {
        gNPCFunctions[this->subtimer][2](this);
    } else {
        DeleteThisEntity();
    }
}

void FusionMenuNPC_Head(Entity* this) {
    if (gNPCFunctions[this->subtimer][1] != NULL) {
        gNPCFunctions[this->subtimer][1](this);
    }
}
